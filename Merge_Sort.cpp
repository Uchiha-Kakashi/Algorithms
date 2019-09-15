#include <iostream>
#include <cstdlib>

using namespace std;


void merge(int *A,int l,int m,int r)
{
	int i,j,s,e,k;
	int B[m-l+1];
	int C[r-m];
	for(i=l;i<=m;i++){
		B[i-l]=A[i];	
	}
	for(j=m+1;j<=r;j++){
		C[j-m-1]=A[j];
	}
	i=0;
	j=0;
	s=l;
	while(i<=m-l && j<=r-m-1){
		if(B[i]<C[j]){
			A[s]=B[i];
			++i;
		}
		else{
			A[s]=C[j];
			++j;
		}
		++s;
	}
	while(i<=m-l){
		A[s]=B[i];
		++i;
		++s;
	}
	while(j<=r-m-1){
		A[s]=C[j];
		++j;
		++s;
	}
}


void Divide(int *A,int l,int r)
{	
	if(l==r){
		return ;
	}
	int m;
	m=(l+r)/2;
	Divide(A,l,m);
	Divide(A,m+1,r);
	merge(A,l,m,r);
}

int main()
{
	int n,i,j,k;
	cin >> n;
	int A[n]={4,2,1,6,8};
	for(i=0;i<n;i++){
		cin >> A[i];
	}
	Divide(A,0,n-1);
	for(k=0;k<n;k++){
		cout << A[k] << " ";
	}
	return 0;
}
