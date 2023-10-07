#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin .tie(0);
    cout.tie(0);

    int64_t Total = 0;
    int32_t N;
    cin >> N;

    vector<int64_t> Times(N);

    for (int32_t I = 0; I < N; ++I)
        cin >> Times[I];

    sort(Times.begin(), Times.end());

    int32_t K = 0;
    int32_t J = N - 1;

    while (K <= J)
    {
        Total += Times[K] + Times[J];

        ++K; --J;
    }

    cout << Total << '\n';

    return 0;
}
