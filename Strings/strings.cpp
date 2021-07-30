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

/*
    File Includes:
--> Basic substring check using sliding window
--> Basic String hashing (Polynomial)
--> Hash init and substring hash in O(1)
--> KMP Naive, proper
--> Substring check using KMP
--> Z-Function Naive

*/


bool substring(string s, string patt){
    bool matched = false;
    for(int i=0, j=patt.length()-1; j<s.length(); i++, j++){
        bool window = true;
        for(int k=i; k<i+patt.length(); k++){
            if(s[k] != patt[k-i]){
                window = false; break;
            }
        }
        if(window){
            cout << i << " "; matched = true;
        }
    }
    return matched;
}


int basicHash(string s){
    int val = 0;
    int p = 31;
    int p_power = 1;

    for(char ch: s){
        val = (val + (ch - 'a' + 1) * p_power) % MOD;
        p_power = (p_power * p) % MOD;
    }
    return val;
    /* O(N) for each query */
}


int power(int a, int n){
    int res = 1;
    while(n > 0){
        if(n % 2 == 0){
            n /= 2; a = (a * a) % MOD;
        }else{
            n--; res = (res * a) % MOD;
        }
    }
    return res;
}

vector<int>inversemod;
vector<int>dp;
void hash_init(string s){
    inversemod = dp = vector<int>(s.length());
    inversemod[0] = 1;
    dp[0] = (s[0] - 'a' + 1) % MOD;
    int p = 31; // Assuming all small letters
    int p_power = 1;

    for(int i=1; i<s.length(); i++){
        char ch = s[i];
        p_power = (p_power * p) % MOD;
        inversemod[i] = power(p_power, MOD - 2);
        // Inverse mod of p^i for all i, because we need to do x../ p^i
        dp[i] = (dp[i-1] + (ch - 'a' + 1) * p_power) % MOD;
    }
}

int substringHash(int l, int r){
    int result = dp[r];
    if(l > 0) result -= dp[l-1];
    result = (result * inversemod[l]) % MOD;
    return result; 
}


vector<int> kmp_naive(string s){
    int n = s.length();
    vector<int>pi(n);
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            if(s.substr(0, j) == s.substr(i - j + 1, j)){
                pi[i] = j;
            }
        }
    }
    return pi;
}

vector<int> kmp(string s){
    int n = s.length();
    vector<int>pi(n);
    for(int i=1; i<n; i++){
        int j = pi[i-1];
        while(j > 0 && s[i] != s[j]){
            j = pi[j-1];
        }  
        if(s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}

int substringKMP(string s, string pattern){
    int num = 0;
    string temp = pattern + "#" + s;
    vector<int>pi = kmp(temp);
    for(int i=0; i<pi.size(); i++){
        if(pi[i] == pattern.length()){
            cout << i - 2 * pattern.length() << " ";
            num++;
        }
    }
    return num;
}

vector<int> zfunction_naive(string s){
    int n = s.length();
    vector<int>z(n);

    z[0] = 0;
    for(int i=1; i<n; i++){
        for(int j=i; j<n; j++){
            if(s[j-i] == s[j]) z[i]++;
            else break;
        }
    }
    return z;
}


int32_t main(){
    init();
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int t; cin >> t;
    cin.ignore();
    for(int l=1; l<=t; l++){
        string s; cin >> s;
        string pat; cin >> pat;
        
    }
}