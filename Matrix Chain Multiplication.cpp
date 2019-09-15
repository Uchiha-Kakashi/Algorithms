#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	int n,i,j,k,L=2,q;
	int M=10000000;
	cin >> n;
	int p[n];
	int m[n][n];
	for(i=0;i<n;i++){
		cin >> p[i];
	}
	for(i=0;i<n;i++){
		m[i][i]=0;	
	}
	while(L<n){
		for(i=1; i<n-L+1; i++){
			j = i+L-1;
			m[i][j] = M;
			for (k=i; k<=j-1; k++){
	        		q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
	        		if (q < m[i][j]){
	        	 		m[i][j] = q;
				}
	    		}
		}
		L++;
	}
	cout << m[1][n-1];
	return 0;
}
