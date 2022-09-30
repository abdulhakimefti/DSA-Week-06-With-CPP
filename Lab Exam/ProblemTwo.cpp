#include<bits/stdc++.h>
using namespace std;

int main(){
    int a;
    cin>>a;
    int A[a];
    for(int i=0;i<a;i++){
        cin>>A[i];
    }
    int b;
    cin>>b;
    int B[a];
    for(int i=0;i<b;i++){
        cin>>B[i];
    }

    for(int i=0;i<b;i++){
        for(int j=0;j<a;j++){
            if(B[i]==A[j]){
                A[j]=-1;
            }
        }
    }
    for(int i=0;i<a;i++){
        if(A[i]!=-1){
            cout<<A[i]<<" ";        }
    }
    cout<<endl;
    return 0;
}
