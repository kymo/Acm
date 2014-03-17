#include <iostream>
#include <vector>
using namespace std;
#define N 20001
int t,n;
vector<int> edge[N];
int node[N];
int balance[N];
bool visited[N];
int dfs(int v)
{
    visited[v - 1] = true;
    vector<int> curEdge = edge[v - 1];
    int ret = 1;
    bool tag = true;
    vector<int>::iterator ite;
    for(ite = curEdge.begin(); ite != curEdge.end(); ite ++)
    {
        if(! visited[*ite - 1])
        {
            int temp = dfs(*ite);
            if(balance[v - 1] < temp)
               balance[v - 1] = temp;
            ret += temp;
            tag = false; 
        }
    }
    if(tag)
    {
        balance[v - 1] = n - 1;
        return ret;
    }
    if(balance[v - 1] < n - ret)
        balance[v - 1] = n - ret;
    return ret;
}
int main()
{
     
    scanf("%d", &t);
        while(t -- )
        {
        scanf("%d", &n);
        for(int i = 0; i < n - 1;i ++)
            edge[i].clear();
        for(int i = 0; i < n - 1; i ++)
        {
            int a,b;
            scanf("%d %d", &a, &b);
            edge[a - 1].push_back(b);
        }
        memset(visited, false, sizeof(visited));
        memset(balance, 0, sizeof(balance));
        dfs(1);
        int maxs = balance[0];
        int index = 0;
        for(int j = 0; j < n; j ++)
        {
            if(maxs > balance[j])
            {
                index = j;
                maxs = balance[j];
            }
        }
        printf("%d %d\n", index + 1, maxs);
        
        }
}
