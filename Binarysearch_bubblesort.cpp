#include <iostream>
using namespace std;


// BubbleSort function
void BubleSort(int *A, int n){
	int temp;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n-1; j++){
			if(A[j] > A[j+1]){
				temp = A[j];
				A[j] = A[j+1];
				A[j+1] = temp;
			}
		}
	}
}


// binarySearch Recursion
int BinarySearch_recursion(int* A, int low, int high, int x){
	if(low > high) return -1;
	int mid = low + (high -  low) / 2;
	if(A[mid] == x) return mid;
	else if(x < A[mid]) return BinarySearch_recursion(A, low, mid-1, x);
	else return BinarySearch_recursion(A, mid+1, high, x);
}

// BinarySearch Interaction
int BinarySearch(int* A, int n, int x){
	BubleSort(A, n);
	int start = 0, end = n - 1;
	
	while(start <= end){
		
		int mid = start + (end - start) / 2;
		if(A[mid] == x) return mid;
		else if(x < A[mid]) end = mid - 1;
		else start = mid + 1;
	}
	return -1;
}

int main(int argc, char *argv[])
{
	int A[] = {10,5,3,1};   //bublesort- A[] = {1,3,5,9,10}
	int size = sizeof(A)/sizeof(A[0]);
	int x = 10;
	
	int index = BinarySearch(A, size, x);
	
	cout << "Sizeof array " << size << endl;
	cout << "Number "<< x <<" is on index: "<<index << endl;
	
	return 0;
}