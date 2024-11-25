#include <iostream>
#include <stdlib.h>
#include <math.h>

/** Alumno: Alfaro Josue Dario  - LU:3490 - DNI:41042253  - APU-SSJ **/

using namespace std;

main(){

        int num;
        int i=1;
        bool ok=false;      // variable de tipo bandera que cambiara el estado segun el ingreso de datos
        cout<<"- Programa que calculara el factorial inverso del valor ingresado -"<<endl;

        while(ok!=true){                                // bucle que se ejecutara mientras el numero ingresado sea menor a 0.
            cout <<"Introduce un valor: ";        // hasta que el numero ingresado sea 0, o mayor.
            cin>>num;

            if(num<=0){
                cout<<"No pueden ingresarse numeros negativos, ni 0 (no tiene valor factorial inverso)"<<endl;
            }else{
                ok=true;
            }
        };


                                        // primeramente se valida si el numero ingresado es igual a 1, dado que !0, y !1 son iguales a 1.
                                        // 1 tiene 2 factoriales inversos, 0 y 1.
        if(num==1){
             cout<<"Factorial inverso: "<<0 <<" y "<< i<<endl;


        }else{                       // de no ser el valor ingresado igual a 1, se hace el calculo del factorial inverso del numero ingresado

                                    // el siguiente bucle obtendra el factorial a la inversa mediante divisiones sucesivas
        while (num>i){              // y se ejecutara mientras el dividendo sea mayor al numero divisor

                num=num/i;          // se hace la division del dividendo por el divisor
                i++;                // al ejecutarse la division, el divisor incrementa en 1 su valor por cada repeticion
                                    // y vuelve a repetirse el bucle

        }

            cout<<"Factorial inverso: "<<i<<endl;

        }
}
