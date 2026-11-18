#include <vector>
using namespace std;

int busqueda_lin(const vector<int>& v, int x)
/* Pre: cierto */
/* Post: si el resultado es v.size(), x no esta en v;
   en caso contrario, indica la posicion de la primera aparicion de x en v */
{
    int n = v.size();
    int i = 0;
    // Avancem fins trobar x o arribar al final
    while (i < n and v[i] != x) ++i;
    return i;
}
