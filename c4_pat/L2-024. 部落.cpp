/*
L2-024. 部落
在一个社区里，每个人都有自己的小圈子，还可能同时属于很多不同的朋友圈。我们认为朋友的朋友都算在一个部落里，于是要请你统计一下，在一个给定社区中，到底有多少个互不相交的部落？并且检查任意两个人是否属于同一个部落。

输入格式：

输入在第一行给出一个正整数N（<= 104），是已知小圈子的个数。随后N行，每行按下列格式给出一个小圈子里的人：

K P[1] P[2] ... P[K]

其中K是小圈子里的人数，P[i]（i=1, .., K）是小圈子里每个人的编号。这里所有人的编号从1开始连续编号，最大编号不会超过104。

之后一行给出一个非负整数Q（<= 104），是查询次数。随后Q行，每行给出一对被查询的人的编号。

输出格式：

首先在一行中输出这个社区的总人数、以及互不相交的部落的个数。随后对每一次查询，如果他们属于同一个部落，则在一行中输出“Y”，否则输出“N”。

输入样例：
4
3 10 1 2
2 3 4
4 1 5 7 8
3 9 6 4
2
10 5
3 7
输出样例：
10 2
Y
N
*/
#include<bits/stdc++.h>
using namespace std;
int f[10010];
void init()
{
	for(int i=0;i<=10010;i++)
	{
		f[i]=i;
	}
}
int find(int x)
{
	if(f[x]==x)return x;
	else return f[x]=find(f[x]);
}
void cmb(int a,int b)
{
	a=find(a);
	b=find(b);
	if(a<b) f[b]=a;
	else f[a]=b;
}
int sum(int n)
{
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		if(f[i]==i) sum++;
	}
	return sum;
}
int main()
{
	int n;
	set<int> k;
	init();
	cin>>n;
	while(n--)
	{
		int num;
		cin>>num;
		int p;
		cin>>p;
		k.insert(p);
		while(--num)
		{
			int t;
			cin>>t;
			k.insert(t);
			cmb(p,t);
		}
	}
	cout<<k.size()<<' '<<sum(k.size())<<endl;
	cin>>n;
	while(n--)
	{
		int a,b;
		cin>>a>>b;
		if(find(a)==find(b)) cout<<'Y'<<endl;
		else cout<<'N'<<endl; 
	}
	return 0;
} 
