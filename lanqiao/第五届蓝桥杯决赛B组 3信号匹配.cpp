/*
标题：信号匹配

    从X星球接收了一个数字信号序列。

    现有一个已知的样板序列。需要在信号序列中查找它首次出现的位置。这类似于串的匹配操作。

    如果信号序列较长，样板序列中重复数字较多，就应当注意比较的策略了。可以仿照串的KMP算法，
进行无回溯的匹配。这种匹配方法的关键是构造next数组。

    next[i] 表示第i项比较失配时，样板序列向右滑动，需要重新比较的项的序号。
如果为-1，表示母序列可以进入失配位置的下一个位置进行新的比较。

    下面的代码实现了这个功能，请仔细阅读源码，推断划线位置缺失的代码。

// 生成next数组 
int* make_next(int pa[], int pn)
{
	int* next = (int*)malloc(sizeof(int)*pn);
	next[0] = -1;
	int j = 0;
	int k = -1;
	while(j < pn-1){
		if(k==-1 || pa[j]==pa[k]){
			j++;
			k++;
			next[j] = k;
		}
		else
			k = next[k];
	}
	
	return next;
}

// da中搜索pa， da的长度为an, pa的长度为pn 
int find(int da[], int an, int pa[], int pn)
{
	int rst = -1;
	int* next = make_next(pa, pn);
	int i=0;  // da中的指针 
	int j=0;  // pa中的指针
	int n = 0;
	while(i<an){
		n++;
		if(da[i]==pa[j] || j==-1){
			i++;
			j++;
		}
		else
			__________________________;  //填空位置
		
		if(j==pn) {
			rst = i-pn;
			break;
		}
	}
	
	free(next);
		
	return rst;
}

int main()
{
	int da[] = {1,2,1,2,1,1,2,1,2,1,1,2,1,1,2,1,1,2,1,2,1,1,2,1,1,2,1,1,1,2,1,2,3};
	int pa[] = {1,2,1,1,2,1,1,1,2};
	
	int n = find(da, sizeof(da)/sizeof(int), pa, sizeof(pa)/sizeof(int));
	printf("%d\n", n);
	
	return 0;
}



注意：通过浏览器提交答案。只填写缺少的内容，不要填写任何多余的内容（例如：说明性文字或已有符号）
answer:j=next[j];

*/ 
#include<bits/stdc++.h>
using namespace std;
int* make_next(int pa[], int pn)
{
	int* next = (int*)malloc(sizeof(int)*pn);
	next[0] = -1;
	int j = 0;
	int k = -1;
	while(j < pn-1){
		if(k==-1 || pa[j]==pa[k]){
			j++;
			k++;
			next[j] = k;
		}
		else
			k = next[k];
	}
	for(int i=0;i<pn;i++)
		cout<<next[i]<<' ';
	cout<<endl;
	return next;
}

// da中搜索pa， da的长度为an, pa的长度为pn 
int find(int da[], int an, int pa[], int pn)
{
	int rst = -1;
	int* next = make_next(pa, pn);
	int i=0;  // da中的指针 
	int j=0;  // pa中的指针
	int n = 0;
	while(i<an){
		n++;
		if(da[i]==pa[j] || j==-1){
			i++;
			j++;
		}
		else
			j=next[j];
//			__________________________;  //填空位置
		
		if(j==pn) {
			rst = i-pn;
			break;
		}
	}
	
	free(next);
		
	return rst;
}
int main()
{
//	int da[] = {1,2,1,2,1,1,2,1,2,1,1,2,1,1,2,1,1,2,1,2,1,1,2,1,1,2,1,1,1,2,1,2,3};
//	int pa[] = {1,2,1,1,2,1,1,1,2};
	int da[]={1,2,3,4,1,2,3,4,5,6,1,2,3,4,5,6,7,8};
	int pa[]={1,2,3,4,5};
	int n = find(da, sizeof(da)/sizeof(int), pa, sizeof(pa)/sizeof(int));
	printf("%d\n", n);
	for(int i=n;i<sizeof(pa)/sizeof(int);i++)
		cout<<da[i]<<' ';
	cout<<endl;
	return 0;
}
