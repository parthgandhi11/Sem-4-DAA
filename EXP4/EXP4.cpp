#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a, b;
    cout << "Enter String 1: ";
    cin >> a;
    cout << "Enter String 2: ";
    cin >> b;
    vector<vector<int>> mat(a.size() + 1, vector<int>(b.size() + 1, 0));
    for (int i = 1; i < a.size() + 1; i++)
    {
        for (int j = 1; j < b.size() + 1; j++)
        {
            if (a[i - 1] == b[j - 1])
            mat[i][j] = mat[i - 1][j - 1] + 1;
            else
            mat[i][j] = max(mat[i - 1][j], mat[i][j - 1]);
        }
    }
    for(int i=0;i<a.size() + 1;i++)
    {
        for(int j=0;j<b.size() + 1;j++)
        cout<<mat[i][j]<<" ";
        cout<<endl;
    }

    string lcs = "";
    int i = a.size();
    int j = b.size();
    while (i != 0 && j != 0)
    {
        if (a[i - 1] == b[j - 1])
        {
            lcs += b[j - 1];
            i -= 1;
            j -= 1;
        }
        else
        {
            if (mat[i][j] == mat[i - 1][j])
            i -= 1;
            else
            j -= 1;
        }
    }
    cout << "LCS is: " << lcs << endl;
    return 0;
}