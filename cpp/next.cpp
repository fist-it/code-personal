#include<iostream>
using namespace std ;
#define SIZE 100

int main()
{
    int Tablica[SIZE];
    int n,a;
    cin >> n ; cout << endl ;
    for(int i=0; i<n; i++){
        cin >> a ;
        Tablica[i]=a ;
        for (int j=0; j<n; j++){
            if(a==Tablica[j]&&j!=i){
                cout << a << ' ' ;
                break;
            }
        }
    }
    return 0 ;
}