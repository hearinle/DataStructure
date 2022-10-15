//表达式求值算法 
/*#include "stdio.h"
#include "iostream"
#include "stdlib.h"
#include "string.h"
#define MAXSIZE 100
using namespace std;*/
#include "headfile.h" 
//操作符堆栈数据抽象及操作定义
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
//操作数堆栈数据抽象及操作定义 
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
//其他功能函数 
int in(char c,char op[]); //判断字符运算符c是否在运算符数组 op 中 
char precede(char,char); //比较两个字符的优先级 
int operatordata(int c1, char c3, int c2); //操作数c1,c2完成c3运算 

char oper[]="+-*/()#";//  指定表达式可能实施的运算符表 

int main()
{ 
	char c1, c2;
	int count,ch,m,n;
    Stack  Optr;
	Stack1 Opnd;
    inistack(Optr);
    inistack1(Opnd);
    push(Optr,'#');  //将起始符压入堆栈 
    printf("read a string:\n");
    cin>>c1;  //#123+45*2-30#    3+2+5*2-6#
    while(c1!='#'||gettop(Optr)!='#')
	{  
	   if( !in(c1,oper))  
	   { 
		  count=c1-48; //转为数字 
		  cin>>c1;
		  while(c1>='0'&&c1<='9') //组装成一个整数 
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
