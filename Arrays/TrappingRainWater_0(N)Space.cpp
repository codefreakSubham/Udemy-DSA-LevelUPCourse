//------------------------------Problem Statement------------------------------------//

 /* Given n non-negative integers representing an elevation map where the width of each 
    bar is 1, compute how much water it can trap after raining. 
    Eg: For the array : 0 1 0 2 1 0 1 3 2 1 2 1,  output: 6                         */

//-----------------------------------------------------------------------------------//

#include<bits/stdc++.h>
using namespace std;

int waterTrapped(vector<int> height)
{
    int n = height.size();
    vector<int> leftMax(n, 0);
    vector<int> rightMax(n, 0);

    leftMax[0] = height[0];
    rightMax[n-1] = height[n-1];

    for(int i = 1; i < n; i++){                        // finding the left maximum of each tower
 
        leftMax[i] = max(leftMax[i-1], height[i]);
    }

    for(int i = n-2; i >= 0; i--){                    //finding the right maximum of each tower
  
        rightMax[i] = max(rightMax[i+1], height[i]);
    }
    
    int trapped = 0;                                  
    
    for(int i = 0; i < n; i++){
        trapped += min(leftMax[i], rightMax[i]) - height[i]; 
    }
    
    return trapped;
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
