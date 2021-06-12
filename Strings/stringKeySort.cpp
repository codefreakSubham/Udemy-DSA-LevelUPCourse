//---------------------------------Problem Statement--------------------------------------//

 /*Sample Input
    3          - No. of strings(consists of space seperated numbers)
    92 022
    82 12
    77 13
    2 false numeric    - sort based on 2nd col, reverse answer or not, numeric comparisn or
                         lexographical comparisn
    
    Sample Output
    82 12
    77 13
    92 022                                                                               */

//---------------------------------------------------------------------------------------//

#include<bits/stdc++.h>
using namespace std;

string extractStringAtKey(string str, int key){

    char *s = strtok((char*)str.c_str(), " ");

    while(key > 1){
        s = strtok(NULL, " ");
        key--;
    }

    return string(s);

}

bool numericCompare(pair<string, string> s1, pair<string, string> s2){
    string key1 = s1.second;
    string key2 = s2.second;

    return stoi(key1) < stoi(key2);
}

bool lexicoCompare(pair<string, string> s1, pair<string, string> s2){
    string key1 = s1.second;
    string key2 = s2.second;

    return key1 < key2;
}

int main()
{
    int n;
    cin>>n;
    cin.get(); //consume the extra \n

    string s;
    vector<string> v;

    for(int i = 0; i < n; i++){
        getline(cin, s);
        v.push_back(s);
    }
    int key;
    string reversal, ordering;

    cin>>key>>reversal>>ordering;


    //to extract keys for comparisn and store them
    vector<pair<string, string>> vp;

    for(int i = 0; i < n; i++){
        vp.push_back({v[i], extractStringAtKey(v[i], key)});
    }

    //sorting
    if(ordering == "numeric"){
        sort(vp.begin(), vp.end(), numericCompare);
    }
    else{
        sort(vp.begin(), vp.end(), lexicoCompare);
    }

    //reversal
    if(reversal == "true"){
        reverse(vp.begin(), vp.end());
    }

    //Output

    for(int i = 0; i < n; i++){
        cout<<vp[i].first<<endl;
    }
}