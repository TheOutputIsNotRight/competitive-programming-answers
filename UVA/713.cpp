//https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=654

#include <bits/stdc++.h>
#define PI 3.1415926535897932384626433832795
#define loop(i,n) for(i = 0; i < n; i++)
#define sz (int) 1e5 + 5
#define ll long long

using namespace std;

// 207 digits = 17 ints (intsize -= 1 bec of implementation)
int arr1[17];
int arr2[17];

void add(int* x, int* y, int* target) {
    fill_n(target, 17, 0);

    for(int i = 0; i < 17; i++) {
        if(x[i] != 0 or y[i] != 0) {
            int nw_v = x[i] + y[i];
            if(nw_v >= 1000000000 and i < 16) {
                target[i] = nw_v - 1000000000;
                target[i+1] += 1;
            } else {
                target[i] = nw_v;
            }
        }
    }
}

string istr(int x) {
    if(x == 0)
    return string("0");

    string result = "";
    int base = 10;
    int i = 0;
    while(x > 0) {
        //result.resize(result.size+1);
        int digit = x % base / (base / 10);
        x -= digit * (base / 10);
        result.push_back((char) (digit + '0'));
        base = base * 10;
        i++;
    }
    reverse(result.begin(), result.end());
    return result;
}

int stri(string x) {
    int result = 0;
    for(int i = 0; i < x.size(); i++) {
        result = result * 10 + (x[i] - '0');
    }
    return result;
}

string arri_str(int* x) {
    string result = "";

    for(int i = 0; i < 17; i++) {
        string s = istr(x[i]);
        result.append(s);
    }

    return result;
}

void str_arri(string x, int* target) {
    fill_n(target, 17, 0);

    for(int i = 0; i < 17; i++) {
        int start = i*9;
        int cnt = 9;
        if(start >= x.size())
            break;
        
        if(cnt+start >= x.size())
            cnt = x.size() - start;
        
        string sub = x.substr(start, cnt);

        target[i] = stri(sub);
    }
}

void printarri(int* arr, int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

string trim(string x) {
    int start = 0, finish = x.size();
    for(int i = 0; i < x.size(); i++) {
        if(x[i] == '0') {
            start++;
        } else {
            break;
        }
    }
    for(int i = x.size()-1; i >= 0; i--) {
        if(x[i] == '0')
            finish--;
        else
            break;
    }
    return x.substr(start, finish - start);
}

int main() {
    /*
    int target[17];
    str_arri(string("19992138712973897893178931213876"), target);
    printarri(target, 17);

    fill_n(target, 17, 0);
    target[0] = 1999;
    cout << arri_str(target) << endl;

    int target2[17];
    fill_n(target2, 17, 0);
    target2[0] = 5;

    int target3[17];
    fill_n(target3, 17, 0);

    add(target, target2, target3);
    printarri(target3, 17);
    */
    #ifndef ONLINE_JUDGE
        freopen("F:\\Programming\\Competitve Programming\\Answers\\input.txt", "r", stdin);
        freopen("F:\\Programming\\Competitve Programming\\Answers\\output.txt", "w", stdout);
    #endif

    int t;
    cin >> t;
    while(t--) {
        string x,y;
        cin >> x >> y;

        reverse(x.begin(), x.end());
        reverse(y.begin(), y.end());

        int a[17], b[17];

        str_arri(x, a);
        str_arri(y, b);

        int sum[17];

        add(a, b, sum);

        string result = arri_str(sum);
        result = trim(result);
        reverse(result.begin(), result.end());

        cout << result << endl;
    }
    
    return 0;
}