#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin .tie(0);
    cout.tie(0);

    uint64_t Moves = 0;
    uint32_t N;
    cin >> N;

    vector<uint64_t> X(N);

    for (uint32_t I = 0; I < N; ++I)
        cin >> X[I];

    for (uint32_t I = 0; I < N; ++I)
    {
        if (X[I + 1] < X[I])
        {
            uint64_t Diff = X[I] - X[I + 1];

            X[I + 1] += Diff;
            Moves    += Diff;
        }
    }

    cout << Moves;

    return 0;
}
