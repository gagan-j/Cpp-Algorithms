#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> nums{1,1,2,2,2,2,2,2,1,1};
    int s = nums.size(),ans =0;
    int freq = 0;
    for(int value:nums){
        if(freq==0){
            ans = value;
        }
        if(ans == value){
            freq++;
        }
        else{
            freq--;
        }
    }
    cout<<ans;
    return 0;
}