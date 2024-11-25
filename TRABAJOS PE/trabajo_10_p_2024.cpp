#include <iostream>
#include <time.h>
using namespace std;

const int MAX=10;

typedef int tvector[MAX];



void cargarVectores(tvector v1, tvector v2);

void agregar(tvector v, int nuevo, int indice);
int aleatorio(int inf,int sup);
void mostrar(tvector v);
int producto(int a, int b);
void productoVectores(tvector v1,tvector v2,tvector v3);

main() {
	srand(time(NULL));
	
	tvector v1,v2,v3;

	cargarVectores(v1,v2);
	
	productoVectores(v1,v2,v3);
	
	
cout<<"\nvector 1"<<endl;
	mostrar(v1);
	
cout<<"\nvector 2"<<endl;
	mostrar(v2);	
	
cout<<"\nProducto"<<endl;
	mostrar(v3);	
	
	

}


void productoVectores(tvector v1,tvector v2,tvector v3){
	int i;
	for(i=0;i<MAX;i++){
		v3[i]=producto(v1[i],v2[i]);
	}	
}
	


void mostrar(tvector v){
	int i;
	
	for (i=0;i<MAX;i++)
		cout<<"["<<v[i]<<"]";
}


	
void cargarVectores(tvector v1, tvector v2){
	int i;
	
	for(i=0;i<MAX;i++){
		v1[i]=aleatorio(-99,99);
		v2[i]=aleatorio(-99,99);
	}
}


int aleatorio(int inf,int sup)
{
	return rand()%(sup-inf)+inf;
}


int producto(int a, int b){
	
	int i;
	bool band;
	int acum;
	int signo = 1;
	
	// Ajustar el signo del resultado
	if ((a < 0 && b > 0) || (a > 0 && b < 0))
	signo = -1;
	
	// Hacer a y b positivos
	a = abs(a);
	b = abs(b);
	
	i = 0;
	
	band = i < b;
	acum = 0;
	
	while (band)
	{
		acum = acum + a;
		i++;
		band = i < b;
	}
	
	return acum * signo;
}
