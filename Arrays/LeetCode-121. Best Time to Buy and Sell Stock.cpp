// You are given an array prices where prices[i] is the price of a given stock on the ith day.

// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

 

// Example 1:

// Input: prices = [7,1,5,3,6,4]
// Output: 5
// Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
// Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
// Example 2:

// Input: prices = [7,6,4,3,1]
// Output: 0
// Explanation: In this case, no transactions are done and the max profit = 0.
 

// Constraints:

// 1 <= prices.length <= 105
// 0 <= prices[i] <= 104


//----------------------------------------------------------------------------------------------------------------------------------------------------


class Solution {
public:
    int maxProfit(vector<int>& price) {
        int maxP = 0 ; int bestB = price[0];
        int n = price.size();

        for(int i = 0 ; i < n ; i++){
            if(price[i] > bestB){                     // price of that day > buyprice tabhi to profit niklega isliye check kiya nahi to sirf best price k liye\
                                                        // check krenge kyuki agr pricce buy se kam  hua to loss hoga profit nahi 
                                                        //maxP main bhi yhi check kr rhe haai ki us din ka or jo phale k price k hisab se profit hai dono main se konsa jda hai
                maxP = max(maxP, price[i] - bestB);
            }

            bestB = min(bestB, price[i]);
        }
        return maxP;
    }
};
