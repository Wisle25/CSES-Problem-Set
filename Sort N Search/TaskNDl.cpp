#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin .tie(0);
    cout.tie(0);

    int64_t Time = 0, Reward = 0;
    int32_t N;
    cin >> N;

    vector<pair<int64_t, int64_t>> Tasks(N);

    for (int32_t I = 0; I < N; ++I)
        cin >> Tasks[I].first >> Tasks[I].second;

    sort(Tasks.begin(), Tasks.end(), [](const auto& A, const auto& B) {
        return A.first < B.first;
    });

    for (int32_t I = 0; I < N; ++I)
    {
        Time   += Tasks[I].first;
        Reward += Tasks[I].second - Time;
    }

    cout << Reward << '\n';

    return 0;
}