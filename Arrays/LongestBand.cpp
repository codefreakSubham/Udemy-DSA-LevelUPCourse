//------------------------------Problem Statement------------------------------------//

 /* Given an array, find the length of longest band of consequetive numbers.
Eg: in array: 1 9 3 0 18 5 2 4 10 7 12 6
the longest band is 0-1-2-3-4-5-6-7 . So output is 8 (length of the band) */

//-----------------------------------------------------------------------------------//

#include<bits/stdc++.h>
using namespace std;

unordered_set<int> s;
int longestBand()
{
    int ans = 0;
    for(int x: s){
        int curr = 0;
        if(s.find(x-1) != s.end())              //if the element can be leader
            continue;
        else{
            while(s.find(x + 1) != s.end()){   //count chain
                curr++;
                x++;
            }
        }
        ans = max(ans, curr+1);                //calculate longest chain
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;

    for(int i = 0; i < n; i++){
        int a;
        cin>>a;
        s.insert(a);
    }
    cout<<longestBand();
}