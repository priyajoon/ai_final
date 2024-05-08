#include <bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int,int>> pairInt;

class mst{
	int n,m;
	int adj[100][100];
	int id[100];
	bool visited[100];

	vector<pair<int,pair<int,int>>> p;

	public:
		mst(){
			n=0;
			m=0;
			for(int i=0;i<100;i++){
				id[i]=i;
			}
			for(int i=0;i<100;i++){
                for(int j=0;j<100;j++){
                    adj[i][j]=0;
                }
            }
		}

		void input(){
			cout << "ENTER NUMBER OF NODES AND EDGES " << endl;
            cin >> n >> m;
            cout << "ENTER EDGES CONNECTING NODES AND EDGE's WEIGHT" << endl;

            for(int i=0;i<m;i++){
            	int x,y,wt;
            	cin>>x>>y>>wt;
            	p.push_back(make_pair(wt,make_pair(x,y)));
            	adj[x][y]=wt;
            	adj[y][x]=wt;
            }
		}

		int g_size(){
			return n;
		}


		//kruskal
		void Union(int x,int y){
			id[root(x)]=root(y);
		}

		int root(int x){
			if(id[x]==x){
				return x;
			}
			else{
				return root(id[x]);
			}
		}

		void kruskals(){
			int mncost=0;
			sort(p.begin(),p.end());
			cout<<"Weight and edges selected = "<<endl;
			for(int i=0;i<m;i++){
				if(root(p[i].second.first)!=root(p[i].second.second)){
					cout<<"Weight : "<<p[i].first<<" Nodes : "<<p[i].second.first<<" "<<p[i].second.second<<" "<<endl;
					mncost+=p[i].first;
					Union(p[i].second.first,p[i].second.second);
				}
			}
			cout<<"Cost by kruskals is : "<<mncost<<endl;
		}



		//prims
		void Prims(){
            //memset(visited, false, sizeof(visited));
            for(int i=0;i<n;i++){
                visited[i]=false;
            }
            visited[0]=true;
            int mncost=0;
            
            for(int k=0;k<n-1;k++){
                int min=INT_MAX;
                int start, end;
                for(int i=0;i<n;i++){
                    if(visited[i]==false){
                        continue;
                    }

                    for(int j=0;j<n;j++){
                        if(adj[i][j]==0 || visited[j]==true){
                            continue;
                        }
                        if(adj[i][j]<min){
                            start=i;
                            end=j;
                            min=adj[i][j];
                        }
                    }
                }
                cout << "WEIGHT :  " << adj[start][end] << " NODES : " << start << " " << end << endl;
                mncost += adj[start][end];
                visited[start] = true;
                visited[end] = true;

            }
            cout << "COST BY PRIMS : " << mncost << endl;
        }

		//dijikstra

		int min_dist(int dist[],bool sptset[]){
			int min=INT_MAX;
			int min_index;
			for(int i=0;i<n;i++){
				if(sptset[i]==false && dist[i]<=min){
					min=dist[i];
					min_index=i;
				}
			}
			return min_index;
		}

		void display(int dist[]){
			for(int i=0;i<n;i++){
				cout<<i<<"   "<<dist[i]<<endl;
			}
		}

		void construct_path(int prev[],int dest){
		    vector<int> path;
		    stack<int> s;
		    int curr=dest;
		    while(curr!=-1){
		        s.push(curr);
		        curr=prev[curr];
		    }

		    while(!s.empty()){
		        path.push_back(s.top());
		        s.pop();
		    }

		    for(int i=0;i<path.size();i++){
		        cout<<path[i];
		        if (i!= path.size() - 1) {
		            cout << " -> ";
		         }
		    }
		    
		}

		void dijkstra(int src){
			int dist[n];
		    bool sptset[n];
		    int prev[n];
		    for(int i=0;i<n;i++){
		        dist[i]=INT_MAX;
		        sptset[i]=false;
		        prev[i]=-1;
		    }
		    dist[src]=0;

		    for(int cnt=0;cnt<n-1;cnt++){
		    	int u=min_dist(dist,sptset);
		    	sptset[u]=true;

		    	for(int i=0;i<n;i++){
		    		if(!sptset[i] && adj[u][i] && dist[u]!=INT_MAX && dist[u]+adj[u][i]<dist[i]){
		    			dist[i]=dist[u]+adj[u][i];
		    			prev[i]=u;
		    		}
		    	}
		    }
		    display(dist);
		    cout << "Shortest distances from source node " << src << ":\n";
		    for (int i = 0; i < n; ++i) {
		        cout << "Node " << i << ": " << dist[i] << "\tPath: ";
		        construct_path(prev,i);
		        cout<<endl;
		    }

		}

};

void selection_sort(int arr[], int n)
{
    int i, j, min_idx;

    // One by one move boundary of
    // unsorted subarray
    for (i = 0; i < n - 1; i++) {

        // Find the minimum element in
        // unsorted array
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }

        // Swap the found minimum element
        // with the first element
        if (min_idx != i)
            swap(arr[min_idx], arr[i]);
    }
}


int main(){
	cout<<"*********Greedy Algorithms***********"<<endl;
	cout<<endl;
	int ch;
	//selection
	int num,k;
	

	//prims-krus-dij
	int c;
	mst t;

	cout<<"Selection sort"<<endl;
	cout<<"Enter number of elements = ";
	cin>>num;
	cout<<"Enter array elements = ";
	int a[num];
	for(int i=0;i<num;i++){
		cin>>a[i];			
	}
	selection_sort(a,num);
	cout<<endl;
	cout<<"After Sorting"<<endl;
	for(int i=0;i<num;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	cout<<endl;

				


	while(1){
		
		cout<<"1. Input Graph"<<endl;
		cout<<"2. Prims Algorithm"<<endl;
		cout<<"3. Kruskal Algorithm"<<endl;
		cout<<"4. Dijikstra's Algorithm"<<endl;
		cout<<"5. Exit"<<endl;
		cout<<"Enter Your choice  = ";
		cin>>ch;

		switch(ch){
			
			case 1:
				t.input();
				cout<<endl;
				break;
			case 2:
				//t.input();
				//cout<<endl;
				t.Prims();
				cout<<endl;
				//t.kruskals();
				//cout<<endl;

				break;
			case 3:
				t.kruskals();
				cout<<endl;
				break;

			case 4:
			    //t.input();
			    //cout<<endl;
			    cout<<"Enter source node = ";
			    cin>>c;
			    t.dijkstra(c);
			    cout<<endl;
			    
			 	//cout<<"Distance from all elements "<<endl;


                //for(int i=0;i<t.g_size();i++){
                 //   cout<<"Distance from source = "<<endl;
                 //   cout<<i<<" : ";
                 //   t.dijkstra(i);
                //}

				break;
			case 5:
				exit(0);
				
			default:
				cout<<"Invalid operation!!!"<<endl;
		}
	}
}