#include<bits/stdc++.h>
using namespace std;

int x[100],f=0;
bool place(int k,int i)
{
    for(int j=0;j<k;j++)
    {
        if(x[j]==i || abs(x[j]-i)==abs(j-k))
        return false;
    }
    return true;
}

void printsol(int n)
{
    cout<<"\nSolution "<<++f<<":"<<endl;
    char a[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        a[i][j]='-';
        a[i][x[i]]='Q';
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        cout<<a[i][j];
        cout<<endl;
    }
}

void nqueen(int k,int n)
{
    for(int i=0;i<n && f<5;i++)
    {
        if(place(k,i))
        {
            x[k]=i;
            if(k==n-1)
            printsol(n);
            else
            nqueen(k+1,n);
        }
    }
}

int main()
{
    int n;
    cout<<"Enter size of grid:";
    cin>>n;
    nqueen(0,n);
    return 0;
}