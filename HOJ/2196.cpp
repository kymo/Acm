/*
 * Author:  mybestwishes
 * Created Time:  2014/3/17 19:03:22
 * File Name: 2196.cpp
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
#include <map>
#include <time.h>
using namespace std;
const int maxint = -1u>>1;
#define N 10001
int n;
struct node
{
    int u,w;
};
map<int ,int> W[N];
vector<node> g[N];
int d[N][3];
int get[N];
bool vis[N];
void dfs(int v)
{
    vis[v] = true;
    int mx = 0;
    int smx = 0;
    int index = 0;
    for(int j = 0; j < g[v].size(); j ++)
    {
        int u = g[v][j].u;
        if(! vis[u])
        {
            dfs(u);
           
            int len = d[u][0] + W[u][v];
            if(mx < len)
            {
                smx = mx;
                mx = len;
                index = u;
            }
            else
            {
                if(smx < len)
                    smx = len;
            }
            //cout<<mx<<"mx"<<endl;
        }
    }
    //cout<<v<<" "<<mx<<" "<<index<<" "<<smx<<endl;
    d[v][0] = mx;
    d[v][1] = smx;
    d[v][2] = index;
}

void dfs2(int v, int f)
{
    vis[v] = true;
    if(f == -1)
    {
        get[v] = d[v][0];
    }
    else
    {
        if(d[f][2] == v)
        {
            if(d[v][0] < d[f][1] + W[f][v])
            {
                
                get[v] = d[f][1] + W[f][v];
                d[v][1] = d[v][0];
                d[v][2] = f;
                d[v][0] = get[v];
                
            }
            else
            {
                if(d[v][1] < d[f][1] + W[f][v])
                    d[v][1] = d[f][1] + W[f][v];
                get[v] = d[v][0];
            }
            //cout<<v<<"+"<<f<<" "<<d[v][0]<<" "<<d[f][1]<<" "<<W[f][v]<<endl;
            
        }
        else
        {
            if(d[v][0] < d[f][0] + W[f][v])
            {
                
                get[v] = d[f][0] + W[f][v];
                d[v][1] = d[v][0];
                d[v][2] = f;
                d[v][0] = get[v];
            }
            else
            {
                if(d[v][1] < d[f][0] + W[f][v])
                    d[v][1] = d[f][0] + W[f][v];
                get[v] = d[v][0];
            }
        }
    }
    for(int j = 0; j < g[v].size(); j ++)
    {
        int u = g[v][j].u;
        if(! vis[u])
            dfs2(u, v);
    }
    //cout<<v<<" "<<f<<" "<<d[v][0]<<" "<<d[v][1]<<" "<<d[v][2]<<" "<<get[v]<<endl;
}

int main() {
    while(scanf("%d", &n) != EOF)
    {
        for(int j = 0; j < N; j ++)
        {
           W[j].clear(); 
            g[j].clear();
        }
    for(int j = 1; j < n; j ++)
    {
        int a,b ;
        scanf("%d %d", &a, &b);;
        W[j].insert(pair<int,int>(a-1,b));
        W[a-1].insert(pair<int,int>(j,b));
        node nd;
        nd.u = a - 1;
        nd.w = b;
        g[j].push_back(nd);
        nd.u = j;
        g[a - 1].push_back(nd);
    }
    memset(get, 0, sizeof(get));
    memset(d, 0, sizeof(d));
    memset(vis, false, sizeof(vis));
    dfs(0);
    memset(vis, false, sizeof(vis));
    dfs2(0, -1);
    for(int j = 0; j < n; j ++)
        printf("%d\n", get[j]);
    }
    return 0;
}

