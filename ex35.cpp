//ex35.cpp  舞伴问题
#include "headfile.h" 
#include "string.h"
#define  MAXQSIZE  100
typedef struct{            //舞伴信息 
	char name[20];
	char sex;
}QElemType;
typedef struct {
   QElemType *base;         
   int  front;               
   int  rear;             
}SqQueue;
//队列初始化 
Status InitQueue (SqQueue &Q){
    Q.base =new QElemType[MAXQSIZE] ;
   if(!Q.base) exit(OVERFLOW);
    Q.front=Q.rear=0;
    return OK;
}
//队列是否为空判断 
bool DeQueueEmpty(SqQueue &Q)
{
	if(Q.front ==Q.rear)
	 return true;
	 else 
	return false;
}
//元素入队列 
Status EnQueue(SqQueue &Q,QElemType e){
    if((Q.rear+1)%MAXQSIZE==Q.front)  return ERROR;
    //strcpy(Q.base[Q.rear].name ,e.name );
    //Q.base[Q.rear].sex=e.sex ;
    Q.base [Q.rear ]=e;    //可以完成； 
	Q.rear=(Q.rear+1)%MAXQSIZE;
     return OK;
}
//元素出队列 
Status DeQueue (SqQueue &Q,QElemType &e){
   if(Q.front==Q.rear) return ERROR;
    strcpy(e.name ,Q.base[Q.front].name);
    e.sex=Q.base[Q.front].sex ;
  //  cout<<"出队验证:"<<e.name<<"  "<<e.sex<<endl;
   Q.front=(Q.front+1)%MAXQSIZE;
   return OK;
} 
//取队头元素 
Status GetHead(SqQueue &Q,QElemType &e)
{ if(Q.front==Q.rear) return ERROR;
  strcpy(e.name ,Q.base[Q.front].name );
  e.sex=Q.base[Q.front].sex ;
  return OK;
}
void DancerPartner(QElemType Person[],int n); //舞伴函数 
int main( )
{
	QElemType  Dancer[100];
	int i,n;
	cout<<"请输入参加舞会的人数(<100)：";
	cin>>n;
	cout<<"按姓名  性别 输入5个舞者：w--女伴  m--男伴\n"; 
	for(i=0;i<n;i++)
	  cin>>Dancer[i].name >>Dancer[i].sex;
	DancerPartner(Dancer,n);
}

void DancerPartner(QElemType Person[],int n)  //n个舞者数组 
{
	int i;
	QElemType m,w;
	SqQueue Mdancer,Fdancer;
	InitQueue(Mdancer);
	InitQueue(Fdancer);
	for(i=0;i<n;i++)           //舞伴进队列 
	  if(Person[i].sex=='w')
	    EnQueue(Fdancer,Person[i]);
	  else
		EnQueue(Mdancer,Person[i]);
	cout<<"舞伴配对输出序列：\n\n";
	i=1;
	while(!DeQueueEmpty(Fdancer) &&!DeQueueEmpty(Mdancer))
	{
		DeQueue (Fdancer,w);
		DeQueue (Mdancer,m);
		cout<<"第 "<<i<<"  对舞伴is：";
		cout<<w.name <<"   "<<m.name <<endl;
		i++;
    }
	if(!DeQueueEmpty(Fdancer))  
	   {
	   GetHead(Fdancer,w);
	   cout<<"未成功配对的第一个女伴是 :\n "<<w.name <<endl; 
		 }
	else if(!DeQueueEmpty(Mdancer)){
		GetHead(Mdancer,m);
	   cout<<"未成功配对的第一个男伴是 :\n"<<m.name <<endl; 
	}
    else
	  cout<<"完成\n";
	} 
