#include <bits/stdc++.h>
using namespace std;
#define int long long int

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
--> Basic DFS
--> Count the number of components
--> Distance between nodes in a tree - distanceDfs() and the treeDistance()
--> Bipartite Check
--> Detect Cycles
--> DFS in-out timers
--> Tree Diameter
--> Subtree Size
--> BFS and SSSP using BFS on unweighted graphs

*/

vector<vector<int>>g;
vector<int>visited;
vector<int>distances;
vector<int>bipartiteColor;
vector<int>subtreeSizes;

void dfs(int s){
	if(visited[s] == 1){
		return;
	}
	visited[s] = 1;
	cout << s + 1 << " ";
	for(int i = 0; i < g[s].size(); ++i){
		dfs(g[s][i]);
	}
}

int components(){
	int n = g.size();
	visited = vector<int>(n, 0);
	int components = 0;
    for(int i=0; i<n; i++){
       		if(visited[i] == 0){
   			components++;
       		dfs(i);
       	}
    }
    return components;
}

void distanceDfs(int s, int val){
	if(visited[s] == 1) return;
	visited[s] = 1;
	distances[s] = val;
	for(int i=0; i<g[s].size(); i++){
		distanceDfs(g[s][i], val + 1);
	}
}

vector<int> treeDistances(int s){
	int n = g.size();
	distances = vector<int>(n, 0);
	visited = vector<int>(n, 0);

	distanceDfs(s, 0);
	return distances;
}

void printGraph(){
	for(int i=0; i<g.size(); i++){
		for(int j=0; j<g[i].size(); j++){
			cout << i + 1 << " " << g[i][j] + 1 << "\n";
		}
	}
	cout << "\n";
}

bool bipartite(int s, int color){
	visited[s] = 1;
	bipartiteColor[s] = color;
	for(int i=0; i<g[s].size(); i++){
		if(!visited[g[s][i]]){
			if(bipartite(g[s][i], color ^ 1) == false) return false;
		}else if(bipartiteColor[s] == bipartiteColor[g[s][i]]) 
			return false;
	}
	return true;
}

bool detectCycle(int s, int parent){ 
	visited[s] = 1;
	for(int i=0; i<g[s].size(); i++){
		if(visited[g[s][i]] == 0){
			if(detectCycle(g[s][i], s) == true) return true;
		}else if(g[s][i] != parent) return true;
	}
	return false;
}

vector<int>in, out;
int timer = 1;
void dfsInOut(int s){
	in[s] = timer++;
	visited[s] = 1;
	for(int i=0; i<g[s].size(); i++){
		if(!visited[g[s][i]]){
			dfsInOut(g[s][i]);
		}
	}
	out[s] = timer++;
}

/* 
	If A lies in the subtree of B, then the intime of B(root) < A
	If A lies in the subtree of B, then the outtime of B(root) > A
*/

int treeDiameter(){
	int root = 0;
	vector<int>distances = treeDistances(0);
	int max = distances[0];
	int maxIndex = 0;
	for(int i=0; i<distances.size(); i++){
		if(distances[i] > max){
			max = distances[i];
			maxIndex = i;
		}
	}
	vector<int>finalDist = treeDistances(maxIndex);
	max = finalDist[0];
	maxIndex = 0;
	for(int i=0; i<finalDist.size(); i++){
		if(finalDist[i] > max){
			max = finalDist[i];
			maxIndex = i;
		}
	}
	return max;
}

/* 
	Requires Rooted Tree: Hence technically Directed Graph.
	So, add only g[u].push_back(v) line.
*/

int subtreeSize(int n){
	int size = 1;
	visited[n] = 1;
	for(int i=0; i<g[n].size(); i++){
		if(!visited[g[n][i]])
		size += subtreeSize(g[n][i]);
	}
	subtreeSizes[n] = size;
	return size;
}

void bfs(int s){	
	queue<int>bfsq;
	bfsq.push(s);
	visited[s] = 1;
	distances[s] = 0; 
	while(!bfsq.empty()){
		int node = bfsq.front();
		cout << node + 1 << " ";
		bfsq.pop();
		for(int i=0; i<g[node].size(); i++){
			if(!visited[g[node][i]]){
				distances[g[node][i]] = distances[node] + 1;
				visited[g[node][i]] = 1;
				bfsq.push(g[node][i]);
			}
		}
	}
}

int32_t main(){
    init();
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int t; cin >> t;
    for(int l=1; l<=t; l++){
        int n, m; cin >> n >> m;
        g = vector<vector<int>>(n, vector<int>());
        while(m--){
        	int u, v; cin >> u >> v;
        	u--; v--;
        	// Undirected. For directed, remove Line 2
        	g[u].push_back(v);
        	//g[v].push_back(u);
        }
        /*
			Using 0 indexed completely in all implementations.
			Only when printing/output, converting back to 1 indexed.
        */
       	
       	visited = vector<int>(n, 0);
     	
    }   
}