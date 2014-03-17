/*
 * Author:  aRon
 * Created Time:  2014/3/7 19:05:46
 * File Name: 2342.cpp
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
#define N 6001
int n;
int rate[N];
vector<int> rel[N];
int a, b;
int D[N][N];
bool visited[N];

void dfs(int v)
{
    visited[v] = true;
    int tot_0 = 0, tot_1 = 0;
    for(int i = 0; i < rel[v].size(); i ++)
    {
        int u = rel[v][i];
        if(! visited[u])
            dfs(u);
        tot_0 += D[u][0];
        if(D[u][0] < D[u][1])
            tot_1 += D[u][1];
        else
            tot_1 += D[u][0];
    }
    D[v][1] = tot_0 + rate[v];
    D[v][0] = tot_1;
}
int main() {
    scanf("%d", &n);
        for(int i = 0; i < n; i ++)
            scanf("%d", &rate[i]);
        for(int i = 0; i < n - 1;i ++)
            rel[i].clear();
        memset(visited, false, sizeof(visited));
        while(scanf("%d %d", &a, &b))    
        {
            if(a == 0 && b == 0)
                break;
            rel[b - 1].push_back(a - 1);
        }
        for(int i = 0; i < n; i ++)
        {
            if(! visited[i])
                dfs(i);
        }
        int max = 0;
        for(int j = 0; j < n; j ++)
        {
            if(max < D[j][0])
                max = D[j][0];
            if(max < D[j][1])
                max = D[j][1];
        }
        printf("%d\n", max);
    return 0;
}

