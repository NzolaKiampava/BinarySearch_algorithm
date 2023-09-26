#include <iostream>
using namespace std;

int BinarySearch(int* A, int n, int x, bool first_last){
	
	int start = 0;
	int end = n - 1;
	int result = -1;
	
	while(start <= end){
		int mid = (end + start)/2;
		
		if(x == A[mid]){
			result = mid;
			
			if(first_last) end = mid - 1;
			else start = mid + 1;
		}else if(x < A[mid]) end = mid - 1;
		else start = mid + 1;
	}
	return result;
}

int main(int argc, char *argv[])
{
	int A[] = {1,2,3,3,4,5};
	int x;
	
	cout << "Which element yiu looking for? \n";
	cin >> x;
	
	int first = BinarySearch(A, sizeof(A)/sizeof(A[0]), x, true);
	int last = BinarySearch(A, sizeof(A)/sizeof(A[0]), x, false);
	
	if(first == -1){
		cout << "The number " << x <<" does not exist\n";
	}
	else{
		cout << "The number "<< x <<" is on array " << last - first + 1 << " times\n";
	}
	return 0;
}