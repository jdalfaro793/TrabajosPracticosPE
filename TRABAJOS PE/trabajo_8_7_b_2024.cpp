#include <iostream>
using namespace std;

void ingreso(int &a, int &b, int &op);
void calculo(int &a, int b, int &i);
void mostrar(int a, int i, int op);

main(){
	int n1,  n2,  op,i;
	ingreso(n1,n2,op);
	calculo(n1,n2,i);
	mostrar(n1,i,op);
	
}

void ingreso(int &a, int &b, int &op){
	do{
		
	cout<<"ingrese divisor"<<endl;
	cin>>a;
	
	cout<<"ingrese dividendo"<<endl;
	cin>>b;
	
	cout<<"ingrese opcion a calcular: 1) cociente - 2) resto)"<<endl;
	cin>>op;
	
	if(op!=1 && op !=2) cout<<"error opcion invalida"<<endl;
	
	} while(a<=0 || b<=0 || a<b || (op!=1 && op!=2));
	
}
	
void calculo(int &a, int b, int &i){
	i=0;

	while(a>=b){
		a=a-b;
		i++;
	}
}



void mostrar(int a, int i, int op){
	if(op==1)
	cout<<"cociente es: "<<i<<endl;
	
	if(op==2)
	cout<<"resto es: "<<a<<endl;
}
