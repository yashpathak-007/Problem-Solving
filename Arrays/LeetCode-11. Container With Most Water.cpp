// You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

// Find two lines that together with the x-axis form a container, such that the container contains the most water.

// Return the maximum amount of water a container can store.

// Notice that you may not slant the container.

 

// Example 1:


// Input: height = [1,8,6,2,5,4,8,3,7]
// Output: 49
// Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
// Example 2:

// Input: height = [1,1]
// Output: 1
 

// Constraints:

// n == height.length
// 2 <= n <= 105
// 0 <= height[i] <= 104



//-----------------------------------------------------------------------------------------------------------------------


class Solution {
public:
    int maxArea(vector<int>& height) {
        // int maxWater = 0 ;
        // int n = height.size();

        // BRUTEFORCE APPROCH FOR THE PARTICULAR PROBLEM

        // for(int i = 0 ; i < n ; i++){ //for left boundary 
        //     for(int j = i+1 ; j < n ; j++){ //for right boundary
        //         int width = j-i; 
        //         int ht = min(height[i], height[j]); //hight till which container can able to fiull water
        //         int area = ht * width; //total water 

        //         maxWater = max(maxWater, area);
        //     }
        // }
        // return maxWater;


        // TWO POINTER APPROCH -- OPTIMISE SOLUTION 

        int maxWater = 0 ;
        int n = height.size();
        int lp = 0; int rp = n-1;
        
        while(lp < rp){

            int width = rp - lp;
            int ht = min(height[rp], height[lp]);
            int currWater = width * ht; 

            maxWater = max(maxWater, currWater);

            // if(height[rp] > height[lp]){
            //     lp++;
            // } 
            // else{
            //     rp--;
            // }

            //we also use ternary operator

            (height[rp]>height[lp]) ? lp++ : rp-- ;
        }
        return maxWater;
    }
};
