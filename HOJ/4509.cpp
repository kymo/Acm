/*
 * Author:  mybestwishes
 * Created Time:  2013/3/21 19:56:48
 * File Name: 3.cpp
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
long long MOD = 1000000007;
typedef struct timeline
{
    int begin;
    int end;
}line;

bool cmp(line a, line b)
{
    if(a.begin == b.begin)
        return a.end < b.end;
    else
        return a.begin < b.begin;
}

line TL[500001];
int main()
{
    int n;
    while(scanf("%d", &n) != EOF)
    {
        for(int j = 0; j < n; j ++)
        {
            int h1, h2, h3, h4;
            scanf("%d:%d %d:%d", &h1, &h2, &h3, &h4);
            TL[j].begin = h1 * 60 + h2;
            TL[j].end = h3 * 60 + h4;
        }
        stable_sort(TL, TL + n, cmp);
        /*for(int j = 0; j < n; j ++)
            cout<<TL[j].begin<<" "<<TL[j].end<<endl;
        */
        line S = TL[0];
        int ans = 0;
        for(int j = 1; j < n; j ++)
        {
            if(S.end < TL[j].begin)
            {
                ans += S.end - S.begin;
                S = TL[j];
            }
            else if(TL[j].end > S.end)
                S.end = TL[j].end;
        }
        ans += S.end - S.begin ;
        printf("%d\n", 1440 - ans);
    }
}

