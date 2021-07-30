/* Main CP File */
#include <bits/stdc++.h>
#define int long long 
#define MOD 1000000007
#define pb push_back
#define all(a) a.begin(), a.end()
#define printarr(arr) for(int i=0; i<arr.size(); i++) cout << arr[i] << " "; cout << "\n";
using namespace std;

void init(){
    #ifndef ONLINE_JUDGE 
    freopen("../input.txt", "r", stdin); 
    freopen("../output.txt", "w", stdout); 
    #endif 
}
class Timer{private: chrono::time_point <chrono::steady_clock> Begin, End; public: Timer () : Begin(), End (){ Begin = chrono::steady_clock::now(); } ~Timer (){ End = chrono::steady_clock::now();cerr << "\nDuration: " << ((chrono::duration <double>)(End - Begin)).count()<< "s\n"; } }T;
/*----------------------------------------------------------------------------------*/

int pairsWithSum(vector<int>arr, int sum){

    int n = arr.size();
    int ans = 0;
    int i = 0, j = n - 1;
 
    while (i < j) {
        if (arr[i] + arr[j] < sum) i++;
        else if (arr[i] + arr[j] > sum) j--;
        else {
            int x = arr[i], xx = i;
            while (i < j and arr[i] == x){
                i++;
            }
            int y = arr[j], yy = j;
            while (j >= i and arr[j] == y){
                j--;
            }
            if (x == y) {
                int temp = i - xx + yy - j - 1;
                ans += (temp * (temp + 1)) / 2;
            }
            else
                ans += (i - xx) * (yy - j);
        }
    }
    return ans;
}


int32_t main(){
    init();
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int t; cin >> t;
    for(int l=1; l<=t; l++){
        
    }
}