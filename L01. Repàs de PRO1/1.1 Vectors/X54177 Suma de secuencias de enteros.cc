#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) {
        int suma = 0;
        int a;
        cin >> a;
        // Sumem fins trobar la primera aparició de x
        while (a != x) {
            suma += a;
            cin >> a;
        }
        // Saltem la resta de la línia
        string resta;
        getline(cin, resta);
        cout << "La suma de la secuencia " << i << " es " << suma << endl;
    }
}
