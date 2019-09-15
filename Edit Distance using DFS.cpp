#include<bits/stdc++.h>

using namespace std;

#define rep(i,k,n) for(int i=k;i<=n;i++)
typedef vector <int > vi;
typedef pair <int,int> pi;
typedef vector <pi> vpi;
typedef vector <vi> vvi;

int dfs(string s1,string s2,int p,int h) ;
typedef vector<pair <float,pair <float,string>>> vps;
bool sortbysec(const pair <float,pair <float,string>> &a,
              const pair <float,pair <float,string>> &b)
{
	return (a.first< b.first);
}

float check(string s1,string s2)
{
    if(s1==""){
    	return 0;
	}
    float c=0;
    vi co(26);
    rep(i,0,s1.length()-1){
    	co[s1[i]-97]++;
    }
    rep(i,0,s2.length()-1){
        co[s2[i]-97]++;
    }
    rep(i,0,25){
        if(co[i]>=2){
        	c++;
    	}
    }
    return c;
}

float guide(string s1,string s2,int p,int h)
{
	vps create;
    int newlength=0;
    int l1=s1.length();
    int l2=s2.length();
    if(l1>l2+2){
        return 0;
    }
    if(p!=-1){
        float f=check(s1,s2)/(float)l2;
        create.push_back({f,{(p+1)%l1,s1}});
        newlength++;
        rep(i,0,l2-1){
        	string s=s1;
        	s.insert(s.begin()+p,s2[i]);
        	float f=check(s,s2)/(float)l2;
            create.push_back({f,{p+1,s}});
         	newlength++;
        }
	    if(p!=-1){
            if(l1-1==p){
                s1.erase(s1.begin()+p);
                float f=check(s1,s2)/(float)l2;
              	create.push_back({f,{-1,s1}});
                newlength++;
            }
            else{
                s1.erase(s1.begin()+p);
                float f=check(s1,s2)/(float)l2;
              	create.push_back({f,{p,s1}});
                newlength++;
            }
        }
    }
	else{
        rep(i,0,l2-1){
        	string s=s1;
        	s+=s2[i];
        	float f=check(s,s2)/(float)l2;
        	create.push_back({f,{p,s}});
         	newlength++;
         }
    }
   	sort(create.begin(),create.begin()+newlength,sortbysec);
    for(int i=newlength-1;i>=0;i--){
        float k=create[i].first;
        float  p=create[i].second.first;
        string s=create[i].second.second;
        int flag=dfs(s,s2,p,h);
        if(flag){
            break;
        }
        create.pop_back();
        }
    create.clear();
}

int dfs(string s1,string s2,int p,int h) 
{
    cout << s1 << endl;
    if(s1==s2){
        cout << s1 << " " << s2 << " " << h;
        cout << endl <<"success";
        exit(1);
    }
    h++;
    guide(s1,s2,p,h);
    return 0;
}

int main()
{
    string s1,s2;
    cin >> s1 >> s2;
    
    dfs(s1,s2,0,0);
  	// cout<<check("abc","bcd");
  	return 0;
}
