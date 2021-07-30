#include <bits/stdc++.h>
using namespace std;
#define int long long int

void init(){
    #ifndef ONLINE_JUDGE 
	freopen("../input.txt", "r", stdin); 
	freopen("../output.txt", "w", stdout); 
	#endif 
}

/*
	File contains:
--> MatMul for same dimension matrices
--> Matrix exponentiation
--> Fibonacci nth term in log(n)

*/

void printmatrix(vector<vector<int>>&m){
	for(int i=0; i<m.size(); i++){
		for(int j=0; j<m[0].size(); j++){
			cout << m[i][j] << " ";
		}
		cout << "\n";
	}
}

vector<vector<int>> matmul(vector<vector<int>>&A, vector<vector<int>>&B, int dim){
	vector<vector<int>>ans(dim, vector<int>(dim));
	for(int i=0; i<dim; i++){
		for(int j=0; j<dim; j++){
			ans[i][j] = 0;
			for(int k=0; k<dim; k++)
				ans[i][j] += A[i][k] * B[k][j];
		}
	}
	return ans;
}

vector<vector<int>> pow(vector<vector<int>>&mat, int power, int dim){
	vector<vector<int>>I(dim, vector<int>(dim));
	for(int i=0; i<dim; i++){
		for(int j=0; j<mat[0].size(); j++){
			if(i == j) I[i][j] = 1;
			else I[i][j] = 0;
		}
	}
	/* Naive: (m^3.n) : while(power--) I = matmul(mat, I, dim); */
	

	/* Binary Exponentiation: m^3.log(n) */
	while(power > 0){
		if(power % 2 == 0){ 
			power /= 2;
			mat = matmul(mat, mat, dim);
		}else{
			I = matmul(mat, I, dim);
			power--;
		}
	}

	return I;
}

int fibonacci(int n){
	vector<vector<int>>transition(2, vector<int>(2));
	transition[0][0] = 0;
	transition[0][1] = 1;
	transition[1][0] = 1;
	transition[1][1] = 1;
	
	transition = pow(transition, n-1, 2);
	return (transition[0][0] + transition[1][0]);
	// Here directly because base[0][0] = base[0][1] = 1;
}

int32_t main(){
	init();
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	for(int l=1; l<=t; l++){
		
		/*int dim; cin >> dim;
		int power; cin >> power;
		vector<vector<int>>mat(dim, vector<int>(dim));
		for(int i=0; i<dim; i++){
			for(int j=0; j<dim; j++){
				cin >> mat[i][j];
			}
		}

		vector<vector<int>>ans = pow(mat, power, dim);
		printmatrix(ans);*/
		
		int n; cin >> n;
		if(n == 1 || n == 2){
			cout << 1 << "\n"; continue;
		}
		cout << fibonacci(n) << "\n";
	}
}