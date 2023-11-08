#include <iostream>
using namespace std;

int wzor(int size) {
    int a, b, c;
  for(int i=1; i <= (3*size/2); i++){
    for(int j=1; j<=size; j++){
      if(i<=size/2-1 && (j == 1 || j == size)){
        cout << "|";
      }
      else if(i==size/2){
        cout << "|";
      }
      else if( (i>=size/2+1) && j == size/2+1 ){
        cout << "|";
      }
      else if( (i >= size-1 && i <= (size/2)*3) && ( (j == i - size+1) && (j <= size/2 ) ) ){
        cout << "\\";
      }
      else if( (i >= size-1 && i <= (size/2)*3) && ( (j+i == 2*size) && (j >= size/2 + 2 ) ) ){
        cout << "/";
      }

      else{
        cout << "*";
      }
    }
    cout << endl;
  }

  c = size - 1;
  b = size + size + ((size/2) -1)*2;
  a = (size * (2*size - size/2 -1)) - b - c;

  cout << "\n* " << a << endl;
  cout << "| " << b << endl;
  cout << "\\/ " << c << endl;

  return(0); 
}

int main() {
  int size;
  cin >> size;
  wzor(size);
  return(0);
}