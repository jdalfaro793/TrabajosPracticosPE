#include <iostream>
#include <stdlib.h>

/** Alumno: Alfaro Josue Dario  - LU:3490 - DNI:41042253  - APU-SSJ**/
using namespace std;

main(){
	int diferencia;
    int acumPar=0;      // Acumulador para la suma de valores pares
    int acumImpar=0;    // Acumulador para la suma de valores impares
    int num=0;        // variable para guardar el numero, y el indicador inicializado en 0
    int cifra=0;          //  variable destructible que guardadara los restos del numero en cada repeticion
    bool ok = false;     // variable que almacenara la validacion del valor ingresado

    bool condicion=true; // variable de tipo bandera para inicio del bucle del calculo


    cout<<"- Algoritmo que determina si el numero ingresado es divisible por 11 -"<<endl;

    while(ok!=true){                                // bucle que se ejecutara mientras el numero ingresado sea menor a 11
    cout <<"Introduce un valor: ";        // hasta que el numero ingresado sea 11, o mayor.
    cin>>num;

    if(num<=11){
    cout<<"No pueden ingresarse numeros negativos menores a 11."<<endl;
    }else{
    ok=true;
    }
    };


    bool f=true;

    while(num>0){
		cifra=num%10;
   	    num=num/10;
        if(num%2==0){
            acumPar=acumPar+cifra;
        }else{
        	acumImpar=acumImpar+cifra;
   		}		
    }


	diferencia=abs(acumPar-acumImpar);

	
	if(diferencia>=10){
	acumImpar=0;
	acumPar=0;
	num=diferencia;
    while(num>0){
		cifra=num%10;
   	    num=num/10;
        if(num%2==0){
            acumPar=acumPar+cifra;
        }else{
        	acumImpar=acumImpar+cifra;
   		}		
    }
    	diferencia=abs(acumPar-acumImpar);
	}
	

	
	if(diferencia==0){
		cout<<"Valor divisible por 11";
		
	}else{
		cout<<"Valor no divisible por 11";
	}
	

	

}

