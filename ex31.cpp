//ex31.cpp 堆栈应用：进制转换，括号匹配，习题等应用操作 

#include "mystack.h"   //堆栈定义的头文件 

bool  CheckHuiwen(char str[]);
bool  Check(char str[]);
void conversion(int N,int d);
bool Matching( );
int main( )
{
	//验证输入字符串进出堆栈是否正确
	char str[100];
	cout<<"输入被检测的进出栈操作序列：";
	cin>>str;
	cout<<str<<endl;
	if(Check(str) )
      cout<<"是合法序列\n";
    else
      cout<<"不是合法序列\n";
	   
	/*验证输入一个字符串是否回文
	char  str[100];
	cout<<"输入一个字符串：";
	cin>>str;
	if(CheckHuiwen(str)) 
	  cout<<str<<"是回文\n";
	  else
	  cout<<str<<"不是回文\n";*/
/*	堆栈的基本操作 
	SqStack  s;
	SElemType  e;
	int i;
	InitStack(s);
	for( i=1;i<=10;i++)
	 Push(s,i);
	cout<<"输出栈中的元素：\n";
	for(i=1;i<=5;i++)
	{
	  Pop(s,e);
	  cout<<e<<"   ";
	}
	OutputStack(s);*/ 
 /*验证进制转换 
	int  n,d;
	cout<<"输入转换的非负整数及转换的进制：" ;
	cin>>n>>d;
	cout<<"转换的进制数：";
	conversion(n,d);*/
/*	//验证括号匹配检验
    bool  f;
	f=Matching( );
	if(f)
	  cout<<"成功\n";
	  else 
	  cout<<"不成功\n";
	*/
}

//堆栈应用1---将一个非负整数N 转换为d进制，并输出 
void conversion(int N,int d)
{
   SqStack  S;
   InitStack(S);	//初始化空栈S
   while(N) 
   {
	   char ch;
	   int k = N % d;
	   ch=k>=0&&k<=9?k+'0':'A'+K-10
       Push(S,ch);	 //把N与8求余得到的八进制数压入栈S
       N=N/d;		    //N更新为N与8的商 
   }
   OutputStack(S);
}

//括号配对检验算法分析及实现
//1）堆栈的定义修改为字符型堆栈 2）对输入的一串括号字符串，判断是否配对 
bool Matching( )
{
   SqStack  S;
   InitStack(S);	//初始化空栈S
   int flag=1;
   SElemType  ch,e;
   cout<<"输入检验的括号字符串，以#结束：";
   cin>>ch;
   while(ch!='#'&&flag){
   	switch(ch){
   		case '[':
   		case '(': Push(S,ch);break;
   		case ')':if(!StackEmpty(S)&&GetTop(S)=='(')
   		          Pop(S,e);
   		         else flag=0;
   		          break;
   		case ']':if(!StackEmpty(S)&&GetTop(S)=='[')
   		          Pop(S,e);
   		         else flag=0;
   		          break;				
	   }
	   cin>>ch;	   
   } 
   if(StackEmpty(S)&&flag) return true;
   else  return false;	
}
//检查回文  习题（2） 
bool  CheckHuiwen(char str[])
{
	SqStack  s;
	InitStack(s);
	int length,i;
	SElemType e;
	length=strlen(str);
	for(i=0;i<length/2;i++)
	 Push(s,str[i]);
	if(length%2==1) i++; //字符串长度为奇数时，让i 后移一个位置
	int  flag=1;//判断过程中的标志，不是回文flag=0
	for(;i<length;i++) //继续判断字符串后半部分字符逐个与堆栈弹出的元素比较
	  {
	  	Pop(s,e);
	  	if(e!=str[i])
	  	   {
			 flag=0; break;
			 }	  
		}
	 if(flag==1)
	   return true;
	 else
	   return false;
}
//习题编程题（5）小题 
bool  Check(char str[]){
	SqStack s;
	InitStack(s);
	int flag=1,i=0;
	SElemType e;
	while(str[i]!='\0'&&flag)
	{
		switch(str[i])
		{
			case 'I':Push(s,str[i]) ;break;
			case 'O':if(!StackEmpty(s)) 
			           Pop(s,e); 
			         else  flag=0;
			          break;
		}
		i++;
	}
	if(StackEmpty(s)&&flag) return true;
   else  return false;	
   
}
