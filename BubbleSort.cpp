/*

Algorithm: Bubble Sort
Problems, Page 38

*/

#include <iostream>

using namespace std;

int main() {

	int n; int *A;
	cin >> n;
	A = new int[n];

	//Input
	for(int i=0;i<n;i++)
		cin >> A[i];


	//Sort
	for(int i=0; i<n; i++) {
		for(int j=n-1; j>i; j--) {
			if(A[j] < A[j-1])
			{
				int x = A[j];
				A[j] = A[j-1];
				A[j-1] = x;
			}
		}
	}


	//Print
	for(int i=0;i<n;i++)
		cout << A[i] << " ";

	cout << endl;

	return 0;
}