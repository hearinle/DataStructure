1.C++动态内存分配：运算符实现 new,delete 
int *p;
p=new int;//向内存申请一个整型空间 
*p=30;
//p=(int *)malloc(sizeof(int));

p=new int[5];//申请5个整型空间，相当于一个一维数组 ,int a[5];
访问：p[0],p[1],p[2].... 
//数据结构中经常使用动态数组申请 
空间的释放：
delete p;  
delete[]p; //数组的释放 
2. C语言中函数参数传递： 
 
 返回值类型 函数名（形参）
 {
 	函数体；
	 return 表达式; 
  } 
  
实参传值给形参的方式：
1）值传递  （一般变量做形参，“单向” ） 
2）地址传递（指针做形参，数组做形参，引用做形参）“双向” 
引用作为函数形参，操作简单，达到指针效果 （C++中喜欢用引用） 

3. 结构体 ：自定义类型 
（1）结构体类型的定义

 struct 类型名{
 	成员类型  成员名；
	 ... 
 	
 }; 
 struct Book{
  	char num[15];
  	char name[20];
  	int price;
  }; 
（2）再定义结构体变量（还包含结构体数组，结构体指针） 

结构体变量定义有三种形式：
先定义类型，再定义变量；     Book  s,t[4],*p;
定义类型同时定义变量；
struct Book{
  	char num[15];
  	char name[20];
  	int price;
  }s,t[4],*p;
直接定义； 
struct {
  	char num[15];
  	char name[20];
  	int price;
  }s,t[4],*p;

（3）结构体变量访问：只能对成员进行访问：分量运算符 . ,  -> 
 .  ，结构体变量访问的运算符
 -> ,结构体的指针访问所指的变量运算符 
如：
 scanf("%s%s%d",s.num,s.name,&s.price);
 for(i=0;i<4;i++)
   cout<<t[i].name<<t[i].price ;//层层分量运算 
 p=&s;
 cout<<p->name<<p->price;

4. typedef -- 类型改名字 
 int a;
 typedef  int  integer;
 typedef  int  status;
 typedef  double  ElemType;
 integer x; //int x;
 改名三个步骤： 先用这个类型定义变量；将变量名改为新类型名；
 最后在句前加typedef; 
  
 typedef int *Pointer;
 Pointer p1,p2;  //int *p1,*p2;
typedef int ARRAY[10];
ARRAY  x,y;  //int x[10],y[10];
  
 typedef  struct Book{
  	char num[5];
  	char name[20];
  	int price;
  } Tbook,*Pbook;
 Tbook a[10]; //结构体数组 
 Pbook  p1,p2; // Book *p1,*p2;
 
 5.链表的知识
  结点表示：
  typedef struct Node{
  	int cof;
  	int exp;
  	struct Node *next;
  }LNode ,*LinkList; 
  LNode s;
  s.cof =7;
  s.exp =0;
  s.next =0;
  LinkList p;//  p结构体指针 
  p=&s;
  p->cof =7;
  p->exp =0;
 链表应用（操作）：
  1）创建链表 2）浏览链表 
  3）查找，插入，删除，合并 
  4）链表撤销
  #define OK 1
  Status InitList_L(LinkList &L){ //初始化 
   L=new LNode;                    	
   L->next=NULL;　　　　　
   return OK; 
} 
 void Creat_list(LinkList &L)//追加方式创建链表 
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
补充:
数组：int a[10];   //顺序存储
链表： // 链式存储，元素之间在内存中不连续 


