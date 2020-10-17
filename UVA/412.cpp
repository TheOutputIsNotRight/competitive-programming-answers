//https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=353

#include <bits/stdc++.h>
#define PI 3.1415926535897932384626433832795
#define loop(i,n) for(i = 0; i < n; i++)
#define sz (int) 1e5 + 5
#define ll long long

using namespace std;

int arr[55];

int gcd(int x, int y) {
    if(y > x)
    swap(x,y);

    if(y == 0)
        return x;

    return gcd(x%y, y);
}

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

    int n;
    cin >> n;
    while(n != 0) {
        int i,j;
        loop(i, n) {
            cin >> arr[i];
        }

        double nfac = cal_factorial(n,2);
        double possible_pairs = nfac / ((nfac / (n*(n-1))) * 2); // n! / ((n - m)! * m!)
        // m = 2
        // (n - 2)! = n! / (n * (n - 1))

        int cnt = 0;

        loop(i, n) {
            for(int j = i+1; j < n; j++) {
                if(gcd(arr[i], arr[j]) == 1) {
                    cnt++;
                }
            }
        }

        if(cnt != 0) {
            double result = cnt / possible_pairs;
            cout << fixed << setprecision(6) << sqrt(6/result) << endl;
        } else {
            cout << "No estimate for this data set." << endl;
        }

        cin >> n;
    }
    
    return 0;
}