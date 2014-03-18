/*
 * Author:  mybestwishes
 * Created Time:  2014/3/18 21:46:04
 * File Name: 1463.cpp
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
#define N 1501
vector<int> tree[N];
int d[N][2];
bool vis[N];
void dfs(int v)
{
    bool tag = false;
    vis[v] = true;
    int mx = 1501;
    int totol0 = 0;
    int totol1 = 1;
    for(int i = 0; i < tree[v].size(); i ++)
    {
        int u = tree[v][i];
        if(! vis[u])
        {
            tag = true;
            dfs(u);
            if(d[u][0] < d[u][1])
                totol1 += d[u][0];
            else
                totol1 += d[u][1];
            totol0 += d[u][1];
        }
    }
    d[v][0] = totol0;
    d[v][1] = totol1;
}
int main() {
    int n;
    while(scanf("%d", &n) != EOF)
    {
        memset(vis, false ,sizeof(vis));
        memset(d, 0, sizeof(d));
        for(int j = 0; j < n; j ++)
            tree[j].clear();
        for(int i = 0;i < n; i ++)
        {
            int index, num;
            scanf("%d:(%d)", &index, &num);
            for(int j = 0; j < num; j ++)
            {
                int a;
                scanf("%d", &a);
                tree[index].push_back(a);
                tree[a].push_back(index);
            }  
            //cout<<index<<" "<<num<<endl;
        }
        dfs(0);
        /*
        for(int j = 0; j < n; j ++)
        {
            cout<<d[j][0]<<" "<<d[j][1]<<endl;
        }
        */
        if(d[0][0] < d[0][1])
            cout<<d[0][0]<<endl;
        else
            cout<<d[0][1]<<endl;
    }
    return 0;
}

