/* Main CP File */
#include <bits/stdc++.h>
#define int long long 
#define pb push_back
#define MOD 1000000007
#define INF 100000000000
#define in(n) int n; cin >> n
#define in2(n, m) int n, m; cin >> n >> m
#define in3(x, y, z) int x, y, z; cin >> x >> y >> z
#define inarr(arr, n) vector<int>arr(n); for(int i=0; i<n; i++) cin >> arr[i];
#define printarr(arr) for(int i=0; i<arr.size(); i++) cout << arr[i] << " "; cout << "\n";
using namespace std;

void init(){
    #ifndef ONLINE_JUDGE 
    freopen("../input.txt", "r", stdin); 
    freopen("../output.txt", "w", stdout); 
    #endif 
}
class Timer{private: chrono::time_point <chrono::steady_clock> Begin, End; public: Timer () : Begin(), End (){ Begin = chrono::steady_clock::now(); } ~Timer (){ End = chrono::steady_clock::now();cerr << "\nDuration: " << ((chrono::duration <double>)(End - Begin)).count()<< "s\n"; } }T;
/*-----------------------------------------------------------------------------------*/

bool ithBitSet(int n, int i){
    int f = 1;
    f <<= i;
    return n & f;
}

int setBits(int n){
    int f = 1, cnt = 0;
    while(f <= n){
        if(f & n) cnt++;
        f <<= 1;
    }
    return cnt;
}

int setBitsLitleFaster(int n){
    int cnt = 0;
    // Runs while there is atleast one set bit.
    while(n > 0){
        cnt++;
        n = n & (n-1);
    }
    return cnt;
}

int32_t main(){
    init();
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int t; cin >> t;
    for(int l=1; l<=t; l++){
        in(n);
        //cout << ithBitSet(n, i) << "\n";
        cout << setBitsLitleFaster(n) << "\n";
    }
}