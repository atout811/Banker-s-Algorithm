
#include <bits/stdc++.h>

using namespace std;

vector<string> isSafe(vector<vector<int>> max, vector<vector<int>> alloc, vector<vector<int>> need, vector<int> avail, int n, int m, vector<bool> work)
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

                    notTrue.erase(notTrue.begin() + i);
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
    cout << "enter number of resources" << endl;
    ;
    cin >> m;

    int n;
    cout << "enter number of process" << endl;
    cin >> n;

    vector<int> available;
    vector<bool> work;
    cout << "please enter available vector" << endl;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        available.push_back(x);
        work.push_back(false);
    }

    vector<vector<int>> maximum(m);

    cout << "please enter Maximum matrix" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int x;
            cin >> x;
            maximum[i].push_back(x);
        }
    }

    vector<vector<int>> allocation(m);
    cout << "please enter Allocation matrix" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int x;
            cin >> x;
            allocation[i].push_back(x);
        }
    }

    vector<vector<int>> need(m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            need[i][j] = maximum[i][j] - allocation[i][j];
        }
    }

    vector<string> seq = isSafe(maximum, allocation, need, available, n, m, work);

    cout << "Yes, Safe state is <";
    for (int i = 0; i < n; i++)
    {
        cout << seq[i] << ",";
    }
    cout << ">" << endl;

    return 0;
}