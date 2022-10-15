//����ʽ������ṹ 3+5X^2+6X^5-10X^8 
//                 4X^2-6X^5+6X^7  
//��ͣ� 3+9X^2+6X^7-10X^8 
#define OK 1 
#define ERROR 0 
#define OVERFLOW -2 
#define  MAXSIZE 100     //��󳤶�
#include "iostream"
using namespace std;
typedef  int  Status; 
typedef struct LNode{
	int coef;
	int expn;
	struct LNode *next;
}LNode,*LinkList;

//��ʼ��
Status InitList_Sq(LinkList& L) {
	L= new LNode;
	L->next =NULL;
	return OK;
}
//����Ĵ�������n���������� 
void Create_List(LinkList& L,int n) //ǰ���� 
{
	L=new LNode;
	L->next =NULL;
	for(int i=1;i<=n;i++)
	{
		LNode *p;
		p=new LNode;  //������ 
		cout<<"ϵ����";cin>>p->coef ;
		cout<<"ָ����";cin>>p->expn;
		p->next =L->next ;
		L->next =p;
	}
}
//������������ 
void Create_List_2(LinkList& L,int n) //ǰ���� 
{
	L=new LNode;
	L->next =NULL;
	for(int i=1;i<=n;i++)
	{
		LNode *p,*q,*s;
		s=new LNode;  //������ 
		cout<<"ϵ����";cin>>s->coef ;
		cout<<"ָ����";cin>>s->expn;
		q=L;p=L->next ;
		while(p&&p->expn <s->expn )
		 {
		 q=p;p=p->next ;}
	    s->next =q->next ;
	    q->next =s;
	}
}
//�������� 
void show(LinkList L)
{ 
  LNode *p;
  p=L->next ;
  while(p)
  {
  	if(p->coef >=0)
	 cout<<p->coef <<"X^"<<p->expn <<"+";
	else 
	 cout<<"\b"<<p->coef <<"X^"<<p->expn <<"+";
	p=p->next ; 
  }
  cout<<"\b  \n";	
}
//���������ʽ������ ������һ����㣬ʹ����ʽ��Ȼ����
void Insert_node(LinkList& L,int c,int e)//c,eΪ�½���ϵ����ָ�� 
{
    	Lnode *p,*q,*s;
		s=new Lnode;   //�½�� 
    	s->coef=c;s->expn=e;
    	q=L;p=L->next ;
		while(p&&p->expn <s->expn )
		 {
		 q=p;p=p->next ;}
	     s->next =q->next ;
	     q->next =s;  
} 
// ���������ʽ������ ��ɾ��ָ��Ϊe�Ľ��
void Delete_node(LinkList& L,int e) //eΪָ�� 
{
	    Lnode *p,*q,*s;
		q=L;p=L->next ;
		while(p&&p->expn!=e)
		 {
		 q=p;p=p->next ;}
	     q->next =p->next;//�޸�ָ��
		 delete p;//�ͷ�pָ��  
} 

//�����������ʽ��ʽ�ṹ����� 
void Merige(LinkList &La,LinkList &Lb,LinkList &Lc )
{
	LinkList pa,pb,pc,r;
	pa=La->next ;
	pb=Lb->next ;
	pc=Lc=La;
	while(pa&&pb)
	{
		if(pa->expn <pb->expn )
		{ pc->next =pa;pc=pa;
		  pa=pa->next ;
		}
       else if(pa->expn >pb->expn  )
       {
	   pc->next =pb;pc=pb;
	   pb=pb->next ;		
       }
      else{ //ָ����� 
      	int sum;
		  sum=pa->coef +pb->coef ;
		  if(sum!=0)
			{
				pa->coef =sum;pc->link =pa;pc=pa;
			    pa=pa->link;
			    r=pb;pb=pb->link ;delete r;
			}
			else{
				r=pa;pa=pa->link ;delete r;
				r=pb;pb=pb->link ;delete r;
			}       	
	  }
  	}
 pc->next=pa?pa:pb;
}

//�����ָ��λ��ɾ����� 
Status ListDelete(LinkList& L, int i) {
	//�ڴ�ͷ���ĵ�����L��,ɾ����i��Ԫ��
	LNode* p,* q;
	p =L;
	int j = 0;
	while ((p->next) && (j < i - 1)) {
		p = p->next; ++j;
	}
	if (!(p->next) || (j > i - 1)) return ERROR;
	q = p->next;
	p->next = q->next;
	delete q;
	return OK;
}
//�����ָ��λ�ò����� 
Status ListInsert(LinkList& L, int i) {
	//�ڴ�ͷ���ĵ�����L�е�i��λ�ò���ֵΪe���½��
	LNode* p;
	p = L;
	int j = 0;
	while (p && (j < i - 1)) {
		p = p->next;
		++j;
	}
	if (!p || j > i - 1)
		return ERROR;
	LNode* s;
	s = new LNode;
	cout << "ϵ����";
	cin >> s->coef;
	cout << "ָ����";
	cin >> s->expn;
	s->next = p->next;
	p->next = s;
	return OK;
}

int main()//����������ʵ�����������ĵ��� 
{
   LinkList L;
   int n;
   cout<<"���봴������n:";
   cin>>n;
   Create_List_2(L,n);//������������ 
   show(L);
   
}
