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
--> Find BRIDGES in the graph
--> Find CUT VERTICES in the graph
--> Topological Sorting (For Directed Graphs Only)
	 
	For trees (Directed acyclic):
--> DFS For LCA
--> Naive LCA Algorithm
--> LCA Binary Lifting - Precalc function
--> LCA Binary Lifting
--> Distance between nodes in a tree in log(N) using LCA

*/

vector<vector<int>>g;
vector<int>visited;

void printGraph(){
	for(int i=0; i<g.size(); i++){
		for(int j=0; j<g[i].size(); j++){
			cout << i + 1 << " " << g[i][j] + 1 << "\n";
		}
	}
	cout << "\n";
}

vector<int>in, low;
int timer;
bool bridgesYesOrNo = false;
void bridges(int node, int parent = -1){
	visited[node] = 1;
	in[node] = low[node] = timer++;

	for(int child: g[node]){
		if(visited[child] == 1){
			if(child == parent) continue;
			
			low[node] = min(low[node], in[child]);
		}else{
			bridges(child, node);
			if(low[child] > in[node]){
				bridgesYesOrNo = true;
				cout << node + 1 << "-->" << child + 1 << " is a Bridge.\n";
			}
			// Current node would also try to reduce its minimum
			low[node] = min(low[node], low[child]);
		}
	}
}

bool cutVerticesOrNot = false;
void cutVertices(int node, int parent = -1){
	visited[node] = true;
	in[node] = low[node] = timer++;
	int children = 0;
	for(int child: g[node]){
		if(visited[child] == 1){
			if(child == parent) continue;
			else low[node] = min(low[node], in[child]);
		}else{
			cutVertices(child, node);
			if(low[child] >= in[node] && parent != -1){
				cout << node + 1 << " is a Cut Vertex.\n";
			}

			low[node] = min(low[node], low[child]);
			children++;
		}
	}
	if(parent == -1 && children > 1){
		cout << node + 1 << " is a Cut Vertex\n";
	}
}

vector<int>indegree;
vector<int> topsort(){
	vector<int>ans;
	queue<int>q;
	for(int i=0; i<indegree.size(); i++){
		if(indegree[i] == 0) q.push(i);
	}

	while(!q.empty()){
		int cur = q.front();
		q.pop();
		ans.push_back(cur);

		for(int i=0; i<g[cur].size(); i++){
			indegree[g[cur][i]]--;
			if(indegree[g[cur][i]] <= 0) q.push(g[cur][i]);
		}
	}
	return ans;
}

vector<int>depths;
vector<int>parent;

void dfs_lca(int s = 0){
	if(visited[s] == 1) return;
	visited[s] = 1;
	if(s == 0){
		depths[s] = 0; 	parent[s] = -1;
	}
	for(int i=0; i<g[s].size(); i++){
		depths[g[s][i]] = depths[s] + 1;
		parent[g[s][i]] = s;
		dfs_lca(g[s][i]);
	}
}

int lca_naive(int a, int b){
	depths = parent = vector<int>(g.size());
	dfs_lca();
	
	if(depths[a] < depths[b]) swap(a, b);
	int diff = abs(depths[a] - depths[b]);
	while(depths[a] > depths[b]){
		a = parent[a];
	}
	if(a == b){
		return b;
	}
	while(parent[a] != parent[b]){
		a = parent[a]; b = parent[b];
	}
	return parent[a];
}

vector<vector<int>>LCA;
int maxN;
void lca_precalc(){
	int n = g.size();
	depths = parent = vector<int>(n);
	dfs_lca(); // Now; parent is calculated (2^0)

	int maxDepth = depths[0];
	for(int i=1; i<n; i++){
		if(depths[i] > maxDepth) maxDepth = depths[i];
	}
	
	maxN = log2(maxDepth); 
	
	LCA = vector<vector<int>>(n, vector<int>(maxN + 1, -1));
	
	for(int j=0; j<n; j++) LCA[j][0] = parent[j];

	for(int i=1; i<=maxN; i++){ // i represents column (2 ^ j)
		for(int j=0; j<n; j++){ // j represents node
			if(LCA[j][i-1] != -1){
				int parent = LCA[j][i-1];
				LCA[j][i] = LCA[parent][i-1];
			}
		}
	}
}


int lca(int a, int b){
	/* 
		b is the deeper one, which will move up.
		depths[b] must be greater
	*/
	if(depths[b] < depths[a]) swap(a, b);
	int diff = depths[b] - depths[a];
	
	while(diff > 0){
		int i = log2(diff);
		b = LCA[b][i];
		diff -= (1<<i);
	}
	if(a == b) return a;
	
	for(int i=maxN; i>=0; i--){
		if(LCA[a][i] != -1 && (LCA[a][i] != LCA[b][i])){
			a = LCA[a][i]; b = LCA[b][i];
		}
	}
	return LCA[a][0];
}

int treeDistance(int a, int b){
	return depths[a] + depths[b] - 2*depths[lca(a, b)];
}

int32_t main(){
    init();
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int t; cin >> t;
    for(int l=1; l<=t; l++){
        int n, m; cin >> n >> m;
        g = vector<vector<int>>(n, vector<int>());
        //indegree = vector<int>(n, 0);
        while(m--){
        	int u, v; cin >> u >> v;
        	u--; v--;
        	g[u].push_back(v);
        	//indegree[v]++;
        }
        /*
			Using 0 indexed completely in all implementations.
			Only when printing/output, converting back to 1 indexed.
        */
        
        visited = vector<int>(n, 0);
        lca_precalc();
        int a, b;
        cout << treeDistance(a-1, b-1) << "\n"; 
        //cout << lca_naive(a-1, b-1)  + 1;
        
    }
}