#include <iostream>
#include <vector>
using namespace std;



int main() {
    vector<int> ar {2,0,2,1,1,0};
    int s = ar.size();
    int low = 0;
    int mid = 0;
    int high = s-1;

    while(mid<=high){
        if(ar[mid]==0){
            swap(ar[low],ar[mid]);
            low++;
            mid++;
        }
        else if(ar[mid]== 1){
            mid++;
    
        }
        else{
            swap(ar[mid], ar[high]);
            high--;
        }
    }

    for(int val : ar){
        cout<< val << " ";
    }

    return 0;
}