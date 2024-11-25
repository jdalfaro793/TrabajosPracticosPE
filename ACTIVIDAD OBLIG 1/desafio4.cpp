

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

/** Alumno: Alfaro Josue Dario  - LU:3490 - DNI:41042253  -  APU-SSJ**/
using namespace std;
int main(){

    int valorIngresado,cuadradoInverso,i=0;   // variables auxiliares, y variable de tipo indicador(i)
    int cuadrado=0;        // variable que guardara el cuadrado mediante suma de inpares
    int invCuadrado=0;    // variable que guardara el numero inverso al cuadrado
    int inv=0;           // variable que guardara la inversa del numero ingresado
    int inv2=0;         // variable que guardara la la inversa del cuadrado del numero invertido llevado a la inversa nuevamente

    bool ok=false;       // variable bandera que validara el ingreso exitoso del dato

    int valor;          // variable que guardara el valor ingresado convertido a entero numerico



     cout<<"- Algoritmo que determina si el numero ingresado es ESPEJO o no -"<<endl;

        while(ok!=true){                                // bucle que se ejecutara mientras el numero ingresado sea menor a 0
            cout <<"Introduce un valor: ";        // hasta que el numero ingresado sea 11, o mayor.
            cin>>valor;

            if(valor<0){
                cout<<"No pueden ingresarse numeros menores a 0."<<endl;
            }else{
                ok=true;
            }
        };

    valorIngresado=valor;           // asignacion del valor ingresado a una variable auxiliar para mostrar por consola

    while(i<valor*2){              // calculo del cuadrado mediante suma de impares (aplicado finalizacion por centinela)
        if(i%2!=0){                     // el bucle suma todos los valores de i mientras sea inpar, mientras se mantenga siendo menor a numero*2
            cuadrado=cuadrado+i;        // se acumulan los valores inpares
            }
        i++;                            // aumenta en 1 el indicador
    }

    i=0;                            // reiniciamos la variable a 0 para reuzarla.


    while(valor>0){                 // el siguiente bucle invierte el valor del numero ingresado. Condicion: que sea el numero mayor a 0 inicialmente
        inv=inv * 10 + (valor % 10);   // acumulador que suma los valores ( el mismo numero a la inversa) que obtendra de  su valor * 10, mas el resto(mod) del valor del numero  dividido en 10
        valor = valor / 10;           // al numero se lo divide en 10 y se guarda el cociente obtenido
    }



    while(i<inv*2){                 // obtenemos la potencia del numero ingresado Invertido mediante sumas de numero impar
        if(i%2!=0){                 // el bucle suma todos los valores de i mientras sea inpar, mientras se mantenga siendo menor al valor de inv*2
        invCuadrado=invCuadrado+i;  // se guarda la suma de inpares en la variable invCuadrado
        }
    i++;
    }

    cuadradoInverso=invCuadrado;                    // variable auxiliar para guardar el cuadrado del numero inverso



    while(invCuadrado>0)                            // calculo que devolvera la inversa del cuadrado del numero ingresado, lleveado a la inversa
                                                    // ejemplo: ingreso 12, su inversa es 21, su cuadrado es 441
                                                    //  La inversa del numero a la inversa es 144: que es el VALOR que devolvera el bucle al finalizar la condicion
    {
        inv2=inv2 * 10 + (invCuadrado % 10);
        invCuadrado = invCuadrado / 10;
    }



    cout<<"----"<<endl;
    cout<<"Numero Ingresado: "<<valorIngresado<<endl ;              //presentacion del valor ingresado inicialmente
    cout<<"Cuadrado del numero Ingresado: "<<cuadrado<<endl;        //presentacion del valor obtenido del cuadrado del numero ingresado
    cout<<"Numero inverso:"<<inv<<endl;                             // muestra del valor obtenido del calculo de la inversa
    cout<<"Cuadrado del numero Inverso: "<<cuadradoInverso<<endl;   //presentacion de los valores obtenidos del cuadrado del numero ingresado a la inversa
    cout<<"----"<<endl;



    // Finalmente se compara si el cuadrado del numero ingresado es igual
    // a la inversa de la potencia del numero ingresado llevado a la inversa nuevamente
    // de cumplirse o no la condicion presentara sus respectivos mensajes
    if(cuadrado==inv2){
    cout<<"RESULTADO: Es espejo"<<endl;
    cout<<"----"<<endl;
    }else{
    cout<<"RESULTADO: No es espejo"<<endl;
    cout<<"----"<<endl;
    }






   system("PAUSE");

}
