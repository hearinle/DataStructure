//多项式的链表结构 3+5X^2+6X^5-10X^8 
//                 4X^2-6X^5+6X^7  
//求和： 3+9X^2+6X^7-10X^8 
#define OK 1 
#define ERROR 0 
#define OVERFLOW -2 
#define  MAXSIZE 100     //最大长度
#include "iostream"
using namespace std;
typedef  int  Status; 
typedef struct LNode{
	int coef;
	int expn;
	struct LNode *next;
}LNode,*LinkList;

//初始化
Status InitList_Sq(LinkList& L) {
	L= new LNode;
	L->next =NULL;
	return OK;
}
//链表的创建，有n个结点的链表 
void Create_List(LinkList& L,int n) //前插结点 
{
	L=new LNode;
	L->next =NULL;
	for(int i=1;i<=n;i++)
	{
		LNode *p;
		p=new LNode;  //申请结点 
		cout<<"系数：";cin>>p->coef ;
		cout<<"指数：";cin>>p->expn;
		p->next =L->next ;
		L->next =p;
	}
}
//创建有序链表 
void Create_List_2(LinkList& L,int n) //前插结点 
{
	L=new LNode;
	L->next =NULL;
	for(int i=1;i<=n;i++)
	{
		LNode *p,*q,*s;
		s=new LNode;  //申请结点 
		cout<<"系数：";cin>>s->coef ;
		cout<<"指数：";cin>>s->expn;
		q=L;p=L->next ;
		while(p&&p->expn <s->expn )
		 {
		 q=p;p=p->next ;}
	    s->next =q->next ;
	    q->next =s;
	}
}
//链表的输出 
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
//在有序多项式链表中 ，插入一个结点，使多项式任然有序
void Insert_node(LinkList& L,int c,int e)//c,e为新结点的系数和指数 
{
    	Lnode *p,*q,*s;
		s=new Lnode;   //新结点 
    	s->coef=c;s->expn=e;
    	q=L;p=L->next ;
		while(p&&p->expn <s->expn )
		 {
		 q=p;p=p->next ;}
	     s->next =q->next ;
	     q->next =s;  
} 
// 在有序多项式链表中 ，删除指数为e的结点
void Delete_node(LinkList& L,int e) //e为指数 
{
	    Lnode *p,*q,*s;
		q=L;p=L->next ;
		while(p&&p->expn!=e)
		 {
		 q=p;p=p->next ;}
	     q->next =p->next;//修改指针
		 delete p;//释放p指针  
} 

//两个有序多项式链式结构的求和 
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
      else{ //指数相等 
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

//链表的指定位置删除结点 
Status ListDelete(LinkList& L, int i) {
	//在带头结点的单链表L中,删除第i个元素
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
//链表的指定位置插入结点 
Status ListInsert(LinkList& L, int i) {
	//在带头结点的单链表L中第i个位置插入值为e的新结点
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
	cout << "系数：";
	cin >> s->coef;
	cout << "指数：";
	cin >> s->expn;
	s->next = p->next;
	p->next = s;
	return OK;
}

int main()//在主函数中实现上述函数的调用 
{
   LinkList L;
   int n;
   cout<<"输入创建个数n:";
   cin>>n;
   Create_List_2(L,n);//创建有序链表 
   show(L);
   
}
