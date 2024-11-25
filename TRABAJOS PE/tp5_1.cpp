#include <iostream>
using namespace std;

main(){
	
	float a,b;
	
	float res;
	
	do{
	cout<<"ingrese dividendo"<<endl;	
	cin>>a;

	cout<<"ingrese divisor"<<endl;
	cin>>b;
	}while(!(a>0 && b>0));
	
	res=a/b;
	
	cout<<"resultado es: "<<res<<endl;
	
	
}
