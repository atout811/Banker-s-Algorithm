
#include <bits/stdc++.h>

using namespace std;

int isSafe(vector<vector<int>> max, vector<vector<int>> alloc, vector<vector<int>> need, vector<int> avail, int n, int m, vector<bool> work)
{
    bool ind;
    vector<int> notTrue;
    vector<string> seq;
    bool start = true;
    while (notTrue.size() || start)
    {
        start = false;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (need[i][j] <= avail[j])
                {
                    ind = true;
                    work[i] = ind;
                    seq.push_back("p" + to_string(i));
                    continue;
                }
                else
                {
                    ind = false;
                    notTrue.push_back(i);
                    break;
                }
            }
        }

        for (int i = 0; i < notTrue.size(); i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (need[notTrue[i]][j] <= avail[j])
                {
                    notTrue.erase(i);
                    ind = true;
                    work[i] = ind;
                    seq.push_back("p" + to_string(i));
                    continue;
                }
                else
                {
                    ind = false;
                    notTrue.push_back(i);
                    break;
                }
            }
        }
    }
    return seq;
}

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
    vector<bool> work;
    cout << "please enter available vector";
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        available.push_back(x);
        work[i] = false;
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

    vector<vector<int>> need;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            need[i][j] = maximum[i][j] - allocation[i][j];
        }
    }

    vector<string> seq = isSafe(maximum, allocation, need, available, n, m, work);
    for (int i = 0; i < n; i++)
    {
        cout << seq[i] << " ";
    }

    return 0;
}