#include <bits/stdc++.h>

using namespace std;

class graph{
	public:
		int V;
		list <pair <int,int> > *adj;
	graph(int v){
		this->V=v;
		adj = new list <pair <int,int> >[V];
	}
	void make_path(int s,int k,int d){
		adj[s].push_back(k,d);
	}
};

int main()
{
	int n,m,i,j,k,d,s;
	cin >> n >> m;
	graph(n);
	for(i=0;i<m;i++){
		cin >> j >> k >> d;
		g.make_path(j,k,d);
	}
	cout << "Enter the starting vertex\n";
	cin >> s;
	
	return 0;
}
