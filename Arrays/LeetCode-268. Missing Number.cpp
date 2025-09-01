// Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

 

// Example 1:

// Input: nums = [3,0,1]

// Output: 2

// Explanation:

// n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.

// Example 2:

// Input: nums = [0,1]

// Output: 2

// Explanation:

// n = 2 since there are 2 numbers, so all numbers are in the range [0,2]. 2 is the missing number in the range since it does not appear in nums.

// Example 3:

// Input: nums = [9,6,4,2,3,5,7,0,1]

// Output: 8

// Explanation:

// n = 9 since there are 9 numbers, so all numbers are in the range [0,9]. 8 is the missing number in the range since it does not appear in nums.



//--------------------------------------------------------------------------------------------------------------------------------------------------------


class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0 ; i <= n ; i++){
            int count = 0;                      // approch 01 - bruteforce 
            for(int j = 0 ; j < n ; j++){
                if(i == nums[j]) count++;
            }
            if(count == 0) return i;
        }
        return -1;

// -----------------------------------------------------------
// using formula for the sum of n number and subtracting the actual sum by the expected sum.

    long long int total = (1LL *n *(n+1))/2;
    long long sum = 0;
    for(int i : nums) sum += i;                                // approch 02 - formula n(n+1)/2

    return (int)total-sum  ;

// --------------------------------------------------------------

        // using xor opration
        int xor1 = 0 ; int xor2 = 0;
        for(int i: nums) xor1 ^= i;
        for(int i = 0 ; i <= n ; i++){              //approch 03 - using xor ** best way 
            xor2 ^= i;
        } 
        return xor1 ^ xor2;
    }
};
