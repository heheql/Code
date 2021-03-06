/*

问题描述
有一个长方形的房间，铺上广场砖。
每个瓦片被染成红色或黑色。一名男子正站在一个黑色的瓷砖。
从瓦，他可以移动到四个相邻的瓷砖之一。
但是他不能在红瓦动，他只能在黑色tiles.Write移动程序计数黑色瓷砖，他可以通过重复上述的移动达到的数量。
 

输入
输入由多个数据集。数据集与包含两个正整数W和H的线开始;
 W和H是瓦片中的x和y方向的号码，分别。
 W和H不超过20.There在数据集，其中的每一个包括W ^字符H以下行。每个字符代表一个瓦片如下的颜色。
'' -黑色瓷砖
“＃” -红瓦
“@” -一个黑色瓷砖男人（恰好出现一次的数据集）

产量
对于每个数据集，您的程序应该输出包含他可以从最初的瓷砖达到区块的个数线（包括自身）。
 

样本输入
6 9
....#.
.....#
......
......
......
......
......
#@...#
.#..#.
11 9
.#.........
.#.#######.
.#.#.....#.
.#.#.###.#.
.#.#..@#.#.
.#.#####.#.
.#.......#.
.#########.
...........
11 6
..#..#..#..
..#..#..#..
..#..#..###
..#..#..#@.
..#..#..#..
..#..#..#..
7 7
..#.#..
..#.#..
###.###
@......
###.###
..#.#..
..#.#..
0 0
 

样本输出
45
59
6
13
*/
#include<bits/stdc++.h>
using namespace std;
bool visit[25][25];
vector<vector<char> > v;
int h,l,x,y,sum;
void dfs(int x,int y)
{
	if(x>=0&&y>=0&&x<h&&y<l&&visit[x][y]==false&&v[x][y]!='#')
	{
		sum++;
		visit[x][y]=true;
		dfs(x-1,y);
		dfs(x+1,y);
		dfs(x,y+1);
		dfs(x,y-1);
	}
}
int main()
{
	
	while(1)
	{	
		cin>>l>>h;
		if(l==0&&h==0) break;		
		
		sum=0;
		v.resize(h);
		memset(visit,false,sizeof(visit));
		
		for(int i=0;i<h;i++)
		{
			for(int j=0;j<l;j++)
			{
				char t;
				cin>>t;
				v[i].push_back(t);
				if(t=='@') x=i,y=j; 
			}
		}
		dfs(x,y);
		cout<<sum<<endl;
		v.clear();
	}
	return 0;
}
