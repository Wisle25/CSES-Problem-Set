#include <iostream>
#include <set>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin .tie(0);
    cout.tie(0);

    uint32_t N;
    cin >> N;

    set<uint64_t> UniqueNums;

    for (uint32_t I = 0; I < N; ++I)
    {
        uint64_t Temp;
        cin >> Temp;

        UniqueNums.insert(Temp);
    }

    cout << UniqueNums.size() << '\n';

    return 0;
}
