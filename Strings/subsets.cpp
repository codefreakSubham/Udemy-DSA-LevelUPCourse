//---------------------------------Problem Statement--------------------------------------//

 /* Given two non empty strings, determine whether the second string is a subsequence of 
    the first string.
    Input: codingminutes        Output: Yes
           cines                                                                        */

//---------------------------------------------------------------------------------------//

#include<bits/stdc++.h>
using namespace std;

bool isSubset(string s1, string s2){
    int i = s1.length()-1;
    int j = s2.length()-1;
    while(i >= 0 && j >=0){
        if(s1[i] == s2[j]){
            i--; j--;
        }
        else{
            i--;
        }
    }

    return(j == -1);
}

int main()
{
    string s1, s2;
    cin>>s1>>s2;

    if(isSubset(s1, s2))
        cout<<"Yes";
    else
        cout<<"No";
    
}
