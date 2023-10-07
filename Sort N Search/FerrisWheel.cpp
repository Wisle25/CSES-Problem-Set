#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin .tie(0);
    cout.tie(0);

    int32_t N, Total = 0;
    int64_t X;
    cin >> N >> X;

    vector<pair<int64_t, bool>> Weights(N);

    for (int32_t I = 0; I < N; ++I)
    {
        cin >> Weights[I].first;
        Weights[I].second = false;
    }

    int32_t Left  = 0;
    int32_t Right = N - 1;

    sort(Weights.begin(), Weights.end());

    while (Left < Right)
    {
        int64_t Weight = Weights[Left].first + Weights[Right].first;

        if (Weight <= X)
        {
            Weights[Left] .second = true;
            Weights[Right].second = true;

            ++Total;
            ++Left;
            --Right;
        }
        else
            --Right;
    }

    for (int32_t I = 0; I < N; ++I)
        if (!Weights[I].second)
            ++Total;

    cout << Total << '\n';

    return 0;
}