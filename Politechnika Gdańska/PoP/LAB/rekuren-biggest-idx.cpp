#include <iostream>
using namespace std;

int find(int arr[], int size, int target, int *index){
	if (arr[size-1] == target){
		*index = size-1;
		size = 0;
	}
	if(size == 0){
		return *index;
	}
	else{
		return find(arr, size-1, target, index);
	}
}

int main()
{
	int size;
	cin >> size;
	int *arr = (int *)malloc(sizeof(int) * size);
	for (int i = 0; i < size; i++){
		cin >> arr[i];
	}
	int target;
	cin >> target;
	int index = -1;
	cout << find(arr, size, target, &index);
	free(arr);
	return 0;
}
