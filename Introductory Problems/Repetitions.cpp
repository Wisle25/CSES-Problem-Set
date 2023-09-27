#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin .tie(0);
    cout.tie(0);

    string Dna;

    cin >> Dna;

    uint32_t ACount, CCount, GCount, TCount, ATemp, CTemp, GTemp, TTemp;
    ACount = CCount = GCount = TCount = ATemp = CTemp = GTemp = TTemp = 1;

    for (uint32_t I = 0; I < Dna.size(); ++I)
    {
        if (Dna[I] == 'A' && Dna[I + 1] == 'A') ++ATemp; else { ACount = max(ACount, ATemp); ATemp = 1; }
        if (Dna[I] == 'C' && Dna[I + 1] == 'C') ++CTemp; else { CCount = max(CCount, CTemp); CTemp = 1; }
        if (Dna[I] == 'G' && Dna[I + 1] == 'G') ++GTemp; else { GCount = max(GCount, GTemp); GTemp = 1; }
        if (Dna[I] == 'T' && Dna[I + 1] == 'T') ++TTemp; else { TCount = max(TCount, TTemp); TTemp = 1; }
    }

    uint32_t MaxChar = max(ACount, CCount);
    MaxChar = MaxChar < max(GCount, TCount) ? max(GCount, TCount) : MaxChar;

    cout << MaxChar;

    return 0;
}