/*
 * Author:  mybestwishes
 * Created Time:  2014/3/8 21:01:57
 * File Name: 1155.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <time.h>
using namespace std;
const int maxint = -1u>>1;
#define N 3001
vector<int> tree[N];

int dp[N][2];
int cost[N][N];
int pay[N];
int num[N];
int n, m;
void dfs(int u)
{
    if(tree[u].size() == 0)
    {
        if(u > n - m)
        {
            num[u] = 1;
            d[u][1] = pay[u];
            d[u][0] = 0;
        }
        else
        {
            dp[u][num[now] = 0] = 0;
        }
        return;
    }
    num[u] = 0;
    dp[u][0] = 0;
    for(int i = 0; i < tree[u].size(); i ++)
    {
        int to = tree[u][i];
        int cos = cost[u][to];
        dfs(to);
    }
}
int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n - m; i ++)
    {
        int t;
        scanf("%d", &t);
        for(int j = 0; j < t; j ++)
        {
            int a,b;
            scanf("%d %d", &a, &b);
            tree[i].push_back(a - 1);
            cost[i][a - 1] = b;
        }
        
        dfs(1);
    }
    
    return 0;
}

