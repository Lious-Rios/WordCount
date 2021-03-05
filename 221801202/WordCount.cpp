#include<cstdio>
#include<iostream>
#include<fstream>
#include<time.h>
#include<cstring>
#include<stdlib.h>
const int rowsPerPar=4;//每段的最大行数、
const int wordsPerRow=15;//每行单词数、
const int wordsmax=300;//最大单词数
const int wordslength=7;//单词长度

using namespace std;

class Words{ //单词类
	public:
		string word; //单词
		int cnt; //数量
};

int getWords(Words *words) {//词频统计函数 
	ifstream fin;
	ofstream fout;
	fin.open("input1.txt");//打开文件
	fout.open("output.txt");//写入文件 
	if(!fin) {
		cout<<"文件打开错误！"<<endl;
		return -1;
	}
	int num=0,i,charnum=0,lines=0;
	string word;
		while(fin) {
			fin>>word; //从文件读单词
			charnum++;
			if(!fin) {
				break;//文件结尾 
			}
			bool flag = false;
			for(i=0;i<num;i++) {
				if(word==words[i].word) { //每次从数组中如果找到该单词
					flag=true;//单词标记为"相同" 
					words[i].cnt++; //该单词的数量加一 
					break;
				}
			}
			
			if(!flag) { //单词标记为"不同" 
				words[i].cnt=1; //新的单词计数为1
				words[i].word=word; //保存该单词
				num++; //总单词数加一 
			}
		}
	fout<<endl<<endl<<"characters:"<<charnum<<endl; 
	fout<<"words:"<<num<<endl;	//初步统计，之后会改为统计有效单词 
	fout<<"lines:"<<lines<<endl;
		fin.close(); //关闭文件
		fout.close();//关闭文件 
		return num; //返回单词个数
}

void createPaperAuto(){//随机文章生成器 
	int rcnt=0,wcnt=0,wcntPerRow=0,lines=1,charNum=0;//行数计数器，单词数计数器 ,行数 ,字符数 
	srand(time(0));	
	ofstream fout1,fout2;//写文件 
	fout1.open("input_random.txt");
	fout2.open("output_random.txt");
	int n=rand()%(3*wordsmax/4)+wordsmax/4;//单词限制 (k/4~k),使文章内容尽量饱满 
	cout<<"得到"<<n<<"个初始单词的文章:"<<endl;
	cout<<"    ";//首行缩进四个字符	
	fout1<<"        ";		
	while(n--)                              //生成单词 
	{
		int k=rand()%wordslength+4;         //每个单词的长度 
		for(int i=1;i<=k;i++)
		{
			int x;
			x=rand()%('~'-'!'+1)+'!';//生成从'!'到'~'的字符，对应ASCII码从33~127，其它键盘上没有 
			charNum++;
			printf("%c",x);
			fout1<<(char)x;				
		}
		printf("   ");//一个单词生成后的间隔
		fout1<<"   ";
		if (wcntPerRow==wordsPerRow){ 
			cout<<endl; 
			fout1<<endl;
			rcnt++;//行计数器+1
			lines++;//行数+1 
			if (rcnt>=rand()%rowsPerPar+1){//每段最大rowsPerPar行，最少1行
				cout<<"    ";//新的段落首行缩进4个字符 
				fout1<<"        ";
				rcnt=0;//下一段重新计数 
			} 
			wcntPerRow=0;//下一行重新计数 
		}						 
		wcnt++;//单词计数器
		wcntPerRow++;//每行单词计数器 
				
	}		
	cout<<endl<<endl<<"文章写入完成！"<<endl;
	fout2<<"characters:"<<charNum<<endl; 
	fout2<<"words:"<<wcnt<<endl;	//初步统计，之后会改为统计有效单词 
	fout2<<"lines:"<<lines<<endl;
	fout1.close();
	fout2.close();
} 

void createPaperCommand(){//文件获取文章 
	Words words[wordsmax] = {"",0}; //单词对象变量定义与初始化
	ofstream fout;
	fout.open("output,txt");
	int n=getWords(words); //获取单词
	fout<<"词频排名前十统计："<<endl;
	for(int i=0;i<n;i++)
	{
	fout<<words[i].word<<':'<<words[i].cnt<<endl;
	}
	fout<<"搜索出共"<<n<<"个单词。"<<endl;
	fout.close();
} 
int main(int argc, char **argv[])
{	
	//Words words[wordsmax] = {"",0}; //单词对象变量定义与初始化
	int choice;//文章获取方式
	cout<<"选择文章获取方式:1.随机生成|2.文件获取"<<endl; 
	cin>>choice;
	switch(choice){
		case 1:createPaperAuto();break;//随机生成,向文件写入 
		case 2:createPaperCommand();break;//从文件获取 
	}
	/*int n=getWords(words); //获取单词
	cout<<"词频排名前十统计："<<endl<<endl;
	for(int i=0;i<n;i++)
	{
		
	cout<<words[i].word<<':'<<words[i].cnt<<endl;
	}
	cout<<"一共"<<n<<"个单词"<<endl;*/
	return 0;
}
