#include<bits/stdc++.h>

using namespace std;

#define ll long long int 
#define mod 1000000007
#define FOR(i,a) for(i=0;i<a;i++)
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define all(x) (x).begin(), (x).end()
#define tr(x,it) for(auto it = x.begin();it!=x.end();++it)
#define fpresent(x,c) ((c).find(x) != (c).end())  //set,map
#define present(c,x) (find(all(c),x) != (c).end()) //vector
#define pr(a,b) cout << a << " " << b << endl
#define pr1(a,b,c) cout << a << " " << b << " "<< c << endl
#define pb push_back 
#define mp make_pair
#define N 100001
#define F first
#define S second

// THE ULTIMATE COMPRESSED CODE FOR THE INPUT STRING

typedef struct node{
	int freq;
	char data;
	node *l;
	node *r;
}node;

class compare{
	public:
		int operator()(const node *a,const node *b){
			return a->freq > b->freq;
		}
};

node *createnode(char c,int a)
{
	node *t;
	t=(node *)(malloc(sizeof(node)));
	t->freq=a;
	t->data=c;
	t->l=NULL;
	t->r=NULL;
	return t;
}

node *createtree(node *r1,node *r2)
{
	node *t;
	t=(node *)(malloc(sizeof(node)));
	t->data='.';
	t->freq=r1->freq + r2->freq;
	t->l=r1;
	t->r=r2;
	return t;	
}

map <char,string> mc;
void printcodes(node *root,string s)
{
	if(root->l==NULL && root->r==NULL){
		cout << root->data << "-->" << s << endl;
		mc=s;
		return ;
	}
	printcode(root->l,s+"0");
	printcode(root->r,s+"1");
}

int main()
{
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("in.txt", "r", stdin);
    // for writing output to output.txt
    freopen("out.txt", "w", stdout);
	#endif
	fastio;
	string s;
	cin >> s;
	int i,j,k,l;
	map <char,int> m;
	pair <char,int> p;
	FOR(i,s.length()){
		k=s[i];
		m[k]++;
	}
	priority_queue <node *, vector <node *>, compare> pq;
	node *t;
	node *r1;
	node *r2;
	tr(m,h){
		p=*h;
		t=createnode(p.F,p.S);
		pq.push(t);
	}
	while(pq.size()>1){
		r1=pq.top();
		pq.pop();
		r2=pq.top();
		pq.pop();
		t=createtree(r1,r2);
		pq.push(t);
	}
	/*while(!pq.empty()){
		t=pq.top();
		cout << t->freq << " " << t->data << endl;
		pq.pop();
	}*/

	printcodes(t,"");
	cout << "The Compressed Code is ==> \n";
	FOR(i,s.length()){
		cout << mc[s[i]];
	} 
	return 0;
}
