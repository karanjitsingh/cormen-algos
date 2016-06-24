/*

Algorithm: Insertion Sort
Section 2.1, PAge 18

*/

#include <iostream>
#include <vector>

using namespace std;

int main() {

	int n; int *A;
	cin >> n;
	A = new int[n];

	//Input
	for(int i=0;i<n;i++)
		cin >> A[i];


	//Sort
	for(int j=1;j<n;j++)
	{
		int key = A[j];
		int i = j-1;
		while(i > -1 && A[i] > key)
		{
			A[i+1] = A[i];
			i=i-1;
		}
		A[i+1] = key;
	}


	//Print
	for(int i=0;i<n;i++)
		cout << A[i] << " ";

	cout << endl;

	return 0;
}