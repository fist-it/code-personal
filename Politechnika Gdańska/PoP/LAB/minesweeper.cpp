#include <iostream>
using namespace std;

#define SIZE 10
//dodane lll
void Change(char arr[][SIZE], int col, int row, char *location) {
    int count = 0;
    for(int i=-1; i < 2; i++) {
        for(int j=-1; j < 2; j++) {
            if(col+i >= 0 && col+i < SIZE && row+j >= 0 && row+j < SIZE) {
                if(arr[col+i][row+j] == '*'){
                    count++;
                }
            }
        }
    }
    *location = count+48;
}

void print(char arr[][SIZE]){
    for(int i=0; i < SIZE; i++) {
        for(int j=0; j < SIZE; j++) {
            cout << arr[i][j];
        }
        cout << endl;
    }
}


int main() {
    char arr[SIZE][SIZE];
    

    for(int i = 0; i < SIZE; i++) {
        for(int j=0; j < SIZE; j++) {
            cin >> arr[i][j];
        }
    }

    for(int i=0; i < SIZE; i++) {
        for(int j=0; j < SIZE; j++) {
            if(arr[i][j] == '.') {
                Change(arr, i, j, &arr[i][j]);
            }
        }
    }

    print(arr);

    return 0;
}
