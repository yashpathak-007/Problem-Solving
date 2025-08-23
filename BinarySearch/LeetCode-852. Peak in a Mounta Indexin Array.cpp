// You are given an integer mountain array arr of length n where the values increase to a peak element and then decrease.

// Return the index of the peak element.

// Your task is to solve it in O(log(n)) time complexity.

 

// Example 1:

// Input: arr = [0,1,0]

// Output: 1

// Example 2:

// Input: arr = [0,2,1,0]

// Output: 1

// Example 3:

// Input: arr = [0,10,5,2]

// Output: 1

 

// Constraints:

// 3 <= arr.length <= 105
// 0 <= arr[i] <= 106
// arr is guaranteed to be a mountain array.

// -------------------------------------------------------------------------------------------------------------

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        //as index 0 and n-1 will never be the peak element of the array
        //as it is mountain array
        int st = 1; int end = arr.size()-1; 
        
        while(st <= end){
            int mid = st + (end - st)/2;

            if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]){
                return mid;
            } 
            else if(arr[mid] < arr[mid-1]){
                end = mid -1;
            }
            else{
                st = mid +1;
            }
        }
        return -1;
    }
};
