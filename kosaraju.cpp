#include <bits/stdc++.h>

using namespace std;

map <int,int> m;

class graph{
	public:
		int V;
		list <int> *adj;
		graph(int v)
		{
			this->V=v;
			adj = new list <int>[v];
		}
		void make_path(int a,int b)
		{
			adj[a].push_back(b);
		}
};

void kosaraju(graph g, stack <int> &s,int i)
{	
	for(auto h=g.adj[i].begin();h!=g.adj[i].end();h++){
		if(m[*h]!=1){
			m[*h]=1;
			kosaraju(g,s,*h);
		}
	}
	cout << "This is working\n";
	return ;
}

void kosaraju_reverse(graph gr,int i)
{	
	for(auto t=gr.adj[i].begin();t!=gr.adj[i].end();t++){
		if(m[*t]!=1){
			m[*t]=1;
			kosaraju_reverse(gr,*t);
		}
	}
	cout << *t << " ";
	return ;
}

int main()
{
	int n,l,i,j,v,k;
	cin >> n >> l;
	stack <int> s;
	graph g(n);
	graph gr(n);
	for(i=0;i<l;i++){
		cin >> j >> k;
		g.make_path(j,k);
		gr.make_path(k,j);
		m[j]=0;
		m[k]=0;
	}
	i=0;
	while(i<n){
		if(m[i]!=0){
			i++;
			continue;
		}
		kosaraju(g,s,i);
	}
	for(i=0;i<n;i++){
		m[i]=0;
	}
	while(!s.empty()){
		i=s.top();
		if(m[i]==0){
			i++;
			continue;
		}
		kosaraju_reverse(gr,i);
		cout << endl;
	}
	return 0;
}
