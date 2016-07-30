/*

Algorithm: Merge Sort
Section 2.3.1, Page 29 and 32

*/

#include <iostream>

using namespace std;

void Merge(int * A, int p,int q, int r) {
	int n1 = q-p+1;
	int n2 = r-q;


	int *L = new int[n1];
	int *R = new int[n2];

	for(int i=0;i<n1;i++)
		L[i] = A[p+i];

	for(int i=0;i<n2;i++)
		R[i] = A[q+1+i];

	

	int i,j;
	i=j=0;

	for(int k=p;k<=r;k++)
	{
		if(i==n1 || j==n2)
			A[k] = i==n1?R[j++]:L[i++];
		else {
			if(L[i] < R[j])
				A[k] = L[i++];
			else 
				A[k] = R[j++];
		}
	}

}

void MergeSort(int * A, int p, int r) {
	if(p<r) {
		int q = (p + r)/2;
		MergeSort(A,p,q);
		MergeSort(A,q+1,r);
		Merge(A,p,q,r);
	}
}

int main() {

	int n; int *A;
	cin >> n;
	A = new int[n];

	//Input
	for(int i=0;i<n;i++)
		cin >> A[i];


	//Sort
	MergeSort(A,0,n-1);


	//Print
	for(int i=0;i<n;i++)
		cout << A[i] << " ";

	cout << endl;

	return 0;
}