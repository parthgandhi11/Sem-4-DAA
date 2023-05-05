#include<bits/stdc++.h>
#include<chrono>
#include<fstream>
using namespace std;

void merge(int a[],int beg,int mid,int end)
{
    int l1=mid-beg+1;
    int l2=end-mid;
    int left[l1],right[l2];
    for(int i=0;i<l1;i++)
    left[i]=a[beg+i];
    for(int i=0;i<l2;i++)
    right[i]=a[mid+1+i];
    int leftind=0,rightind=0,ind=beg;
    while(leftind<l1 && rightind<l2)
    {
        if(left[leftind]<=right[rightind])
        a[ind]=left[leftind++];
        else
        a[ind]=right[rightind++];
        ind++;
    }
    while(leftind<l1)
    {
        a[ind]=left[leftind++];
        ind++;
    }
    while(rightind<l2)
    {
        a[ind]=right[rightind++];
        ind++;
    }
}

void mergesort(int a[],int beg,int end)
{
    if(beg<end)
    {
        int mid=(beg+end)/2;
        mergesort(a,beg,mid);
        mergesort(a,mid+1,end);
        merge(a,beg,mid,end);
    }
}

void quick(int b[],int beg,int end)
{
    if(beg>end)
    return;
    int pivot=beg,low=beg+1,high=end;
    while(pivot!=high)
    {
        if(b[low]<=b[pivot])
        low++;
        else
        {
            if(b[high]>b[pivot])
            high--;
            else
            {
                if(low<high)
                swap(b[low],b[high]);
                else
                {
                    swap(b[pivot],b[high]);
                    break;
                }
            }
        }
    }
    quick(b,beg,high-1);
    quick(b,high+1,end);
}

int main()
{
    cout<<"n\tMergeSort\tQuickSort";
    for(int n=100;n<=100000;n+=100)
    {
        int a[n],b[n];
        for(int i=0;i<n;i++)
        a[i]=rand()%n;
        copy(a,a+n,b);

        //Merge Sort
        auto start = chrono::high_resolution_clock::now();
        mergesort(a,0,n-1);
        auto end = chrono::high_resolution_clock::now();
        cout<<"\n"<<n<<"\t"<<chrono::duration_cast<chrono::microseconds>(end - start).count()<<"\t";

        //Quick Sort
        start = chrono::high_resolution_clock::now();
        quick(b,0,n-1);
        end = chrono::high_resolution_clock::now();
        cout<<chrono::duration_cast<chrono::microseconds>(end - start).count();
    }
    return 0;
}