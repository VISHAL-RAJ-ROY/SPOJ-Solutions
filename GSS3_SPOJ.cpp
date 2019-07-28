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
using st = string; typedef long long int li; typedef pair<int, int> ii; typedef pair<int, ii> iii; typedef tuple<int,int> i2; typedef tuple<int,int,int,int> i3; typedef vector<int> vi; typedef vector<ii> vii; typedef vector<i2> vi2; typedef vector<i3> vi3; typedef vector<iii> viii; typedef vector<vi> vvi; typedef vector<vvi> vvvi; typedef pair<li, li> ll; typedef pair<li, ll> lll; typedef tuple<li,li> l2; typedef tuple<li,li,li> l3; typedef vector<li> vl; typedef vector<ll> vll; typedef vector<l2> vl2; typedef vector<l3> vl3; typedef vector<lll> vlll; typedef vector<vl> vvl; typedef vector<vvl> vvvl; typedef double db; typedef complex<db> cd; typedef vector<cd> vcd; template <class S> using ve = vector<S>; template <class S> using gr = greater<S>; template <class S> using le = less<S>;

const double pi = 2 * acos(0.0);
const int oo = 0x3f3f3f3f; // don't use for long long
const double inf = 1.0/0.0;
#define max4(a,b,c,d) max(a,max3(b,c,d))
#define max5(a,b,c,d,e) max(a,max4(b,c,d,e))

// note :
// i3 is tuple<int,int,int,int> here {prefix_max, suffix_max, subarray_sum_max, sum_of_interval}
// changed to store sum of the segment 
class segtree { // left and right inclusive
    private:
        vi v; vi3 tree; int n; 
    public:
        segtree() {};
        segtree( vi & arr ) { n = sz(arr); SEL(x,arr) v.eb(x); tree.assign(4*n+4,{0,0,0,0}); build(1,0,n-1); }
        i3 func( i3 a, i3 b ) { if(at(a,0) == -oo) return b; if(at(b,0) == -oo) return a; return {max(at(a,0),at(a,3)+at(b,0)),max(at(b,1),at(b,3)+at(a,1)),max3(at(a,2),at(b,2),at(a,1)+at(b,0)),at(a,3)+at(b,3)}; } // any associative function
        void build( int node, int l, int r ) {
            if( l == r ) tree[node] = {v[l],v[l],v[l],v[l]};
            else { int m = (l+r)/2, le = 2*node, ri = 2*node+1; build(le,l,m); build(ri,m+1,r); tree[node] = func(tree[le],tree[ri]); }
        }
        i3 query( int node, int l, int r, int ql, int qr ) {
            if( ql > qr ) return {-oo,-oo,-oo,0};
            else if( l == ql && r == qr ) return tree[node];
            else { int m = (l+r)/2; return func(query(2*node,l,m,ql,min(qr,m)),query(2*node+1,m+1,r,max(m+1,ql),qr)); }
        }
        void update( int node, int l, int r, int index, int inc_by ) {
            if( l == r ) tree[node] = {inc_by,inc_by,inc_by,inc_by};
            else { int m = (l+r)/2; ( m<index ? update(2*node+1,m+1,r,index,inc_by):update(2*node,l,m,index,inc_by)); tree[node] = func(tree[2*node],tree[2*node+1]); }
        }
        int query(int l, int r) { return at(query(1,0,n-1,l,r),2); } 
        void update(int index, int inc_by) { update(1,0,n-1,index,inc_by); } 
};

int main() {
    ios_base::sync_with_stdio(0);
    // read("rr.txt");
    int n; cin>>n; vi v(n,0); FOR(i,0,n) cin>>v[i]; int q; cin>>q; segtree tr(v);
    FOR(i,0,q) {
        int qq,x,y; cin>>qq>>x>>y; if(!qq) tr.update(x-1,y); else cout<<tr.query(x-1,y-1)<<"\n";
    }
    return 0;
}
