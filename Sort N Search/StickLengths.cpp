#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin .tie(0);
    cout.tie(0);

    int32_t N;
    cin >> N;

    vector<int64_t> Sticks(N);

    for (int32_t I = 0; I < N; ++I)
        cin >> Sticks[I];

    sort(Sticks.begin(), Sticks.end());

    bool IsEven = N % 2 == 0;
    int32_t Mid = IsEven ? N / 2 : (N + 1) / 2;
    int64_t Total = 0;

    for (int32_t I = 0; I < N; ++I)
    {
        if (!IsEven && I == Mid - 1) continue;

        int64_t Diff = abs(Sticks[I] - Sticks[Mid]);
        Total += Diff;
    }

    cout << Total << '\n';

    return 0;
}
