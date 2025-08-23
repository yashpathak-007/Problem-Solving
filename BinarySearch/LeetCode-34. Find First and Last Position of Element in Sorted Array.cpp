// Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

// If target is not found in the array, return [-1, -1].

// You must write an algorithm with O(log n) runtime complexity.

 

// Example 1:

// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]
// Example 2:

// Input: nums = [5,7,7,8,8,10], target = 6
// Output: [-1,-1]
// Example 3:

// Input: nums = [], target = 0
// Output: [-1,-1]
 

// Constraints:

// 0 <= nums.length <= 105
// -109 <= nums[i] <= 109
// nums is a non-decreasing array.
// -109 <= target <= 109

// ------------------------------------------------------------------------------------------------------------------------------------------------------

class Solution {
public:
    int firstPos(vector<int>& a, int key){ //functionm that find first pos of target
        int st = 0 ; int end = a.size()-1;
        int ans = -1;
        
        while (st <= end){
            int mid = st + (end - st)/2;
            if(a[mid] == key){
                ans = mid;
                end = mid -1;
            }
            else if(a[mid] < key){
                st = mid +1;
            }
            else{
                end = mid -1;
            }
        }
        return ans;
    }

    int lastPos(vector<int>& a, int key){  //function that find lastPos of target
        int st = 0 ; int end = a.size()-1;
        int ans = -1;
        
        while (st <= end){
            int mid = st + (end - st)/2;
            if(a[mid] == key){
                ans = mid;
                st = mid + 1;
            }
            else if(a[mid] < key){
                st = mid +1;
            }
            else{
                end = mid -1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& a, int target) {
        // auto low = lower_bound(nums.begin(), nums.end(), target);
        // auto high = upper_bound(nums.begin(), nums.end(), target);
        
        // if (low == nums.end() || *low != target) return {-1, -1};
        // return {int(low - nums.begin()), int(high - nums.begin() -       1)};

        //ye to tha STL use krke lakin apn bnaenge logic khudse okkk..!!
        int first = firstPos(a, target);
        int last = lastPos(a, target);

        return {first, last};

    }
};
