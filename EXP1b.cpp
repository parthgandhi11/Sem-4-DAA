#include<bits/stdc++.h>
#include <chrono>
#include <fstream>
using namespace std;

int main()
{
    cout<<"n\tInsertion sort\tSelection sort";
    for(int n=91600;n<=100000;n+=100)
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
            {
                t=a[i];
                a[i]=a[i-1];
                a[i-1]=t;
            }
            for(int j=i-1;j>0;j--)
            {
                if(a[j]<a[j-1])
                {
                    t=a[j];
                    a[j]=a[j-1];
                    a[j-1]=t;
                }
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