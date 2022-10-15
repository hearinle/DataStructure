//����ʽ�Ĵ洢�������Ĳ��ҡ����롢ɾ���Ȳ��� 
//2+3x^2+5X^4+6X^8  
#define OK 1 
#define ERROR 0 
#define OVERFLOW -2 
#define  MAXSIZE 100     //��󳤶�
#include "iostream"
using namespace std;
typedef  int  Status; 
//typedef int ElemType;    //�����Ϳ����¶���Ϊ�ṹ������ 
typedef struct{
	double coef;
	int  expn;
}ElemType;
typedef  struct {
  ElemType  *elem;     //ָ������Ԫ�صĻ���ַ
  int  length;          //���Ա�ĵ�ǰ����                                                      
 }SqList;
 
 //=====��ʼ������ 
Status InitList_Sq(SqList &L){    //����һ���յ�˳���L
    L.elem=new ElemType[MAXSIZE];   //Ϊ˳������ռ�
    if(!L.elem) exit(OVERFLOW);       //�洢����ʧ��
    L.length=0;					  //�ձ���Ϊ0
    return OK;
}
//======�������Ա�L
void DestroyList(SqList &L)
{
  if (L.elem) delete[]L.elem;    //�ͷŴ洢�ռ�
}
//=====������Ա�L
void ClearList(SqList &L) 
{
   L.length=0;                //�����Ա�ĳ�����Ϊ0
}
//=====�����Ա�L�ĳ���
int GetLength(SqList L)
{
   return (L.length);             
}
//=====�ж����Ա�L�Ƿ�Ϊ�� 
int IsEmpty(SqList L)
{
  if (L.length==0) return 1;      
   else return 0;
}
//=====��ȡ���Ա�L�еĵ�i������Ԫ�ص����ݣ��β�e����ֵ 
Status GetElem(SqList L,int i,ElemType &e)
{
  if (i<1||i>L.length) return ERROR;//�ж�iֵ�Ƿ����
    e=L.elem[i-1];   //��i-1�ĵ�Ԫ�洢�ŵ�i������
  return OK;
}
//����Ԫ��e 
int LocateELem(SqList L,ElemType e)
{
  for (int i=0;i<L.length;i++)
 if (L.elem[i].coef ==e.coef &&L.elem[i].expn  ==e.expn) 
    return i+1;                
  return 0;
}
//====�����Ա�L�е�i������Ԫ��֮ǰ��������Ԫ��e 
Status ListInsert_Sq(SqList &L,int i ,ElemType e){
   if(i<1 || i>L.length+1) return ERROR;  //iֵ���Ϸ�
   if(L.length==MAXSIZE) return ERROR;    //��ǰ�洢�ռ�����     
   for(int j=L.length-1;j>=i-1;j--) 
       L.elem[j+1]=L.elem[j];    //����λ�ü�֮���Ԫ�غ���
    L.elem[i-1]=e;               //����Ԫ��e�����i��λ��
  ++L.length;		     	//����1
  return OK;
}
//=====�����Ա�L�е�i������Ԫ��ɾ��
Status ListDelete_Sq(SqList &L,int i){
   int j;
   if((i<1)||(i>L.length)) return ERROR;//iֵ���Ϸ�
   for(j=i;j<=L.length-1;j++) 
    L.elem [j-1]=L.elem [j]; //��ɾ��Ԫ��֮���Ԫ��ǰ��  
   --L.length;               	//����1
  return OK;
}
//����ʽ���뺯��
void input(SqList &Ls,int n)
{
	ElemType e;
    int i; 
 	for( i=1;i<=n;i++)//����ʽ�Ĵ��� 
	 { 
	 cout<<"\nϵ����";	 
	 cin>>e.coef ;
	 cout<<"\nָ����";	 
	 cin>>e.expn ;
	 ListInsert_Sq(Ls,i,e);
	 }	
 } 
//����ʽ������� 
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
	input(Ls,n);//���� 
	cout<<"����ʽ�����"<<endl; 
	output(Ls);
	cout<<"���� ȡ����i��Ԫ�أ�"; 
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
	cout<<"�������Ԫ�أ�λ�ú�ϵ����ָ��";
	cin>>i>>e.coef >>e.expn ;
	if(ListInsert_Sq( Ls,i , e))
    {
	cout<<"after inserted,the SqList is: ";
	 output(Ls); 
	 }
	 else
	  cout<<"Insert no succ\n";
    DestroyList(Ls); //�ͷŴ洢�ռ�	
}
//ʵ��ͼ��˳���������� 
