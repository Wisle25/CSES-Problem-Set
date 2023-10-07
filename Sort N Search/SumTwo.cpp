#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin .tie(0);
    cout.tie(0);

    bool HasSolution = false;
    int32_t N;
    int64_t X;
    cin >> N >> X;

    vector<pair<int64_t, int32_t>> Nums(N);

    for (int32_t I = 0; I < N; ++I)
    {
        int64_t Value;

        cin >> Value;
        Nums[I] = { Value, I };
    }

    int32_t Left  = 0;
    int32_t Right = N - 1;

    sort(Nums.begin(), Nums.end());

    while (Left < Right)
    {
        int64_t Value = Nums[Left].first + Nums[Right].first;

        if (Value == X)
        {
            HasSolution = true;

            cout << Nums[Left].second + 1 << " " << Nums[Right].second + 1 << " ";

            ++Left;
            --Right;
        }
        else if (Value < X) ++Left;
        else                --Right;
    }

    if (!HasSolution) cout << "IMPOSSIBLE" << '\n';

    return 0;
}