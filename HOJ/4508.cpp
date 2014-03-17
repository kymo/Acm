/*
 * Author:  mybestwishes
 * Created Time:  2013/3/22 11:06:38
 * File Name: 4508.cpp
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
int a[101], b[101];
int n, m;
int f[101][100001];



int main() {
    int n;
    while(scanf("%d", &n) != EOF)
    {
        for(int j = 1; j <= n; j ++)
            scanf("%d %d", &a[j], &b[j]);
        scanf("%d", &m);
        for(int j = 0; j <= n; j ++)
            f[j][0] = 0;
        for(int j = 0; j <= m; j ++)
            f[0][j] = 0;
        for(int j = 1; j <= n; j ++)
        {
            for(int k = 1; k <= m; k ++)
            {
                if(k - b[j] >= 0)
                {
                    int t = k;
                    int mx = 0, cnt = 0;
                    while(t >= 0)
                    {
                        int temp = f[j - 1][k - b[j] * cnt];
                        if(cnt != 0)
                            temp += cnt * a[j];
                        mx = (mx > temp) ? mx : temp;
                        cnt ++;
                        t = k - cnt * b[j];
                    }
                    f[j][k] = mx;
                }
                else
                    f[j][k] = f[j - 1][k];
            }
        }
        
        printf("%d\n", f[n][m]);
    }
    return 0;
}

