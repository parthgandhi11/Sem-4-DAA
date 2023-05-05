#include <bits/stdc++.h>

using namespace std;

int minDistance(int dist[], bool sptSet[], int n)
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < n; v++)
    {
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
    }
    return min_index;
}

int main()
{
    int n;
    cout << "Enter number of nodes:";
    cin >> n;
    int graph[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;
    }
    int ch = 1;
    while (ch == 1)
    {
        char a, b;
        int weight;
        cout << "Enter node 1:";
        cin >> a;
        cout << "Enter node 2:";
        cin >> b;
        cout << "Enter weight of connection:";
        cin >> weight;
        graph[int(a) - 97][int(b) - 97] = weight;
        graph[int(b) - 97][int(a) - 97] = weight;
        cout << "Enter more connections?(Y=1):";
        cin >> ch;
    }
    char source;
    cout << "Enter the source vertex: ";
    cin >> source;
    int src = int(source) - 97;

    int dist[n];
    bool sptSet[n];
    for (int i = 0; i < n; i++)
    {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    dist[src] = 0;

    for (int count = 0; count < n - 1; count++)
    {
        int u = minDistance(dist, sptSet, n);

        sptSet[u] = true;

        for (int v = 0; v < n; v++)
        {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
        }
    }

    cout << "\nVertex\tDistance from Source" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << char(97 + i) << "\t" << dist[i] << endl;
    }

    return 0;
}