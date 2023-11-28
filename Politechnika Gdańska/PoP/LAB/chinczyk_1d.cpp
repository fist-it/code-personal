#include <iostream>
using namespace std;

int main() {
    int score[4] = {0, 0, 0, 0};
    int *scr = score;
    int start[4] = {0, 0, 0, 0};
    int N;
    char a;
    int current = 0;
    cout << "Ile punktów do wygranej?: ";
    cin >> N;
    while(1==1){
        int current_player = current % 4;
        cout << "Tura gracza: " << current_player + 1 << endl;
        cin >> a;
        
        if(a == 'm'){
            int j = 0;
            cout << "wyniki: ";
            while(j < 4){
                cout << score[j] << " ";
                j++;
            }
            cout << endl;
        }
        if(a == 'r') {
            cout << "rzut!: ";
            int in = 0;
            cin >> in;
            if(in > 6){
                cout << "nieprawidlowa komenda" << endl;
                continue;
            }
            if(start[current_player] != 2){
                if(in == 1){
                    if(start[current_player] == 0 || start[current_player] == 1){
                        start[current_player] = 1;
                        current++;
                        continue;
                    }
                    else {
                        start[current_player] = 0;
                        current++;
                        continue;
                    }
                }
                if(in == 6) {
                    if(start[current_player] == 1){
                        start[current_player] = 2;
                        current++;
                        continue;
                    }
                    else {
                        start[current_player] = 0;
                        current++;
                        continue;
                    }
                    }
                else {
                    start[current_player] = 0;
                    current++;
                    continue;
                }
            }
            else {
                score[current_player] += in;
                if(score[current_player] >= N){
                    cout << "gracz " << current_player + 1 << " wygrywa!" << endl;
                    break;
                }
                current++;
                continue;
            }
        }
        if(a == 'q'){
            break;
        }
        continue;
    }
    return 0;
}



