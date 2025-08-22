// You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

// Return the single element that appears only once.

// Your solution must run in O(log n) time and O(1) space.

 

// Example 1:

// Input: nums = [1,1,2,3,3,4,4,8,8]
// Output: 2
// Example 2:

// Input: nums = [3,3,7,7,10,11,11]
// Output: 10
 

// Constraints:

// 1 <= nums.length <= 105
// 0 <= nums[i] <= 105

// ----------------------------------------------------------


class Solution {
public:
    int singleNonDuplicate(vector<int>& a) {
        int st = 0 ; int end = a.size()-1;
        //edge case 
        if(a.size()==1)
            return a[0];
        
        //using binary search for finding single element
        while(st <= end){
            int mid = st + (end - st)/2;
            
            //if mid is at 0th and n-1th index 
            if( mid == 0 && a[mid] != a[mid+1])
                return a[mid];
            if(mid == a.size()-1 && a[mid] != a[mid-1])
                return a[mid];
            
            //if middle element is the single element
            if (a[mid] != a[mid-1] && a[mid] != a[mid+1])
                return a[mid];

            //if no of elements both side of mid is even 
            if(mid % 2 == 0){
                if(a[mid] == a[mid-1]){
                    end = mid-1; //left side 
                }
                else{
                    st = mid + 1;  //right side
                }
            }//for odd no of the elements 
            else{
                if(a[mid]==a[mid-1]){ //right side
                    st = mid+1; 
                }
                else{
                    end = mid-1; //left side
                }
            }
        }
        return -1;
    }

};
