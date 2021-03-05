#include <cstring>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>  
const int rowsPerPar=4;//ÿ�ε����������
const int wordsPerRow=15;//ÿ�е�������
const int wordsmax=300;//��󵥴���
const int wordslength=7;//���ʳ���

using namespace std;
int num=0,i,lines=0,validnum=0;
 
class Paper{//���ļ��������� 
public:
	void fread(char * filename);
	void fwrite(char * filename);
private:
	map<string,int> words;
};

class Words{ //������
	public:
		string word; //����
		int cnt; //����
};

int cmpare(const pair<string, int>& x, const pair<string, int>& y)  {  //value�Ƚ� 
    return x.second > y.second;   
}  
   
void sort(map<string, int>& tMap,vector<pair<string, int> >& wordVector)  {  //��Ƶ���� 
    for (map<string, int>::iterator curr = tMap.begin(); curr != tMap.end(); curr++)   
        wordVector.push_back(make_pair(curr->first, curr->second));    
   
    sort(wordVector.begin(), wordVector.end(), cmpare);  
}  

bool isSeparator(char c){//�жϷָ��������з������ҷ���ĸ 
	return !(isupper(c)||islower(c)||isdigit(c));
}

int getCharNum(Words *words) {//�ӵ�����ͳ���ַ� 
	ifstream fin,in;
	ofstream fout;
	fin.open("input.txt",ios::in | ios::out | ios::binary);//���ļ�
	fout.open("output.txt",ios::in | ios::out | ios::binary);//д���ļ� 
	if(!fin) {
		cout<<"�ļ��򿪴���"<<endl;
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
			fin>>word; //���ļ�������
			if(!fin) {
				break;//�ļ���β 
			}
			bool flag = false;
			for(i=0;i<num;i++) {
				if(word==words[i].word) { //ÿ�δ�����������ҵ��õ���
					flag=true;//���ʱ��Ϊ"��ͬ" 
					words[i].cnt++; //�õ��ʵ�������һ 
					break;
				}
			}
			
			if(!flag) { //���ʱ��Ϊ"��ͬ" 
				words[i].cnt=1; //�µĵ��ʼ���Ϊ1
				words[i].word=word; //����õ���
				num++; //���������һ 
			}
		}
	fout<<"characters:"<<charnum-1<<endl; 
	fin.close(); //�ر��ļ�
	fout.close();//�ر��ļ� 
	return charnum; //�����ַ���
}
 
bool isValidWord(string str){//�ж���Ч���� 
	if (str.length()<4)
		return false;
	char c[10000];
	strcpy(c,str.c_str());//תΪ�ַ����� 
	for (int i=0;i<4;i++){
		if((!(isupper(c[i])||islower(c[i])))){
					
			return false;
		}	
	}
}

int CountLines(char *filename){//��ȡ���� 
	ifstream ReadFile;
	int n=0;
	char line[wordsmax/wordsPerRow];
	string temp;
	ReadFile.open(filename,ios::in);//��ֻ���ķ�ʽ��ȡ�ļ�
	if(ReadFile.fail())//�ļ���ʧ��:����0
	{
	   return 0;
	}
	else//�ļ�����
	{
	while(getline(ReadFile,temp)!=NULL)
	{
	 
	   n++;
	}
	    return n;
	}
	ReadFile.close();
}

