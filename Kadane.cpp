#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> nums{1,2,3,4,5};
    int s = nums.size();
    int currsum =0;
    int maxnum=0;
    for(int i=0;i<s;i++){
        currsum += nums[i];
        maxnum = max(currsum,maxnum);
        if(currsum<0){
            currsum =0;
        }
    }
    cout << "Maximum subarray sum is " << maxnum << endl;
    return 0;
}