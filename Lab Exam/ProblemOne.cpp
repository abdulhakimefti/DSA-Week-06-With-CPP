#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    int fq[max+1];
    for (int i = 0; i < max+1; i++)
    {
        fq[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {

        if (arr[i] != -1)
        {
        
            for (int j = 0; j < n; j++)
            {
                if (arr[i] == arr[j])
                {
                    fq[arr[i]]++;
                  if(i!=j){
                      arr[j]=-1;
                  }
                }
            }
        }
    }
    for(int i=0;i<max+1;i++){
        if(fq[i]!=0){
            cout<<i<< " => " <<fq[i]<<endl;
        }
    }
    return 0;
}