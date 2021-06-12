//---------------------------------Problem Statement--------------------------------------//

 /* You are given a string, you have to print all the possible subsequences of the string,
    sorted by length and lexicographic sorted order if length is same
    Input: abcd    Output: a, b, c, d, ab, ac, ad, bc, bd, cd, abc, abd, acd, bcd, abcd  */

//---------------------------------------------------------------------------------------//

#include<bits/stdc++.h>
using namespace std;

void subsequences(string input, string output, vector<string> &v){

    if(input.size() == 0){
        v.push_back(output);
        return;
    }

    char ch = input[0];
    string reduced_input = input.substr(1);

    //includes
    subsequences(reduced_input, output + ch, v);

    //excludes
    subsequences(reduced_input, output, v);

}

bool comp(string s1, string s2){
    if(s1.length() == s2.length())
        return s1 < s2;
    return s1.length() < s2.length();
}

int main()
{
    string s;
    cin>>s;
    vector<string>v;

    subsequences(s, "", v);
    sort(v.begin(), v.end(), comp);

    for(string x: v){
        cout<<x<<endl;
    }

}