#include <cstring>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>  
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

int cmpare(const pair<string, int>& x, const pair<string, int>& y)  {  //value比较 
    return x.second > y.second;   
}  
   
void sort(map<string, int>& tMap,vector<pair<string, int> >& wordVector)  {  //词频排序 
    for (map<string, int>::iterator curr = tMap.begin(); curr != tMap.end(); curr++)   
        wordVector.push_back(make_pair(curr->first, curr->second));    
   
    sort(wordVector.begin(), wordVector.end(), cmpare);  
} 

bool isSeparator(char c){//判断分隔符：所有非数字且非字母 
	return !(isupper(c)||islower(c)||isdigit(c));
}

bool isValidWord(string str){//判断有效单词 
	if (str.length()<4)
		return false;
	char c[wordsmax*wordslength];
	strcpy(c,str.c_str());//转为字符数组 
	for (int i=0;i<4;i++){
		if(!(isupper(c[i])||islower(c[i]))){
			return false;
		}
	}
}

int CountLines(char *filename){//获取行数 
	ifstream ReadFile;
	int n=0;
	char line[wordsmax/wordsPerRow];
	string temp;
	ReadFile.open(filename,ios::in);//用只读的方式读取文件
	if(ReadFile.fail())//文件打开失败:返回0
	{
	   return 0;
	}
	else//文件存在
	{
	while(getline(ReadFile,temp)!=NULL)
	{
	 
	   n++;
	}
	    return n;
	}
	ReadFile.close();
}

int getCharNum(Words *words) {//从单词中统计字符 
	ifstream fin,in;
	ofstream fout;
	fin.open("input.txt",ios::in | ios::out | ios::binary);//打开文件
	fout.open("output.txt",ios::in | ios::out | ios::binary);//写入文件 
	if(!fin) {
		cout<<"文件打开错误！"<<endl;
		return -1;
	}
	int num=0,i,charnum=0,lines=0;
	char c;
	in.open("input.txt",ios::in);
	while(!in.eof())
	{	 
	if(c!='\n') charnum++;
	  else
	   charnum+=0;
		in>>c;
	}
	in.close();
	string word;
		while(fin) {
			fin>>word; //从文件读单词
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
				num++; //单词种类加一 
			}
		}
	fout<<"characters:"<<charnum-1<<endl; 
	fin.close(); //关闭文件
	fout.close();//关闭文件 
	return charnum; //返回字符数
}

void countCharNum(){//输出字符个数 
	Words words[wordsmax] = {"",0}; //单词对象变量定义与初始化
	ofstream fout;
	fout.open("output.txt");
	int n=getCharNum(words); //获取字符数 
	fout<<"搜索出共"<<n<<"个字符。"<<endl;
	fout.close();
} 
int main(int argc, char *argv[])
{	
	int cnt=0;
	ifstream fin;
	fin.open("input.txt");//打开文件 
	if(fin.fail())
	{
		cout <<"ifstream open file error"<<endl;
		return -1;
	}
    map<string, int> tMap;  
    string word; 
    while (fin >> word)  
    {  
        pair<map<string,int>::iterator,bool> ret = tMap.insert(make_pair(word, 1));  
        if (!ret.second)  
            ++ret.first->second;  
    }   
   
    vector<pair<string,int> > wordVector;  
    sort(tMap,wordVector);  
    for(int i=0;i<wordVector.size();i++)  
    cout<<wordVector[i].first<<": "<<wordVector[i].second<<endl;  
	return 0;
}
