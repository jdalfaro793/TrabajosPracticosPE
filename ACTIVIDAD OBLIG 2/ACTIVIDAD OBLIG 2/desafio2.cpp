#include <iostream>
#include <stdio.h>
#include <stdlib.h>

/** Alumno: Alfaro Josue Dario  - LU:3490 - DNI:41042253  -  APU-SSJ**/
using namespace std;

//------INICIO DE DECLARACION DE MODULOS, PROCEDIMIENTOS Y FUNCIONES

int invetirNumero(int numero);
int obtenerCuadrado(int numero, int n);
int obtenerModulo(int a, int b);
int obtenerCociente(int a, int b);
int obtenerProducto(int a, int b);
bool validarEspejo(int numero, int numeroInvertido); //
void presentarMensaje(bool valorComparacion);
void ingresarValor(int &numero);


//------INICIO DE PROGRAMA PRINCIPAL

int main(){
    int valor=0;
    int numeroInvertido=0;
    ingresarValor(valor);                                                                       //Modulo para el ingreso del valor
    numeroInvertido=invetirNumero(valor);
    presentarMensaje(validarEspejo(valor,numeroInvertido));                                     //Modulo que presenta el mensaje segun el valor logico que tome el parametro. El Modulo validarEspejo(), se encarga del trabajo
    system("PAUSE");
}


//------INICIO DE PROCEDIMIENTOS Y FUNCIONES

//El siguiente modulo se usa para validar el ingreso correcto del dato de tipo numerico para continuar con la ejecucion del programa
void ingresarValor(int &valor){
    do
    {
        cout<<"Ingrese numero: ";
        cin>>valor;
        if (valor < 0 ){                                                                            //condicion que evalua que el valor ingresado no sea menor a 0 (negativo)
                cout <<"Numeros negativos son invalidos " << endl;
        }else{
                if (valor==0)                                                                       //evalua que el valor ingresado no sea 0
                        cout <<"El numero 0 es invalido para la ejecucion" << endl;
        }
    }while (valor<=0);
}

//El modulo se usa para presentar el mensaje final de la operacion del programa, recibe un valor logico que determina el mensaje a mostrar
void presentarMensaje(bool valorComparacion){
    if(valorComparacion==true){
        cout<<"El numero es espejo"<<endl;
    }else{
        cout<<"El numero no es espejo"<<endl;
    }
}

//Modulo que recibe los 2 valores a comparar si son ESPEJOS, hace la operacion de obtener cuadrado de ambos valores y devuelve el resultado final
bool validarEspejo(int numero, int numeroInvertido){
if(invetirNumero( obtenerCuadrado(numero,2))==obtenerCuadrado(numeroInvertido,2)){                      //La condicion evalua que la potencia del numero y la potencia del mismo numero invertido sean iguales
    return true;
}else
    return false;
}

//El siguiente modulo recibe un valor y retorna el mismo valor pero en forma invertida
int invetirNumero(int numero)
{
    int aux=numero;
    int resto=0,numInv=0;
    while(aux>0)
    {
        resto=obtenerModulo(aux,10);                                 //Llamado al modulo Obtenermodulo() para obtener el modulo del valor entre 1
        aux=obtenerCociente(aux,10);
        numInv=aux+resto;
    }
    return numInv;
}

//El siguiente MODULO RECURSIVO devuelve el valor cuadrado del numero ingresado por parametro
int obtenerCuadrado(int numero, int n){
    if(n==1){
    return numero;                                                   //Si el exponente se iguala a 1, retorno el numero ingresado del calculo echo (CASO BASE)
    }
    if(n==0)
    {return 0;
    }
    else{
    return obtenerProducto(numero,obtenerCuadrado(numero,n-1));      //sino, llamo al modulo obtenerProducto, donde invoco al mismo modulo recursivo como parametro multiplicador
    }
}

//Modulo que devolvera el cociente de 2 valores pasados por parametro (Por resta sucesivas)
int obtenerCociente(int a, int b)
{
    int cociente=0;
    while(a>=b)
    {
        a=a-b;                                                      //Obtener el cociente mediante restas sucesivas
        cociente++;                                                 //En cada repeticion se aumenta en uno
    }
    return cociente;                                                //Retorno el cociente obtenido de la resta
}

//Modulo que devolvera el producto de 2 valores pasados por parametro (Por sumas sucesivas)
int obtenerProducto(int a, int b)
{
    int resultado;
    while(b>0){
        resultado=resultado+a;                                      //Si cumple la condicion de ser el multiplicador mayor a 0, se suma el multiplo y se descuenta el multiplicador en 1
        b--;
    }
    return resultado;                                               //Retorno el resultado obtenido de la suma
}


//Modulo que devolvera el resto o modulo obtenido de 2 valores pasados por parametro (Por resta sucesivas)
int obtenerModulo(int a, int b)
{
    while(a>=b)
    {
        a=a-b;                                                      //Obtener el resto mediante restas sucesivas
    }
    return a;                                                       //Retorno el resto obtenido(0 indica division exacta)
}
