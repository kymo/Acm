/*
 * Author:  mybestwishes
 * Created Time:  2014/4/10 20:12:02
 * File Name: ztysdp_1855.cpp
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

int dp[100][400][400];
int n,m;
int state[400];
int cur[100],total;
bool ok(int j, int r)
{
    if(state[j] & cur[r])
        return 0;
    return 1;
}
int getSum(int n)
{
    int ret = 0;
    while(n > 0)
    {
        ret += n % 2;
        n = n / 2;
    }
    return ret;
}
void init()
{
    scanf("%d %d", &m, &n);
    
    for(int j = 0; j < m; j ++)
    {
        cur[j] = 0;
        char ch[12];
        scanf("%s", ch);
        for(int k = 0; k < n; k ++)
        {
            if(ch[k] == 'H')
            {
                cur[j] += (1 << (n - 1 - k));
            }
        }
        cout<<cur[j]<<" ";
    }
    cout<<endl;
    for(int j = 0; j < (1 << n); j ++)
    {
        if(j & (j << 1) || j & (j << 2))
            continue;
        state[total ++] = j;
    }
    for(int j = 0; j <total; j ++)
        cout<<state[j]<<" ";
    cout<<endl;
    cout<<getSum(14)<<endl;
    for(int j = 0; j < total; j ++)
    {
        if(ok(j,0))
        {
            for(int k = 0; k < total; k ++)
                dp[0][j][k] = getSum(j);
        }
    }
    for(int j = 0; j < total; j ++)
    {
        if(! ok(j,1))
            continue;
        for(int k = 0; k < total; k ++)
        {
            if(! ok(k,0))
                continue;
            if(state[j] & state[k])
                continue;
            
            dp[1][j][k] = dp[0][k][0] + getSum(j);
        }
    }
    for(int i = 2; i < m; i ++)
    {
        for(int j = 0; j < total; j ++)
        {
            if(! ok(j,i))
                continue;
            for(int k = 0; k < total; k ++)
            {
                if(! ok(k,i - 1))
                    continue;
                if(state[j] & state[k])
                    continue;
                for(int l = 0; l < total; l ++)
                {
                    if(! ok(l, i - 2))
                        continue;
                    if(state[j] & state[l] || state[k] & state[l])
                        continue;
                    dp[i][j][k] = max(dp[i][j][k], dp[i - 1][k][l] + getSum(j));   
                }
            }
        }
    }
    int ans = 0;
    for(int j = 0; j < total; j ++)
    {
        for(int k = 0; k < total; k ++)
        {
            if(ans < dp[m-1][j][k])
                ans = dp[m-1][j][k];
        }
    }
    cout<<ans<<endl;
}
int main() {
    init();
    return 0;
}

