#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main(){
   vector<int> nums {1,2,3,1,1,1,1,4,2,3};
   int n = nums.size();
   vector<int> pref(n,0);  // 1,3,6,7,8,9,10,14,16,19
   pref[0] = nums[0];
   for(int i = 1; i < n; i++){
      pref[i] = pref[i-1] + nums[i];
   }
   int k = 3;
   int count = 0;
   unordered_map<int, int> m;
   for(int i = 0; i < n; i++){
      if(pref[i] == k){
         count++;
         continue;
      }
      int diff = pref[i] - k;

      if(m.find(diff) != m.end()){
         count++;
      }
      m[pref[i]] = i;

   }
   cout << count << endl;

}