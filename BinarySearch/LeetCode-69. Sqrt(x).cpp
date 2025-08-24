// Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.

// You must not use any built-in exponent function or operator.

// For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.
 

// Example 1:

// Input: x = 4
// Output: 2
// Explanation: The square root of 4 is 2, so we return 2.
// Example 2:

// Input: x = 8
// Output: 2
// Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.
 

// Constraints:

// 0 <= x <= 231 - 1


// -----------------------------------------------------------------------------------------------------------------------------------------


class Solution {
public:
//we try to find sqrt using the concept of binary search.
    long long int binarySearchSQRT(int n){
        int st = 0 ; int end = n;
        long long int ans = -1;
        while(st<= end){
            long long int mid = st + (end - st)/2;
            long long int sq = mid*mid; // so that it can handle sq     values that exceeds the maximum value limit of int.

            if(sq == n){
                return mid;
            }
            else if(sq < n){
                ans = mid; // if not divided properly then stored round value will be return as the sq root stored in the ans variable in each iteration for sq less then  the number it dipicted the possible ans of the problem.
                st = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }
        return ans;
    }
    int mySqrt(int x) {
        return binarySearchSQRT(x);
    }
};
