// Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

// You must implement a solution with a linear runtime complexity and use only constant extra space.

 

// Example 1:

// Input: nums = [2,2,1]

// Output: 1

// Example 2:

// Input: nums = [4,1,2,1,2]

// Output: 4

// Example 3:

// Input: nums = [1]

// Output: 1

 

// Constraints:

// 1 <= nums.length <= 3 * 104
// -3 * 104 <= nums[i] <= 3 * 104
// Each element in the array appears twice except for one element which appears only once.





// -------------------------------------------------------------------------------------------------------------------


class Solution {
public:
    int singleNumber(vector<int>& nums) {

        // this is a brut force approch for solving the proble 
        //but we can solve this by using bit manipulation using 
        //xor operation to get optimised version of the solution.

        int n = nums.size();
        for(int i = 0; i < n ; i++){
            int count = 0 ;
            for(int j = 0; j < n ; j++){
                if(nums[i] == nums[j]) count++;
            }
            if(count == 1) return nums[i];
        }
        return -1;


        // ------------------------------------------

        //better approch - bit manipulation
        // n^n=0 and n^0 = n 
        // eg = 2^2^1 --> 0^2=2 --> 2^2 =0 --> 0^1 = 1 <--ans

        int ans = 0;
        for(int i : nums){     //MORE OPTIMISE
            ans ^= i;
        }
        return ans;
    }
};
