#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin .tie(0);
    cout.tie(0);

    int32_t N, Total = 1;
    cin >> N;

    vector<pair<int64_t, int64_t>> Movies(N);

    for (int32_t I = 0; I < N; ++I)
    {
        int64_t Start, End;

        cin >> Start >> End;

        Movies[I] = { Start, End };
    }

    sort(Movies.begin(), Movies.end(), [](const auto& A, const auto& B) {
        return A.second < B.second;
    });

    int64_t EndTime = Movies[0].second;

    for (size_t I = 0; I < N; ++I)
    {
        if (Movies[I].first >= EndTime)
        {
            EndTime = Movies[I].second;
            ++Total;
        }
    }

    cout << Total << '\n';

    return 0;
}
