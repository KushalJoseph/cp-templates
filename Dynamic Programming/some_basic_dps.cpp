/* Main CP File */
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define M 1000000007

void init(){
    #ifndef ONLINE_JUDGE 
    freopen("../input.txt", "r", stdin); 
    freopen("../output.txt", "w", stdout); 
    #endif 
}
class Timer{private: chrono::time_point <chrono::steady_clock> Begin, End; public: Timer () : Begin(), End (){ Begin = chrono::steady_clock::now(); } ~Timer (){ End = chrono::steady_clock::now();cerr << "\nDuration: " << ((chrono::duration <double>)(End - Begin)).count()<< "s\n"; } }T;
void printvec(vector<int>arr){for(int i=0; i<arr.size(); i++)cout << arr[i] << " "; cout << "\n";}
/*-----------------------------------------------------------------------------------*/


int staircaseFibRecursion(int n){ // 3 instead of 2
    vector<int>dp(n+1);
    dp[0] = -1; // Invalid
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for(int i=4; i<=n; i++){
        dp[i] = (dp[i-1] + dp[i-2] + dp[i-3]) % M;
    }
    return dp[n];
}

int coinChange(vector<int>coins, int amount){
    int INF = amount + 1;  
    int dp[amount + 1];
    for(int i=0; i<amount+1; i++){
        dp[i] = INF;
    }
    dp[0] = 0;
    for(int i=1; i<=amount; i++){
        for(int j=0; j<coins.size(); j++){
            if(i >= coins[j])
            dp[i] = min(dp[i], dp[i - coins[j]] + 1);
        }
    }
    if(dp[amount] == INF){
        return -1;
    }
    return dp[amount];
}

int min3(int a, int b, int c){
    if(a < b) if(a < c)return a; else return c;
    else if(b < c) return b; else return c;
}
int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size(), m = matrix[0].size();    
    for(int i=1; i<n; i++){
        for(int j=0; j<m; j++){
            if(j != 0 && j != n-1)
            matrix[i][j] += min3(matrix[i-1][j-1], matrix[i-1][j], matrix[i-1][j+1]);
            else if(j == 0)
            matrix[i][j] += min(matrix[i-1][j], matrix[i-1][j+1]);
            else
            matrix[i][j] += min(matrix[i-1][j-1], matrix[i-1][j]);
        }
    }
       
    int minVal = matrix[n-1][0];
    for(int i=0; i<m; i++){
        if(matrix[n-1][i] < minVal) minVal = matrix[n-1][i];
    }
    return minVal;
}

int gridMinPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        
        for(int i=1; i<m; i++){
            grid[0][i] += grid[0][i-1];
        }
        
        for(int i=1; i<n; i++){
            grid[i][0] += grid[i-1][0];
        }
        
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
            }
        }
        
        return grid[n-1][m-1];
    }

int subsetSum(vector<int>set, int sum){
    vector<int>dp(sum + 1, 0);
    dp[0] = 1;
    for(int i=0; i<set.size(); i++){
        for(int j=sum; j>=i; j--){
            if(j - set[i] >= 0)
            if(dp[j] || dp[j - set[i]] == 0){
                continue;
            }else{
                dp[j] = set[i];
            }
        }
    }
    printvec(dp);
    if(dp[sum] == 0)
    return -1;
    else{
        int cur = sum;
        while(cur > 0){
            cout << dp[cur] << " ";
            cur -= dp[cur];
        }
    }
    return 1;
}

int maxSubarraySum(vector<int>arr){
    int n = arr.size();
    vector<int>dp(n);
    dp[0] = arr[0];
    int max = dp[0];
    for(int i=1; i<n; i++){
        if(dp[i-1] > 0){
            dp[i] = dp[i-1] + arr[i];
        }else{
            dp[i] = arr[i];
        }
        if(dp[i] > max) max = dp[i];
    }
    return max;
}



int32_t main(){
    init();
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int t; cin >> t;
    for(int l=1; l<=t; l++){
        int n, sum; cin >> n >> sum;
        vector<int>arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];

        cout << coinChange(arr, sum) << "\n";
    }

}