#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a,b;
    cin>>a>>b;
    int n=a.size()+1;
    int m=b.size()+1;
    int mat[n][m]={0};
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            if(a[i-1]==b[j-1])
            mat[i][j]=mat[i-1][j-1]+1;
            else
            mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        cout<<mat[i][j]<<" ";
        cout<<endl;
    }
    
    string lcs="";
    n--;m--;
    while(n!=0 && m!=0)
    {
        if(a[n-1]==b[m-1])
        {
            lcs=b[m-1]+lcs;
            n--;m--;
        }
        else
        {
            if(mat[n][m]==mat[n-1][m])
            n--;
            else
            m--;
        }
    }
    cout<<lcs;
    return 0;
}