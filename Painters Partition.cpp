#include <iostream>
#include <vector>
using namespace std;

bool isValid(vector<int> ar, int painter, int n, int mid){
    
    if(painter > n){
        return false;
    }
    
    int unit = 0;
    int painters = 1;

    for(int i = 0; i < n; i++){
        if(ar[i] > mid){
            return false;
        }
        if(ar[i]+unit <= mid){
            unit += ar[i];
        }
        else{
            painters++;
            unit = ar[i];
        }
    }
    return (painters==painter) ? true : false;

}

int partition(vector<int> ar, int painter, int n){
    int total_unit = 0;
    for(int i = 0; i < n; i++){
        total_unit += ar[i];
    }
    int st = 0;
    int end = total_unit;
    int ans = 0;
    while(st <= end){
        int mid = st + (end - st)/2;
        if(isValid(ar, painter, n, mid)){
            ans = mid;
            end = mid - 1;
        }
        else{
            st = mid + 1;
        }
    }
    return ans;
}

int main() {
    vector<int> ar{40, 30, 10, 20};
    int painter = 2;
    int n = 4;
    int ans = partition(ar, painter, n);
    cout << ans;

    

    return 0;
}