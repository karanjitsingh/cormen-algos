/*

Algorithm: Priority Queues implemented with Heaps
Section 6.5, Page 139-140

*/

#include <iostream>

using namespace std;

int heapSize=0;

void MaxHeapify(int *A, int i) {
	int l = 2*i + 1;
	int r = 2*i + 2;
	int largest;

	if (l<heapSize && A[l] > A[i])
		largest = l;
	else
		largest = i;
	if(r<heapSize && A[r] > A[i])
		largest = r;
	if(largest != i) {
		int temp = A[i];
		A[i] = A[largest];
		A[largest]= temp;
		MaxHeapify(A,i);
	}
}

int HeapMaximum(int * A) {
	return A[0];
}

int HeapExtractMax(int * A) {
	if(heapSize == 0) {
		cout << "Heap underflow!\n";
		return 0;
	}

	int max = A[0];
	A[0] = A[heapSize-1];
	heapSize--;
	MaxHeapify(A,0);

	return max;
}

void HeapIncreaseKey(int * A, int i, int key) {
	if (key < A[i]) {
		cout << "New key is smaller than current key." << endl;
		return;
	}

	A[i] = key;
	
	while(i>0 && A[i/2] < A[i]) {
		int temp = A[i/2];
		A[i/2] = A[i];
		A[i] = temp;
		i = i/2;
	}
}

void MaxHeapInsert(int * A, int key) {
	heapSize++;
	A[heapSize-1] = key-1;
	HeapIncreaseKey(A,heapSize-1,key);
}

int main() {


	int n; int *A,m,key;
	cout << "Enter heap max length: ";
	cin >> n;
	A = new int[n];

	while(1) {
		cout << "1. Heap Extract" << endl;
		cout << "2. Insert" << endl;
		cout << "3. Print array" << endl;
		cin >> m;

		switch(m) {
			case 1:
				cout << HeapExtractMax(A) << endl;
				break;
			case 2:
				if(heapSize == n){
					cout << "Heap Overflow!" << endl;
					break;
				}

				cout << "Enter key to insert: ";
				cin >> key;
				MaxHeapInsert(A, key);
				break;
			case 3:
				for(int i =0;i<heapSize;i++)
					cout << A[i] << " ";
				cout << endl;
		}
	}

	return 0;
}