// 3. Insertion Sort

// Idea: Build sorted array one element at a time by inserting each element into its correct position.

// Process:

//   Start from index 1 → pick element (key)

//   Compare with elements on left, shift larger ones

// Insert key in correct place

// Time Complexity:

//   Worst: O(n^2)

//   Best: O(n) (when array already sorted)

//   Average: O(n^2)

// Space Complexity: O(1)

// Stable? ✅


#include<iostream>
using namespace std ;

void insertionSort(int arr[] , int n){
    for (int i = 1; i < n; i++)
    {
        int temp = arr[i]; int j;
        for (j = i-1; j >= 0; j--)
        {
            if (arr[j] > temp)
            {   
                arr[j+1] = arr[j];
            }
            else{
                break;
            }
        }
        arr[j+1] = temp;
    }
    
}

int main(){
    int arr[] = {10 , 8 , 2, 5 , 4 , 7};
    int n = 6 ; 
    insertionSort(arr, n);
    cout<<"Sorted Array : ";
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}
