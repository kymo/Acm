/*
 * Author:  mybestwishes
 * Created Time:  2014/4/10 19:15:22
 * File Name: ztysdp_3254.cpp
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
#define mod 100000000
int state[600];
int dp[20][600];
int cur[600];
int n,m,total;
bool ok(int j, int r)
{
    if(state[j] & cur[r])
        return 0;
    return 1;
}
void init()
{
    scanf("%d %d", &m, &n);
    for(int i = 0; i < m; i ++)
    {
        cur[i] = 0;
        for(int j = 0; j < n; j ++)
        {
            int temp;
            scanf("%d", &temp);
            if(temp == 0)
            {
                cur[i] += (1 << (n - 1 - j));
            }       
        }
    }
    total = 0;
    for(int j = 0; j < (1 << n); j ++)
    {
        if(! (j & (j >> 1)))
            state[total ++] = j;
    }
    
        
    for(int j = 0; j < total; j ++)
        if(ok(j,0))
            dp[0][j] = 1;
    for(int i = 1; i < m; i ++)
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
                dp[i][j] = (dp[i][j] + dp[i - 1][k]) % mod;
            }
        }
    }
    int ans = 0;
    for(int j = 0; j < total; j ++)
    {
        ans += dp[m-1][j];
    }
    cout<<ans<<endl;
}
int main() {
    init();
    return 0;
}

