#include <iostream>
	using namespace std;

	const int MAX=20;

	typedef float tvector[MAX];

	void insertar(tvector num, int &ocup, float nuevo);
	void borrar(tvector num, int &ocup, float borrado);
	float calcularPromedio(tvector num, int ocup);
	void mostrar_vector(tvector num, int ocup, int opcion);

	main(){
		
		tvector numeros;
		int ocup=-1,ord;
		char opcion;
		float nuevo;
		
		do{
			cout<<"\n---MENU DE OPCIONES---"<<endl;
			cout<<"(a) insertar valor al vector"<<endl;
			cout<<"(b) borrar un valor del vector"<<endl;
			cout<<"(c) calcular el promedio de valores"<<endl;
			cout<<"(d) mostrar valores almacenados"<<endl;
			cout<<"(s) salir del programa"<<endl;	
			cout<<"----------------------\n"<<endl;
			cout<<"ingrese opcion: ";
			cin>>opcion;
			
			switch(opcion){
				
			case 'a': 
				cout<<"Ingrese valor a cargar al vector: ";
				cin>>nuevo;
				insertar(numeros, ocup, nuevo);
				
				break;
				
			case 'b': 
				cout<<"Ingrese valor a borrar en el vector: ";
				cin>>nuevo;
				borrar(numeros, ocup, nuevo);

				break;
			case 'c':
				if(ocup>-1){
					cout<<"El promedio es: "<<calcularPromedio(numeros,ocup)<<endl;
				}else{
					cout<<"Vector vacio, debe cargar valores."<<endl;
				}
				break;
			case 'd': 
				cout<<"Ingrese orden de visualizacion = 1) Creciente - 2) Decreciente"<<endl;
				cin>>ord;
				if(ord!=1 && ord!=2) 
					cout<<"opcion de visualizacion invalida"<<endl;
				else{
					cout<<"Su vector es:"<<endl;
					mostrar_vector(numeros, ocup,ord);	
				}
				break;
			case 's': 
				cout<<"Adios!"<<endl;
				break;
			default:
				cout<<"Opcion no valida"<<endl;
			}
		}while(opcion!='s');
	}
	
	
	void insertar(tvector num, int &ocup, float nuevo){
		int i,j;
		
		if(ocup==MAX)
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
	
	
	void borrar(tvector num, int &ocup, float borrado){
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
		
		
	float calcularPromedio(tvector num, int ocup){
		float suma=0;
		for(int i=0; i<=ocup; i++){
			suma=num[i]+suma;
		}		
		return suma/(ocup+1);
	}
		
	void mostrar_vector(tvector num, int ocup, int opcion){
		if(opcion==1)
			for(int i=0;i<=ocup;i++)
				cout<<"["<<num[i]<<"]";
		else
			for(int i=ocup;i>=0;i--)
			cout<<"["<<num[i]<<"]";
		
	}
