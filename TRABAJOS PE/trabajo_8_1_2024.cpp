#include <iostream>
using namespace std;

void ingreso(int &num1, int &num2);
void calculo(int num1, int num2, int &cociente);
void mostrar(int num1, int num2, int cociente);

int main() {
	int a,b, cociente;
	ingreso(a,b);
	calculo(a,b,cociente);
	mostrar(a,b,cociente);
}

void ingreso(int &num1, int &num2){
	cout<<"ingrese dividendo"<<endl;
	cin>>num1;
	do{
		cout<<"ingrese divisor"<<endl;
		cin>>num2;
		
		if(num2==0)
			cout<<"el divisor no puede ser cero"<<endl;
		
	} while(!(num2!=0));
}

void calculo(int num1, int num2, int &cociente){
	int signo= -1;
	if ((num1<0 && num2<0) || (num1>=0 && num2>0))
		signo= 1;
		

	if(num1<0)
		num1=num1*(-1);
		
	if(num2<0)
		num2=num2*(-1);
		
		   
	cociente=0;
		
	while (num1>=num2){
		num1=num1-num2;
		cociente=cociente+1;
	}
	
	cociente=cociente*signo;
}
	
void mostrar(int num1, int num2, int cociente){
	cout<<"El cociente entre "<<num1<<" y "<<num2<<" es "<<cociente<<endl;		
}
