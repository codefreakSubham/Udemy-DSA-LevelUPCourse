//---------------------------------Problem Statement--------------------------------------//

 /* Given an string, write a function to replace all the spaces in the string with '%20'.
    The string has sufficient space at the end to hold the additional charecters.
    Input: hello world, how are you?     Output: hello%20world,%20how%20are%20you?                                                  */

//---------------------------------------------------------------------------------------//

#include<bits/stdc++.h>
using namespace std;

string replace(char *arr)
{

    int spaces = 0;
    for(int i = 0; i < strlen(arr); i++){
        if(arr[i] == ' ')
            spaces++;
    }

    int idx = strlen(arr) + 2*spaces;
    arr[idx] = '\0';
    idx--;

    for(int i = strlen(arr) -1; i >= 0; i--){
        if(arr[i] == ' '){
            arr[idx--] = '0';
            arr[idx--] = '2';
            arr[idx--] = '%';
        }
        else{
            arr[idx] = arr[i];
            idx--;
        }
    }
}

int main()
{
    char arr[1000];
    cin.getline(arr, 1000);
    replace(arr);
    cout<<arr;
}