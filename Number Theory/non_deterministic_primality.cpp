#include <bits/stdc++.h>
using namespace std;
#define int long long
#define null NULL

void init(){
    #ifndef ONLINE_JUDGE 
	freopen("../input.txt", "r", stdin); 
	freopen("../output.txt", "w", stdout); 
	#endif 
}

/*
	File contains:
--> Fermat's Primality Test

*/

int pow(int a, int n, int mod){
	int res = 1;
	while(n){
		if(n % 2 == 0){
			n /= 2;
			a = (a * a) % mod;
		}else{
			n--;
			res = (res * a) % mod;
		}
	}
	return res;
}

/* Complexity: Log(N) */
int fermatPrimality(int n){
	int iter = 5;
	if(n <= 4){
		return n == 2 || n == 3;
	}
	for(int i=1; i<=iter; i++){
		int a = 2 + rand() % (n-3);
		if(pow(a, n-1, n) != 1){
			return 0;
		}
	}
	return 1;
}


int32_t main(){
	init();
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	for(int l=1; l<=t; l++){
		int n; cin >> n;
		cout << fermatPrimality(n) << "\n";
	}
}