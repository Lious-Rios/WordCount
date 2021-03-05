
#include<cstdio>
#include<iostream>
#include<fstream>
#include<time.h>
#include<cstring>
#include<stdlib.h>
const int rowsPerPar=2;//每段的最大行数、
const int wordsPerRow=4;//每行单词数、
const int wordsmax=10;//最大单词数
const int wordslength=5;//单词长度

using namespace std;

void createPaper(void){
	
} 
int main(int argc,char *argv[])
{	
	int rcnt=0,wcnt=0,wcntPerRow=0,lines=1,charNum=0;//行数计数器，单词数计数器 ,行数 ,字符数 
	srand(time(0));	
	ofstream fout;
	fout.open("w2.txt");
	int n=rand()%(3*wordsmax/4)+wordsmax/4;//单词限制 (k/4~k),使文章内容尽量饱满 
	cout<<"得到"<<n<<"个初始单词的文章:"<<endl;
	cout<<"    ";//首行缩进四个字符			
	while(n--)                              //生成单词 
	{
		int k=rand()%wordslength+4;         //每个单词的长度 
		for(int i=1;i<=k;i++)
		{
			int x;
			x=rand()%('~'-'!'+1)+'!';//生成从'!'到'~'的字符，对应ASCII码从33~127，其他键盘上没有 
			charNum++;
			printf("%c",x);
			fout<<(char)x;				
		}
		printf("  ");//一个单词生成后的间隔
		if (wcntPerRow==wordsPerRow){ 
			cout<<endl; 
			rcnt++;//行计数器+1
			lines++; 
			if (rcnt>=rand()%rowsPerPar+1){//每段最大rowsPerPar行，最少1行
				cout<<"    ";//新的段落首行缩进4个字符 
				rcnt=0;//下一段重新计数 
			} 
			wcntPerRow=0;//下一行重新计数 
		}						 
		wcnt++;//单词计数器
		wcntPerRow++;//每行单词计数器 
		fout<<" ";
				
	}		
	cout<<endl<<endl<<"characters:"<<charNum<<endl; 
	cout<<"words:"<<wcnt<<endl;	//初步统计，之后会改为统计有效单词 
	cout<<"lines:"<<lines<<endl;
	fout.close();
	return 0;
}
