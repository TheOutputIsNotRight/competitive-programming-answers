//https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=305

#include <bits/stdc++.h>
#define PI 3.1415926535897932384626433832795
#define loop(i,n) for(i = 0; i < n; i++)
#define sz (int) 1e5 + 5
#define ll long long

using namespace std;

double cal_factorial(int s, int e) {
    double total = 1;
    for(int i = s; i >= e; i--) {
        total = total * i;
    }

    return total;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("F:\\Programming\\Competitve Programming\\Answers\\input.txt", "r", stdin);
        freopen("F:\\Programming\\Competitve Programming\\Answers\\output.txt", "w", stdout);
    #endif

    int n,m;
    cin >> n >> m;
    while(n != 0 or m != 0) {
        int cancel = n - m;

        double dividend = cal_factorial(n, max(m+1, n-m+1));
        double divisor = cal_factorial(min(n - m, m), 2);

        double result = 0;
        if(divisor != 0)
            result = dividend/divisor;

        printf("%d things taken %d at a time is %.0f exactly.\n", n, m, result);

        cin >> n >> m;
    }

    return 0;
}