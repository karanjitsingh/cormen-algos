/*

Algorithm: Head Sort Implemented With Arrays
Section 6.2-6.4, Page 130-136

*/

#include <iostream>

using namespace std;

int min = 0;	/*	min = 1 means heap is of type min-heap
					Similarly for min = 1*/
void MaxHeapify(int *A, int i, int heapSize) {
	int l = 2*i + 1;
	int r = 2*i + 2;
	int largest;

	if (l<heapSize && (A[l] > A[i]) ^ ::min)
		largest = l;
	else
		largest = i;
	if(r<heapSize && (A[r] > A[i]) ^ ::min)
		largest = r;
	if(largest != i) {
		int temp = A[i];
		A[i] = A[largest];
		A[largest]= temp;
		MaxHeapify(A,i,largest);
	}
}

void BuildMaxHeap(int * A,int n) {
	for(int i=n/2-1;i>=0;i--) {
		MaxHeapify(A,i,n);
	}
}

void HeapSort(int * A, int n) {
	BuildMaxHeap(A,n);
	for(int i=n-1;i>=1;i--) {
		int temp = A[0];
		A[0] = A[i];
		A[i] = temp;
		MaxHeapify(A,1,n);
	}
}

int main() {

	int n; int *A;
	cin >> n;
	A = new int[n];

	::min =1;

	//Input
	for(int i=0;i<n;i++)
		cin >> A[i];


	//HeapSort
	HeapSort(A,n);

	//Print
	for(int i=0;i<n;i++)
		cout << A[i] << " ";

	cout << endl;

	return 0;
}