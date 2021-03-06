/*
标题：骰子迷题

    小明参加了少年宫的一项趣味活动：每个小朋友发给一个空白的骰子（它的6个面是空白的，没有数字），要小朋友自己设计每个面写哪个数字。但有如下要求：

    1. 每个面只能填写 0 至 8 中的某一个数字。

    2. 不同面可以填写同样的数字，但6个面总和必须等于24。

    填好后，小朋友可以用自己填写好数字的骰子向少年宫的两个机器人挑战----玩掷骰子游戏。规则如下：

    三方同时掷出自己的骰子，如果出现任何相同的数字，则三方都不计分。
  
    如果三方数字都不同，则最小数字一方扣 1 分，最大数字一方加 1 分。
   
    小明看到了两个机器人手中的骰子分别是：

    0 0 0 8 8 8
  
    1 1 4 5 6 7

    请你替小明算一下，他如何填写，才能使自己得分的概率最大。

    请提交小明应该填写的6个数字，按升序排列，数字间用一个空格分开。

    如果认为有多个答案，提交字母序最小的那个方案。

    请严格按照格式，通过浏览器提交答案。
    注意：只提交一行内容，含有6个被空格分开的数字。不要写其它附加内容，比如：说明性的文字。
*/
#include <bits/stdc++.h>
using namespace std;
int a[6];
int b[6];
int maxn=-1000;
bool visit[9];

void check()
{
	int sum=0;
	for(int i=0;i<6;i++)
	{
		if(a[i]>0) sum+=3;
		if(a[i]<8) sum-=3;
		
		if(a[i]>1) sum+=2;
		else if(a[i]<1) sum-=2;
		
		if(a[i]>4) sum++;
		else if(a[i]<4) sum--;
		
		if(a[i]>5) sum++;
		else if(a[i]<5) sum--;
		
		if(a[i]>6) sum++;
		else if(a[i]<6) sum--;
		
		if(a[i]>7) sum++;
		else if(a[i]<7) sum--;

	}
	if(sum>maxn) 
	{
		maxn=sum;
		memcpy(b,a,sizeof(a));
	}
	
}
void dfs(int a[],int deep)
{

	if(deep==6)
	{	
		if(accumulate(a,a+6,0)==24)
				check();
		return ;
	}
	for(int i=0;i<=8;i++)
	{
		
			a[deep]=i;
			dfs(a,deep+1);

	}
}
int main()
{
    dfs(a,0);
	for(int i=0;i<6;i++)
	{
		cout<<b[i]<< ' ';
	}
	cout<<endl;
    return 0;
}

