 //思考：如何表示多项式：5+2X2+4X5+6X8-10X9
 #include "iostream"
 using namespace std;
 typedef struct{
 	int coef;
 	int expn;
 }PY;
 int main()
 {
 	PY  a[5];
 	for(int i=0;i<5;i++)
 	  cin>>a[i].coef >>a[i].expn ;
 	for(int i=0;i<5;i++)
 	  cout<<a[i].coef <<"X"<<a[i].expn <<"+";
 	cout<<"\b ";
 }
  
 
