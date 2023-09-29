#include <iostream>
using namespace std;

int CircularArraySearch(int* A, int n, int x){
	int low = 0;
	int high = n - 1;
	
	while(low <= high){
		int mid = (high + low)/2;
		
		if(A[mid] == x) return mid;  // case 1: Find x, yhea :)
			
			//Verify which  part of array is sorted
		else if(A[mid] <= A[high]){   // Case 2: Right Half is sorted
			if(x > A[mid] && x <= A[high]) low = mid + 1;   //go searching is right sorted half
			else high = mid - 1;
		}
		else    // A[low] <= A[mid]      left half is sorted
		{
			if(x >= A[low] && x < A[mid]) high = mid - 1;    //go searching in left sorted half
			else low = mid + 1;     //go searching right
		}
	}
	
	return -1;
}
int main(int argc, char *argv[])
{
	int A[] = {12,12,14,6,5,10,11,30};
	int x;
	
	cin >> x;
	
	int result = CircularArraySearch(A, sizeof(A)/sizeof(A[0]), x);
	
	if(result == -1)
		cout << "We couldnt find " << x << endl;
	else 
		cout << x <<" was found at index " << result << endl;
	
	return 0;
}