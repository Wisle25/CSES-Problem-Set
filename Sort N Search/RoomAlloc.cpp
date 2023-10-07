#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin .tie(0);
    cout.tie(0);

    int32_t N, K = 0;
    cin >> N;

    vector<tuple<int64_t, int64_t, int32_t>> Custs(N);

    for (int32_t I = 0; I < N; ++I)
    {
        int64_t Arrival, Departure;

        cin >> Arrival >> Departure;

        Custs[I] = { Arrival, Departure, -1 };
    }

    sort(Custs.begin(), Custs.end(), [](const auto& A, const auto& B) {
        return get<1>(A) < get<1>(B);
    });

    int32_t Left  = 0;
    int32_t Right = 0;

    while (Left < N && Right < N)
    {
        int32_t Before = Right - 1 < 0 ? 0 : Right - 1;

        if (get<1>(Custs[Left]) < get<0>(Custs[Right]))
        {
            int32_t& RightRoom = get<2>(Custs[Right]);
            int32_t  LeftRoom  = get<2>(Custs[Left]);

            RightRoom = LeftRoom;

            ++Left;
        }
        else
        {
            if (get<1>(Custs[Before]) < get<0>(Custs[Right]))
            {
                int32_t& RightRoom = get<2>(Custs[Right]);
                int32_t  LeftRoom  = get<2>(Custs[Left]);

                RightRoom = LeftRoom;

                ++Left;
            }
            else
            {
                int32_t& RightRoom = get<2>(Custs[Right]);
                RightRoom          = ++K;
            }
        }

        ++Right;
    }

    cout << K << '\n';
    for (int32_t I = 0; I < N; ++I)
        cout << get<2>(Custs[I]) << " ";
    cout << '\n';

    return 0;
}