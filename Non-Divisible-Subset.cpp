#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'nonDivisibleSubset' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. INTEGER_ARRAY s
 */

int nonDivisibleSubset(int k, vector<int> s)
{
    int result = 0;
    std::map<int, int> mp;

    for (const auto &n : s)
    {
        mp[n % k]++;
    }

    for (int i = 0; i < (k - 1) / 2; i++)
    {
        result += std::max(mp[i + 1], mp[k - 1 - i]);
    }

    result += (mp[0] > 0) + (k % 2 == 0 && mp[k / 2] > 0);

    return result;
}

int nonDivisibleSubset1(int k, vector<int> s)
{
    int result = 0;
    int div = 0;
    std::map<int, int> mp;

    for (const auto& n : s)
    {
        mp[n % k]++;
    }

    if (k % 2)
    {
        div = k / 2;
    }
    else
    {
        div = k / 2 - 1;
    }

    result = (mp[0] ? 1 : 0);

    for (int i = 1; i <= div; ++i)
    {
        result += std::max(mp[i], mp[k - i]);
    }

    if (!(k % 2) && mp[k / 2])
    {
        result++;
    }

    return result;
}
