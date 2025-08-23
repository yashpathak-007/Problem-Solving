// A peak element is an element that is strictly greater than its neighbors.

// Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

// You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.

// You must write an algorithm that runs in O(log n) time.

 

// Example 1:

// Input: nums = [1,2,3,1]
// Output: 2
// Explanation: 3 is a peak element and your function should return the index number 2.
// Example 2:

// Input: nums = [1,2,1,3,5,6,4]
// Output: 5
// Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.
 

// Constraints:

// 1 <= nums.length <= 1000
// -231 <= nums[i] <= 231 - 1
// nums[i] != nums[i + 1] for all valid i.


//-=-------------------------------------------------------------------------------------------------------------------------------------------------------------

class Solution {
public:
    int findPeakElement(vector<int>& a) {
        int st = 0 ; int end = a.size()-1;

        if(a.size()==1){ // edge case
            return 0;
        }

        while (st<= end){
            int mid = st + (end - st)/2;
            //two other edge cases.
        //     if(mid == 0){
        //         if(a[mid]>a[mid+1]){
        //             return mid;
        //         }
        //         else{
        //             return (mid+1);
        //         }
        //     }
        //     else if(mid == a.size()-1){       //detailed solutiom

        //         if(a[mid]>a[mid-1]){
        //             return mid;
        //         }
        //         else{
        //             return (mid-1);
        //         }
        //     }
        //     else if(a[mid] > a[mid-1] && a[mid] > a[mid+1]){
        //         return mid;
        //     }
        //     else if(a[mid] < a[mid+1]){ //right jao
        //         st = mid+1;
        //     }
        //     else {  //left jao
        //         end = mid-1;
        //     } 

        //compact version of the following code 
        // all edge cases at once with mid found to be peak value.
        if((mid == 0 || a[mid] > a[mid-1]) && 
        (mid == a.size()-1 || a[mid] > a[mid+1])){
                    return mid;
        }
        if(mid < a.size()-1 && a[mid] < a[mid+1]){
            st=mid + 1;                                                      // compact solution
        }
        else{
            end = mid -1;
        }
        }// while ka hai closing braces
        return -1;
    }
};
