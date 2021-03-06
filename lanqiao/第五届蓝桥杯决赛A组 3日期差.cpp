/*

标题：日期差

    历史上，不同的人类聚居地可能有不同的历法，因而记录下来的资料中日期的换算就很麻烦。
	幸好今天我们统一使用公元纪年法。当然，这种历法对求两个日期差多少天也不是十分简便，但毕竟是可以忍受的。

    下面的程序计算了两个日期的差值，两个日期都使用公元纪年法。

    请分析程序逻辑，并推断划线部分缺失的代码。

int to_day(int y, int m, int d)
{
	int mon[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
	int day = 0;
	int i;
	for(i=1; i<y; i++){
		day += (i%4==0 && i%100!=0 || i%400==0)? 366 : 365;
	}
	
	if(y%4==0 && y%100!=0 || y%400==0) mon[2]++;
	
	for(i=1; i<m; i++){
		_____________________;  //填空位置
	}
	
	return day + d;
}

int diff(int y1, int m1, int d1, int y2, int m2, int d2)
{
	int a = to_day(y1, m1, d1);
	int b = to_day(y2, m2, d2);
	return b-a;
}

int main()
{
	int n = diff(1864,12,31,1865,1,1);
	printf("%d\n", n);
	return 0;
}

注意：通过浏览器提交答案。只填写缺少的内容，不要填写任何多余的内容（例如：说明性文字或已有符号）。
answer: day+=mon[i];
*/
#include<bits/stdc++.h>
using namespace std;
int to_day(int y, int m, int d)
{
	int mon[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
	int day = 0;
	int i;
	for(i=1; i<y; i++){
		day += (i%4==0 && i%100!=0 || i%400==0)? 366 : 365;
	}
	
	if(y%4==0 && y%100!=0 || y%400==0) mon[2]++;
	
	for(i=1; i<m; i++){
			day+=mon[i];  //填空位置
	}
	
	return day + d;
}

int diff(int y1, int m1, int d1, int y2, int m2, int d2)
{
	int a = to_day(y1, m1, d1);
	int b = to_day(y2, m2, d2);
	return b-a;
}

int main()
{
	int n = diff(1864,12,31,1865,1,1);
	printf("%d\n", n);
	cout<<diff(2017,1,1,2017,1,31);
	return 0;
} 
