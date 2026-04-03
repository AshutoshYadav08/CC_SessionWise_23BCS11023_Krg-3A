#include<iostream>
#include<string>
using namespace std;  

const int base = 10;

int hashfunc(string s){
    int h = 0;
    for(int i = 0;i<s.size();i++){
        h = h * base + (s[i] - 'a' + 1);
    }
    return h;
}

int main(){


    string pattern = "cba";
    string s = "abcabcbadbbcba";


    int m = pattern.size();
    int n = s.size();

    int textHash = hashfunc(s.substr(0,m));
    int patternHash = hashfunc(pattern);
    int power = 1;







    for(int i = 0;i<m-1;i++){
        power = power * base;
    }

    for(int i = 0;i<=n-m;i++){
        if(textHash == patternHash){
            cout<<"string found at index "<<i<<endl;
        }
        if(i<n-m){
            textHash -= (s[i] - 'a' + 1) * power;
            textHash = textHash * base + (s[i+m] - 'a' + 1);
        }
    
    }



}