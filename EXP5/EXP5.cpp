#include<bits/stdc++.h>
using namespace std;

int main()
{
    double n,w;
    cout<<"Enter weight of bag:";
    cin>>w;
    cout<<"Enter number of items:";
    cin>>n;
    double m=3;
    vector<vector<double>> a;
    for(int i=0;i<n;i++)
    {
        double x,y,z;
        cout<<"\nEnter weight of item "<<i+1<<":";
        cin>>x;
        cout<<"Enter value of item "<<i+1<<":";
        cin>>y; 
        z=y/x;
        a.push_back({z,x,y,double(i+1)});
    }
    sort(a.begin(),a.end(),greater <>());
    double max_profit=0;
    for(int i=0;i<n;i++)
    {
        if(a[i][1]<=w)
        {
            w-=a[i][1];
            max_profit+=a[i][2];
        }
        else
        {
            max_profit+=a[i][0]*w;
            break;
        }
    }
    cout<<"Max profit is: "<<max_profit;
    return 0;
}