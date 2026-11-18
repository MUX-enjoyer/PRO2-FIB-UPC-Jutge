#include <vector>
using namespace std;

struct parint {int prim, seg;};

parint max_min1(const vector<int>& v)
/* Pre: v.size()>0 */
/* Post: el primer componente del resultado es el valor maximo de v;
   el segundo componente del resultado es el valor minimo de v */
{
    parint res;
    res.prim = res.seg = v[0];
    for (int i = 1; i < v.size(); ++i) {
        if (v[i] > res.prim) res.prim = v[i];
        else if (v[i] < res.seg) res.seg = v[i];
    }
    return res;
}

pair<int,int> max_min2(const vector<int>& v)
/* Pre: v.size()>0 */
/* Post: el primer componente del resultado es el valor maximo de v;
   el segundo componente del resultado es el valor minimo de v */
{
    pair<int,int> res;
    res.first = res.second = v[0];
    for (int i = 1; i < v.size(); ++i) {
        if (v[i] > res.first) res.first = v[i];
        else if (v[i] < res.second) res.second = v[i];
    }
    return res;
}

void max_min3(const vector<int>& v, int& x, int& y)
/* Pre: v.size()>0 */
/* Post: x es el valor maximo de v;  y es el valor minimo de v */
{
    x = y = v[0];
    for (int i = 1; i < v.size(); ++i) {
        if (v[i] > x) x = v[i];
        else if (v[i] < y) y = v[i];
    }
}
