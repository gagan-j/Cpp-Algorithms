#include<iostream>
using namespace std;
int main(){
  int ar[]{90,80,70,60,50,40,30,20,10,0};
  int n = 10;
  for(int i = 1;i<=n-1;i++){
    for(int j=i;j>=0;j--){
      if(ar[j-1]>ar[j]){
        swap(ar[j],ar[j-1]);
      }
    }

  }
  for(int i=0;i<n;i++){
    cout<<ar[i]<<" ";
  }
}
/*#include <iostream>
#include <vector>
using namespace std;

vector<int> insertionSort (vector<int>& ar){
    int s = ar.size();
    

    for(int i = 0; i < s - 1; i++){
        for(int j = i ; j >= 0; j--){
            if (ar[j+1] < ar[j]){
                swap(ar[j+1],ar[j]);
            }
        }
    }
    return ar;
}

int main() {
    vector<int> ar {12,34,677,2,0,2,56,234,666,2323,6,2,1,54,67,7,8};
    insertionSort (ar);

    for(int val : ar){
        cout<< val << " ";
    }

    return 0;
}
*/