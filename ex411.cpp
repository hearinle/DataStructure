#include "iostream"
#include "fstream"
#include "string.h"
#define  MaxSize 100
using namespace std; 
//��������ֱ�����ַ���һά�����ʾ 
typedef char SString[MaxSize];
//��ȡ�ִ�����s���е�pos�㿪ʼ����ȡ����Ϊm���ִ�������t  
//void SubString(SString s,SString &t,int pos,int m);
//�Ӵ����,�ִ�t�Ƿ����������s�� 
int Index_BF(SString s,SString t,int pos);
typedef struct{
	char *ch;
	int length;
}SString;

int main( ){
	ifstream fin("d:\\abcd.txt");
	ofstream fout("d:\\abcdout.txt");
	SString PDNA,VDNA,vt;
	char vm[2*MaxSize];
	int  i,j,n,m,k,flag=0;
	cout<<"���ļ��ж�ȡ��������������";
	fin>>n;
	cout<<n<<endl;
	//ѭ����ȡ�������˵Ļ������У��������ж�
	for(i=1;i<=n;i++) 
	{
		fin>>VDNA>>PDNA;
		strcpy(vm,VDNA);strcat(vm,VDNA);//�������ִ��洢2��ת�浽vm 
		flag=0; m=strlen(VDNA);
		for(j=1;j<=m;j++)
		{
		    SubString(vm,vt,j,m);//��vm�еĵ�jλ�ÿ�ʼ��ȡ�ִ�m��������vt
			k=Index_BF(PDNA,vt);
			if(k!=0)
			    break;
		}
		if(k!=0)
		  fout<<VDNA<<"    "<<PDNA<<"    "<<"YES\n";
		else 
		  fout<<VDNA<<"    "<<PDNA<<"    "<<"NO\n";
	}
	fin.close( );
	fout.close();
}
//ȡ�ִ� ,pos��λ�� 
void SubString(SString s,SString &t,int pos,int m)
{
  int i;
  for(i=0;i<m;i++)
     t[i]=s[pos+i-1];
   t[i]='\0';
} 
//�Ӵ����,�ִ�t�Ƿ����������s�� 
int Index_BF(SString s,SString t)
{
  int  n=strlen(s), m=strlen(t);
  SString  str;
   for(int k=0;k<=n-m;k++)
     { 
        SubString(s,str,k+1,m);
        if(strcmp(str,t)==0)
          return  k+1;
     }
  return 0;
} 
int Index_BF(SString s,SString t,int pos)//�±��0��ʼ�� 
{
	int i,j;
	i=pos-1;j=0;
//	int  n=strlen(s), m=strlen(t);
	while(i<s.length &&j<t.length )
	{
		if(s.ch[i]==t.ch[j]){
			i++;j++;}
		else
		{  i=i-j+1;j=0;	}
	}                       
	if(j>=m)
	 return i-m;
	else 0;
}



