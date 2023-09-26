#include <iostream>
using namespace std;

void BubleSort(int* A, int n){
	int temp;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n - 1; j++){
			if(A[j] > A[j+1]){
				temp = A[j];
				A[j] = A[j+1];
				A[j+1] = temp; 
			}
		}
	}
}

//Find first accorence
int BinarySearch_first_accorence(int* A, int n, int x){
	int start = 0;
	int end = n - 1;
	int result = -1;
	BubleSort(A, n);
	
	while(start <= end){
		int mid = (end + start)/2;
		
		if(x == A[mid]){
			result = mid;
			end = mid - 1;
		}else if (x < A[mid]) end = mid - 1;
		else start = mid + 1; 
	}
	return result;
	
}

//Find last accorence
int BinarySearch_last_accorence(int* A, int n, int x){
	int start = 0;
	int end = n - 1;
	int result = -1;
	BubleSort(A, n);
	
	while(start <= end){
		int mid = (start + end)/2;
		
		if(x == A[mid]){
			result = mid;
			start = mid + 1;
		} else if(x < A[mid]) end = mid - 1;
		else start = mid + 1;
	}

	return result;
}


int main(int argc, char *argv[])
{
	int A[] = {1,24,10,10,10,10,20};
	int size = sizeof(A)/sizeof(A[0]);
	int x = 10;
	
	int result = BinarySearch_last_accorence(A, size, x);
	
	if(result != -1)
		cout << "Number " << x << " is on index "<< result << endl;
 	else cout << "Number " << x << "not found\n";
 	
 	cout << "\nAll the values on the array\n";
 	for(int i=0; i < size; i++){
		 cout << A[i] << " ";
	 }
	 
	 cout << endl;
 	
	return 0;
}