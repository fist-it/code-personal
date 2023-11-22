#include <iostream>
using namespace std;

int main()
{
    int n, a;
    cin >> n;
    int *Tablica = (int *)malloc(n * sizeof(int));
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        Tablica[i] = a;
        for (int j = 0; j < n; j++)
        {
            if (a == Tablica[j] && j != i)
            {
                cout << a << ' ';
                break;
            }
        }
    }
    free(Tablica);
    return 0;
}