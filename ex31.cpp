//ex31.cpp ��ջӦ�ã�����ת��������ƥ�䣬ϰ���Ӧ�ò��� 

#include "mystack.h"   //��ջ�����ͷ�ļ� 

bool  CheckHuiwen(char str[]);
bool  Check(char str[]);
void conversion(int N,int d);
bool Matching( );
int main( )
{
	//��֤�����ַ���������ջ�Ƿ���ȷ
	char str[100];
	cout<<"���뱻���Ľ���ջ�������У�";
	cin>>str;
	cout<<str<<endl;
	if(Check(str) )
      cout<<"�ǺϷ�����\n";
    else
      cout<<"���ǺϷ�����\n";
	   
	/*��֤����һ���ַ����Ƿ����
	char  str[100];
	cout<<"����һ���ַ�����";
	cin>>str;
	if(CheckHuiwen(str)) 
	  cout<<str<<"�ǻ���\n";
	  else
	  cout<<str<<"���ǻ���\n";*/
/*	��ջ�Ļ������� 
	SqStack  s;
	SElemType  e;
	int i;
	InitStack(s);
	for( i=1;i<=10;i++)
	 Push(s,i);
	cout<<"���ջ�е�Ԫ�أ�\n";
	for(i=1;i<=5;i++)
	{
	  Pop(s,e);
	  cout<<e<<"   ";
	}
	OutputStack(s);*/ 
 /*��֤����ת�� 
	int  n,d;
	cout<<"����ת���ķǸ�������ת���Ľ��ƣ�" ;
	cin>>n>>d;
	cout<<"ת���Ľ�������";
	conversion(n,d);*/
/*	//��֤����ƥ�����
    bool  f;
	f=Matching( );
	if(f)
	  cout<<"�ɹ�\n";
	  else 
	  cout<<"���ɹ�\n";
	*/
}

//��ջӦ��1---��һ���Ǹ�����N ת��Ϊd���ƣ������ 
void conversion(int N,int d)
{
   SqStack  S;
   InitStack(S);	//��ʼ����ջS
   while(N) 
   {
	   char ch;
	   int k = N % d;
	   ch=k>=0&&k<=9?k+'0':'A'+K-10
       Push(S,ch);	 //��N��8����õ��İ˽�����ѹ��ջS
       N=N/d;		    //N����ΪN��8���� 
   }
   OutputStack(S);
}

//������Լ����㷨������ʵ��
//1����ջ�Ķ����޸�Ϊ�ַ��Ͷ�ջ 2���������һ�������ַ������ж��Ƿ���� 
bool Matching( )
{
   SqStack  S;
   InitStack(S);	//��ʼ����ջS
   int flag=1;
   SElemType  ch,e;
   cout<<"�������������ַ�������#������";
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
//������  ϰ�⣨2�� 
bool  CheckHuiwen(char str[])
{
	SqStack  s;
	InitStack(s);
	int length,i;
	SElemType e;
	length=strlen(str);
	for(i=0;i<length/2;i++)
	 Push(s,str[i]);
	if(length%2==1) i++; //�ַ�������Ϊ����ʱ����i ����һ��λ��
	int  flag=1;//�жϹ����еı�־�����ǻ���flag=0
	for(;i<length;i++) //�����ж��ַ�����벿���ַ�������ջ������Ԫ�رȽ�
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
//ϰ�����⣨5��С�� 
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
