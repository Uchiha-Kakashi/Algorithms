#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int n,i,j,k,mx,mn,l;
    cout << "Enter the number of elements\n";
    cin >> n;
    int A[n];
    int B[n]={0};
    mx=-1;
    mn=101;
    cout << "Enter the elements in the array\n";
    for(i=0;i<n;i++){
        cin >> A[i];
        if(A[i]<mn){
            mn=A[i];
        }
        if(A[i]>mx){
            mx=A[i];
        }
    }
    cout << "The maximum and minimum numbers are " << mx << "  " << mn << endl;
    l=mx-mn+1;
	int sum[l]={0};
	memset(sum,0,sizeof(sum));
	
    for(i=0;i<n;i++){
        k=A[i]-mn;
        while(k<l){
            sum[k]++;
            k++;
        }
    }
    
    for(i=0;i<n;i++){
        j=A[i]-mn;
        k=sum[j]-1;
        sum[j]--;
        B[k]=A[i];
    }
    
    for(i=0;i<n;i++){
        cout << B[i] << " ";
    }
    
    return 0;
}

