#include <bits/stdc++.h>
#define 	mod 		1000000007
#define 	enl 		"\n"
#define 	pc(i,o) 	cout << "Case " << (i+1) << ": " << o << enl
#define 	rep(i,a,n) 	for(int i = a; i<n; i++)

using namespace std;

long _gcd(long a, long b) { return b == 0 ? a : _gcd(b, a % b); } 

long mod_pow( long b, long e)
{
    long r = 1;
    long pow = b % mod;
    while( e > 0 )
    {
        if( e&1 ) r = ( r*pow )%mod;
        pow = ( pow*pow )%mod;
        e >>= 1;
    }
    return r;
}

long inv( long x )
{
    return mod_pow( x, mod-2 );
}

long solve(long n, int k){
	long res = 0;

	rep(i,0,n)
		res = (res % mod + mod_pow(k,_gcd(i,n)) % mod) % mod;

	res = (res % mod * inv(n) % mod) % mod;
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t,k;
	long n;
	cin >> t;
	rep(i,0,t){
		cin >> n >> k;
		pc(i,solve(n,k));
	}
	return 0;
}