#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    uint32_t N;
    vector<bool> Num;

    cin >> N;

    Num.resize(N + 2, false);

    for (uint32_t I = 0; I <= N; ++I)
    {
        uint32_t Idx;
        cin >> Idx;

        Num[Idx] = true;
    }

    for (uint32_t I = 1; I < Num.size(); ++I)
    {
        if (!Num[I])
        {
            cout << I;

            break;
        }
    }

    return 0;
}
