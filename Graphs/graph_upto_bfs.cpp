#include <bits/stdc++.h>
using namespace std;
#define null NULL

class Graph{
    public:
    int v;
    vector<vector<int>>adj;
    vector<bool>visited;
    
    Graph(int v){
        this->v=v;
        for(int i=1;i<=v;i++){
            vector<int>newVec;
            adj.push_back(newVec);
            visited.push_back(false);
        }
    }
    
    void addEdge(int u,int v){
        adj[u].push_back(v);
    }
    
    vector<int>neighbours(int i){
        return adj[i];
    }
    
    void printAll(){
        for(int i=0;i<adj.size();i++){
            cout<<"Vertices adj to "<<i<<" are: ";
            for(int j=0;j<adj[i].size();j++){
                cout<<adj[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    
    void dfs(int at){
        if(visited[at]==true)return;
        visited[at]=true;
        cout<<at<<" ";
        for(int i=0;i<adj[at].size();i++){
            dfs(adj[at][i]);
        }
    }
    
    void bfs(int at){
        vector<bool>visited;
        for(int i=1;i<=v; i++)visited.push_back(false);
     
        queue<int>q;
    
        visited[at]=true;
        q.push(at);
     
        while(!q.empty())
        {
            int cur=q.front();
            cout<<cur<< " ";
            q.pop();
    
            for(int i=0;i<adj[cur].size();i++)
            {
                if (!visited[adj[cur][i]])
                {
                    visited[adj[cur][i]]=true;
                    q.push(adj[cur][i]);
                }
            }
        }
    }
};


int main()
{
    Graph* g=new Graph(8);
		g->addEdge(0,1);
		g->addEdge(0,2);
		g->addEdge(1,2);
		g->addEdge(1,4);
		g->addEdge(1,7);
		g->addEdge(1,0);
		g->addEdge(2,0);
		g->addEdge(2,7);
		g->addEdge(2,3);
		g->addEdge(2,1);
		g->addEdge(3,2);
		g->addEdge(3,4);
		g->addEdge(3,6);
		g->addEdge(3,5);
		g->addEdge(4,1);
		g->addEdge(4,3);
		g->addEdge(4,5);
		g->addEdge(5,4);
		g->addEdge(5,3);
		g->addEdge(6,3);
		g->addEdge(7,1);
		g->addEdge(7,2);
		g->printAll();cout<<"\n";
		g->dfs(3);cout<<"\n";
		//for(int i=0;i<g->neighbours(4).size();i++)cout<<g->neighbours(4)[i]<<" ";
		g->bfs(3);
        cout<<"\n";
}
