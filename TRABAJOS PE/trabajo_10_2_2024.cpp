#include <iostream>
#include <time.h>
using namespace std;

const int MAX_VALOR=15;

typedef char tvector[MAX_VALOR];

void agregar(tvector num, int &ocup, char nuevo);
void insertar(tvector num, int &ocup, int nuevo);
void borrar(tvector num, int &ocup, int borrado);
void cargarVector(tvector num, int &ocup);
void mostrarVector(tvector num, int &ocup);
int aleatorio(int inf,int sup);
void menu(int &opcion);
bool buscarMayusculas(tvector num,int ocup);

int secreto (tvector datos,  int ocup);

int secreto (tvector datos,  int ocup)
{ int aux;
if (ocup==0)
	aux=datos[ocup];
else {
	aux=secreto(datos,ocup-1);
	if (aux>datos[ocup])
		aux=datos[ocup];
}	return aux;

}

main() {
	
	tvector numeros;
	srand(time(NULL));
	int ocup=-1;
	char opcion;
	char nuevo;
	
	
	do{
		cout<<"\n---MENU DE OPCIONES---"<<endl;
		cout<<"(a) agregar valor al vector"<<endl;
		cout<<"(b) borrar un valor del vector"<<endl;
		cout<<"(c) determinar si el vector contiene solo minusculas"<<endl;
		cout<<"(s) determinar si el vector contiene solo minusculas"<<endl;
		cout<<"(d) mostrar valores almacenados en el vector"<<endl;
		cout<<"(0) fin del programa"<<endl;	
		cout<<"----------------------\n"<<endl;
		cout<<"ingrese opcion: ";
		cin>>opcion;
		
		switch(opcion){
			
		case 'a': 
			cout<<"ingrese valor a cargar al vector: ";
			cin>>nuevo;
			agregar(numeros, ocup, nuevo);
			mostrarVector(numeros,ocup);
			
			break;
			
		case 'b': 
			cout<<"ingrese valor a borrar en el vector: ";
			cin>>nuevo;
			borrar(numeros, ocup, nuevo);
			mostrarVector(numeros,ocup);
			break;
		case 'c': 
			if(buscarMayusculas(numeros,ocup)){
				cout<<"El vector tiene letras mayusculas!."<<endl;
			}else{
				cout<<"El vector solo contiene minusculas!."<<endl;
			}
			break;
		case 'd': 
			cout<<"Su vector es:"<<endl;
			mostrarVector(numeros, ocup);
			break;
			
		case 's': 
			cout<<"Su vector es:"<<secreto(numeros,ocup)<<endl;
			
			break;
			
		case '0': 
			cout<<"Adios!"<<endl;
			break;
		default:
			cout<<"opcion no valida"<<endl;
			
		}
		
	}while(opcion!='0');
	

	
}

bool buscarMayusculas(tvector num, int ocup){
	
	bool mayus=false;
	
	int i=0;
	
	if(ocup!=-1){
		while((i<=ocup) && !mayus){
			if(num[i]>='A' && num[i]<='Z'){
				mayus=true;
			} else {
				i++;
			}
			
		}
	}
	
	return mayus;
}


int aleatorio(int inf,int sup)
{
	return rand()%(sup-inf)+inf;
}

void cargarVector(tvector num, int &ocup){
	for(int i=0;i<=MAX_VALOR-1;i++){
		agregar(num,ocup,aleatorio(97,122));
	}
	cout<<"se cargo el vector exitosamente"<<endl;
}
	
void mostrarVector(tvector num, int &ocup){
	for(int i=0;i<=ocup;i++){
		cout<<"["<<num[i]<<"]";
	}
}

void agregar(tvector num, int &ocup, char nuevo){
	if(ocup==MAX_VALOR) {
		cout<<"vector lleno.."<<endl;
	}
	else
	{
		ocup++;
		num[ocup]=nuevo;
	}
}
	
void insertar(tvector num, int &ocup, int nuevo){
	int i,j;
	
	if(ocup==MAX_VALOR)
	{
		cout<<"VECTOR LLENO"<<endl;	
	}
	else
	{
		i=0;
		while((i<=ocup) && (nuevo>num[i])){
			i++;
		}
		j=ocup;
		while(j>=i){
			num[j+1]=num[i];
			j--;
		}
		num[i]=nuevo;
		ocup++;
	}	
}
	
void borrar(tvector num, int &ocup, int borrado){
	int i;
	bool encontrado;
	
	if(ocup==-1) {
		cout << "vector vacio..."<<endl;
	}
	else
	{
		encontrado=false;
		i=0;
		
		while((i<=ocup) && !encontrado){
			if(borrado==num[i]) 
				encontrado=true;
			else 
				i++;
		}
		if(encontrado){
			while(i<ocup){
				num[i]=num[i+1];
				i++;
			}
			ocup--;
			cout<<"elemento eliminado..."<<endl;
		}else{
			cout<<"elemento no existe"<<endl;
		}
		
	}
	
}
