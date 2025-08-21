// Taking an array of size n and swap the alternate values only with each other (Ajecent values), line {1,2,4,5,6} -----> {2,1,4,3,6,5}

#include<iostream>
using namespace std;

//optional , recommended to use std:: swap function for th epurpose of swapinhg of values .
void swap(int &a, int &b){  // we have to pass values of the array as the reference variable other wise it send the copy of the variable.
    int temp;
    temp = a;
    a = b;
    b = temp;

    return;
}

void inputInArray(int arr[], int n){
    cout<<"Enter elements of the array:";
    for (int i = 0; i < n; i++)
    {
        cin>> arr[i];
    } 
}
void swapAlternate(int arr[], int n){
     for(int i = 0 ; i < n ; i+=2){
        if((i+1) < n ){
            swap(arr[i], arr[i+1]);
        }
     }
     return;
}
void printARR(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        cout<< arr[i]<<" ";
    } 
    cout<<endl;
}
int main(){
    // int arr[6] = {12,44,675,7,8,4};
    int n ;
    cout<<"Enter the size of the array : "  ;
    cin>>n;
    int arr[50];
    inputInArray(arr, n);
    cout<<"before swapping the alternate values"<<endl;
    printARR(arr, n);
    swapAlternate(arr, n);
    cout<<"After swaping the alternate values"<<endl;
    printARR(arr, n);
}
