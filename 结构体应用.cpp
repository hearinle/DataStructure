//�ṹ��Ӧ�ã�ÿ��ѧ����ѧ�ţ��������ɼ�������10��ѧ��һά����
//������ѧ���ĳɼ�ƽ���ֺ��ҳ��ɼ���ߵ�ͬѧ��ѧ�š��������ɼ�
#define LEN 5
#include "iostream"
using namespace std;
typedef struct stu{
	char num[12];
	char name[20];
	int score;
}Stu;
int main()
{ 
  Stu  a[LEN];
  int i,sum,max,mk;
  cout<<"������ѧ�����飺"; 
  for(i=0;i<LEN;i++)
   cin>>a[i].num>>a[i].name>>a[i].score;
  sum=max=a[0].score; mk=0;
  for(i=1;i<LEN;i++)
  {
  	sum=sum+a[i].score;
  	if(a[i].score>max)
  	 {
	   max=a[i].score;
	   mk=i;
	 }
   }
   cout<<"ƽ���֣�"<<sum/LEN<<endl;
   cout<<"��߷ֵ�ѧ�ţ��������ɼ���";
   cout<<a[mk].num<<"  "<<a[mk].name<<"  "<<a[mk].score<<endl;
   }
