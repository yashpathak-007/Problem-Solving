// Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

// You must write an algorithm that runs in O(n) time and without using the division operation.

 

// Example 1:

// Input: nums = [1,2,3,4]
// Output: [24,12,8,6]
// Example 2:

// Input: nums = [-1,1,0,-3,3]
// Output: [0,0,9,0,0]
 

// Constraints:

// 2 <= nums.length <= 105
// -30 <= nums[i] <= 30
// The input is generated such that answer[i] is guaranteed to fit in a 32-bit integer.
 

// Follow up: Can you solve the problem in O(1) extra space complexity? (The output array does not count as extra space for space complexity analysis.)



//-----------------------------------------------------------------------------------------------------------------------------------------------------------



class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        //BRUTE FORCE APPROCH 

        int n = nums.size();
      
        //vector of size n which is initiated with 1
        vector<int> ans(n,1) ;
      
        // for(int i = 0 ; i < n ; i++){
        //     // int product = 1;
        //     for(int j = 0 ; j < n ; j++){
        //         if(j != i){
        //             // product *= nums[j];
        //             ans[i] *= nums[j]; 
        //         }
        //     }
        //     // ans[i] = product;
        // }
        // return ans;

        // OPTIMISE APPROCH


        // vector<int> suffix(n,1);
        // vector<int> prefix(n,1);

        // for(int i = 1 ; i < n ; i++){
        //     prefix[i] = prefix[i-1] * nums[i-1];
        // }
        
        // for(int i = n-2 ; i >= 0 ; i--){
        //     suffix[i] = suffix[i+1] * nums[i+1];
        // }
        
        // for(int i = 0 ; i < n ; i++){
        //     ans[i] = prefix[i] * suffix[i];
        // }

        // return ans;


        // MORE OPTIMISE APPROCH - O(1) SPACE COMPLEXITY
        //we dont have to use the extra vectors for prefix and suffix

        
        for(int i = 1 ; i < n ; i++){
            ans[i] = ans[i-1] * nums[i-1];
        }

        int suff = 1;
        for(int i = n-2; i >=0 ; i--){ //reverse loop n-2 to 0
            suff *= nums[i+1];
            ans[i] *= suff; 
        }
        return ans;
    }
};
