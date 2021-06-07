//------------------------------Problem Statement------------------------------------//

 /* Given an array, find the minimum number of swaps required to get the array sorted
    Input: 2 4 5 1 3       Output: 3                                                */

//-----------------------------------------------------------------------------------//

#include<bits/stdc++.h>
using namespace std;

int minSwaps(vector<int> v)
{
    int n = v.size();

    pair<int, int> ap[n];

    for(int i = 0; i < n; i++){
        ap[i].first = v[i];
        ap[i].second = i;
    }

    int vis[n] = {0};

    sort(ap, ap+n);                         //Sort to compare indices with original array

    int ans = 0;
    for(int i = 0; i < n; i++){
        if(vis[i] || ap[i].second == i)     // If already checked or value is in correct position
            continue;

        int cycle = 0;
        int node = i;
        while(!vis[node]){                  //calculate elements in each cycle and add to answer
                                            //Add (cycle-1) to answer.
            vis[node] = 1;
            cycle+=1;
            node = ap[node].second;
        }
        ans += (cycle-1);
    }
    return ans;
}


int main()
{
    int n;
    cin>>n;
    vector<int> v(n, 0);

    for(int i = 0; i < n; i++){
        cin>>v[i];
    }

    cout<<minSwaps(v);
}