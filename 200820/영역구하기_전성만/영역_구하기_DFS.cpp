#include <bits/stdc++.h>
using namespace std;

int pos[4][2] = {{0, 1},{1, 0},{0, -1}, {-1, 0}};
int cnt, M, N;

void dfs(vector<vector<int>> &v, int x, int y) 
{
    v[x][y] = 1;
    cnt++;
    for(int i = 0; i < 4; i++) 
    {
        int x_ = x + pos[i][0];
        int y_ = y + pos[i][1];
        if (x_ >= 1 && x_ <= M && y_ >= 1 && y_ <= N && !v[x_][y_]) 
        {
            dfs(v, x_, y_);
        }
    }
}

int main() 
{
    int m, n, k;
    cin >> n >> m >> k;
    M = m; N = n;
    
    vector<vector<int>> v(m+1, vector<int>(n+1, 0));
    while(k--) 
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for(int x = x1 + 1; x <= x2; x++) 
        {
            for(int y = y1 + 1; y <= y2; y++) 
            {
                v[x][y] = 1;
            }
        }
    }

    vector<int> ans;
    for (int i = 1; i <= m; i++) 
    {
        for (int j = 1; j <= n; j++) 
        {
            if(!v[i][j]) 
            {
                cnt = 0;
                dfs(v, i, j);
                ans.emplace_back(cnt);
            }
        }
    }

    cout << ans.size() << '\n';

    sort(ans.begin(), ans.end());

    for(auto i : ans) 
    {
        cout << i << ' ';
    }

    return 0;
}