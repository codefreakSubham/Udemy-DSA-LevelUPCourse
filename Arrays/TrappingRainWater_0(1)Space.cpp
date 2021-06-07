//------------------------------Problem Approach------------------------------------//

 /* Instead of taking two arrays, we will maintain two variables maxLeft and maxRight.
    Input: 0 1 0 2 1 0 1 3 2 1 2 1   Output: 6                                     */

//-----------------------------------------------------------------------------------//


#include<bits/stdc++.h>
using namespace std;

int waterTrapped(vector<int> height)
{
    int n = height.size();
    
    int left = 1;
    int right = n-2;
    int maxRight = height[n-1];
    int maxLeft = height[0];
    
    int water = 0;
    
    while(left <= right){
        if(maxLeft < maxRight){
            if(height[left] > maxLeft){
                maxLeft = height[left];
            }
            else{
                water += maxLeft-height[left];           
            }
            left++;
        }
        else{
            if(height[right] > maxRight){
                maxRight = height[right];
            }
            else{
                water += maxRight - height[right];
            }
            right--;
        }
    }
    
    return water;
}    

int main()
{
    int n;
    cin>>n;
    vector<int> height(n, 0);

    for(int i = 0; i < n; i++){
        cin>>height[i];
    }
    cout<<waterTrapped(height);
}

