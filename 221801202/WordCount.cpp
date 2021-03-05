/*第二次修改：用户控制单词数，单词长度。通过显示看效果*/
#include<cstdio>
#include<iostream>
#include<fstream>
#include<time.h>
#include<cstring>
#include<stdlib.h>
using namespace std;


int main()
{	
	char c;
	int wordsmax,wordslength;//最大单词数，单词长度
	srand(time(0));	
	ofstream fout;
	fout.open("w2.txt");
	cout<<"请限制单词数量：";
	cin>>wordsmax; 
	cout<<"请限制单词长度：";//单词越长，每个单词出现的频率越低 
	cin>>wordslength;
	int n=rand()%(3*wordsmax/4)+wordsmax/4;//单词限制 (k/4~k),使文章内容尽量饱满 
	cout<<"于是，你得到"<<n<<"个单词的文章"<<endl;                                      
	cout<<"是否显示文章？（y|n）：";
	cin>>c;
	putchar('\n');
	cout<<"   ";//首行缩进四个字母 			
	while(n--)                              //生成单词 
	{
		int k=rand()%wordslength+4;         //每个单词的长度 
		for(int i=1;i<=k;i++)
		{
			int x,s;                         //x表示当前字符的ascii码 ，s控制字符的大小写  
			s=rand()%2;                      //随机使s为1或0 
			if(s==1){                        //s=1,x->大写字母
				x=rand()%('Z'-'A'+1)+'A'; 	 
			}     
			else {							 //s=0,x->小写字母 
				x=rand()%('z'-'a'+1)+'a';    
			}
			if (c=='y'){
				printf("%c",x);

				fout<<(char)x;
			}
			if (c=='n') {
				fout<<(char)x;	
			}        
						
		}
		wcnt++;
		printf(" ");						//单词间的空格  
		fout<<" ";		
	}		
	cout<<endl<<"一共"<<wcnt<<"个单词";//初步统计，之后会改为有效单词数	
	fout.close();
	return 0;
}
