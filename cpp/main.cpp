#include <iostream>
using namespace std;

#define SIZE 10

//vertical - (1)
//horizontal - (-1)
//singular - (0)

int checkdir(char arr[][], int row, int col){
	if(arr[row][col] == '*'){
		if(arr[row][col+1] == '*' || arr[row][col-1] == '*'){
			return(1);
		}
		else if(arr[row+1][col] == '*' || arr[row-1][col] == '*'){
			return(-1);
		}
		else{
			return(0);
		}
	}
}

int size(char arr[][], int row, int col){
	int size = 0;
	int dir = checkdir(arr, row, col);
	if(dir = 0){
		size = 1;
	}
	else if(dir = 1){
		int currentrow = row;
		while(arr[currentrow][col] == '*'){
			size++;
			currentrow--;
		}
	}
	else if(dir = -1){
		int currentcol = col;
		while(arr[row][currentcol] == '*'){
			size++;
			currentcol++;
		}
	}
	else {
		return 0;
	}
	return size;
}

void changeship(char arr[][], int row, int col){
	dir = checkdir(arr, row, col);
	size = size(arr, row, col)
	if(dir == -1){ //horizontal 
		for(int i=0; i<size; i++){
			*arr[row][col+i] = size;
		}
	}
	else if(dir == 1){ //vertical
		for(int i=0; i<size; i++){
			*arr[row+i][col] = size	
		}
	}
	else{
		*arr[row][col] = 1;
	}
}


void printboard(arr[][]){
	for(int i=0; i<SIZE; i++){
		for(int j=0; j<SIZE; j++){
			cout << arr[i][j];
		}
		cout << endl;
	}
}


int main() {
	char board[SIZE][SIZE];
	cin << board;
	for(int i=0; i<SIZE; i++){
		for(int j=0; j<SIZE; j++){
			if(board[i][j] == '*'){
				changeship(board, i, j);
			}
		}
	}

	printboard(board);
	return 0;
}
