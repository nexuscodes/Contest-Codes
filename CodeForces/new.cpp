#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

#define ff first
#define ss second
#define ll long long
#define double long double
#define pb push_back
#define pll pair<ll, ll>
#define pii pair<int, int>

#define sz(x) (int)x.size()
#define range(x) x.begin(),x.end()
#define rep(i,k,n) for(int i=k;i<n;i++)
#define show(x) cout<<#x<<" :: "<<x<<'\n';
#define iosbase ios_base::sync_with_stdio(false); cin.tie(NULL);
#define show2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<'\n';
#define show3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<'\n';
#define oset tree<int , null_type, less<int> , rb_tree_tag, tree_order_statistics_node_update>

using namespace std;
using namespace __gnu_pbds;

const ll inf = 1e18;
const ll N = 2000005;
const ll mm = 1e9 + 7;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    iosbase;
    
    int test;
    cin>>test;
    while(test--)
    {
        int n, x;
        cin>>n>>x;

        int a[n];
        vector<int> idx[31];
        for(int i = 0; i < n; i++)
        {
            cin>>a[i];
            for(int j = 0; j < 31; j++)
            {
                if(a[i] & (1 << j))
                {
                    idx[j].pb(i);
                }
            }
        }

        int cur[31] = {0};

        for(int i = 0; i < n - 1; i++)
        {
            for(int j = 30; j >= 0; j--)
            {
                if(a[i] & (1 << j))
                {
                    cur[j]++;
                    int next;
                    if(cur[j] < (int)idx[j].size())
                    {
                        next = idx[j][cur[j]];
                        cur[j]++;
                    }
                    else
                    {
                        next = n - 1;
                    }
                    a[i] = (a[i] ^ (1 << j));
                    a[next] = (a[next] ^ (1 << j));
                    x--;
                }
                if(x == 0) break;
            }
            if(x == 0) break;
        }
        
        if(x > 0)
        {
            if(x % 2 && ((n == 2) || (n > 2 && x == 1)))
            {
                a[n - 2] = (a[n - 2] ^ 1);
                a[n - 1] = (a[n - 1] ^ 1);
            }
        }
        for(int i = 0; i < n; i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<'\n';
    }
    return 0;
}
