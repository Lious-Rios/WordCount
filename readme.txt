/*基本能够实现文章的生成并写入文件，用作测试样例*/
#include<cstdio>
#include<iostream>
#include<fstream>
#include<time.h>
#include<cstring>
#include<stdlib.h>
using namespace std;
const int WORDSMAX=1000;//最大单词数 
const int WORDSLENGTH=5;//最大单词长度 

int main()
{	
	srand(time(0));	
	ofstream fout;
	fout.open("w2.txt");
	int n=rand()%(3*WORDSMAX/4)+WORDSMAX/4;//单词限制 (k/4~k),使文章内容尽量饱满 
	cout<<"   ";//首行缩进四个字母 
	while(n--)                              //开始生成单词 
	{
		printf(" ");						//单词间的空格  
		int k=rand()%WORDSLENGTH+1;         //每个单词的长度 
		for(int i=1;i<=k;i++)
		{
			int x,s;                         //x表示当前字符的ascii码 ，s控制字符的大小写  
			s=rand()%2;                      //随机使s为1或0 
			if(s==1)
			{                        		 //s=1,x->大写字母
				x=rand()%('Z'-'A'+1)+'A'; 	 
			}     
			else {							 //s=0,x->小写字母 
				x=rand()%('z'-'a'+1)+'a';    
			}
			printf("%c",x);  
			fout<<(char)x;   //写入文件
		}
		fout<<" ";
	}	
	fout.close();
	return 0;
}
