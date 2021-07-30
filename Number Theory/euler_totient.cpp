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
--> Initialize euler_phi Array 
--> Phi without using phi Array
--> Gcd Sum problem and supplemtary functions

*/

vector<int>euler_phi;

void initPhi(int n){
	euler_phi = vector<int>(n+1);
	for(int i=0; i<=n; i++) euler_phi[i] = i;

	for(int i=2; i<=n; i++){
		if(euler_phi[i] == i){
			// It is a prime
			for(int j=i; j<=n; j += i){
				euler_phi[j] /= i;
				euler_phi[j] *= (i-1);
			}
		}
	}
}

int phi(int n){
	int res = n;
	for(int i=2; i*i<=n; i++){
		if(n % i == 0){
			res /= i;
			res *= (i-1); // Refer formula
		}
		while(n % i == 0){
			n /= i;
		}
	}
	if(n > 1){
		res /= n;
		res *= (n-1); // If Final Prime number =! 1
	}
	return res;
}

int count(int factor, int n){
	/* 
	   This function return the count of numbers from 1 to n, such 
	   that GCD(i, N) == factor.
	   The params are the factor, and the number n.
	*/
	return euler_phi[n/factor];
}
int gcdSum(int n){
	int res = 0;
	for(int i=1; i*i<=n; i++){
		if(n % i == 0){
			int factor1 = i;
			int factor2 = n/i;

			res += factor1 * count(factor1, n);
			if(factor1 != factor2){
				res += factor2 * count(factor2, n);
			}
		}
	}
	return res;
}

int32_t main(){
	init();
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int t; cin >> t;

	initPhi(100000);
	for(int l=1; l<=t; l++){
		int n; cin >> n;
		//cout << euler_phi[n] << "\n";
		cout << gcdSum(n) << "\n";
	}
}