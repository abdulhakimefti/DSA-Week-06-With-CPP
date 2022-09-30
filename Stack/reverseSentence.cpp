#include<bits/stdc++.h>
#include"MYSTACK.h"
using namespace std;

void reverseSentence(string s){
    Stack<string> st;
    for(int i=0;i<s.size();i++){
            string word= "";
            while(i<s.size()&&s[i]!=' '){
                word+=s[i];
                i++;
            }
        st.push(word);
    }
    while(!st.empty()){
        cout<<st.pop()<<  " ";
    }
    cout<<endl;
}

int main(){
    string s = "I am Efti";
    reverseSentence(s);
    return 0;
}