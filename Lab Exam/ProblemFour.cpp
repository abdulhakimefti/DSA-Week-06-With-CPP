#include<bits/stdc++.h>
using namespace std;

int main(){
    int m,n;
    cin>>m>>n;
    int mat[m][n];

    for(int i=0;i<m;i++){
        for(int j =0;j<n;j++){
            cin>>mat[i][j];
        }
    }
      for(int i=0;i<m;i++){
        for(int j =0;j<n;j++){
          for(int k=0;k<m;k++){
               for(int l=0;l<n;l++){
                    if(mat[i][j]==mat[k][l]&&(i!=k||j!=l)){
                        mat[k][l]=-1;
                    }
               } 
          }
        }
    }
      for(int i=0;i<m;i++){
        for(int j =0;j<n;j++){
         cout<<mat[i][j]<<  " ";
        }
        cout<<endl;
    }
    return 0;
}