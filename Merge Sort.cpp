#include <iostream>
#include <vector>

using namespace std;

void sorted(vector<int>& nums, int st, int mid, int end){
    vector<int> temp;
    int i = st;
    int j = mid + 1;
    while(i <= mid && j <= end){
        if(nums[i] <= nums[j]){
            temp.push_back(nums[i]);
            i++;
        }
        else{
            temp.push_back(nums[j]);
            j++;
        }
    }
    while(i <= mid){
        temp.push_back(nums[i]);
        i++;
    }
    while(j <= end){
        temp.push_back(nums[j]);
        j++;
    }
    for(int i = 0; i < temp.size(); i++){
        nums[i+st] = temp[i];
    }


}

void merge(vector<int>& nums, int st, int end){
    if(st < end){
        int mid = st + (end - st)/2;

        merge(nums, st, mid);
        merge(nums, mid + 1, end);
        sorted(nums, st, mid, end);
    }
}

int main(){
    vector<int> nums {1,42,12,5,2324,0,987,6};
    merge(nums, 0, nums.size() - 1);

    for(int val : nums){
        cout << val << " ";
    }

}