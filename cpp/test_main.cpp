#include<iostream>
using namespace std;

#define true 1
#define SIZE 20


int main()
{
	int num[SIZE]={};
	char input;
	int n=0;
	int Acount=-1;
    int idx = 0;
	while(true)
	{
		cin >> input;
		if(input=='Q'){ // quit
			break;
		}
		else if(input=='A'){ // append n to the end of the array	
			cin >> n;
			if(Acount==-1){
				num[0]=n;
				Acount++;
			}
			else {
				num[(Acount+1)%20]=n;
				Acount++;
			}
		}
		else if (input == 'P') { // print every n-th element
            cin >> n;
            int i = idx;
            for (int count = 0; count < SIZE; count++) {
                if (count == SIZE - 1) {
                    cout << num[i];
                } else {
                    cout << num[i] << " ";
                }
                i = (i + n) % SIZE;
            }
            cout << endl;
		}
		else if(input=='M'){ // max index
			int idx = 0;
			int max = 0;
			if(Acount>=SIZE){
				for(int i=0; i<SIZE; i++){
					if(num[i]>max){
						max = num[i];
						idx = i;
					}
				}
			}
			else{
				for(int i=0; i<=(Acount%20); i++){
					if(num[i]>max){
						max = num[i];
						idx = i;
					}
				}
			}
			cout << idx << endl;
		}
	}
	return 0;
}
