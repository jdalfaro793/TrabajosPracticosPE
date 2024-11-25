#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>


/** Alumno: Alfaro Josue Dario  - LU:3490 - DNI:41042253 - APU-SSJ **/

using namespace std;

main(){

        int valor,acum=0,i=0;  // Declaracion de variables de tipo entero
        bool estado=true,encontrado=false; // variables bandera para finalizar el bucle y devolver el resultado segun el estado logico con el q terminen.

        bool ok=false;      // variable de tipo bandera que cambiara el estado segun el ingreso de datos

        cout<<"- Programa que determina si el valor ingresado pertenece a la serie 0,0,1,4,11,26,57,... -"<<endl;

        while(ok!=true){                                // bucle que se ejecutara mientras el numero ingresado sea menor a 0.
            cout <<"introduce un valor: "<<endl;        // hasta que el numero ingresado sea 0, o mayor.
            cin>>valor;

            if(valor<0){
                cout<<"valor incorrecto, numero negativo."<<endl;
            }else{
                ok=true;
            }
        };


        do{                          //bucle do{ }while(...) que evaluara si el valor ingresado pertenece o no a la serie
            acum=(acum*2)+i;        // variable que ira guardando la secuencia esperada en cada recorrido 0,0,4,11,26...

            if(acum==valor){    // la condicion evalua si el valor es igual al valor obtenido en el recorrido
            estado=false;          // de encontrar la coincidencia en el rango de sucesiones y el valor pasado, la bandera "estado" cambia el estado a false para terminar el bucle
            encontrado=true;        // la bandera encontrado cambia el valor a true para dar a conocer que encontro la coincidencia.
            }
            else{
                if(acum<2147483616){    // de no encontrar la coincidencia se evalua si el valor de la secuencia es menor al valor maximo de la serie
                i++;                // si resulta ser menor aun, se aumenta en 1 el indice y se repite el bucle
                }
                else{
                estado=false;       // al llegar al valor de la serie termina el bucle cambiando la bandera a false para no crear bucle infinito
                }
            }
        }while( estado );

        if(encontrado==true){
        cout<<"el valor: "<<valor<<" pertenece a la serie"<<endl;   // mostrara si pertenece a la sucesion de valores.
        }else{
        cout<<"el valor: "<<valor<<" no pertenece a la serie"<<endl;
        }


    system("pause");
}

