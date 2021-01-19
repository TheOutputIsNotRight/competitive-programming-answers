//https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&category=0&problem=380

#include <bits/stdc++.h>
#include <string>
#define PI 3.1415926535897932384626433832795
#define loop(i,n) for(i = 0; i < n; i++)
#define sz (int) 1e5 + 10
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define f first
#define s second

using namespace std;

int movement[2][8] = {
    {-2, -2,  1, -1, 2,  2, -1, 1},
    { 1, -1, -2, -2, 1, -1,  2, 2}
};
bool visited[10][10];
int gridcost[10][10];

bool isValid(int x, int y) {
    return x>=0&&y>=0 && x<8&&y<8;
}

void get_neighbors(int x, int y, vector<pair<int,int>> &neighbors) {
    int i,j;
    loop(i,8) {
        loop(j,8) {
            if(isValid(movement[0][i] + x, movement[1][i] + y)) {
                //cout << "got new neighbor" << endl;
                neighbors.push_back(mp(movement[0][i] + x, movement[1][i] + y));
            }
        }
    }
    return;
}
/*
void bfs(int x, int y, int depth, int t0, int t1) {
    if(visited[x][y])
        return -1;

    visited[x][y] = 1;
    vector<pair<int,int>> neighbors;
    get_neighbors(x, y, neighbors);

    for(int i = 0; i < neighbors.size(); i++) {
        pair<int,int> cord = neighbors[i];
        if(cord.first == t0 && cord.second == t1) {

        } else {
            bfs(x, y, depth++, t0, t1)
        }
    }
}
*/

int bfs(int x, int y, int t0, int t1) {
    queue< pair< pair<int,int>,int> > q;
    q.push({{x, y}, 0});

    while(!q.empty()) {
        pair<int,int> cord = q.front().first;
        int depth = q.front().second;
        q.pop();

        if(visited[cord.first][cord.second]) {
            continue;
        }
        visited[cord.first][cord.second] = 1;

        if(cord.first == t0 && cord.second == t1) {
            return depth;
        }

        vector<pair<int,int>> neighbors;
        get_neighbors(cord.first, cord.second, neighbors);
            //cout << "checking " << neighbors.size() << endl;
        for(int i = 0; i < neighbors.size(); i++) {
            pair<int,int> nwcord = neighbors[i];
            if(!visited[nwcord.first][nwcord.second]) {
                q.push({nwcord, depth+1});
            }
        }
    }

    return -1;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("F:\\Programming\\Competitve Programming\\Answers\\input.txt", "r", stdin);
        freopen("F:\\Programming\\Competitve Programming\\Answers\\output.txt", "w", stdout);
    #endif

    string a(2, ' '),b(2, ' ');
    while(scanf("%c%c %c%c\n", &(a[0]), &(a[1]), &(b[0]), &(b[1])) == 4) {
        int x0 = a[0] - 'a', y0 = a[1] - '1', x1 = b[0] - 'a', y1 = b[1] - '1';

        //cout << x0 << ' ' << y0 << ' ' << x1 << ' ' << y1 << endl;

        //if(x0 == x1 && y0 == y1) {
        //    cout << "To get from " << a << " to " << b << " takes 0 knight moves." << endl;
        //    continue;
        //}

        int i,j;
        loop(i,10) {
            loop(j,10) {
                visited[i][j] = 0;
                gridcost[i][j] = INT_MAX;
            }
        }

        int depth = bfs(x0, y0, x1, y1);
        cout << "To get from " << a << " to " << b << " takes " << depth << " knight moves." << endl;
    }

    return 0;
}
