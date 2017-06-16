#include <bits/stdc++.h>
#define enl "\n"
#define pc(i,o) cout << "Case " << (i) << ": " << o << enl
#define rep(i,a,n) for(int i = a; i<n; i++)
#define irep(i,a,n) for(int i = n; i>=a; i--)
#define dig(c) (c - '0')
#define sz size()

using namespace std;
typedef string st;
typedef long long ll;
typedef unsigned long ul;
template<class T> string to_str(T t){stringstream ss; ss<<t; return ss.str();}

ul tenPows[11];

void fillPows(){
	tenPows[0] = 1;
	rep(i,1,11)	tenPows[i] = 10 * tenPows[i-1];
}

ll countZ(st n){

	ll suf[n.sz],pref[n.sz];

	suf[0] = 0;
	rep(i,1,n.sz)
		suf[i] = tenPows[i-1] * dig(n[n.sz-i]) + suf[i-1];
	
	pref[n.sz-1] = 0;
	irep(i,0,n.sz-2)
		pref[i] = 10 * pref[i+1]  + dig(n[n.sz - 2 - i]);

	ll ans = 1;

	rep(k,0,n.sz){
		if(dig(n[n.sz-k-1])) ans += tenPows[k] * pref[k];
		else ans+= tenPows[k] * (pref[k] - 1) + suf[k] + 1;
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	ul n;
	st m;
	fillPows();
	cin >> t;
	rep(i,0,t){
		cin >> n >> m;
		if(n!=0){
			n--;
			ll ans = ll (countZ(m) - countZ(to_str(n)));
			pc(i+1,ans);
		} 
		else
			pc(i+1,countZ(m));
	}

	return 0;
}
