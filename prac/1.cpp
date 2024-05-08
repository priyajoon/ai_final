#include <bits/stdc++.h>
using namespace std;

bool visited[20];
vector<int> gp[20];
int depth[20];
int parent[20];
vector<int> depth_limit;



void dfs(int v){
	cout<<v<<" ";
	visited[v]=1;
	for(int i:gp[v]){
		if(visited[i]){
			continue;
		}
		dfs(i);
	}
}

void bfs(int v){
	queue<int> q;
	q.push(v);
	visited[v]=1;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		cout<<x<<" ";
		for(int i:gp[x]){
			if(visited[i]){
				continue;
			}
			q.push(i);
			visited[i]=1;
		}
	}

}

void clear_vis(){
	for(int i=0;i<20;i++){
		visited[i]=0;
	}
}

void depth_limit_search(int v,int start,int limit_dp){
	if(depth[v]+1<=limit_dp and depth[v]+1>=start){
		depth_limit.push_back(v);
	}

	cout<<v<<" ";
	visited[v]=1;
	for(int i:gp[v]){
		if(visited[i]){
			continue;
		}
		parent[i]=v;
		depth[i]=max(depth[i],depth[v]+1);
		depth_limit_search(i,start,limit_dp);
	}
}

void dls(int v,int start,int end){
	int cnt=0;
	for(int i=0;i<depth_limit.size();i++){
		if(depth_limit[i]==v){
			cnt++;
			break;
		}
	}
	vector<int> path;
	if(cnt){
		cout<<"Element found"<<endl;
		cout<<"path is : ";
		int p;
		while(true){
			p=parent[v];
			v=p;
			if(p==-1){
				break;
			}
			path.push_back(p);
		}

		for(int i=path.size()-1;i>=0;i--){
			if(depth[path[i]]+1>=start){
				cout<<path[i]<<" ";
			}
		}
		cout<<endl;
	}
	else{
		cout<<"Element not found"<<endl;
	}

}





int main(){
	int n,e;
	cout<<"Enter number of nodes = ";
    cin>>n;
    cout<<"Enter number of edges = ";
    cin>>e;
    cout<<"enter source and destination"<<endl;
    for(int i=0;i<e;i++){
    	int x,y;
    	cin>>x>>y;
    	gp[x].push_back(y);
    	gp[y].push_back(x);
    }

    int source=0;
    cout<<"Enter source node = ";
    cin>>source;
    parent[source]=-1;
	int start,end,val;
		


	while(1){
		cout<<"1 BFS"<<endl;
		cout<<"2 DFS"<<endl;
		cout<<"3 DLS"<<endl;
		cout<<"4 Exit"<<endl;
		cout<<"Enter choice = ";
		int ch;
		cin>>ch;
		switch(ch){
		    case 1:
		    	bfs(source);
		    	cout<<endl;
		    	clear_vis();
		    	break;
		    case 2:
		    	dfs(source);
		    	cout<<endl;
		    	clear_vis();
		    	break;
		    case 3:
		    	cout<<"Enter the range of depth = ";
				cin>>start>>end;
				cout<<"Enter value to search = ";
				cin>>val;
				depth_limit_search(source,start,end);
				cout<<endl;
				dls(val,start,end);
				cout<<endl;
				for(int i=0;i<depth_limit.size();i++){
					depth_limit.pop_back();
				}
		    	clear_vis();
		    	break;
		    case 4:
		    	exit(1);
		    	break;
		    default:
		    	cout<<"Invalid choice";

		}
	}
    
}



/*Enter number of nodes = 4                                                        
Enter number of edges = 6                                                        
enter source and destination                                                     
0 1                                                                              
0 2                                                                              
1 2                                                                              
2 0                                                                              
2 3                                                                              
3 3 */