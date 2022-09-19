#include <stdio.h>
#include <string.h>

#define MAXSIZE 100

struct Stack {
    int top;
    int array[MAXSIZE];
} st;

void initialize() {
    st.top = -1;
}

int isFull() {
    if(st.top >= MAXSIZE-1)
        return 1;
    else
        return 0;
}

int isEmpty() {
 if(st.top == -1)
     return 1;
 else
     return 0;
}

void push(int num) {
    if (isFull())
        printf("STACK IS FULL\n");
    else
        st.array[++st.top] = num;
}

int pop() {
    if (isEmpty())
        printf("STACK IS EMPTY\n");
    else
        return st.array[st.top--];
}

int main() {
    char exp[100], c;
    int i;
    initialize();
    printf("ENTER AN EXPRESSION: ");
    gets(exp);

    for(i = 0; i < strlen(exp); i++){
        if(exp[i] == '{')
            push(exp[i]);
        else if(exp[i] == '}'){
            if (st.array[st.top]== '{')
                pop();
            else {
            printf("NOT BALANCED\n");
            return 0;
            }
        }
        if(exp[i] == '[')
            push(exp[i]);
        else if(exp[i] == ']'){
            if (st.array[st.top]== '[')
                pop();
            else {
            printf("NOT BALANCED\n");
            return 0;
            }
        }
        if(exp[i] == '(')
            push(exp[i]);
        else if(exp[i] == ')'){
            if (st.array[st.top]== '(')
                pop();
            else {
            printf("NOT BALANCED\n");
            return 0;
            }
        }
    }

    if(isEmpty())
        printf("BALANCED\n");
    else
        printf("NOT BALANCED\n");

    return 0;
}
