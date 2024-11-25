#include <iostream>
#include <math.h>

using namespace std;

	float perimetro (int a, int b);
	float area (int a, int b);

	main(){
		int ca,co;
		float a,p;
		
		do{
			cout<<"ingrese cateto adyacente"<<endl;
			cin>>ca;
			cout<<"ingrese cateto opuesto"<<endl;
			cin>>co;
			
			
		} while(!((ca>0) && (co>0)));
		
		
		a=area(ca,co);
		
		p=perimetro(ca,co);
		
		cout<<"area es: "<<a<<endl;
		cout<<"perimetro es: "<<p<<endl;
	}
	
	float perimetro (int a, int b){
		float h,p;
		h=sqrt(powf(a,2.0)+powf(b,2.0));
		p=h+a+b;
		return p;
	}
	
	float area (int a, int b){
		float ar;
		ar=(a*b)/2.0;
		
		return ar;
	}
