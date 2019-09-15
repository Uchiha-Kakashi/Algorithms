#include <bits/stdc++.h>

using namespace std;

int binary_search(int a,int b,int k,int *A)
{
	int m;
	m=(a+b)/2;
	if(a>b){
		return -1;
	}
	if(A[m]==k){
		return m;
	}
	if(A[m]>k){
		return binary_search(a,m-1,k,A);
	}
	else{
		return binary_search(m+1,b,k,A);
	}
}

int main()
{
	int n,i,j;
	cout << "Enter the number of elements in the array\n";
	cin >> n;
	int A[n];
	cout << "Enter the elements in the array\n";
	for(i=0;i<n;i++){
		cin >> A[i];
	}
	cout << "Enter the element to be searched\n";
	cin >> j;
	i=binary_search(0,n-1,j,A);
	if(i>=0){
		cout << "The key exist at index " << i << endl;
	}
	else{
		cout << "The key does not exist in the array\n";
	}
	return 0;
}
