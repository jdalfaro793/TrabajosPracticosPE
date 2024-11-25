#include <iostream>
#include <stdlib.h>
#include <stdio.h>

/** Alumno: Alfaro Josue Dario  - LU:3490 - DNI:41042253  -  APU-SSJ**/
using namespace std;

//------INICIO DE DECLARACION DE MODULOS, PROCEDIMIENTOS Y FUNCIONES

int obtenerModulo(int a, int b);
int obtenerCociente(int a, int b);
int obtenerProducto(int a, int b);

bool primo(int n);
void ingresoValor(int &valor);
void mostrarFactPrimos(int valor);


//------INICIO DE PROGRAMA PRINCIPAL

int main(){

    int valor=0;
    ingresoValor(valor);        //Procedimiento que pedira el ingreso del valor y hara su validacion
    mostrarFactPrimos(valor);   //Procedimiento que llamara a la funcion primo y mostrara el resultado de la descomposicion de los valores primos

}



//------INICIO DE PROCEDIMIENTOS Y FUNCIONES

/*
Anotacion De ingreso de valores:
Me base en las reglas de validacion de la pagina: https://es.numere-prime.ro/descomposicion-numeros-compuestos-en-factores-primos.php
Que sugiere que los numeros no puedan ser negativos, 0 o 1, puesto que estos no pueden descomponerse o no son numeros primos o compuestos.
*/
//El siguiente modulo se usa para validar el ingreso correcto del dato de tipo numerico para continuar con la ejecucion del programa
void ingresoValor(int &valor){
    do
    {
        cout<<"Ingrese numero: ";
        cin>>valor;
        if (valor < 0 ){    //condicion que evalua que el valor ingresado no sea menor a 0 (negativo)
                cout <<"Numeros negativos son invalidos " << endl;
        }else{
                if (valor==1) //evalua que el valor ingresado no sea 1
                   {
                        cout <<"El numero 1, por convenio matematico, no se considera ni primo ni compuesto" << endl;
                   }
                else{

                 if (valor==0)  //evalua que el valor no sea 0, porque no tiene descomposicion en factores primos
                    cout <<"0 no se puede descomponer en factores primos, 0 no es numero primo ni compuesto" << endl;

                }

        }
    }while (valor<2);
}

//El siguiente modulo hara los calculos y presentara la descomposicion en factores primos del valor ingresado
void mostrarFactPrimos(int valor){
cout<<"\nEl valor: "<<valor<<" , descompuesto en factores primos es"<<endl;
int i=2;                                                                            //variable indice con valor igual a 2, por ser el primer numero primo existente
    do{
       if( primo(i)==true){                                                         //la condicion evalua que el valor que toma i sea primo
         if(obtenerModulo(valor,i)==0){                                             //de cumplirse con ser primo se evalua que el resto de la division del valor ingresado y el valor de i sea 0, que indica una division exacta
                valor=obtenerCociente(valor,i);                                     //se cambia el valor de la variable 'valor' al mismo valor dividido entre i
                cout<<i<<" *";                                                      // y finalmente se presenta el resultado del factor primo por el que se dividio
            }else{
            i++;                                                                    // de no cumplirse con la condicion se actualiza el valor de i en +1
            }
        }
    }while(valor!=1);                                                               //el bucle finalizara cuando el valor ingresado llega al caso base, osea a 1
}



//Modulo que devolvera el resto o modulo obtenido de 2 valores pasados por parametro (Por resta sucesivas)
int obtenerModulo(int a, int b)
{
    while(a>=b)
    {
        a=a-b;                                                                       //Obtener el resto mediante restas sucesivas
    }
    return a;                                                                        //Retorno el resto obtenido(0 indica division exacta)
}

//Modulo que devolvera el cociente de 2 valores pasados por parametro (Por resta sucesivas)
int obtenerCociente(int a, int b)
{
    int cociente=0;
    while(a>=b)
    {
        a=a-b;                                                                        //Obtener el cociente mediante restas sucesivas
        cociente++;                                                                   //En cada repeticion se aumenta en uno
    }
    return cociente;                                                                  //Retorno el cociente obtenido
}



//el siguiente modulo recursivo evalua que el valor que se envia, sea primo, recibe el valor a validar y un cociente igual a 1
bool primo(int n){
    if(n==1){                                                                         //si el valor del numero iguala a 1 que vendria a ser el caso base, retorna true
        return true;
    }else{
        return primo(n-1);                                                        //sino, la funcion recursiva se llama a asi misma reduciendo el valor ingresado en uno, para volver a validarse
    }
}


