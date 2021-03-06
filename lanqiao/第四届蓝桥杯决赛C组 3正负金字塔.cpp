/*

标题：正负金字塔

    看下面的图形：

     + - + - - + - + - - + - - + -
      - - - + - - - - + - - + - -
       + + - - + + + - - + - - +
        + - + - + + - + - - + -
         - - - - + - - - + - -
          + + + - - + + - - +
           + + - + - + - + -
            + - - - - - - -
             - + + + + + +
              - + + + + +
               - + + + +
                - + + +
                 - + +
                  - +
                   -

    它是由正号和负号组成的金字塔形状。其规律是：每个符号的左上方和右上方符号如果相同，则输出为正号，否则为负号。其第一行数据由外部输入。

    以下代码实现了该功能。请仔细阅读代码，并填写划线部分缺失的代码。


void f(char* x, int space, int n)
{
	int i;
	if(n<1) return;

	for(i=0; i<space; i++) printf(" ");
	for(i=0; i<n; i++) printf("%c ", x[i]);
	printf("\n");
	
	for(i=0; i<n-1; i++) x[i] = ____________________________;
	f(x,space+1,n-1);		 
}

// 用于f的测试
int test()
{
	char x[] = "+-+--+-+--+--+-";
	//char x[] = "+-+";
	f(x, 5, sizeof(x)-1);
	return 0;
}



    请分析代码逻辑，并推测划线处的代码，通过网页提交。
    注意：仅把缺少的代码作为答案，千万不要填写多余的代码、符号或说明文字！！
answer:(x[i]==x[i+1])?'+':'-' 
*/
#include<bits/stdc++.h>
using namespace std;
void f(char* x, int space, int n)
{
	int i;
	if(n<1) return;

	for(i=0; i<space; i++) 
		printf(" ");
	for(i=0; i<n; i++) 
		printf("%c ", x[i]);
	printf("\n");
	
	for(i=0; i<n-1; i++) 
		x[i] = (x[i]==x[i+1])?'+':'-';
	f(x,space+1,n-1);		 
}

// 用于f的测试
int main()
{
//	char x[] = "+-+--+-+--+--+-";
	char x[] = "+-+";
	f(x, 5, sizeof(x)-1);
	return 0;
}
