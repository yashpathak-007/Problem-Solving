#include<iostream>
#include<vector>

using namespace std;
//function to find pivot.
int findPivot(vector<int>& a, int n){
    int st = 0 ; int end = n-1;
    while(st < end){
        int mid = st + (end-st)/2;
        if((a[mid]< a[mid+1]) && (a[mid]< a[mid-1])){
            return mid;
        }
        else if(a[mid]>= a[0]){
            st = mid +1;
        }
        else{
            end = mid -1;
        }
    }
    return -1;
} 

//main  function
int main(){
    vector<int> a = {1,2,3,4,7,2,3,4};
    int ans = findPivot(a, a.size());
    cout<<"Index of the pivot element is : "<< ans;
}


// output ==> Index ofthe pivot element is : 5

