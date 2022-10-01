#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int mincost(int arr[], int n)
{
   priority_queue< int, vector<int>, greater<int>>queue(arr, arr+n);
   int minimumcost = 0;

   while (queue.size() > 1) 
   {
      int item1 = queue.top();            
      queue.pop();

      int item2 = queue.top();          
      queue.pop();

      minimumcost += item1 + item2;         
      queue.push(item1 + item2);
   }
   return minimumcost;
}

int main() {
   int ropelength[] = {8,3,9,1,11};
   int n =5;
   cout << "Total minimum cost: "<<mincost(ropelength, n);
}