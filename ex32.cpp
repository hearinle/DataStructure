//循环队列的抽象定义及基本操作 实现 
#include "headfile.h" 
#define  MAXQSIZE  100
typedef int QElemType;
typedef struct {
   QElemType *base;  //初始化的动态分配存储空间
   int  front;            //头指针   
   int  rear;             //尾指针
}SqQueue;
//队列初始化 
Status InitQueue (SqQueue &Q){
    Q.base =new QElemType[MAXQSIZE] ;
   if(!Q.base) exit(OVERFLOW);
    Q.front=Q.rear=0;
    return OK;
}
//元素入队列 
Status EnQueue(SqQueue &Q,QElemType e){
    if((Q.rear+1)%MAXQSIZE==Q.front)  return ERROR;
    Q.base[Q.rear]=e;
    Q.rear=(Q.rear+1)%MAXQSIZE;
     return OK;
}
//元素出队列 
Status DeQueue (SqQueue &Q,QElemType &e){
   if(Q.front==Q.rear) return ERROR;
   e=Q.base[Q.front];
   Q.front=(Q.front+1)%MAXQSIZE;
   return OK;
}
int main( )
{
	SqQueue  sd;
	InitQueue(sd);
	int i;
	QElemType e;
	for(i=1;i<=5;i++)
	  {
	  	EnQueue(sd,i);
	  }
	for(i=1;i<=5;i++)
	{
		DeQueue(sd,e);
		cout<<e<<"  ";
	}
	cout<<endl;
	
} 
//根据PPT中内容，补充完成链式队列的定义及操作 
//数据类型定义 
typedef struct QNode{
   QElemType   data;
   struct QNode  *next;
}Qnode, *QueuePtr;
typedef struct {
   QueuePtr  front;            //队头指针   
   QueuePtr  rear;             //队尾指针
}LinkQueue;  
//链队列的操作
//初始化， 带头结点的链队列 
Status InitQueue (LinkQueue &Q){
   Q.front=Q.rear=new  QNode; 
    if(!Q.front) exit(OVERFLOW);
    Q.front->next=NULL;
     return OK;
}
Status QueueEmpty (LinkQueue Q){
    return (Q.front==Q.rear);                             
 }
Status GetHead (LinkQueue Q, QElemType &e){
   if(Q.front==Q.rear) return ERROR;
   e=Q.front->next->data;
   return OK;
}
Status EnQueue(LinkQueue &Q,QElemType e){
    QueuePtr p;
	p=new Qnode;
    if(!p) exit(OVERFLOW);
    p->data=e; p->next=NULL;
    Q.rear->next=p;
    Q.rear=p;
    return OK;
}
Status DeQueue (LinkQueue &Q,QElemType &e){
   QueuePtr p;
   if(Q.front==Q.rear) return ERROR;
   p=Q.front->next;
   e=p->data;
   Q.front->next=p->next;
   if(Q.rear==p) Q.rear=Q.front;
   delete p;
   return OK;
}

