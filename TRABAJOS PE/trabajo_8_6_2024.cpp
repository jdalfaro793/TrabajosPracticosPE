#include <iostream>
#include <math.h>

using namespace std;

void ingreso(int &a, int &b, int &c);
void calculo(int a, int b, int c, float &x1, float &x2, bool &exito);
void mostrar(float x1, float x2);
float cuadradoAproximado(int n);


int main() {
	int a, b, c;
	float x1, x2;
	bool bande=false;
	
	ingreso(a, b, c);
	calculo(a,b,c,x1,x2,bande);
	if(bande)
		mostrar(x1,x2);
}

void ingreso(int &a, int &b, int &c){
	do{
		cout<<"Ingrese valor (a)"<<endl;
		cin>>a;
		
		cout<<"Ingrese valor (b)"<<endl;
		cin>>b;
		
		cout<<"Ingrese valor (c)"<<endl;
		cin>>c;
		
		
		if(a==0) cout<<"error: no se puede calcular raices con a=0"<<endl;
		
	} while(!(a!=0));
}


void calculo(int a, int b, int c, float &x1, float &x2, bool &exito){

	int discri=powf(b,2)-4*a*c;
	if(discri>=0){

		x1=((-1*b)+cuadradoAproximado(discri))/(2*a);
		x2=((-1*b)-cuadradoAproximado(discri))/(2*a);
		exito=true;
	} else {
		cout<<"no se pueden calcular las raices"<<endl;
	}
}
	
void mostrar(float x1, float x2){
	cout<<"La raiz x1 es: "<<x1<<endl;
	cout<<"La raiz x2 es: "<<x2<<endl;
}

float cuadradoAproximado(int n){
	int i=1,a,cuad_a,b,cuad_b,j;
	bool band=true;
	float cuad_aprox;
	
	while(band){
		if(i*i>n){
			band=false;
			a=i*i-n;
			cuad_a=i;
			
			i--;
			b=n-i*i;
			cuad_b=i;
		}else{
			i++;
		}
	}
		
	if(a<b) 
		  j=cuad_a;
	else 
		j=cuad_b;
		
	cuad_aprox=((n+j*j)*(1.0))/((j*2)*(1.0));
		
	return cuad_aprox;
}
