// C++ program to illustrate Banker's Algorithm
#include <bits/stdc++.h>

using namespace std;

// Function to find the need of each process
void calculateNeed(int n, int m, vector<vector<int>> need, vector<vector<int>> maxm,
                   vector<vector<int>> allot)
{
    // Calculating Need of each n
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)

            // Need of instance = maxm instance -
            //                    allocated instance
            need[i][j] = maxm[i][j] - allot[i][j];
}

// Function to find the system is in safe state or not
bool isSafe(int n, int m, int processes, int avail, vector<vector<int>> maxm,
            int allot)
{
    int need[n][m];

    // Function to calculate need matrix
    calculateNeed(need, maxm, allot);

    // Mark all processes as infinish
    bool finish[n] = {0};

    // To store safe sequence
    int safeSeq[n];

    // Make a copy of available resources
    int work[m];
    for (int i = 0; i < m; i++)
        work[i] = avail[i];

    // While all processes are not finished
    // or system is not in safe state.
    int count = 0;
    while (count < n)
    {
        // Find a process which is not finish and
        // whose needs can be satisfied with current
        // work[] resources.
        bool found = false;
        for (int p = 0; p < n; p++)
        {
            // First check if a process is finished,
            // if no, go for next condition
            if (finish[p] == 0)
            {
                // Check if for all resources of
                // current n need is less
                // than work
                int j;
                for (j = 0; j < m; j++)
                    if (need[p][j] > work[j])
                        break;

                // If all needs of p were satisfied.
                if (j == m)
                {
                    // Add the allocated resources of
                    // current n to the available/work
                    // resources i.e.free the resources
                    for (int k = 0; k < m; k++)
                        work[k] += allot[p][k];

                    // Add this process to safe sequence.
                    safeSeq[count++] = p;

                    // Mark this p as finished
                    finish[p] = 1;

                    found = true;
                }
            }
        }

        // If we could not find a next process in safe
        // sequence.
        if (found == false)
        {
            cout << "System is not in safe state";
            return false;
        }
    }

    // If system is in safe state then
    // safe sequence will be as below
    cout << "System is in safe state.\nSafe"
            " sequence is: ";
    for (int i = 0; i < n; i++)
        cout << safeSeq[i] << " ";

    return true;
}

// Driver code
int main()
{
    int processes[] = {0, 1, 2, 3, 4};
    int m;
    cout << "enter number of resources";
    cin >> m;

    int n;
    cout << "enter number of resources";
    cin >> n;

    // Available instances of resources
    vector<int> avail;
    cout << "please enter available vector";
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        avail.push_back(x);
    }

    // Maximum m that can be allocated
    // to processes
    vector<vector<int>> maxm;

    cout << "please enter Maximum matrix";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int x;
            cin >> x;
            avail.push_back(x);
        }

        // Resources allocated to processes
        int allot[][m] = {{0, 1, 0},
                          {2, 0, 0},
                          {3, 0, 2},
                          {2, 1, 1},
                          {0, 0, 2}};

        // Check system is in safe state or not
        isSafe(n, m, processes, avail, maxm, allot);

        return 0;
    }