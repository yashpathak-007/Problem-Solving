// 1. Selection Sort

// Idea: Repeatedly find the minimum element from the unsorted part and put it at the beginning.

// Process:

//   Outer loop → pick index i

//   Inner loop → find index of min element in [i…n-1]

//   Swap min element with arr[i]

// Time Complexity:

//   Worst: O(n^2)

//   Best: O(n^2)

//   Average: O(n^2)

// Space Complexity: O(1) (in-place)

// Stable? ❌ (swapping may change relative order)


#include<iostream>
#include <algorithm> 
using namespace std;

void selectionSort(int arr[], int n){
    
    for(int i = 0 ; i < n ; i++){
        int min = i;
        for (int j = i+1; j < n ; j++)
        {
            if(arr[min] > arr[j])
                min = j;
        }
        swap(arr[min], arr[i]);             
        
    }
}

int main(){
    int arr[] = {6, 4, 2, 1 ,8};

    int n = 5;cout << "UnSorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;   

    selectionSort(arr,n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
