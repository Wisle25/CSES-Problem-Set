#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin .tie(0);
    cout.tie(0);

    int32_t N, M;
    cin >> N >> M;

    set<pair<int64_t, int32_t>> Prices;
    vector<int64_t> Cust(M);

    for (int32_t I = 0; I < N; ++I)
    {
        int64_t Value;
        cin >> Value;

        Prices.insert({ Value, I });
    }

    for (int32_t I = 0; I < M; ++I)
        cin >> Cust[I];

    for (int32_t I = 0; I < M; ++I)
    {
        auto Price = Prices.lower_bound({ Cust[I] + 1, 0 });

        if (Price == Prices.begin())
            cout << -1 << '\n';
        else
        {
            --Price;
            cout << (*Price).first << '\n';
            Prices.erase(Price);
        }
    }

    return 0;
}
