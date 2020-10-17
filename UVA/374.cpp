// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=310

#include <bits/stdc++.h>
#define PI 3.1415926535897932384626433832795
#define loop(i,n) for(i = 0; i < n; i++)
#define sz (int) 1e5 + 5
#define ll long long

using namespace std;

int b,p,m;

ll dcpow(int x, int y) { // divide and conquer power (10^16 = (10^8)^2)
    if(y == 0) {
        return 1;
    }

    ll sq = dcpow(x, y/2) % m;
    sq = sq * sq % m;

    if(y % 2 == 1)
        sq = sq * x;

    return sq;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("F:\\Programming\\Competitve Programming\\Answers\\input.txt", "r", stdin);
        freopen("F:\\Programming\\Competitve Programming\\Answers\\output.txt", "w", stdout);
    #endif

    while(scanf("%d\n%d\n%d", &b, &p, &m) == 3) {
        int mod = b % m;

        ll result = dcpow(mod, p) % m;

        cout << result << endl;
    }
    return 0;
}
