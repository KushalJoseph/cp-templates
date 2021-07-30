/* Main CP File */
#include <bits/stdc++.h>
#define int long long 
#define pb push_back
#define M 1000000007
#define INF 100000000000
#define in(n) int n; cin >> n
#define in2(n, m) int n, m; cin >> n >> m
#define in3(x, y, z) int x, y, z; cin >> x >> y >> z
#define arrin(arr, n) vector<int>arr(n); for(int i=0; i<n; i++) cin >> arr[i];
#define printarr(arr) for(int i=0; i<n; i++) cout << arr[i] << " "; cout << "\n";
using namespace std;

void init(){
    #ifndef ONLINE_JUDGE 
    freopen("../input.txt", "r", stdin); 
    freopen("../output.txt", "w", stdout); 
    #endif 
}
class Timer{private: chrono::time_point <chrono::steady_clock> Begin, End; public: Timer () : Begin(), End (){ Begin = chrono::steady_clock::now(); } ~Timer (){ End = chrono::steady_clock::now();cerr << "\nDuration: " << ((chrono::duration <double>)(End - Begin)).count()<< "s\n"; } }T;
/*-----------------------------------------------------------------------------------*/

vector<int>parent;
vector<int>rankArr;

int find(int n){
    if(parent[n] < 0) return n; // N is already a parent;
    parent[n] = find(parent[n]);
    return parent[n];
}

void unionByRank(int a, int b){
    a = find(a); b = find(b);
    if(a == b) return;

    if(rankArr[a] > rankArr[b]){
        parent[b] = a; 
        rankArr[a] += rankArr[b];
    }else{
        parent[a] = b; 
        rankArr[b] += rankArr[a];
    }
}


int32_t main(){
    init();
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int t; cin >> t;
    for(int l=1; l<=t; l++){
        int n; cin >> n;
        parent = vector<int>(n+1);
        rankArr = vector<int>(n+1);
        parent[0] = rankArr[0] = -1; // Invalid
        for(int i=1; i<=n; i++){
            parent[i] = -1;
            rankArr[i] = 1;
        }
        unionByRank(1, 4);
        unionByRank(1, 5);
        unionByRank(1, 6);
        unionByRank(1, 3);
        for(int i=1; i<=n; i++){
            cout << parent[i] << " ";
        }cout << "\n";
        for(int i=1; i<=n; i++){
            cout << rankArr[i] << " ";
        }
    }
}