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
--> GCD-Extended algorithm to find sol of ax + by = g(a, b)
--> LDA Solution algorithm to find sol of ax + by = c

*/

int gcd_extended(int a, int b, int& x, int& y){
	if(b == 0){
		x = 1; y = 0; // Base case equation solution
		return a; 
	}
	int x1, y1;
	int gcd_n = gcd_extended(b, a % b, x1, y1);
	x = y1;
	y = x1 - y1 * (a/b);
	return gcd_n;
}

int diophantineSolution(int a, int b, int c, int& x, int& y){
	int x0, y0;
	int g = gcd_extended(abs(a), abs(b), x0, y0);
	if(c % g != 0){
		return 0;
	}
	x = x0 * c/g;
	y = y0 * c/g;
	if(a < 0) x = -x;
	if(b < 0) y = -y;
	return 1;
}


int32_t main(){
	init();
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	for(int l=1; l<=t; l++){
		int a, b, c; // ax + by = c
		int x, y;
		cin >> a >> b >> c;
		if(diophantineSolution(a, b, c, x, y) == 0){
			cout << "No solution possible" << "\n"; continue;
		}else{
			cout << "Solution: x = " << x << ", y = " << y << "; \n";
		}
	}
}