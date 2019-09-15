#include<bits/stdc++.h>

using namespace std;

int main()
{
	string str1,str2;
	cin >> str1;
	cin >> str2;
  	map <string,string> m;
  	queue <pair <string,pair <int,int>>> q;
  	m[str1]=str1;
  	q.push(make_pair(str1,make_pair(0,0)));
  	while(!q.empty()){
  		pair <string,pair <int,int>> p=q.front();
    	q.pop();
    	string s=p.first;
    	if(s==str2){
        	string x=str2 ;
       		while(m.find(x)->second !=x){
            	cout << x << " ";
            	x=m.find(x)->second ;  
       		}
       		cout << x << endl ;
        	cout << p.second.second ;
        	break;
    	}
    	for(int i=0 ;i<str2.size() ;i++){
    		string z;
       		string r="";
      		r=r+str2[i] ;
      		z=r+s;
      		m[z]=s;
 			q.push(make_pair( z,make_pair(p.second.first+1,p.second.second+1)));
    	}
  		if(p.second.first<s.size()-1){
		  	q.push(make_pair( s,make_pair(p.second.first,p.second.second+1)));
		}
		if(s.size()!=0){
  			s.erase(p.second.first,1);
  			m[s]=p.first ;
  	    	q.push(make_pair(s,make_pair(p.second.first,p.second.second+1)));
		}
	}
	return 0;
}
