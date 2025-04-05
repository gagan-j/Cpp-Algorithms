#include<iostream>
#include<vector>

using namespace std;

int merge(vector<int>& nums, int st, int end, int mid){
    int inv = 0;
    int i = st, j = mid + 1;
    vector<int> temp;
    while(i <= mid && j <= end){
        if(nums[i] <= nums[j]){
            temp.push_back(nums[i]);
            i++;
        }
        else{
            temp.push_back(nums[j]);
            inv += (mid - i + 1);
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
        nums[st+i] = temp[i];
    }
    return inv;

}

int ms(vector<int>& nums, int st, int end){
    if(st < end){
        int mid = st + (end - st)/2;
        int lt = ms(nums, st, mid);
        int rt = ms(nums, mid + 1, end);
        int in = merge(nums, st, end, mid);
        return lt+rt+in;
    }
    return 0;
}


int main(){
    vector<int> nums {6, 3, 5, 2, 7};
    int inv = ms(nums, 0, nums.size() - 1);
    cout << "inversions are : " << inv << endl;

}