void createPaperAuto(){//������������� 

	int rcnt=0,wcnt=0,wcntPerRow=0,lines=1,charNum=0;//������������������������ ,���� ,�ַ��� 
	ofstream fout1,fout2;//д�ļ� 
	fout1.open("input_random.txt");
	fout2.open("output_random.txt");
	int n=rand()%(3*wordsmax/4)+wordsmax/4;//�������� (k/4~k),ʹ�������ݾ������� 
	cout<<"�õ�"<<n<<"����ʼ���ʵ�����:"<<endl;
	cout<<"    ";//���������ĸ��ַ�	
	fout1<<"        ";		
	while(n--)                              //���ɵ��� 
	{
		int k=rand()%wordslength+4;         //ÿ�����ʵĳ��� 
		for(int i=1;i<=k;i++)
		{
			int x;
			x=rand()%('~'-'!'+1)+'!';//���ɴ�'!'��'~'���ַ�����ӦASCII���33~127������������û�� 
			charNum++;
			printf("%c",x);
			fout1<<(char)x;				
		}
		printf("   ");//һ���������ɺ�ļ��
		fout1<<"   ";
		if (wcntPerRow==wordsPerRow){ 
			cout<<endl; 
			fout1<<endl;
			rcnt++;//�м�����+1
			lines++;//����+1 
			if (rcnt>=rand()%rowsPerPar+1){//ÿ�����rowsPerPar�У�����1��
				cout<<"    ";//�µĶ�����������4���ַ� 
				fout1<<"        ";
				rcnt=0;//��һ�����¼��� 
			} 
			wcntPerRow=0;//��һ�����¼��� 
		}						 
		wcnt++;//���ʼ�����
		wcntPerRow++;//ÿ�е��ʼ����� 
				
	}		
	cout<<endl<<endl<<"����д����ɣ�"<<endl;
	fout2<<"characters:"<<charNum<<endl; 
	fout2<<"words:"<<wcnt<<endl;	//����ͳ�ƣ�֮����Ϊͳ����Ч���� 
	fout2<<"lines:"<<lines<<endl;
	fout1.close();
	fout2.close();
} 

void countCharNum(){//����ַ����� 
	Words words[wordsmax] = {"",0}; //���ʶ�������������ʼ��
	ofstream fout;
	fout.open("output.txt");
	int n=getCharNum(words); //��ȡ�ַ��� 
	fout<<"characters:"<<n<<endl;
	fout.close();
} 

void Paper::fread(char * filename){//���ļ� 
	ifstream ifs(filename);//���ļ���
	if(ifs.fail())
	{
		cout <<"ifstream open file error"<<endl;
		return;
	}
	string word;
	while( ifs >> word)
	{
		if(isValidWord(word))//���Ϊ��Ч���� 
		words[word]++;
	}
 	ifs.close();
}
 
void Paper::fwrite(char * filename){//д�ļ� 
	int wcnt=0,wtype=0;//���������͵������� 
	ifstream fin;
	ofstream fout;
	int s=CountLines("input.txt");
	fin.open("input.txt",ios::app|ios::out);//���ļ� 
	fout.open("output.txt",ios::app|ios::out);
	if(fin.fail())
	{
		cout <<"ifstream open file error"<<endl;
		
	}
    map<string, int> tMap;  
    string word; 
    while (fin >> word)  
    {  	
		transform(word.begin(),word.end(),word.begin(),::tolower);
	    if(isValidWord(word)){
	        pair<map<string,int>::iterator,bool> ret = tMap.insert(make_pair(word, 1));  
	        if (!ret.second)  
	            ++ret.first->second; 
				wcnt++;
		} 
    }   
    vector<pair<string,int> > tVector; //�������>>Ҫ���� 
    sort(tMap,tVector);
    fout<<"lines:"<<s<<endl;
    fout<<"words:"<<wcnt<<endl;
    if (tVector.size()>10){
		fout<<"Ƶ����ߵ�10����������:"<<endl;
    	for(int i=0;i<10;i++)
    		fout<<tVector[i].first<<": "<<tVector[i].second<<endl;
	}
    else{
    	fout<<"Ƶ����ߵ�"<<tVector.size()<<"����������:"<<endl;
		for(int i=0;i<tVector.size();i++)  
	    	fout<<tVector[i].first<<": "<<tVector[i].second<<endl;
	}
	fin.close();
	fout.close();
}

int main(int argc,char **argv){  
	if(argc!=3){
		cout <<"����input.txt/output.txt"<<endl;
	}
	countCharNum();
	Paper p;
	p.fread(argv[1]);//input.txt
	p.fwrite(argv[2]);//output.txt
	cout<<"����output.txt�鿴�����";
	return 0;
}














