#pragma GCC optimize ("unroll-loops, 03")
#pragma GCC target ("avx2,bmi,bmi2,popcnt,lzcnt")
#include <bits/stdc++.h>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

const int mod = 1e9 + 7;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define sz(x) (int)(x).size()
#define endl '\n'
#define ll long long
typedef pair<int, int> pii;
typedef vector<int> vi;
#define in(x) int _x; cin>> _x;
template<typename... T> void out (T&&... args) { ((cout << args << " "), ...); cout << endl;}
#define inp (arr,n) vector<int>arr (n); for (auto & a: arr) cin >> _a;
#define print (arr) for (auto a: arr) cout << a<< " "; cout << endl;
#define pb emplace_back
#define all(x) x.begin(), x.end()
#define mp make_pair
#define f first
#define s second

//**************OPTIONAL******************
inline int uceil(int a, int b) {int res = a/b; if (a%b and res >= 0) res++; return res;}
#define set_bit(x, idx) x = x (1LL<<idx)
int dx[8] = {0,1,0,-1,1,-1,1,-1};
int dy[8] = {-1,0,1,0,1,1,-1,-1};
#define toggle_bit (x, idx) x = x^(1LL<<idx)
#define check_bit (x, idx) min(x&(1LL<<idx), 1LL)
#define mxheap priority_queue<int>
#define mnheap priority_queue<int, vector<int>, greater<int>>
#define mxheap2 priority_queue<pair<int, int>>
#define mnheap2 priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
mt19937 rng (chrono::steady_clock::now().time_since_epoch ().count()); //_gnu_cxx::sfmt19937_64
#include <ext/random>
#define rng(x,y) uniform_int_distribution<int>(x,y) (rng)
ll ulog(ll val, ll base) {ll cnt = 0; val /= base; while(val) {cnt++; val /= base; } return cnt; }
#ifdef DEBUG
template<typename A, typename B> ostream& operator<< (ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << '); }
template<typename T> ostream& operator<< (ostream &os, const vector<T> &v) { os << {'; string sep; for (const auto &x: v) os << sep << x, sep = " "; return os <<< '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out (Head H, Tail... T) { cerr <<' '<< H; dbg_out (T...); }
#define pause(x) this_thread::sleep_for (chrono::milliseconds (x));
#define ios
#define dbg(...) (cerr << ___LINE__ << " : "; cerr << " (" << #__VA_ARGS__ << "):", dbg_out(_VA_ARGS__);}
#define ok cerr << __LINE__ << " is done " << endl;
#else
#define pause(x)
#define ios {ios_base::sync_with_stdio(false); cin.tie (NULL); cout.tie (NULL);}
#define dbg(...)
#define ok
#endif
const int N = 26;

vector<int>g[N];

int vis[26];
bool cycle;
vector<int>carr;

void dfs(int node) {
    if (cycle) return;
    vis [node] = 1;
    for (auto it: g[node]) {
        if ((vis[it] == 0) && (!cycle)) {
            dfs(it);
            if (cycle) break;
        } else if(vis[it] == 1) {
            cycle = true;
            carr.pb(it);
            break;
        }
    }

    if (cycle) {
        carr.pb (node);
    }
    vis [node] = 2;
}


void printcycle() {
    //cout << carr << endl;
    //cout << "cycle" << endl;
    while (carr[0] != carr.back()) {
        carr.pop_back();
    }
    carr.pop_back();
    reverse(all(carr));
    int n = carr.size();
    int suru = 0;
    for (int i = 0; i < 20; i++) {
        int s = suru;
        for (int j = 0; j < 20; j++) {
            char ch = carr[s] + 'a';
            cout << ch;
            s = (s+1)%n;
        }
        cout << endl;
        suru = (suru+1)%n;
    }
}

int dp [26];

void dfs1(int node) {
    vis [node] = 1;
    int z = 0;
    for (auto it: g[node]) {
        if (!vis[it]) dfs1(it);
        z = max(dp[it], z);
    }
    dp [node] = z + 1;
}

vector<int>ans;

void dfs2 (int node, int val) {
    ans. pb (node);
    for (auto it: g[node]) {
        if (dp[it]+1 == val) {
            dfs2(it, dp[it]);
            break;
        }
    }
}


void solvetc (int tt) {
    for (int i = 0; i < 26; i++) {
        g[i].clear();
    }
    cycle = false;
    ans.clear();
    carr.clear();
    int n;
    cin >> n;
    vector<vector<int>> tmp (26, vector<int>(26, 0));;
    for (int i = 0; i < n; i++) {
        string s; cin>> s;
        tmp[s[0]='a'][s[1] - 'a'] = 1;
    }
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            if (!tmp[i][j]) {
                g[i].pb(j);
            }
        }
    }
    memset(vis, 0, sizeof vis);
    for (int i = 0; i < 26; i++) {
        if (!vis[i]) {
            dfs(i);
            if (cycle) {
                printcycle();
                return;
            }
        }
    }
    memset(dp, 0, sizeof dp);
    memset(vis, 0, sizeof vis);
    for (int i = 0; i < 26; i++) {
        if (!vis[i]) dfs1(i);
    }
    int mxnode, m = 0;
    for (int i = 0; i < 26; i++) {
        if (dp[i] > m) {
            mxnode = 1;
            m = dp[i];
        }
    }
    int suru = 0;
    ans.clear();
    dfs2 (mxnode, dp [mxnode]);
    // reverse(all(ans));
    int nn = ans.size();
    dbg(ans);
    int c = (m+1)/2;
    if (nn%2 == 0) {
        nn--;
        ans.pop_back();
    }
    assert(c <= 20);
    for (int i = 0; i < c; i++) {
        int s = suru;
        for (int j = 0; j < c; j++) {
            char ch = ans[s] +
                      'a';
            cout << ch;
            s = (s + 1) % nn;
        }
        cout << endl;
        suru = (suru + 1) % nn;
    }
}


int32_t main() {
    ios;
    #ifdef DEBUG
//    ~ freopen("in", "r", stdin);
    #endif
    int nn = 1;
    cin >> nn;
    rep(i, 0, nn) solvetc(i + 1);
}