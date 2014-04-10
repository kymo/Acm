/*
 * Author:  mybestwishes
 * Created Time:  2014/3/22 20:50:36
 * File Name: 2528.cpp
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
int ans = 0;
bool tag[10001];
int a[10001];
int b[10001];
struct line
{
    int s;
    int id;
};
line seg[200001];
typedef struct node
{
    int left, right;
    int index;
    node(int _left, int _right)
    {
        left = _left;
        right = _right;
    }
    struct node *left_child;
    struct node *right_child;
}TreeNode;


bool cmp(line a, line b)
{
    return a.s < b.s;
}

void build(TreeNode *node, int left ,int right)
{
    node->left_child = (TreeNode*)malloc(sizeof(TreeNode));
    node->right_child = (TreeNode*)malloc(sizeof(TreeNode));
    node->left = left;
    node->index = 0;
    node->right = right;
    if(right - left == 0)
        return;
    int mid = (left + right) / 2;
    build(node->left_child, left, mid);
    build(node->right_child, mid + 1, right);
}

void insert(TreeNode *node, int left ,int right, int index)
{
    cout<<"sdf"<<endl;
    cout<<left<<" "<<right<<" "<<index<<" "<<endl;
    if(node->left == left && node->right == right)
    {
        node->index = index;
        if(right - left == 0)
            return;
        insert(node->left_child, node->left_child->left, node->left_child->right, index);
        insert(node->right_child, node->right_child->left, node->right_child->right, index);
        return;
    }   
    int mid = (node->right + node->left) / 2;
    if(right <= mid)
    {
        insert(node->left_child, left, right, index);
    }
    else if(left < mid)
    {
        insert(node->left_child, left, mid, index);
        insert(node->right_child, mid + 1, right, index);
    }
    else
    {
        insert(node->right_child, left, right, index);
    }
    
}

void display(TreeNode *node)
{
    if(node->right - node->left == 0)
    {
        if(node->index != 0)
        {
            tag[node->index] = true;
        }
        return;
    }
    display(node->left_child);
    display(node->right_child);
}

int main() {
    int c, n;
    scanf("%d", &c);
    for(int i = 0; i < c; i ++)
    {
       
        TreeNode *node;
        node = (TreeNode*)malloc(sizeof(TreeNode));
        scanf("%d", &n);
        memset(tag ,false ,sizeof(tag));
        ans = 0;
        for(int j = 0; j < n; j ++)
        {
            scanf("%d %d", &a[j], &b[j]);
            seg[j * 2].s = a[j];
            seg[j * 2].id = -(j);
            seg[j * 2 + 1].s = b[j];
            seg[j * 2 + 1].id = j;
        }
        sort(seg, seg + 2 * n, cmp);
        int tmp = seg[0].s, num = 1;
        for(int j = 0; j < 2 * n ; j++)
        {
            if(seg[j].s != tmp)
            {
                num += 1;
                tmp = seg[j].s;
            }
            if(seg[j].id < 0)
                a[-seg[j].id] = num;
            else
                b[seg[j].id] = num;
        } 
        
        build(node, 1, 2 * n);
        cout<<"sdf"<<endl;
        for(int j = 0; j < n; j ++)
        {
            insert(node, a[j], b[j], j + 1);
        }
        cout<<"sdsdff"<<endl;
        display(node);
        
        for(int j = 1; j <= n; j ++)
        {
            if(tag[j])
                ans ++;
        }
        delete node;
        printf("%d\n", ans); 
    }
    return 0;
}

