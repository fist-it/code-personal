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
		else if(input=='P'){ //print every n-th element
			cin >> n;
			if(n==1){
				if(Acount>=SIZE){
					for(int i=0;i<SIZE;i++){
					cout << num[i] << " ";
				}
				}
				else{
					for(int i=0;i<=(Acount%20);i++){
					cout << num[i] << " ";
				}
				}
			}
			else {
				if(Acount>=SIZE){
					for(int i=0;i<SIZE;i+=n){
						cout << num[i] << " ";
					}
				}
				else{
					for(int i=0;i<=(Acount%20);i+=n){
						cout << num[i] << " ";
					}
				}
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
