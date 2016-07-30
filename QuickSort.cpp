/*

Algorithm: Quick Sort
Section 7.1, Page 146

*/

#include <iostream>

using namespace std;

int Partition(int * A,int p,int r) {
	int x = A[r],temp;
	int i=p-1;
	
	for (int j=p;j<r;j++) {
		if (A[j]<=x) {
			i++;
			temp = A[i];
			A[i]=A[j];
			A[j]=temp;
		}
	}
	
	temp = A[i+1];
	A[i+1]=A[r];
	A[r]=temp;
	return i+1;
}

void QuickSort(int * A, int p, int r)
{
	if(p<r) {
		int q = Partition(A,p,r);
		QuickSort(A,p,q-1);
		QuickSort(A,q+1,r);
	}
}

int main() {

	int n; int *A;
	cin >> n;
	A = new int[n];

	//Input
	for(int i=0;i<n;i++)
		cin >> A[i];

	//HeapSort
	QuickSort(A,0,n-1);

	//Print
	for(int i=0;i<n;i++)
		cout << A[i] << " ";

	cout << endl;

	return 0;
}