#include <bits/stdc++.h>
using namespace std;
#define int long long int

/*
------IN THIS FILE-----
-> Is Prime?
-> Sieve of Eratosthenes - All primes until N
-> Segmented Sieve - All primes between L and R
-> Prime Factors
    i. Brute Force Method
    ii. Better Method
    iii. Sieve Method
-> Pow(A, N)
-> Modular Exponentiation (Binary)

*/

void init(){
    #ifndef ONLINE_JUDGE 
	freopen("../input.txt", "r", stdin); 
	freopen("../output.txt", "w", stdout); 
	#endif 
}

bool isPrime(int n){
	if(n == 1 || n == 0){
		return false;
	}
	for(int i=2; i*i<=n; i++){
		if(n % i == 0){
			return false;
		}
	}
	return true;
}

void sieveOfEratosthenes(int n){
	vector<bool>is_prime(n+1,true);
	is_prime[0] = false; is_prime[1] = false;
	for(int i=2; i*i<=n; i++){
		if(is_prime[i] == true){
			for(int j=i*i; j<=n; j += i){
				is_prime[j] = false;
			}
		}
	}
	for(int i=0; i<n+1; i++){
		if(is_prime[i]){
			cout << i << " ";
		}
	}
}

void segmentedSieve(int L, int R){
	
}

void primeFactorsBrute(int n){
	for(int i=2; i<=n; i++){
		if(n % i == 0){
			int count = 0;
			while(n % i == 0){
				count++;
				n /= i;
			}
			cout << i << "^" << count << "*";
		}
	}
}

void primeFactors(int n){
	for(int i=2; (i * i <= n); i++){
		if(n % i == 0){
			int count = 0;
			while(n % i == 0){
				count++;
				n /= i;
			}
			cout << i << "^" << count << "*";
		}
	}
	if(n > 1){
		cout << n << "^" << 1;
	}
}

vector<int>sieve_table;
void createSieve(int n){
	sieve_table = vector<int>(n+1, -1);
	for(int i=2; i*i<=n; i++){
		if(sieve_table[i] == -1){
			for(int j=i; j<=n; j += i){
				if(sieve_table[j] == -1){
					sieve_table[j] = i;
				}
			}
		}
	}
}
vector<int> sieveFactorization(int n){
	vector<int>primeFactors;
	if(sieve_table[n] == -1){
		return primeFactors;
	}else{
		while(sieve_table[n] != -1){
			primeFactors.push_back(sieve_table[n]);
			n /= sieve_table[n];
		}
		if(n != 1 && n != 0){
			primeFactors.push_back(n);
		}
	}
	return primeFactors;
	/* If primeFactors returned is null, then it is a prime*/
}

int64_t power(int a, int b){
	int res = 1;
	while(b){
		if(b % 2 == 0){
			b /= 2;
			a *= a;
		}else{
			res *= a;
			b--;
		}
	}
	return res;
}

int64_t modularExponent(int a, int b, int mod){
	int res = 1;
	while(b){
		if(b % 2 == 0){
			b /= 2;
			a = (a*a) % mod;
		}else{
			res = (res*a) % mod;
			b--;
		}
	}
	return res;
}

int32_t main(){
	init();
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	createSieve(60000);
	for(int l=1; l<=t; l++){
		//int a; cin >> a;
		//int b; cin >> b;
		//cout << power(a,b) << "\n";
		//cout << isPrime(b) << "\n";
		//sieveOfEratosthenes(b);
		/*int k; cin >> k;
		vector<int>factors = sieveFactorization(k);
		for(int i=0; i<factors.size(); i++) cout << factors[i] << " ";
		cout << "\n";*/
		int n; cin >> n;
		cout << isPrime(n) << "\n";
	}
	
}