#include <bits/stdc++.h>

using namespace std;

int GCD(int a,int b)
{
	if(a==0){
		return b;
	}
	return GCD(b%a,a);
}

int main()
{
	int a,b,g;
	cout << "Enter the two numbers\n";
	cin >> a >> b;
	if(a>b){
		g=a;
		a=b;
		b=g;
	}
	
	g=GCD(a,b);
	cout << "GCD of these numbers is " << g << endl;
	
	cout << "The inbuilt function for the same\n";
	cout << __gcd(a,b) << endl;
	return 0;
}
