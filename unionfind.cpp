#include <iostream>

using namespace std;


/*
题目背景
若某个家族人员过于庞大，要判断两个是否是亲戚，确实还很不容易，现在给出某个亲戚关系图，求任意给出的两个人是否具有亲戚关系。
题目描述
规定：x和y是亲戚，y和z是亲戚，那么x和z也是亲戚。如果x,y是亲戚，那么x的亲戚都是y的亲戚，y的亲戚也都是x的亲戚。
输入格式
第一行：三个整数n,m,p，（n<=5000,m<=5000,p<=5000），分别表示有n个人，m个亲戚关系，询问p对亲戚关系。
以下m行：每行两个数Mi，Mj，1<=Mi，Mj<=N，表示Mi和Mj具有亲戚关系。
接下来p行：每行两个数Pi，Pj，询问Pi和Pj是否具有亲戚关系。
输出格式
P行，每行一个’Yes’或’No’。表示第i个询问的答案为“具有”或“不具有”亲戚关系。

输入 #1
6 5 3
1 2
1 5
3 4
5 2
1 3
1 4
2 3
5 6

输出 #1
Yes
Yes
No
*/

int fa[5001];

void init(int n) {
    for(int i = 1; i <= n; ++i)
        fa[i] = i;
}

int find(int x) {
    if(x == fa[x]) {
        return x;
    }
    else {
        fa[x] = find(fa[x]);
        return fa[x];
    }
}

void merge(int i, int j) {
    fa[find(i)] = find(j);
}

int main()
{
    int n, m, p, x, y;
    cin>>n>>m>>p;
    init(n);
    for(int i = 0; i < m; ++i) {
        cin>>x>>y;
        merge(x, y);
    }
    for(int i = 0; i <= p; ++i) {
        cin>>x>>y;
        if(find(x) == find(y)) {
            cout<<"true"<<endl;
        }
        else {
            cout<<"False"<<endl;
        }
    }
}