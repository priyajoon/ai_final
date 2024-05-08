#include <bits/stdc++.h>
using namespace std;



vector<int> g[100];

void func(int n){
	vector<int> ans(n,-1);

	ans[0]=0;
	vector<bool> visited(n,false);

	set<int> st;

	for(int u=1;u<n;u++){
		for(auto c:g[u]){
			if(ans[c]!=-1){
				visited[ans[c]]=true;
			}
		}

		int color=0;

		for(int i=0;i<n;i++){
			if(visited[i]==false){
				color=i;
				break;
			}
		}
		
		ans[u]=color;
		st.insert(color);

		for(auto c:g[u]){
			if(ans[c]!=-1){
				visited[ans[c]]=false;
			}
		}
	}

	cout<<"Vertex "<<" "<<"Color"<<endl;
	for(int i=0;i<n;i++){
		cout<<i<<"          "<<ans[i]<<endl;
	}

}

int main(){
	cout<<"Enter number of vertex and edges = ";
	int n,m;
	cin>>n>>m;
	cout<<"Enter connecting edges "<<endl;
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	func(n);
	return 0;
}


/*
	INPUT
	
7 8

0 1
1 2
1 3
1 4
3 4
4 5
4 6
5 6

*/