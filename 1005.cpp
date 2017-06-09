#include <bits/stdc++.h>
#define enl "\n"
#define rep(i,a,n) for(int i = a; i<n; i++)
#define debug(x) cout << #x " = " << (x) << enl

using namespace std;
typedef unsigned long long ll;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t,n,k;
	ll res,aux;
	cin >> t;
	rep(i,1,t+1){
		res = 1;
		cin >> n >> k;

		rep(j,n-k+1,n+1)
			res *= j;

		aux = res;

		while(k)
			res /= k--;

		res *= aux;
		cout << "Case " << i << ": " << res << enl;
		
	}

	return 0;
}
