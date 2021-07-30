#include <bits/stdc++.h>
using namespace std;
#define int long long
#define null NULL
#define MOD (int) 1000000007

void init(){
    #ifndef ONLINE_JUDGE 
	freopen("../input.txt", "r", stdin); 
	freopen("../output.txt", "w", stdout); 
	#endif 
}

/* log(max(a, b)) */
int gcd(int a, int b){
	if(b == 0) return a;
	else return gcd(b, b%a);
}

int pow(int a, int n){
	int res = 1;
	while(n){
		if(n % 2 == 0){
			n /= 2;
			a = (a * a) % MOD;
		}else{
			n--;
			res = (res * a) % MOD;
		}
	}
	return res;
}

int moduloinverse(int a, int m){
	return pow(a, m-2);
}

vector<int>factorials;
void computeFactorials(int n){
	factorials = vector<int>(n+1);
	factorials[0] = factorials[1] = 1;
	for(int i=2; i<=n; i++){
		factorials[i] = (factorials[i-1] * i) % MOD;
	}
}

int ncr(int n, int r){
	if(r > n) return 0;
	int res = factorials[n];
	res = (res * moduloinverse(factorials[r], MOD)) % MOD;
	res = (res * moduloinverse(factorials[n-r], MOD)) % MOD;
	return res;
}

int32_t main(){
	init();
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	computeFactorials(1000000);
	int t; cin >> t;
	for(int l=1; l<=t; l++){
		int n, r; cin >> n >> r;
		cout << ncr(n, r) << "\n";
	}
}