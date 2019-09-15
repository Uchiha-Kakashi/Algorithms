#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

void swapnums(int *A,int a,int b)
{
	int t;
	if(a==b){
		return;
	}
	else{
		t=A[a];
		A[a]=A[b];
		A[b]=t;
	}
}

void quicksort(int *A,int left,int right,int n)
{
	int pivot=left;
	int l,r;
	l=left;
	r=right;
	if(left>=right){
		return ;
	}
	while(right!=left){
		if(pivot==left){
			if(A[pivot]<=A[right]){
				right--;
			}
			else{
				swapnums(A,pivot,right);
				pivot=right;
			}
		}
		else{
			if(A[pivot]>=A[left]){
				left++;
			}
			else{
				swapnums(A,pivot,left);
				pivot=left;
			}
		}
	}
	quicksort(A,l,pivot-1,n);
	quicksort(A,pivot+1,r,n);
	return ;
}

int main()
{
	int n,pivot,i;
	cout << "Enter the size of the array\n";
	cin >> n;
	int A[n];
	cout << "Enter the elements in the array\n";
	for(i=0;i<n;i++){
		cin >> A[i];
	}
	quicksort(A,0,n-1,n);
	cout << "The sorted array is :- \n";
	for(i=0;i<n;i++){
		cout << A[i] << " ";	
	}
	return 0;
}

