#include<iostream>
using namespace std;
int main(){
  int ar[10]{3,4,2,23,45,67,86,99,0,1};
  int n = 10;
  for(int i = 1; i < n; i++ ){
    for(int j = 0; j< n-i; j++){
      if(ar[j]>ar[j+1]){
        swap(ar[j],ar[j+1]);
      }
    }
  }
  for(int i = 0; i<n; i++){
    cout<<ar[i]<<" ";
  }
}
/*#include <iostream>
#include <vector>
using namespace std;

vector<int> bubbleSort(vector<int>& arr){
    int size = arr.size();
    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
    return arr;
}

int main() {
    vector<int> arr {4,8,6,1,0};
    bubbleSort(arr);
    for (int val : arr){
        cout<<val<<" ";
    }

    return 0;
}*/