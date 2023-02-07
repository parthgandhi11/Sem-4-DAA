#include <bits/stdc++.h>
#include <chrono>
#include <fstream>

using namespace std;


int main(){
    int n=100000;
    int arr[n];

    ofstream outdata;
    outdata.open("ArrValues.txt");
    
    //random values filling
    for(int i=0;i<n;i++)
    {
        arr[i] = rand() % n;
        outdata<<arr[i]<<", ";
        // cout<<arr[i]<<", ";
    }
    int copyarr[n];
    copy(arr,arr+n,copyarr);

    printf("\tInsertion Sort\tSelection Sort");
    for(int i=100;i<=n;i+=100)
    {   
        //Insertion Sort
        auto start = chrono::high_resolution_clock::now();
        for(int j=1;j<i;j++)
        {
            int k=j;
            while(k>0 && arr[k-1]>arr[k])
            {
                int temp = arr[k-1];
                arr[k-1] = arr[k];
                arr[k] = temp;
                k--;
            }
        }
        auto end = chrono::high_resolution_clock::now();
        cout<<"\n"<<i/100<<","<<chrono::duration_cast<chrono::nanoseconds>(end - start).count()<<",";

        //Selection Sort
        start = chrono::high_resolution_clock::now();
        for(int j=0;j<i-2;j++)
        {
            //finding the smallest element
            int min = j+1;
            for(int k=j+2;k<i;k++)
            {
                min=copyarr[min]>copyarr[k]?k:min;
            }
            int temp = copyarr[j];
            copyarr[j] = copyarr[min];
            copyarr[min] = temp;
        }
        end = chrono::high_resolution_clock::now();
        cout<<chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    }    

}