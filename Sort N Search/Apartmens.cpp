#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin .tie(0);
    cout.tie(0);

    int32_t N, M, Total = 0;
    int64_t K;
    cin >> N >> M >> K;

    vector<int64_t> Desired(N);
    vector<int64_t> Aps(M);

    for (int32_t I = 0; I < N; ++I)
        cin >> Desired[I];

    for (int32_t I = 0; I < M; ++I)
        cin >> Aps[I];

    sort(Aps.begin()    , Aps.end());
    sort(Desired.begin(), Desired.end());

    int32_t DPtr = 0;
    int32_t APtr = 0;

    while (DPtr < N && APtr < M)
    {
        if (abs(Desired[DPtr] - Aps[APtr]) > K)
        {
            if (Desired[DPtr] > Aps[APtr])
                ++APtr;
            else
                ++DPtr;
        }
        else
        {
            ++Total;
            ++DPtr;
            ++APtr;
        }
    }

    cout << Total << '\n';

    return 0;
}