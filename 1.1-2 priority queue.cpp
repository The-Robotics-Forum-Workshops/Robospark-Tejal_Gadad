#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int findMinimumCost(int arr[], int n) {
   //priority queue is set as whose value is bigger, have higher priority
   priority_queue< int, vector<int>, greater<int>>queue(arr, arr+n);

   int minCost = 0;

   while (queue.size() > 1) {              //when queue has more than one element
      int item1 = queue.top();            //item1 is the shortest element
      queue.pop();

      int item2 = queue.top();          //item2 is bigger than item1 but shorter then other
      queue.pop();

      minCost += item1 + item2;         //connect ropes and add them to the queue
      queue.push(item1 + item2);
   }
   return minCost;
}

int main() {
   int ropeLength[] = {4, 3, 2, 6, 5, 7, 12};
   int n = 7;
   cout << "Total minimum cost: " << findMinimumCost(ropeLength, n);
}