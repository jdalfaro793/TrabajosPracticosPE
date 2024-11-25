#include <iostream>
using namespace std;

void ingreso(int &catetoA, int &catetoB);
void calculoHipotenusa(int catetoA, int catetoB, float &hipo);
void mostrar(float hipo);
float cuadradoAproximado(int n);

int main(int argc, char *argv[]) {
	int catetoA, catetoB;
	float hipo;
	
	ingreso(catetoA, catetoB);
	calculoHipotenusa(catetoA, catetoB, hipo);
	mostrar(hipo);
	
	
	return 0;
}

void ingreso(int &catetoA, int &catetoB){
	do{
		cout<<"Ingrese longitud primer cateto (a)"<<endl;
		cin>>catetoA;
		
		cout<<"Ingrese longitud segundo cateto (b)"<<endl;
		cin>>catetoB;
		
		if(!(catetoA>0 && catetoB>0)) cout<<"error: los catetos deben ser positivos"<<endl;
		
	} while(!(catetoA>0 && catetoB>0));
}



void calculoHipotenusa(int catetoA, int catetoB, float &hipo){
	int potA=catetoA*catetoA;
	int potB=catetoB*catetoB;
	int res=potA+potB;
	hipo=cuadradoAproximado(res);
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

void mostrar(float hipo){
	cout<<"La hipotenusa del triangulo es: "<<hipo<<endl;
}
