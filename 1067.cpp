#include <bits/stdc++.h>
#define MAX 1000002
#define MOD 1000003
#define rep(i,a,n) for(int i = a; i<n; i++)

using namespace std;

long mod_pow( long b, long e, long mod = MOD )
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
    return mod_pow( x, MOD-2 );
}

long fact[MAX];


void fill(){
	fact[0] = fact[1] = 1;
	rep(i,2,MAX){
		fact[i] = (i % MOD * fact[i-1] % MOD ) % MOD;
	}
}

long solve(long n, long k){
	long res,num,den;
	num = fact[n] % MOD;
	den = ((fact[k] % MOD) * (fact[n-k] % MOD) % MOD);
	den = inv(den) % MOD;
	res = ( num  * den ) % MOD;
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);

	long t,n,k,res;
	fill();
	cin >> t;

	rep(i,0,t){
		cin >> n >> k;
		res = solve(n,k);
		cout << "Case " << (i+1) << ": " << res << "\n";
	}

	return 0;
}
