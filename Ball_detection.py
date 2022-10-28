import cv2
import numpy as np

cap = cv2.VideoCapture(0)

while True:
    ret, frame = cap.read()
    blurred = cv2.GaussianBlur(frame, (11, 11), 0)  
    imgHSV = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)

    colorlow = np.array([29, 86, 6])
    colorhigh = np.array([64, 255, 255])
    mask = cv2.inRange(imgHSV, colorlow, colorhigh)
    mask = cv2.erode(mask, None, iterations=2)
    mask = cv2.dilate(mask, None, iterations=2)
    contours, hierarchy = cv2.findContours(mask,cv2.RETR_TREE,cv2.CHAIN_APPROX_SIMPLE)
    if len(contours) > 0:
        c = max(contours, key=cv2.contourArea)
        (x, y), radius = cv2.minEnclosingCircle(c)
        M = cv2.moments(c)
        center = (int(M["m10"] / M["m00"]), int(M["m01"] / M["m00"]))
        if radius > 10:
            cv2.circle(frame, (int(x), int(y)), int(radius),(0, 255, 255), 2)
            cv2.circle(frame, center, 2, (0, 0, 255), 1)

    cv2.imshow("frame", frame)

    return1 = cv2.waitKey(10)
    if return1 == ord("q"):
        break

cv2.destroyAllWindows()