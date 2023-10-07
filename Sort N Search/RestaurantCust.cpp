#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin .tie(0);
    cout.tie(0);

    int32_t N, Total = 0, Anytime = 0;
    cin >> N;

    vector<pair<int64_t, int64_t>> Custs;

    for (int32_t I = 0; I < N; ++I)
    {
        int64_t Arrival, Leaving;

        cin >> Arrival >> Leaving;

        Custs.push_back({ Arrival, 1 });
        Custs.push_back({ Leaving, -1 });
    }

    sort(Custs.begin(), Custs.end());

    for (size_t I = 0; I < Custs.size(); ++I)
    {
        Total += Custs[I].second;

        Anytime = max(Anytime, Total);
    }

    cout << Anytime << '\n';

    return 0;
}
