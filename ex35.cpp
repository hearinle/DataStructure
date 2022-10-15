//ex35.cpp  �������
#include "headfile.h" 
#include "string.h"
#define  MAXQSIZE  100
typedef struct{            //�����Ϣ 
	char name[20];
	char sex;
}QElemType;
typedef struct {
   QElemType *base;         
   int  front;               
   int  rear;             
}SqQueue;
//���г�ʼ�� 
Status InitQueue (SqQueue &Q){
    Q.base =new QElemType[MAXQSIZE] ;
   if(!Q.base) exit(OVERFLOW);
    Q.front=Q.rear=0;
    return OK;
}
//�����Ƿ�Ϊ���ж� 
bool DeQueueEmpty(SqQueue &Q)
{
	if(Q.front ==Q.rear)
	 return true;
	 else 
	return false;
}
//Ԫ������� 
Status EnQueue(SqQueue &Q,QElemType e){
    if((Q.rear+1)%MAXQSIZE==Q.front)  return ERROR;
    //strcpy(Q.base[Q.rear].name ,e.name );
    //Q.base[Q.rear].sex=e.sex ;
    Q.base [Q.rear ]=e;    //������ɣ� 
	Q.rear=(Q.rear+1)%MAXQSIZE;
     return OK;
}
//Ԫ�س����� 
Status DeQueue (SqQueue &Q,QElemType &e){
   if(Q.front==Q.rear) return ERROR;
    strcpy(e.name ,Q.base[Q.front].name);
    e.sex=Q.base[Q.front].sex ;
  //  cout<<"������֤:"<<e.name<<"  "<<e.sex<<endl;
   Q.front=(Q.front+1)%MAXQSIZE;
   return OK;
} 
//ȡ��ͷԪ�� 
Status GetHead(SqQueue &Q,QElemType &e)
{ if(Q.front==Q.rear) return ERROR;
  strcpy(e.name ,Q.base[Q.front].name );
  e.sex=Q.base[Q.front].sex ;
  return OK;
}
void DancerPartner(QElemType Person[],int n); //��麯�� 
int main( )
{
	QElemType  Dancer[100];
	int i,n;
	cout<<"������μ���������(<100)��";
	cin>>n;
	cout<<"������  �Ա� ����5�����ߣ�w--Ů��  m--�а�\n"; 
	for(i=0;i<n;i++)
	  cin>>Dancer[i].name >>Dancer[i].sex;
	DancerPartner(Dancer,n);
}

void DancerPartner(QElemType Person[],int n)  //n���������� 
{
	int i;
	QElemType m,w;
	SqQueue Mdancer,Fdancer;
	InitQueue(Mdancer);
	InitQueue(Fdancer);
	for(i=0;i<n;i++)           //�������� 
	  if(Person[i].sex=='w')
	    EnQueue(Fdancer,Person[i]);
	  else
		EnQueue(Mdancer,Person[i]);
	cout<<"������������У�\n\n";
	i=1;
	while(!DeQueueEmpty(Fdancer) &&!DeQueueEmpty(Mdancer))
	{
		DeQueue (Fdancer,w);
		DeQueue (Mdancer,m);
		cout<<"�� "<<i<<"  �����is��";
		cout<<w.name <<"   "<<m.name <<endl;
		i++;
    }
	if(!DeQueueEmpty(Fdancer))  
	   {
	   GetHead(Fdancer,w);
	   cout<<"δ�ɹ���Եĵ�һ��Ů���� :\n "<<w.name <<endl; 
		 }
	else if(!DeQueueEmpty(Mdancer)){
		GetHead(Mdancer,m);
	   cout<<"δ�ɹ���Եĵ�һ���а��� :\n"<<m.name <<endl; 
	}
    else
	  cout<<"���\n";
	} 
