#include "iostream"
#include "fstream"
#include "string.h"
#define  MaxSize 100
using namespace std; 
//数据类型直接用字符串一维数组表示 
typedef char SString[MaxSize];
//截取字串，从s串中的pos点开始，截取长度为m的字串，存入t  
//void SubString(SString s,SString &t,int pos,int m);
//子串检查,字串t是否包含在主串s中 
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
	cout<<"从文件中读取检验任务数量：";
	fin>>n;
	cout<<n<<endl;
	//循环读取病毒和人的基因序列，并进行判断
	for(i=1;i<=n;i++) 
	{
		fin>>VDNA>>PDNA;
		strcpy(vm,VDNA);strcat(vm,VDNA);//将病毒字串存储2倍转存到vm 
		flag=0; m=strlen(VDNA);
		for(j=1;j<=m;j++)
		{
		    SubString(vm,vt,j,m);//从vm中的第j位置开始截取字串m个，存入vt
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
//取字串 ,pos是位置 
void SubString(SString s,SString &t,int pos,int m)
{
  int i;
  for(i=0;i<m;i++)
     t[i]=s[pos+i-1];
   t[i]='\0';
} 
//子串检查,字串t是否包含在主串s中 
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
int Index_BF(SString s,SString t,int pos)//下标从0开始的 
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



