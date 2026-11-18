#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Equip {
    int num;
    int punts;
    int gols_marcats;
    int gols_rebuts;
};

// Ordre: més punts, més diferència de gols i, si empaten, número més petit
bool va_abans(const Equip& a, const Equip& b) {
    if (a.punts != b.punts) return a.punts > b.punts;
    int dif_a = a.gols_marcats - a.gols_rebuts;
    int dif_b = b.gols_marcats - b.gols_rebuts;
    if (dif_a != dif_b) return dif_a > dif_b;
    return a.num < b.num;
}

int main() {
    int n;
    cin >> n;
    // Els equips es numeren de l'1 a l'N
    vector<Equip> equips(n);
    for (int i = 0; i < n; ++i) {
        equips[i].num = i + 1;
        equips[i].punts = equips[i].gols_marcats = equips[i].gols_rebuts = 0;
    }
    // La casella (i, j) és el partit entre i i j: i marca x gols i j en marca y
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int x, y;
            cin >> x >> y;
            if (i != j) {   // la diagonal no compta
                equips[i].gols_marcats += x;
                equips[i].gols_rebuts += y;
                equips[j].gols_marcats += y;
                equips[j].gols_rebuts += x;
                if (x > y) equips[i].punts += 3;
                else if (x < y) equips[j].punts += 3;
                else {
                    ++equips[i].punts;
                    ++equips[j].punts;
                }
            }
        }
    }
    sort(equips.begin(), equips.end(), va_abans);
    for (int i = 0; i < n; ++i) {
        cout << equips[i].num << ' ' << equips[i].punts << ' '
             << equips[i].gols_marcats << ' ' << equips[i].gols_rebuts << endl;
    }
}
