#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	    int n,i,j,k,l;
	    cout << "Enter the number of items and Knapsack Capacity\n";
	    cin >> n >> k;
	    int w[n];
	    int v[n];
	    cout << "Enter the item weights and their values\n";
	    for(i=0;i<n;i++){
	        cin >> w[i] >> v[i];
	    }
	    int A[n+1][k+1];
	    for(i=0;i<=n;i++){
  	    	for(j=0;j<=k;j++){
  	      	  A[i][j]=0;
  	      }
  	    }		
   	    for(i=1;i<n+1;i++){
        	for(j=0;j<=k;j++){
        	    if(j<w[i-1]){
        	    	A[i][j]=A[i-1][j];
        	    }
        	    else{
			l=w[i-1];
        	    	A[i][j]=max(A[i][j-1],v[i-1]+A[i-1][j-l]);       
        	    }
        	}
    	    }
	for(i=0;i<=n;i++){
		for(j=0;j<=k;j++){
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
	cout << "The maximum value is => ";
  	 cout << A[n][k] << endl;
	i=n;
	j=k;
	cout << "Weights included are => ";
	while(A[i][j]!=0){
		if(A[i][j]>A[i-1][j]){
			cout << w[i-1] << " ";
			j-=w[i-1];
			i--;
		}
		else{
			i--;			
		}
	}
  	  return 0;
}
