#include <bits/stdc++.h>
using namespace std;
#define int long long int

void init(){
    #ifndef ONLINE_JUDGE 
    freopen("../input.txt", "r", stdin); 
    freopen("../output.txt", "w", stdout); 
    #endif 
}

/*
	In this file:
--> Kosaraju, basic dfs and transpose dfs
--> Tarjan and tarjanDfs

*/

vector<vector<int>>g;
vector<vector<int>>transpose;
vector<int>visited;
vector<int>order;

vector<int>SCC;

void printGraph(){
	for(int i=0; i<g.size(); i++){
		for(int j=0; j<g[i].size(); j++){
			cout << i + 1 << " " << g[i][j] + 1 << "\n";
		}
	}
	cout << "\n";
}

void dfs(int s){
	if(visited[s] == 1) return;
	visited[s] = 1;
	for(int i=0; i<g[s].size(); i++){
		if(visited[g[s][i]] == 0)
		dfs(g[s][i]);
	}
	order.push_back(s);
}

void dfsTranspose(int s){
	if(visited[s] == 1) return;
	visited[s] = 1;
	for(int i=0; i<transpose[s].size(); i++){
		if(visited[transpose[s][i]] == 0)
		dfsTranspose(transpose[s][i]);
	}
	SCC.push_back(s);
}

void kosaraju(){
	for(int i=0; i<g.size(); i++){
		if(!visited[i]){
			dfs(i);
		}
	}

	visited = vector<int>(g.size(), 0);
	for(int i=order.size()-1; i>=0; i--){
		if(visited[order[i]] == 0){
			SCC.clear();
			dfsTranspose(order[i]);
			cout << "Called from " << order[i] + 1 << " and SCC is: ";
			for(int i=0; i<SCC.size(); i++){
				cout << SCC[i] + 1 << " ";
			}
			cout << "\n";
		}
	}
}

vector<int>in, low;
vector<bool>inStack;
stack<int>st;
int timer;
int SCCcount;

void tarjanDfs(int s){
	if(visited[s] == 1) return;
	visited[s] = 1;
	in[s] = low[s] = timer++;
	inStack[s] = 1;
	st.push(s);

	for(int i=0; i<g[s].size(); i++){
		if(visited[g[s][i]] == 1 && inStack[g[s][i] == true]){
			low[s] = min(low[s], in[g[s][i]]);
		}else{
			tarjanDfs(g[s][i]);
			if(inStack[g[s][i]] == true)
			low[s] = min(low[s], low[g[s][i]]);
		}
	}

	// All paths visited from current node, check for SCC
	if(in[s] == low[s]){
		SCCcount++; int iter = 1000;
		while(st.top() != s && iter > 0){
			int node = st.top();
			cout << node + 1 << " ";
			inStack[node] = false;
			st.pop();
			iter--;
		}
		inStack[s] = false;
		cout << s + 1 << "\n";
		st.pop();
	}
}


void tarjan(){
	in = low = vector<int>(g.size());
	inStack = vector<bool>(g.size(), 0);

	for(int i=0; i<g.size(); i++){
		if(!visited[i]){
			tarjanDfs(i);
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
        transpose = vector<vector<int>>(n, vector<int>());
        while(m--){
        	int u, v; cin >> u >> v;
        	u--; v--;
        	g[u].push_back(v);
        	transpose[v].push_back(u);
        }
        /*
			Using 0 indexed completely in all implementations.
			Only when printing/output, converting back to 1 indexed.
        */
       	visited = vector<int>(n, 0);
     	kosaraju();
     	/*visited = vector<int>(n, 0);
     	cout << "\n";
     	tarjan();*/
     	
    }   
}