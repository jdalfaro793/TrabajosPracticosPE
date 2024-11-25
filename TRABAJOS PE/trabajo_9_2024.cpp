#include <iostream>
using namespace std;

int producto(int x, int y);
int potencia(int x,int y);
int cuadrado(int n);
void productoProcedimiento(int x, int y, int &res);
void potenciaProcedimiento(int x,int y, int &res);
bool esPrimo(int n, int divisor);

int main(int argc, char *argv[]) {
	
	int a,b,res;
	cout<<"ingrese a: "<<endl;
	
	cin>>a;
	
	if(esPrimo(a, a/2)){
		cout<<"es primo:"<<a<<endl;
	}else{
		cout<<"no primo:"<<a<<endl;
	}
	
	return 0;
	
}

bool esPrimo(int n, int divisor) {
	if (divisor == 1)
		return true; // Si hemos llegado a 1, el número es primo
	else if (n % divisor == 0)
		return false; // Si encontramos un divisor distinto de 1 y n, no es primo
	else
		return esPrimo(n, divisor - 1); // Continuar con el siguiente divisor
}

void productoProcedimiento(int x, int y, int &res){
	
	if(x==0)
		res=0;
	else{
		productoProcedimiento(x-1,y,res);
		res=res+y;
	}
}
	

void potenciaProcedimiento(int x,int y, int &res){
	if (y==0) res=1;
	else {
		potenciaProcedimiento(x,y-1,res);
		res=res*x;
	}
}

int potencia(int x,int y){
	if (y==0) return 1;
	else return producto(x,potencia(x,y-1));
}


int producto(int x, int y){
	if (x==0)
		return 0;
	else
		return producto(x-1,y)+y;
}

int cuadrado(int n){
	if (n==1) return 1;
	else return cuadrado(n-1) + 2*n-1;
	
}
