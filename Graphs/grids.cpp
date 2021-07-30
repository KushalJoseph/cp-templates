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
--> Simple validPoint() function
--> DFS
--> Components count
--> BFS + SSSP

*/

vector<vector<int>>g;
vector<vector<int>>visited;

void printGrid(){
	for(int i=0; i<g.size(); i++){
		for(int j=0; j<g[i].size(); j++){
			cout << g[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

// Up, Right, Down, Left.
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

bool validPoint(int x, int y){
	if(x < 0 || x >= g.size() || y < 0 || y >= g[0].size()) return false;

    /* For grid components remove the comments put below */
	if(visited[x][y] == 1 /*|| g[x][y] == 0*/) return false;
	else return true;
}

void dfs(int x, int y){
	if(validPoint(x, y)){
		visited[x][y] = 1;
		cout << g[x][y] << " ";
	}
	for(int i=0; i<4; i++){
		if(validPoint(x + dx[i], y + dy[i])){
			dfs(x + dx[i], y + dy[i]);
		}
	}
}

int components(){
	int components = 0;
	for(int i=0; i<visited.size(); i++){
		for(int j=0; j<visited[0].size(); j++){
			if(g[i][j] == 1 && visited[i][j] == 0){
				components++;
				dfs(i, j);
			}
		}
	}
	return components;
}

vector<vector<int>>distances;
void bfs(int x, int y){
	distances = vector<vector<int>>(g.size(), vector<int>(g[0].size()));
	queue<pair<int,int>>q;
	if(validPoint(x, y)) visited[x][y] = 1, distances[x][y] = 0;
	else {cout << "Invalid Point"; return;}
	
	q.push({x, y});
	while(!q.empty()){
		pair<int, int>p = q.front(); q.pop();
		int curx = p.first, cury = p.second;
		visited[curx][cury] = 1;
		cout << g[curx][cury] << " ";
		for(int i=0; i<4; i++){
			if(validPoint(curx + dx[i], cury + dy[i])){
				q.push({curx + dx[i], cury + dy[i]});
				visited[curx + dx[i]][cury + dy[i]] = 1;
				distances[curx + dx[i]][cury + dy[i]] = distances[curx][cury] + 1;
			} 	
		}
	}
}


int32_t main(){
    init();
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int t; cin >> t;
    for(int l=1; l<=t; l++){
        int r, c;
        cin >> r >> c;
        g = vector<vector<int>>(r, vector<int>(c));
        visited = vector<vector<int>>(r, vector<int>(c, 0));
        for(int i=0; i<r; i++){
        	for(int j=0; j<c; j++){
        		cin >> g[i][j];
        	}
        }
        

    }   
}