#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define INF LLONG_MAX
/*
	https://test-case-generator.herokuapp.com/
	https://csacademy.com/app/graph_editor/
*/

void init(){
    #ifndef ONLINE_JUDGE 
    freopen("../input.txt", "r", stdin); 
    freopen("../output.txt", "w", stdout); 
    #endif 
}

/*
	In this file:
--> Dijkstras SSSP
--> Bellman Ford SSSP

*/

vector<vector<pair<int,int>>>g;
vector<int>visited;

void printGraph(){
	for(int i=0; i<g.size(); i++){
		for(int j=0; j<g[i].size(); j++){
			cout << i + 1 << " " << g[i][j].first + 1 << " " << g[i][j].second <<  "\n";
		}
	}
	cout << "\n";
}

/*
	Note: The pair being pushed into the queue is different from graph edge pairs:
--> Graph Edges: u: {v, w}
--> Queue Edges: {dist, node}

*/

priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
vector<int> dijkstra(int s){
	int n = g.size();
	vector<int>distances(g.size(), INF);
	
	distances[s] = 0;
	pq.push({0, s});

	while(!pq.empty()){
		int currNode = pq.top().second;
		int currDist = pq.top().first;
		pq.pop();
		for(pair<int,int> edge: g[currNode]){
			if(currDist + edge.second < distances[edge.first]){
				distances[edge.first] = currDist + edge.second;
				pq.push({distances[edge.first], edge.first});
			}
		}
	}
	return distances;
}

vector<vector<int>>edgeList;
vector<int> bellmanFord(int s, int numOfVertices){
	int m = edgeList.size();
	vector<int>distances(numOfVertices, INF);
	distances[s] = 0;
	for(int i=0; i<numOfVertices-1; i++){
		for(int j=0; j<m; j++){
			if(distances[edgeList[j][0]] < INF)// Valid starting point
			distances[edgeList[j][1]] = min(distances[edgeList[j][1]], distances[edgeList[j][0]] + edgeList[j][2]);
		}
	}
	return distances;
}



int32_t main(){
    init();
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int t; cin >> t;
    for(int l=1; l<=t; l++){
        int n, m; cin >> n >> m;
        
        g = vector<vector<pair<int,int>>>(n, vector<pair<int,int>>());
        edgeList = vector<vector<int>>(n, vector<int>(3));
        while(m--){
        	int u, v, w; cin >> u >> v >> w;
        	u--; v--;
        	/*g[u].push_back({v, w});
        	g[v].push_back({u, w});*/
        	// For directed graph.
        	edgeList.push_back({u, v, w});
        	edgeList.push_back({v, u, w});
        }
        
        vector<int>distances = bellmanFord(0, n);

        //vector<int>distances = dijkstra(0);
        for(int i=0; i<n; i++) cout << distances[i] << " ";
    }
}