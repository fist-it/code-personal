#include <iostream>
using namespace std;

void wzor(int size, int h, int v){
    for(int y=1; y <= v * (3*size/2); y++){
        for(int x=1; x <= h*size; x++){
            
            

            if( (y%(3*size/2) != 0 && y %(3*size/2) <= size/2-1) && (x % size == 1 || x % size == 0)){
                
                cout << "|";
            }
            else if(y%(3*size/2) == size/2){
                cout << "|";
            }
            else if( (y%(3*size/2)>=size/2+1 || y%(3*size/2) == 0) && x%size == size/2 +1){
                cout << "|";
            }
            else if( (y%(3*size/2) >= size-1 && y%(3*size/2) <= (3*size/2)) && ( (x%size == y%(3*size/2) - size +1) &&  (x%size <= size/2) && x%size != 0)){
                cout << "\\";
            }
            else if( ((y)%(3*size/2) >= size) && (((x%size + y%(3*size/2) == 2*size) && (x%size >= size/2 +2)) || (x%size==0 && y%(3*size/2)==(3*size/2)-size/2) || (x%size==size/2+2 && y%(3*size/2)==(3*size/2)-1))){
                cout << "/";
            }


            else{
                cout << "*";
            }
            
        }
        cout << endl;
    }
}


int main() {
  int size, h, v;
  int a, b, c;
  cin >> size;
  cin >> h;
  cin >> v;
  if(size <=0 || h <=0 || v <=0 || size%2 == 0){
        cout << "Wrong input";
    }
  else{
    wzor(size, h, v);
    c = size - 1;
    b = size + size + ((size/2) -1)*2;
    a = (size * (2*size - size/2 -1)) - b - c;


    cout << "\n* " << h*v*a << endl;
    cout << "| " << h*v*b << endl;
    cout << "\\/ " << h*v*c << endl;
  }
  return(0);
}