//多项式的存储，基本的查找、插入、删除等操作 
//2+3x^2+5X^4+6X^8  
#define OK 1 
#define ERROR 0 
#define OVERFLOW -2 
#define  MAXSIZE 100     //最大长度
#include "iostream"
using namespace std;
typedef  int  Status; 
//typedef int ElemType;    //该类型可重新定义为结构体类型 
typedef struct{
	double coef;
	int  expn;
}ElemType;
typedef  struct {
  ElemType  *elem;     //指向数据元素的基地址
  int  length;          //线性表的当前长度                                                      
 }SqList;
 
 //=====初始化操作 
Status InitList_Sq(SqList &L){    //构造一个空的顺序表L
    L.elem=new ElemType[MAXSIZE];   //为顺序表分配空间
    if(!L.elem) exit(OVERFLOW);       //存储分配失败
    L.length=0;					  //空表长度为0
    return OK;
}
//======销毁线性表L
void DestroyList(SqList &L)
{
  if (L.elem) delete[]L.elem;    //释放存储空间
}
//=====清空线性表L
void ClearList(SqList &L) 
{
   L.length=0;                //将线性表的长度置为0
}
//=====求线性表L的长度
int GetLength(SqList L)
{
   return (L.length);             
}
//=====判断线性表L是否为空 
int IsEmpty(SqList L)
{
  if (L.length==0) return 1;      
   else return 0;
}
//=====获取线性表L中的第i个数据元素的内容，形参e带出值 
Status GetElem(SqList L,int i,ElemType &e)
{
  if (i<1||i>L.length) return ERROR;//判断i值是否合理
    e=L.elem[i-1];   //第i-1的单元存储着第i个数据
  return OK;
}
//查找元素e 
int LocateELem(SqList L,ElemType e)
{
  for (int i=0;i<L.length;i++)
 if (L.elem[i].coef ==e.coef &&L.elem[i].expn  ==e.expn) 
    return i+1;                
  return 0;
}
//====在线性表L中第i个数据元素之前插入数据元素e 
Status ListInsert_Sq(SqList &L,int i ,ElemType e){
   if(i<1 || i>L.length+1) return ERROR;  //i值不合法
   if(L.length==MAXSIZE) return ERROR;    //当前存储空间已满     
   for(int j=L.length-1;j>=i-1;j--) 
       L.elem[j+1]=L.elem[j];    //插入位置及之后的元素后移
    L.elem[i-1]=e;               //将新元素e放入第i个位置
  ++L.length;		     	//表长增1
  return OK;
}
//=====将线性表L中第i个数据元素删除
Status ListDelete_Sq(SqList &L,int i){
   int j;
   if((i<1)||(i>L.length)) return ERROR;//i值不合法
   for(j=i;j<=L.length-1;j++) 
    L.elem [j-1]=L.elem [j]; //被删除元素之后的元素前移  
   --L.length;               	//表长减1
  return OK;
}
//多项式输入函数
void input(SqList &Ls,int n)
{
	ElemType e;
    int i; 
 	for( i=1;i<=n;i++)//多项式的创建 
	 { 
	 cout<<"\n系数：";	 
	 cin>>e.coef ;
	 cout<<"\n指数：";	 
	 cin>>e.expn ;
	 ListInsert_Sq(Ls,i,e);
	 }	
 } 
//多项式输出函数 
 void output(SqList Ls)
 {  int i;
   ElemType e;
   for(i=1;i<=Ls.length;i++)
	  {
	  	GetElem(Ls,i,e);
	  	if(e.coef >=0)
		  cout<<e.coef <<"X^"<<e.expn <<"+";
		else 
		  cout<<"\b"<<e.coef <<"X^"<<e.expn <<"+";
	  	}
	 cout<<"\b  \n";
 }
int main( )
{
	SqList  Ls;
	InitList_Sq(Ls);
	ElemType  e;
	int n,i;
	cout<<"input data number to n:";
	cin>>n; 
	cout<<"input  data:\n";
	input(Ls,n);//创建 
	cout<<"多项式输出："<<endl; 
	output(Ls);
	cout<<"输入 取出第i个元素："; 
	 cin>>i;
	GetElem(Ls,i,e);
    cout<<"\nno."<<i<<" is: ";
	cout<<e.coef <<"X^"<<e.expn <<"\n";
	cout<<"delete elem no.:";
	int num;
	cin>>num;
	if(ListDelete_Sq(Ls,num))
    {
	cout<<"after deleted,the SqList is: ";
	output(Ls);	
	}
	else
	  cout<<"delete no succ\n";
	cout<<"输入插入元素：位置和系数和指数";
	cin>>i>>e.coef >>e.expn ;
	if(ListInsert_Sq( Ls,i , e))
    {
	cout<<"after inserted,the SqList is: ";
	 output(Ls); 
	 }
	 else
	  cout<<"Insert no succ\n";
    DestroyList(Ls); //释放存储空间	
}
//实现图书顺序表基本操作 
