
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int processes[] = {0, 1, 2, 3, 4};
    int m;
    cout << "enter number of resources";
    cin >> m;

    int n;
    cout << "enter number of resources";
    cin >> n;

    vector<int> available;
    cout << "please enter available vector";
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        available.push_back(x);
    }

    vector<vector<int>> maximum;

    cout << "please enter Maximum matrix";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int x;
            cin >> x;
            maximum[i][j] = x;
        }
    }

    vector<vector<int>> allocation;
    cout << "please enter Maximum matrix";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int x;
            cin >> x;
            allocation[i][j] = x;
        }
    }

    return 0;
}