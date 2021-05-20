
#include <bits/stdc++.h>

using namespace std;

vector<string> isSafe(vector<vector<int>> max, vector<vector<int>> alloc, vector<vector<int>> need, vector<int> avail, int n, int m, vector<bool> work)
{
    bool ind;
    bool row;
    vector<int> notTrue;
    vector<string> seq;
    bool start = true;
    while (notTrue.size() || start)
    {
        start = false;

        for (int i = 0; i < need.size(); i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (need[i][j] <= avail[j])
                {
                    row = true;
                }
                else
                {
                    row = false;
                    break;
                }
            }
            if (row)
            {
                ind = true;
                work.push_back(ind);
                seq.push_back("p" + to_string(i));
                for (int j = 0; j < m; j++)
                {
                    avail[j] += alloc[i][j];
                }
            }
            else
            {
                ind = false;
                notTrue.push_back(i);
            }
        }

        for (int i = 0; i < notTrue.size(); i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (need[notTrue[i]][j] <= avail[j])
                {

                    row = true;
                }
                else
                {
                    row = false;
                    break;
                }
            }
            if (row)
            {
                ind = true;
                work.push_back(ind);
                seq.push_back("p" + to_string(notTrue[i]));
                notTrue.erase(notTrue.begin() + i);
            }
            else
            {
                ind = false;
                notTrue.push_back(i);
            }
        }
    }
    return seq;
}

int req(vector<vector<int>> &max, vector<vector<int>> &alloc, vector<vector<int>> &need, vector<int> &avail, int n, int m, vector<bool> work, vector<int> p, int num)
{
    bool ind;
    for (int j = 0; j < m; j++)
    {
        if (p[j] <= need[num][j])
        {
            ind = true;
        }
        else
        {
            ind = false;
            return 0;
        }
    }
    for (int j = 0; j < m; j++)
    {
        if (p[j] <= avail[j])
        {
            ind = true;
        }
        else
        {
            ind = false;
            return 0;
        }
    }
    for (int j = 0; j < m; j++)
    {
        avail[j] -= p[j];
    }
    for (int j = 0; j < m; j++)
    {
        alloc[num][j] += p[j];
    }
    for (int j = 0; j < m; j++)
    {
        need[num][j] -= p[j];
    }

    return 1;
}

int main()
{

    int m;
    cout << "enter number of resources" << endl;

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

    vector<vector<int>> maximum;

    cout << "please enter Maximum matrix" << endl;
    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        for (int j = 0; j < m; j++)
        {
            int x;
            cin >> x;

            temp.push_back(x);
        }
        maximum.push_back(temp);
    }

    vector<vector<int>> allocation;
    cout << "please enter Allocation matrix" << endl;
    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        for (int j = 0; j < m; j++)
        {
            int x;
            cin >> x;

            temp.push_back(x);
        }
        allocation.push_back(temp);
    }

    vector<vector<int>> need;
    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        for (int j = 0; j < m; j++)
        {

            temp.push_back(maximum[i][j] - allocation[i][j]);
        }
        need.push_back(temp);
    }

    int choose = 5;
    while (choose != 0)
    {
        cout << "If You need Safety Algorithm input 1" << endl
             << "If you need Recourse - Request Algorithm input 2" << endl
             << "If you need to exit press 0 " << endl;
        cin >> choose;

        if (choose == 1)
        {
            vector<string> seq = isSafe(maximum, allocation, need, available, n, m, work);

            cout << "Yes, Safe state is <";
            for (int i = 0; i < n; i++)
            {
                cout << seq[i] << ",";
            }
            cout << ">" << endl;
        }
        else if (choose == 2)
        {
            int num;
            cout << "please enter the number of process you need " << endl;
            cin >> num;
            cout << "please enter the values of the proccess" << endl;
            vector<int> p;
            for (int i = 0; i < m; i++)
            {
                int temp;
                cin >> temp;
                p.push_back(temp);
            }
            int res;
            res = req(maximum, allocation, need, available, n, m, work, p, num);
            if (res)
            {

                vector<string> seq = isSafe(maximum, allocation, need, available, n, m, work);
                cout << "Yes request can be granted with safe state , Safe state <P" + to_string(num) + "req,";

                for (int i = 0; i < n; i++)
                {
                    if (i == num)
                        continue;
                    cout << seq[i] << ",";
                }
                cout << ">" << endl;
            }
            else
            {
                cout << "No";
            }
        }
        else if (choose != 0)
        {
            cout << "Please enter valid number" << endl;
        }
    }

    return 0;
}