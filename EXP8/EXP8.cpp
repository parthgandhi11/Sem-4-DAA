#include <bits/stdc++.h>
using namespace std;

int f = 0, moves = 0;
void printsol(int a[4][4])
{
    cout << "\nGoal state reached. Moves taken: " << moves << endl;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
    f = 1;
}

int calculatecost(int a[4][4], int goal[4][4])
{
    int cost = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (a[i][j] != goal[i][j])
                cost++;
        }
    }
    return cost;
}

void solve(int a[4][4], int goal[4][4], int direction, int x, int y)
{
    moves++;
    if (f == 0)
    {
        int left, right, top, bottom;
        vector<vector<int>> cost(4, vector<int>(4, INT_MAX));
        if (direction != 3 && x - 1 >= 0)
        {
            int b[4][4];
            copy(&a[0][0], &a[0][0] + 16, &b[0][0]);
            swap(b[x][y], b[x - 1][y]);
            cost[0][0] = calculatecost(b, goal);
            cost[0][1] = 1;
            cost[0][2] = x - 1;
            cost[0][3] = y;
        }
        if (direction != 4 && y + 1 < 4)
        {
            int b[4][4];
            copy(&a[0][0], &a[0][0] + 16, &b[0][0]);
            swap(b[x][y], b[x][y + 1]);
            cost[1][0] = calculatecost(b, goal);
            cost[1][1] = 2;
            cost[1][2] = x;
            cost[1][3] = y + 1;
        }
        if (direction != 1 && x + 1 < 4)
        {
            int b[4][4];
            copy(&a[0][0], &a[0][0] + 16, &b[0][0]);
            swap(b[x][y], b[x + 1][y]);
            cost[2][0] = calculatecost(b, goal);
            cost[2][1] = 3;
            cost[2][2] = x + 1;
            cost[2][3] = y;
        }
        if (direction != 2 && y - 1 >= 0)
        {
            int b[4][4];
            copy(&a[0][0], &a[0][0] + 16, &b[0][0]);
            swap(b[x][y], b[x][y - 1]);
            cost[3][0] = calculatecost(b, goal);
            cost[3][1] = 4;
            cost[3][2] = x;
            cost[3][3] = y - 1;
        }
        sort(cost.begin(), cost.end());
        direction = cost[0][1];
        if (direction == 1)
            swap(a[x][y], a[x - 1][y]);
        if (direction == 2)
            swap(a[x][y], a[x][y + 1]);
        if (direction == 3)
            swap(a[x][y], a[x + 1][y]);
        if (direction == 4)
            swap(a[x][y], a[x][y - 1]);
        if (cost[0][0]==0)
            printsol(a);
        solve(a, goal, direction, cost[0][2], cost[0][3]);
    }
}

int main()
{
    int a[4][4];
    int goal[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, -1}};
    cout << "Enter the puzzle:" << endl;
    int x, y;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == -1)
            {
                x = i;
                y = j;
            }
        }
    }
    int flag = calculatecost(a, goal);
    if (flag == 0)
        cout<<"Enterred puzzle is already in goal state";
    else
        solve(a, goal, 0, x, y);
    return 0;
}