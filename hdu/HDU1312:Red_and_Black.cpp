/*

��������
��һ�������εķ��䣬���Ϲ㳡ש��
ÿ����Ƭ��Ⱦ�ɺ�ɫ���ɫ��һ��������վ��һ����ɫ�Ĵ�ש��
���ߣ��������ƶ����ĸ����ڵĴ�ש֮һ��
�����������ں��߶�����ֻ���ں�ɫtiles.Write�ƶ����������ɫ��ש��������ͨ���ظ��������ƶ��ﵽ��������
 

����
�����ɶ�����ݼ������ݼ����������������W��H���߿�ʼ;
 W��H����Ƭ�е�x��y����ĺ��룬�ֱ�
 W��H������20.There�����ݼ������е�ÿһ������W ^�ַ�H�����С�ÿ���ַ�����һ����Ƭ���µ���ɫ��
'' -��ɫ��ש
������ -����
��@�� -һ����ɫ��ש���ˣ�ǡ�ó���һ�ε����ݼ���

����
����ÿ�����ݼ������ĳ���Ӧ��������������Դ�����Ĵ�ש�ﵽ����ĸ����ߣ�������������
 

��������
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
 

�������
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