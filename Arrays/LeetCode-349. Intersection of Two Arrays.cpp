// Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.

 

// Example 1:

// Input: nums1 = [1,2,2,1], nums2 = [2,2]
// Output: [2]
// Example 2:

// Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
// Output: [9,4]
// Explanation: [4,9] is also accepted.
 

// Constraints:

// 1 <= nums1.length, nums2.length <= 1000
// 0 <= nums1[i], nums2[i] <= 1000

// --------------------------------------------------------------------------

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    //     vector<int> ans;

    //     for(int i = 0 ; i < nums1.size(); i++){
    //         int element = nums1[i];

    //         bool isPresent = false;
    //         for(int k = 0 ; k < ans.size() ;  k++){
    //             if(ans[k] == element){
    //                 isPresent = true;
    //                 break;
    //             }
    //         }
                
    //         if(isPresent) continue;

    //         //checking == with the i th index value to all values of the 2nd array.
    //         for(int j = 0 ; j < nums2.size() ; j++){
    //             if(element == nums2[j]){
    //                 ans.push_back(nums1[i]);
    //                 nums1[i] = -1;
    //                break;
    //             }
    //         }
            
    //     }
    //     return ans;
    
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> ans;
        
        int i=0, j = 0;
        
        while(i< nums1.size() &&  j < nums2.size()){
            if(nums1[i]==nums2[j]){
                if(ans.empty() || ans.back()!=nums1[i]){
                ans.push_back(nums1[i]);
                }
                i++;j++;
            }
            else if(nums1[i]<nums2[j])
                i++;
            else
                j++;
        }
    return ans;
    }
};
