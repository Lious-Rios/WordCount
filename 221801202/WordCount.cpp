/*�����ܹ�ʵ�����µ����ɲ�д���ļ���������������*/
#include<cstdio>
#include<iostream>
#include<fstream>
#include<time.h>
#include<cstring>
#include<stdlib.h>
using namespace std;
const int WORDSMAX=1000;//��󵥴��� 
const int WORDSLENGTH=5;//��󵥴ʳ��� 

int main()
{	
	srand(time(0));	
	ofstream fout;
	fout.open("w2.txt");
	int n=rand()%(3*WORDSMAX/4)+WORDSMAX/4;//�������� (k/4~k),ʹ�������ݾ������� 
	cout<<"   ";//���������ĸ���ĸ 
	while(n--)                              //��ʼ���ɵ��� 
	{
		printf(" ");						//���ʼ�Ŀո�  
		int k=rand()%WORDSLENGTH+1;         //ÿ�����ʵĳ��� 
		for(int i=1;i<=k;i++)
		{
			int x,s;                         //x��ʾ��ǰ�ַ���ascii�� ��s�����ַ��Ĵ�Сд  
			s=rand()%2;                      //���ʹsΪ1��0 
			if(s==1)
			{                        		 //s=1,x->��д��ĸ
				x=rand()%('Z'-'A'+1)+'A'; 	 
			}     
			else {							 //s=0,x->Сд��ĸ 
				x=rand()%('z'-'a'+1)+'a';    
			}
			printf("%c",x);  
			fout<<(char)x;   //д���ļ�
		}
		fout<<" ";
	}	
	fout.close();
	return 0;
}
