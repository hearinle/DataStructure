//���ʽ��ֵ�㷨 
/*#include "stdio.h"
#include "iostream"
#include "stdlib.h"
#include "string.h"
#define MAXSIZE 100
using namespace std;*/
#include "headfile.h" 
//��������ջ���ݳ��󼰲�������
typedef struct Stackch
{ 
	char  *a;
    char  *top;
    int  stackssize;
}Stack;
void inistack(Stack &s);
char gettop(Stack &s);
void push(Stack &s,char ch);
void pop(Stack  &s, char &ch);
//��������ջ���ݳ��󼰲������� 
typedef struct Stackch1
{ 
	int  *a;
    int  *top;
    int  stackssize;
}Stack1;
void inistack1(Stack1 &s);
void push1(Stack1 &s,int ch);
void pop1(Stack1  &s, int &ch);
int gettop1(Stack1 &s);
//�������ܺ��� 
int in(char c,char op[]); //�ж��ַ������c�Ƿ������������ op �� 
char precede(char,char); //�Ƚ������ַ������ȼ� 
int operatordata(int c1, char c3, int c2); //������c1,c2���c3���� 

char oper[]="+-*/()#";//  ָ�����ʽ����ʵʩ��������� 

int main()
{ 
	char c1, c2;
	int count,ch,m,n;
    Stack  Optr;
	Stack1 Opnd;
    inistack(Optr);
    inistack1(Opnd);
    push(Optr,'#');  //����ʼ��ѹ���ջ 
    printf("read a string:\n");
    cin>>c1;  //#123+45*2-30#    3+2+5*2-6#
    while(c1!='#'||gettop(Optr)!='#')
	{  
	   if( !in(c1,oper))  
	   { 
		  count=c1-48; //תΪ���� 
		  cin>>c1;
		  while(c1>='0'&&c1<='9') //��װ��һ������ 
		  {count=count*10+c1-48;
		    cin>>c1;
		  }		   
		   push1(Opnd, count);
	       }
	   else
	   {
		  switch(precede(gettop(Optr),c1))
		  { 
		  case '<':  push(Optr,c1); cin>>c1;break;
		  case '=':  pop(Optr,c2);  cin>>c1;break; 
		  case '>':  pop(Optr,c2); 
			         pop1(Opnd,n);
			         pop1(Opnd,m);
			         push1(Opnd,operatordata(m,c2,n));
					 break;
		  }
	  }
  
     }
     ch=gettop1(Opnd);
     cout<<ch<<endl;
}

void inistack(Stack &s){
    s.a =new char[MAXSIZE];
	s.top=s.a ;
	s.stackssize=0;
}

void inistack1(Stack1 &s){
    s.a =new int[MAXSIZE];
	s.top=s.a ;
	s.stackssize=0;
}

void push(Stack &s,char ch)
{
   *s.top++=ch;
}

void push1(Stack1 &s,int ch)
{
   *s.top++=ch;
}

void pop(Stack &s, char&ch)
{
  ch=*--s.top;
}

void pop1(Stack1 &s, int &ch)
{
  ch=*--s.top;
}
char gettop( Stack &s)
{  
	return *(s.top-1);
}

int gettop1(Stack1 &s)
{  
	return *(s.top-1);
}
int in(char c,char op[])
{ 
	for(int i=0; op[i]!='\0'; i++)
     if(c==op[i])
		  return 1;
  return 0;
}

char precede(char c1,char c2)
{ 
	char ch;
	switch(c1)
	{  
	case '+':
             switch(c2)
			 {
				case '+':
				case '-': 
				case ')': 
				case '#': ch='>';break;
				case '*':
				case '/':
				case '(': ch='<';break;
			//	ch='>';break; 
			 }
			 break;
   case '-':
	       switch(c2)
			 {
				case '+':
				case '-':ch='>';break;
				case '*':
				case '/':
				case '(':ch='<';break;
				case ')':
				case '#':ch='>';break; 
			 }
			 break;
   case '*':
	        switch(c2)
			 {
				case '+':
				case '-':
				case '*':
				case '/':ch='>';break;
				case '(':ch='<';break;
				case ')':
				case '#':ch='>';break;
			 }
			 break;
   case '/':
	       switch(c2)
			 {
				case '+':
				case '-':
				case '*':
				case '/':ch='>';break;
				case '(':ch='<';break;
				case ')':
				case '#':ch='>';break;
			 }
			 break;
   case '(':switch(c2)
			 {
				case '+':
				case '-':
				case '*':
				case '/':
				case '(':ch='<';break;
				case ')':ch='=';break;
			 }
			 break;
   case ')':switch(c2)
			 {
				case '+':
				case '-':
				case '*':
				case '/':
		
				case ')':
				case '#': ch='>';break;	
			 }
			 break;
   case '#':switch(c2)
			 {
				case '+':
				case '-': ch='<';break;
				case '*':
				case '/':
				case '(':ch='<';break;
				case '#':ch='=';break;
			 }
			 break;
   }
   return  ch;  
}

int operatordata(int c1,char c3,int c2)
{ 
	int ch;
	switch(c3)
	{
	case '+': ch=c1+c2;break;
	case '-': ch=c1-c2;break;
	case '*': ch=c1*c2;break;
	case '/': ch=c1/c2;break;
	}
	return ch;
}
