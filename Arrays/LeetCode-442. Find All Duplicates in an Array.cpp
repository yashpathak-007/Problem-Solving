// Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears at most twice, return an array of all the integers that appears twice.

// You must write an algorithm that runs in O(n) time and uses only constant auxiliary space, excluding the space needed to store the output

 

// Example 1:

// Input: nums = [4,3,2,7,8,2,3,1]
// Output: [2,3]
// Example 2:

// Input: nums = [1,1,2]
// Output: [1]
// Example 3:

// Input: nums = [1]
// Output: []
 

// Constraints:

// n == nums.length
// 1 <= n <= 105
// 1 <= nums[i] <= n
// Each element in nums appears once or twice.


// ----------------------------------------------------------------------------


//we are using here index marking trick where we mark the visited indexed value as negative so that when the particular element in the arraay repeats then that index is already marked as negative that we can use the condition like nums[index] < is less then zero 0 mean -ve hence value if the partipular itrative index is duplicate so we puch back the particular value toi the vector .

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;

        for(int i= 0; i < nums.size(); i++){
            
            int index = abs(nums[i])-1;
            if (nums[index]<0){
                // result.push_back(abs(nums[i]));  //yuha par index + 1 ki value rakh sakte hai kyuki apn num ka index -1 krke nikala tha phale 
                result.push_back(index + 1);
            }
            else{
                nums[index] = -nums[index];
            }
        }
        return result;
    }
};

// class Solution {
// public:
//     vector<int> findDuplicates(vector<int>& nums) {
        
//         vector<int> values;
//         for(int i =0; i < nums.size(); i++){
//             int index = abs(nums[i]) -1;

//             if(nums[index] < 0){
//                 values.push_back(index + 1);
//             } else{
//                 nums[index] = -nums[index];
//             }
//         }

//         return values;
//     }
// };


