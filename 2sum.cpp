#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int main(){ /*
  vector<int> arr{2,6,5,8,11};
  unordered_map<int, int> m;
  int k = 14;
  vector<int> ans;
  for(int i = 0; i < arr.size(); i++){
    int diff = k - arr[i];

    if(m.find(diff) != m.end()){
      ans.push_back(m[diff]);
      ans.push_back(i);
    }
    m[arr[i]] = i;
  }
  for(int val : ans){
    cout << val <<" ";
  } */

  vector<int> arr{2,5,6,8,11};
  int n = arr.size();

  int l = 0;
  int r = n - 1;
  int k = 14;

  while(l <= r){
    int sum = arr[r] + arr[l];
    if(sum == k){
      cout << l << " " << r << endl;
      break;
    }
    else if(sum < k){
      l++;
    }
    else{
      r--;
    }
  }



}