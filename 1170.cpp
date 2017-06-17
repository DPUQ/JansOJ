#include <bits/stdc++.h>
#define 	MAX 		1e10
#define 	mod 		100000007
#define 	enl 		"\n"
#define 	debug(x) 	cout << #x " = " << (x) << enl
#define		here		cout << "here" << enl
#define 	pc(i,o) 	cout << "Case " << (i+1) << ": " << o << enl
#define 	rep(i,a,n) 	for(int i = a; i<n; i++)
#define 	sz 			size()
#define 	pb 			push_back
#define 	bg 			begin()
#define 	ed 			end()
#define 	all(v) 		(v.begin(),v.end())
#define 	sr 			sort

using namespace std;
typedef 	long long 			ll;
typedef 	vector<ll> 			vi;

const int fS = 2e6;
vi powers;
ll fact[fS];

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

ll inv( ll x )
{
    return mod_pow( x, mod-2 );
}

long upper(ll x){  
    long l=0,r=powers.sz;  
    long mid;  
    while(l<r){  
        mid=((l+r)>>1);
        if( x < powers[mid])r=mid;
        else l=mid+1;
    }
    return r;  
}  

long lower(ll x){  
    long l=0,r=powers.sz;  
    long mid;  
    while(l<r){  
        mid=((l+r)>>1);  
        if(x <= powers[mid])r=mid;  
        else l=mid+1;
    }  
    return r;  
}  

void fill(){

	fact[0] = 0; fact[1] = 1;
	rep(i,2,2e6)
		fact[i] = (fact[i-1] % mod * i % mod) % mod;

	ll num;
	for(int i = 2; i < 100001; i++){
		num = i;

		while(num*i <= MAX){
			num *= i;
			powers.pb(num);
		}
	}
	sr all(powers);
	powers.resize(unique all(powers) - powers.bg);
}


ll solve(ll n, ll m){

	long low = lower(n);
	long up = upper(m);
	ll res = fact[2*(up-low)];
	res = (res % mod * inv( ( ( fact[up-low] % mod * fact[up-low] % mod ) % mod * (up-low+1) % mod ) % mod) % mod ) % mod;
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	int t;
	ll n,m;
	fill();
	cin >> t;
	rep(i,0,t){
		cin >> n >> m;
		pc(i,solve(n,m));
	}
	return 0;
}
