#include <bits/stdc++.h>
#define MAX 2000001
#define mod 1000000007
#define enl "\n"
#define debug(x) cout << #x " = " << (x) << enl
#define rep(i,a,n) for(int i = a; i<n; i++)

using namespace std;
typedef long long ll;


/* Calculates x ^ y % mod*/
ll mod_pow( ll b, ll e)
{
    ll r = 1;
    ll pow = b % mod;
    while( e > 0 )
    {
        if( e&1 ) r = ( r*pow )%mod;
        pow = ( pow*pow )%mod;
        e >>= 1;
    }
    return r;
}

/* Calculates the multiplicative inverse of x*/
ll inv( ll x )
{
    return mod_pow( x, mod-2 );
}

/* fact[i] = i! */
ll fact[MAX];

/* Fastest mod factorial, fill fact array*/
void fillFact(){
	fact[0] = fact[1] = 1;
	rep(i,2,MAX)
		fact[i] = (i % mod * fact[i-1] % mod ) % mod;
}

/* Fast enough function for nCk % mod */
ll mod_comb(int n, int k){
	return (fact[n] % mod * inv((fact[k] % mod * fact[n-k] % mod) % mod ) % mod) % mod;
}

int main()
{
	ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	int t;
	ll n,k;
	fillFact();
	cin >> t;
	rep(i,0,t){
		cin >> n >> k;
		cout << "Case "<< (i+1) << ": "<< mod_comb(n+k-1,n) << enl;
	}
	
	return 0;
}
