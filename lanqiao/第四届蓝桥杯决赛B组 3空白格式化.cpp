/*
标题：空白格式化

    本次大赛采用了全自动机器测评系统。

    如果你的答案与标准答案相差了一个空格，很可能无法得分，所以要加倍谨慎！

    但也不必过于惊慌。因为在有些情况下，测评系统会把你的答案进行“空白格式化”。
	其具体做法是：去掉所有首尾空白；中间的多个空白替换为一个空格。所谓空白指的是：空格、制表符、回车符。

    以下代码实现了这个功能。仔细阅读代码，填写缺失的部分。


void f(char* from, char* to)
{
	char* p_from = from;
	char* p_to = to;
	
	while(*p_from==' ' || *p_from=='\t' || *p_from=='\n') p_from++;
	
	do{
		if(*p_from==' ' || *p_from=='\t' || *p_from=='\n'){ 
			do{p_from++;} while(*p_from==' ' || *p_from=='\t' || *p_from=='\n');
			if(____________________) *p_to++ = ' ';  //填空位置
		}
	}while(*p_to++ = *p_from++);
}


    请分析代码逻辑，并推测划线处的代码，通过网页提交。
    注意：仅把缺少的代码作为答案，千万不要填写多余的代码、符号或说明文字！！
本以为填1就行，但是尾部不能有空格
如果 空格持续到 结束 就不赋值 空格
answer:*p_from 
*/
#include<bits/stdc++.h>
using namespace std;
char a[]={" 0123   789 "} , b[100]={'\0'};
void f(char* from, char* to)
{
	char* p_from = from;
	char* p_to = to;
	
	while(*p_from==' ' || *p_from=='\t' || *p_from=='\n') 
		p_from++;
	
	do{

		if(*p_from==' ' || *p_from=='\t' || *p_from=='\n')
		{ 
			do
			{
				p_from++;
			} while(*p_from==' ' || *p_from=='\t' || *p_from=='\n');
			
	   		if(*p_from) *p_to++ = ' ';  //填空位置
		}
	}while(*p_to++ = *p_from++);
}
int main()
{
	
	f(a,b);
	for(int i=0;b[i]!='\0';i++)
	{
		if(b[i]==' ') cout<<'*';
		else cout<<b[i];
	}
	return 0;
} 
