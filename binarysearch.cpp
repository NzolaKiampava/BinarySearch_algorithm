#include <iostream>

using namespace std;

int BinarySearch_recursion(int* A, int low, int high, int x) {
	if (low > high) return -1;
	int mid = low + (high - low) / 2;

	if (x == A[mid]) return mid;
	else if (x < A[mid]) return BinarySearch_recursion(A, low, mid - 1, x);
	else return BinarySearch_recursion(A, mid + 1, high, x);
}

int BinarySearch(int* A, int n, int x){
	int start = 0, end = n - 1;
	while (start <= end)
	{
		int mid = start + (end - start) / 2;  // (start+low)/2
		
		if (A[mid] == x) {
			return mid;    //fOUND x, return (exit)
		}
		else if (x < A[mid])
			end = mid - 1;
		else
			start = mid + 1;
	}
	return - 1;
}
int main() {

	int A[] = { 1,6,13,21,36,47,63,81,97 };
	int size = sizeof(A) / sizeof(A[0]);
	int x = 36;

	int index = BinarySearch(A, size, x);

	if (index != -1)
		cout << "Number " << x << ", is on index: " << index << endl;
	else
		cout << "We could not find " << x << "on array\n";

	cout << "size of Array: " << size << endl; 

	return 0;
}
