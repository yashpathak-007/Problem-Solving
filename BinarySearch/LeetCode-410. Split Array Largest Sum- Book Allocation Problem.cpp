// Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.

// Return the minimized largest sum of the split.

// A subarray is a contiguous part of the array.

 

// Example 1:

// Input: nums = [7,2,5,10,8], k = 2
// Output: 18
// Explanation: There are four ways to split nums into two subarrays.
// The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.
// Example 2:

// Input: nums = [1,2,3,4,5], k = 2
// Output: 9
// Explanation: There are four ways to split nums into two subarrays.
// The best way is to split it into [1,2,3] and [4,5], where the largest sum among the two subarrays is only 9.
 

// Constraints:

// 1 <= nums.length <= 1000
// 0 <= nums[i] <= 106
// 1 <= k <= min(50, nums.length)



// -----------------------------------------------------------------------------------------------------

// also known as book allocation problem.

class Solution {
public:
    bool isValid(vector<int>& a, int k, int maxAllow){
        int n = a.size(); int splits = 1 ; int sum = 0;

        for(int i = 0 ; i < n; i++){
            if(a[i] > maxAllow){
                return false;
            }
            if(sum + a[i] <= maxAllow){
                sum += a[i];
            }
            else{
                splits++;
                sum = a[i];
            }
        }
        return splits > k ? false : true;
    }
    int splitArray(vector<int>& a, int k) {
        int sum = 0;
        if(a.size() < k){
            return -1;
        }
        for(int i = 0 ; i < a.size(); i++){
            sum += a[i];
        }

        int st = *max_element(a.begin(), a.end()); //0 bhi le sakte ho bs no of iteration bd jaegi
 ; 
        int end = sum;
        int ans = -1;

        while(st <= end){
            int mid = st + (end - st)/2;
            if(isValid(a,k,mid)){ //mid is the valid sum of subarray
                ans = mid;
                end = mid -1;
            }
            else{ //mid is invalid sum of any subarray of the given array
                st = mid + 1; //move right side
            }
        } 
        return ans;
    }
};
