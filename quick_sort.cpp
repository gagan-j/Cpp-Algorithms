#include <iostream>
#include <vector>

using namespace std;

int paritioning(vector<int>& nums, int low, int high){

    int pivot = nums[low];
    int i = low + 1, j = high;
    while(i <= j){
        while(i <= high && nums[i] <= pivot){
            i++;
        }
        while(j > low && nums[j] > pivot){
            j--;
        }
        if(i < j){
            swap(nums[i], nums[j]);
        }
        
    }
    swap(nums[j],nums[low]);
    return j;
    
}

void quicksort(vector<int>& nums, int low, int high){
    if(low < high){
        int parti = paritioning(nums, low, high);
        quicksort(nums, low, parti - 1);
        quicksort(nums, parti + 1, high);
    }
}

int main(){
    vector<int> nums {12,5,1,567,9,7,6,34,0,99,879};
    quicksort(nums, 0, nums.size()-1);
    for(int val : nums){
        cout << val << " ";
    }
}