//-------------------------Problem Statement--------------------------

/* Given and array find the highest peak */

#include <bits/stdc++.h>
using namespace std;

int highest_mountain(vector<int> arr)
{
    int largest = 0;
    int n = arr.size();
    for(int i = 1; i < n-1;){

        if(arr[i] > arr[i-1] and arr[i] > arr[i+1]){
            int count = 1;
            int j = i;
            while(j >= 1 and arr[j-1] < arr[j]){
                j--;
                count++;
            }
            while(i <= n-2 and arr[i] > arr[i+1]){
                i++;
                count++;
            }
            largest = max(largest, count);
        }
        else{
            
            i++;
        }
    }
    return largest;
}

int main(){

    vector<int> arr = {5, 6, 1, 2, 3, 4, 5, 4, 3, 2, 0, 1, 2, 3, -2, 4};
    cout<<highest_mountain(arr);
}



