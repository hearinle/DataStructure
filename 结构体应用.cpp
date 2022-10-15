//结构的应用：每个学生有学号，姓名，成绩，定义10个学生一维数组
//求所有学生的成绩平均分和找出成绩最高的同学的学号、姓名、成绩
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
  cout<<"请输入学生数组："; 
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
   cout<<"平均分："<<sum/LEN<<endl;
   cout<<"最高分的学号，姓名，成绩：";
   cout<<a[mk].num<<"  "<<a[mk].name<<"  "<<a[mk].score<<endl;
   }
