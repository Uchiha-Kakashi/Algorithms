#include <bits/stdc++.h>

using namespace std;

int find(int a,int *A)
{
	int t;
	if(A[a]==a){
		return a;
	}
	return find(A[a],A);
}

class comparison{
	public:
		int operator()(const pair <int,int> &a,const pair <int,int> &b){
			return a.second > b.second;
		}
};

int main()
{
	map <int,pair <int,int>> ma;												// map stores edge and an int to visit (i) ma[i]=some_pair(edge)
	priority_queue <pair <int,int>,vector <pair <int,int>>, comparison> pq;   // to sort and struct is i to distance d the pair is i to d
	pair <int,int> p;
	pair <int,int> s;
	int n,m,i,j,k,l; 
	int d,id,pj,pk,w; 
	cin >> n >> m;
	int A[n];
	for(i=0;i<n;i++){
		A[i]=i;
	}
	for(i=0;i<m;i++){
		cin >> j >> k >> d;
		p=make_pair(i,d);
		pq.push(p);
		s=make_pair(j,k);
		ma[i]=s;
	}
	l=0;
	w=0;
	while(!pq.empty() && l<n-1){
		p=pq.top();
		d=p.second;
		id=p.first;
		s=ma[id];
		j=s.first;
		k=s.second;
		pj=find(j,A);
		pk=find(k,A);
		if(pj!=pk){
			A[pj]=pk;
			l++;
			cout << j << " " << k << endl;
			w+=d;
		}
		pq.pop();
	}
	cout << "Weight of the MST is " << w << endl;
	return 0;
}
