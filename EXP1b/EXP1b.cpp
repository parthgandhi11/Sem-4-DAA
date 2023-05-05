#include<bits/stdc++.h>
#include <chrono>
#include <fstream>
using namespace std;

int main()
{
    cout<<"n\tInsertion sort\tSelection sort";
    ofstream outdata;
    outdata.open("ArrValues.txt");
    outdata<<"dfgndfgn";
    for(int n=100;n<=100;n+=100)
    {
        int a[n],b[n];
        for(int i=0;i<n;i++)
        a[i]=rand()%n;
        copy(a,a+n,b);

        //Insertion sort
        auto start = chrono::high_resolution_clock::now();
        for(int i=1;i<n;i++)
        {
            int t;
            if(a[i]<a[i-1])
            swap(a[i],a[i-1]);
            for(int j=i-1;j>0;j--)
            {
                if(a[j]<a[j-1])
                swap(a[j],a[j-1]);
                else
                break;
            }
        }
        auto end = chrono::high_resolution_clock::now();
        cout<<"\n"<<n<<"\t"<<chrono::duration_cast<chrono::nanoseconds>(end - start).count()<<"\t";

        //Selection sort
        start = chrono::high_resolution_clock::now();
        for(int i=0;i<n;i++)
        {
            int min=b[i],ind=i;
            for(int j=i+1;j<n;j++)
            {
                if(min>b[j])
                {
                    min=b[j];
                    ind=j;
                }
            }
            if(ind!=i)
            {
                b[ind]=b[i];
                b[i]=min;
            }
        }
        end = chrono::high_resolution_clock::now();
        cout<<chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    }
}