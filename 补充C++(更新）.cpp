1.C++��̬�ڴ���䣺�����ʵ�� new,delete 
int *p;
p=new int;//���ڴ�����һ�����Ϳռ� 
*p=30;
//p=(int *)malloc(sizeof(int));

p=new int[5];//����5�����Ϳռ䣬�൱��һ��һά���� ,int a[5];
���ʣ�p[0],p[1],p[2].... 
//���ݽṹ�о���ʹ�ö�̬�������� 
�ռ���ͷţ�
delete p;  
delete[]p; //������ͷ� 
2. C�����к����������ݣ� 
 
 ����ֵ���� ���������βΣ�
 {
 	�����壻
	 return ���ʽ; 
  } 
  
ʵ�δ�ֵ���βεķ�ʽ��
1��ֵ����  ��һ��������βΣ������� �� 
2����ַ���ݣ�ָ�����βΣ��������βΣ��������βΣ���˫�� 
������Ϊ�����βΣ������򵥣��ﵽָ��Ч�� ��C++��ϲ�������ã� 

3. �ṹ�� ���Զ������� 
��1���ṹ�����͵Ķ���

 struct ������{
 	��Ա����  ��Ա����
	 ... 
 	
 }; 
 struct Book{
  	char num[15];
  	char name[20];
  	int price;
  }; 
��2���ٶ���ṹ��������������ṹ�����飬�ṹ��ָ�룩 

�ṹ�����������������ʽ��
�ȶ������ͣ��ٶ��������     Book  s,t[4],*p;
��������ͬʱ���������
struct Book{
  	char num[15];
  	char name[20];
  	int price;
  }s,t[4],*p;
ֱ�Ӷ��壻 
struct {
  	char num[15];
  	char name[20];
  	int price;
  }s,t[4],*p;

��3���ṹ��������ʣ�ֻ�ܶԳ�Ա���з��ʣ���������� . ,  -> 
 .  ���ṹ��������ʵ������
 -> ,�ṹ���ָ�������ָ�ı�������� 
�磺
 scanf("%s%s%d",s.num,s.name,&s.price);
 for(i=0;i<4;i++)
   cout<<t[i].name<<t[i].price ;//���������� 
 p=&s;
 cout<<p->name<<p->price;

4. typedef -- ���͸����� 
 int a;
 typedef  int  integer;
 typedef  int  status;
 typedef  double  ElemType;
 integer x; //int x;
 �����������裺 ����������Ͷ������������������Ϊ����������
 ����ھ�ǰ��typedef; 
  
 typedef int *Pointer;
 Pointer p1,p2;  //int *p1,*p2;
typedef int ARRAY[10];
ARRAY  x,y;  //int x[10],y[10];
  
 typedef  struct Book{
  	char num[5];
  	char name[20];
  	int price;
  } Tbook,*Pbook;
 Tbook a[10]; //�ṹ������ 
 Pbook  p1,p2; // Book *p1,*p2;
 
 5.�����֪ʶ
  ����ʾ��
  typedef struct Node{
  	int cof;
  	int exp;
  	struct Node *next;
  }LNode ,*LinkList; 
  LNode s;
  s.cof =7;
  s.exp =0;
  s.next =0;
  LinkList p;//  p�ṹ��ָ�� 
  p=&s;
  p->cof =7;
  p->exp =0;
 ����Ӧ�ã���������
  1���������� 2��������� 
  3�����ң����룬ɾ�����ϲ� 
  4��������
  #define OK 1
  Status InitList_L(LinkList &L){ //��ʼ�� 
   L=new LNode;                    	
   L->next=NULL;����������
   return OK; 
} 
 void Creat_list(LinkList &L)//׷�ӷ�ʽ�������� 
 {
 	int i;
 	LinkList p,r;
 	r=L;
 	for(i=1;i<=4;i++)
 	{
 		p=new LNode;
 		cin>>p->cof >>p->exp ;
 		r->next =p;
 		r=p;
	 }
 	r->next =NULL;//=0	
 }
����:
���飺int a[10];   //˳��洢
���� // ��ʽ�洢��Ԫ��֮�����ڴ��в����� 


