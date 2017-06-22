#include <bits/stdc++.h>
#define MAX 1001
#define mod 1000000007
#define enl "\n"
#define debug(x) cout << #x " = " << (x) << enl
#define pc(i,o) cout << "Case " << (i+1) << ": " << o << enl
#define rep(i,a,n) for(int i = a; i<n; i++)

using namespace std;
typedef long long ll;

ll fact[MAX];
ll comb[MAX][MAX];

void fill()
{
    fact[1] = fact[0] = ll(1);
    rep(i,2,MAX)
        fact[i] = (i*fact[i-1])%mod;

    rep(i,0,MAX)
    {
        comb[i][0] = comb[i][i] = ll(1);

        rep(k,1,i)
            if(i - 1 < k)
				comb[i][k] = comb[i - 1][k - 1] % mod;
			else
				comb[i][k] = ( (comb[i - 1][k] % mod) + (comb[i - 1][k - 1]%mod) ) % mod;
    }
}

ll solve(int n, int m, int k){
	ll ans = comb[m][k] , der;
	int x = n - k, y = m - k;
	der = fact[x];
	rep(i,1,y+1){
		if(i%2)
			der = (der % mod - (comb[y][i] * fact[x-i]) % mod + mod) % mod;
		else
			der = (der % mod + (comb[y][i] * fact[x-i]) % mod ) % mod;
	}
	
	ans = (ans % mod * der % mod) % mod;
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	fill();
	int t,n,m,k; ll ans;
	cin >> t;
	rep(i,0,t){
		cin >> n >> m >> k;
		ans = solve(n,m,k);
		pc(i,ans);
	}
	return 0;
}
