//------------------------------Problem Statement------------------------------------//

 /* Given an array find the smallest subarray that needa to be sorted in-place so that 
 the entire array becomes sorted. If the input array is already sorted, the function 
 should return [-1, -1], else the starting and ending indices of the array.
 
 Input: 1 2 3 4 5 8 6 7 9 10 11            Output: [5, 7]                           */

//-----------------------------------------------------------------------------------//

#include<bits/stdc++.h>
using namespace std;

bool outOfOrder(int i, vector<int> v){
    if(i == 0)
        return v[i] > v[1];
    if(i == v.size()-1)
        return v[i] < v[i-1];
    return (v[i] > v[i+1] || v[i] < v[i-1]);
}

vector<int> sortSubarray(vector<int> v)
{
    int n = v.size();
    
    int smallest = INT_MAX;
    int largest = INT_MIN;
    
    for(int i = 1; i < v.size(); i++){
        if(outOfOrder(i, v)){
            smallest = min(smallest, v[i]);
            largest = max(largest, v[i]);
        }    
    }

    if(smallest == INT_MAX)
        return {-1, -1};
    
    int left = 0;
    while(smallest >= v[left]){
        left++;
    }
    int right = n-1;
    while(largest <= v[right]){
        right--;
    }
    
    return {left, right};

}

int main(){
    int n; 
    cin>>n;
    vector<int> v(n, 0);

    for(int i = 0; i < n; i++){
        cin>>v[i];
    }

    vector<int> res = sortSubarray(v);

    cout<<"["<<res[0]<<", "<<res[1]<<"]";
    
}