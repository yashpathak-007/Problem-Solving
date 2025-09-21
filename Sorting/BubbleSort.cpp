// 2. Bubble Sort

// Idea: Repeatedly swap adjacent elements if they are in the wrong order.

// Process:

//   Each pass “bubbles up” the largest element to the end.

//   Keep doing passes until array sorted.

// Time Complexity:

//   Worst: O(n^2)

//   Best: O(n) (when already sorted, with optimized version)

//   Average: O(n^2)

// Space Complexity: O(1)

// Stable? ✅ (doesn’t change relative order)

#include<iostream>
#include<algorithm>
using namespace std;
void bubbleSort(int arr[],int n){
    for(int i = 1 ; i < n ; i++){
        for(int j = 0 ; j < n-i ; j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}
int main(){
    int arr[] = {10,3,5,8,1,12};
    int n = 6;
    bubbleSort(arr,n);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

}
