#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isValid(vector<int> ar, int cow, int mid){
    
    int count = 1;
    int last_position = ar[0];

    for(int i=1;i<ar.size();i++){
        if(ar[i]-last_position >= mid ){
            count++;
            last_position = ar[i];
            if(count==cow){
                return true;
            }
        }
    }
    return false;
   

}

int aggresivecow(vector<int> ar, int cow){
    sort(ar.begin(), ar.end());
    int st = 1;
    int end = ar.back()-ar[0];
    int ans = 0;
    while(st <= end){
        int mid = st + (end - st)/2;
        if(isValid(ar, cow, mid)){
            ans = mid;
            st = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    return ans;
}

int main() {
    vector<int> ar{1,2,4,8,9};
    int cow = 3;
    int ans = aggresivecow(ar, cow);
    cout << ans;

    

    return 0;
}