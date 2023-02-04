#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void FailureFunction(string P, int F[])
    {
        int m = P.length();
        for (int i = 0; i < m; i++)
            F[i] = 0;
        int i = 1;
        int j = 0;
        while (i < m)
        {
            if (P[i] == P[j])
            { // we have matched j+1 chars
                F[i] = j + 1;
                i++, j++;
            }
            else if (j > 0) // use failure function to shift P
                j = F[j - 1];
            else
            {
                F[i] = 0; // no match
                i++;
            }
        }
    }
    int findLastOccurence(string T, string P)
    {
        int ans = -1;
        int F[1000005];
        int m = P.length();
        int n = T.length();
        FailureFunction(P, F);
        int i = 0;
        int j = 0;

        while (i < n)
        {
            // if (T[i] == P[j])
            // {
            //     i++;
            //     j++;
            // }
            // if (j == m)
            // {
            //     ans = i - j + 1;
            //     j = F[j - 1];
            // }
            // else
            // {
            //     if (P[j] != T[i])
            //     {
            //         if (j > 0)
            //             j = F[j - 1];
            //         else
            //             i++;
            //     }
            // }
            if(T[i] == P[j]){
                if(j == m-1){
                    ans = i-j+1;
                    j = F[j-1];
                }
                else{
                    i++, j++;
                }
            }
            else{
                if(j>0)
                    j = F[j-1];
                else
                    i++;
            }
        }
        // while ((n - i) >= (m - j))
        // {
        //     if (P[j] == T[i])
        //     {
        //         j++;
        //         i++;
        //     }

        //     if (j == m)
        //     {
        //         ans = i - j + 1;
        //         j = F[j - 1];
        //     }

        //     // mismatch after j matches
        //     else if (i < n && P[j] != T[i])
        //     {
        //         // Do not match lps[0..lps[j-1]] characters,
        //         // they will match anyway
        //         if (j != 0)
        //             j = F[j - 1];
        //         else
        //             i = i + 1;
        //     }
        // }
        return ans;
    }
};

int main()
{
    string A, B;
    cin >> A >> B;
    Solution ob;
    cout << ob.findLastOccurence(A, B) << "\n";
    return 0;
}