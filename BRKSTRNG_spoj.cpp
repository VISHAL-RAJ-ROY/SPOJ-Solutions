/*
** Vishal Raj Roy
** Indian Institute of Technology Kharagpur
*/

#include <bits/stdc++.h>

using namespace std;

#define posLSB(X) __builtin_ctz(X)
#define num1bit(X) __builtin_popcount(X)
#define numlead0(X) __builtin_clz(X)
#define gcd(X,Y) __gcd(X,Y)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define lb lower_bound
#define ub upper_bound
#define bs binary_search
#define ifpresent(CON,VAL) (CON.find(VAL) != CON.end())
#define all(x) x.begin(),x.end()
#define at(X,N) get<N>(X)
#define ins insert
#define xx first
#define yy second
#define sz(x) ((int)x.size())
#define count_ones __builtin_popcountl
#define nl cout<<"\n";
#define name(X) (#X)
#define watch(X) cout << (#X) << " is " << (X) << "\n"
#define sqr(x) ((x)*(x))
#define mod(x, m) ((((x) % (m)) + (m)) % (m))
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define mem(x,val) memset((x),(val),sizeof(x))
#define rite(X) freopen(X,"w",stdout)
#define read(X) freopen(X,"r",stdin)
//FOR(i,1,10) gives 1,2,3,....,9 and FOR(i,10,1) gives 9,8,....,1 also FOR(it, end(v), begin(v)) and FOR(it, begin(v), end(v))
#define FOR(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define SEL(X,C) for( auto & X : C )
#define ima INT_MAX
#define imi INT_MIN
#define lma LLONG_MAX
#define lmi LLONG_MIN

using st = string; typedef long long int li; typedef pair<int, int> ii; typedef pair<int, ii> iii; typedef tuple<int,int> i2; typedef tuple<int,int,int> i3; typedef vector<int> vi; typedef vector<ii> vii; typedef vector<vi> vvi;

const double pi = 2 * acos(0.0);
const int oo = 0x3f3f3f3f; // don't use for long long
const double inf = 1.0/0.0;

int main() {
    ios_base::sync_with_stdio(0);
    // read("rr.txt");
    int n,m;
    while( cin>>n>>m ) {
        // error(n,m);
        vi p(m+2,0); p[0] = 0; p[m+1] = n;
        FOR(i,1,m+1) cin>>p[i];
        vvi dp(m+2,vi(m+2,0));
        vvi mi(m+2,vi(m+2,0));
        // watch(p);
        for( int s = 0; p[s] < n; s++ ) dp[s][1] = 0;
        for( int s = 0; p[s+1] < n; s++ ) dp[s][2] = p[s+2]-p[s], mi[s][2] = s+1;
        if( m >= 2 ) {
            for( int s = 0; p[s+2] < n; s++ )  {
                int a = p[s+1]-p[s], b = p[s+3]-p[s+2];
                mi[s][3] = ( a > b ? s+1 : s+2 );
                dp[s][3] = 2*(p[s+3]-p[s])-max(a,b);
            }
            FOR(l,4,m+2) {
                for( int s = 0; p[s+l-1] < n; s++ ) {
                    int x = mi[s][l-1], y = mi[s+1][l-1];
                    dp[s][l] = oo;
                    for( int z = x; z <= y; z++ ) {
                        int cut = dp[s][z-s]+dp[z][l-(z-s)];
                        if( cut < dp[s][l] ) 
                            dp[s][l] = cut, mi[s][l] = z;
                    }
                    dp[s][l] += (p[l+s]-p[s]);
                }
            } 
        }
        cout<<dp[0][m+1]<<"\n";
    }
    return 0;
}
