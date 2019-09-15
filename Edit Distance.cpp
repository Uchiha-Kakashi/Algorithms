#include <bits/stdc++.h>
 
using namespace std; 
 
int main() 
{ 
    string s1,s2; 
    int l1,l2,i,j,m; 
    cin >> s1; 
    cin >> s2; 
    l1=s1.length(); 
    l2=s2.length(); 
    int A[l1+1][l2+1]={0}; 
    for(i=0;i<=l1;i++){ 
        for(j=0;j<=l2;j++){ 
            if(i==0){ 
                A[i][j]=j; 
            } 
            else if(j==0){ 
                A[i][j]=i; 
            } 
            else if(s1[i-1]==s2[j-1]){ 
                A[i][j]=A[i-1][j-1]; 
            } 
            else{ 
                m=min(min(A[i-1][j],A[i-1][j-1]),A[i][j-1])+1; 
                A[i][j]=m; 
            } 
        } 
    } 
    cout << A[l1][l2] << endl;
    // Printing the path
    i=l1;
    j=l2;
    while(A[i][j]!=0){
        if(A[i][j]==A[i-1][j-1]+1){
            cout << "REPLACE  ";
            cout << s1[i-1] << "-->" << s2[j-1] << endl;
            i--;
            j--;
        }
        else if(A[i][j]==A[i-1][j]+1){
            cout << "DELETE   ";
            cout << s1[i-1] << endl;
            i--;
        }
        else if(A[i][j]==A[i][j-1]+1){
            cout << "INSERT   ";
            cout << s2[j-1] << endl;
        	j--;
        }
        else{
            i--;
            j--;
        }
    } 
    return 0; 
}
