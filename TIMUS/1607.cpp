//https://acm.timus.ru/submit.aspx?space=1&num=1607

#include <bits/stdc++.h>
#define PI 3.1415926535897932384626433832795
#define loop(i,n) for(i = 0; i < n; i++)
#define revloop(i,n) for(i = n; i >= 0; i--)
#define sz (int) 1e5 + 5
#define ll long long

using namespace std;

int main() {
    int a,b,c,d; //petr inital, petr incr, taxi inital, taxi dec
    cin >> a >> b >> c >> d;

    int petr = a; //current petr offer
    int taxi = c; //current taxi offer
    
    int final = a;
    while(petr < taxi) { //no deal has been made yet
        petr += b;
        if(petr >= taxi) {//if petr is asking more, minimize to driver's
            final = taxi;
            break;
        } else {
            taxi -= d;
            if(petr >= taxi) {// if taxi is asking less, maximize to petr's
                final = petr;
                break;
            }
        }
    }

    cout << final;

    return 0;
}