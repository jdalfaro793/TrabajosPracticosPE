#include <iostream>
#include <stdlib.h>
#include <time.h>       //Libreria para usar la funcion rand y srand
#include <stdio.h>

/** Alumno: Alfaro Josue Dario  - LU:3490 - DNI:41042253  -  APU-SSJ**/
using namespace std;

//------INICIO DE DECLARACION DE MODULOS, PROCEDIMIENTOS Y FUNCIONES

int generarNumRamdom();
int obtenerModulo(int a, int b);
int obtenerCociente(int a, int b);
int obtenerProducto(int a, int b);
bool determinarPar(int numero);
bool determinarMultiploDe3(int numero);
bool determinarDivisiblePor11(int numero);
bool determinarCapicua(int numero);
bool hacerPregunta();
void verIndicacion(int indice,bool valor);
void validarIngreso( int &numero);
void listarCoincidenciasPar(bool resultadoPar);
void listarCoincidenciasMultiplo3(bool resultadoPar, bool resultadoMultiplo3);
void listarCoincidenciasDivisiblePor11(bool resultadoPar, bool resultadoMultiplo3, bool ResultadoDivisiblePor11);
void listarCoincidenciasCapicua(bool resultadoPar, bool resultadoMultiplo3, bool ResultadoDivisiblePor11, bool ResultadoCapicua);
void mostrarRespuesta(int intento,bool respuesta);
void mostrarMenu();
void ejecutarOpciones(int &secreto, int &opcion, int &numeroPresentado, bool &op1, bool &op2,bool &op3, bool &op4, bool &op5, bool &op6);
void mostrarSecreto(int secreto);



//------INICIO DE PROGRAMA PRINCIPAL

main()
{
    srand(time(NULL));
    int opcion=0,secreto=0,numeroPresentado=0;                              //Variables principales
    bool op1=false,op2=false,op3=false,op4=false,op5=false,op6=false;       //Variables banderas, controlan cada decision tomada dentro del menu

    do
    {
        mostrarMenu();                                                                  //Llamado al procedimiento que mostrara el menu de opciones
        cin>>opcion;
        ejecutarOpciones(secreto, opcion, numeroPresentado, op1,op2,op3, op4,op5, op6); //Llamado al procedimiento que ejecutara la opcion elegida
    }
    while(opcion!=7);

}


//------INICIO DE PROCEDIMIENTOS Y FUNCIONES

//Modulo que muestra el resultado de la opcion elegida segun el switch de opciones que se pueden elegir
void ejecutarOpciones(int &secreto, int &opcion, int &numeroPresentado, bool &op1, bool &op2,bool &op3, bool &op4, bool &op5, bool &op6)
{
    switch(opcion)
    {
    case 1:
        secreto=generarNumRamdom();                                     //Genero un numero ramdom entre 100 y 999 mediante el modulo generarNumRamdom()
        cout<<"\t\nEl adivino eligio su numero aleatorio!\n"<<endl;
        op1=true;                                                       //Cambio de estado de la primer bandera
        break;
    case 2:
        if(op1==true)                                                   //Condicion que valida que la primer bandera este verdadera
        {
            verIndicacion(1,determinarPar(secreto));                    //Muestro la pista en forma textual para mejor comprension de la lista de numeros
            listarCoincidenciasPar(determinarPar(secreto));                    //Muestro la lista de numeros generada en primer instancia (PARES o IMPARES)
            op2=true;                                                   //Cambio de estado de la 2da bandera
            if(hacerPregunta()==true)                                   //Llamo al modulo hacerPregunta() que le hara la pregunta de probar suerte al usuario
            {
                validarIngreso(numeroPresentado);                       //Modulo que valida el ingreso correcto del numero en el rango 100-999
                if(numeroPresentado==secreto)                           //Condicion que evalua si el numero ingresado es igual al secreto
                {
                    mostrarRespuesta(1,true);                           //Modulo que presentara el mensaje de gano y su respectivo premio.
                    mostrarSecreto(secreto);                            //Modulo que mostrara el numero secreto
                    op1=false;
                }
                else
                {
                    mostrarRespuesta(0,false);                          //Modulo que presentara el mensaje de perdio
                    mostrarSecreto(secreto);
                    op1=false;                                          //Cambio el estado de la bandera para desactivar las opciones
                }
            }
        }
        else
        {
            mostrarRespuesta(-1,false);                                  //Modulo que mostrara el mensaje de error si la bandera no esta en true
        }
        break;
    case 3:
        if(op1==true && op2==true)                                       //Condicion que valida que la primer y 2da bandera esten verdaderas
        {
            verIndicacion(2,determinarMultiploDe3(secreto));                                //Muestro la pista en forma textual para mejor comprension de la lista de numeros
            listarCoincidenciasMultiplo3(determinarPar(secreto),determinarMultiploDe3(secreto)); //Muestro la lista de numeros generada en 2da instancia (PARES o IMPARES, MULTIPLOS O NO DE 3)
            op3=true;
            if(hacerPregunta()==true)                                                       //Llamo al modulo hacerPregunta() que le hara la pregunta de probar suerte al usuario
            {
                validarIngreso(numeroPresentado);                                           //Modulo que valida el ingreso correcto del numero en el rango 100-999
                if(numeroPresentado==secreto)
                {
                    mostrarRespuesta(2,true);                                               //Modulo que presentara el mensaje de gano y su respectivo premio.
                    mostrarSecreto(secreto);                                                //Modulo que presentara el numero secreto.
                    op1=false;
                }
                else
                {
                    mostrarRespuesta(0,false);                                              //Modulo que presentara el mensaje de perdio
                    mostrarSecreto(secreto);
                    op1=false;                                                              //Cambio el estado de la bandera para desactivar las opciones
                }
            }
        }
        else
            mostrarRespuesta(-1,false);                                                     //Modulo que mostrara el mensaje de error si la bandera no esta en true
        break;
    case 4:
        if(op1==true && op2==true && op3==true)                                                                                     //Condicion que valida que la primer, 2da y 3er  bandera esten verdaderas
        {
            verIndicacion(3,determinarDivisiblePor11(secreto));                                                                     //Muestro la pista en forma textual para mejor comprension de la lista de numeros
            listarCoincidenciasDivisiblePor11(determinarPar(secreto),determinarMultiploDe3(secreto),determinarDivisiblePor11(secreto));    //Muestro la lista de numeros generada en 3er instancia (PARES o IMPARES, MULTIPLOS O NO DE 3, DIVISIBLES O NO POR 11)
            op4=true;
            if(hacerPregunta()==true)                                                                                               //Llamo al modulo hacerPregunta() que le hara la pregunta de probar suerte al usuario
            {
                validarIngreso(numeroPresentado);                                                                                   //Modulo que valida el ingreso correcto del numero en el rango 100-999
                if(numeroPresentado==secreto)
                {
                    mostrarRespuesta(3,true);                                                                                       //Modulo que mostrara la respuesta de gano y su respectivo premio
                    mostrarSecreto(secreto);
                    op1=false;
                }
                else
                {
                    mostrarRespuesta(0,false);
                    mostrarSecreto(secreto);
                    op1=false;
                }
            }
        }
        else
            mostrarRespuesta(-1,false);
        break;
    case 5:
        if(op1==true && op2==true && op3==true && op4==true)                                                                                            //Condicion que valida que la primer, 2da, 3er y 4ta bandera esten verdaderas
        {
            verIndicacion(4,determinarCapicua(secreto));
            listarCoincidenciasCapicua(determinarPar(secreto),determinarMultiploDe3(secreto),determinarDivisiblePor11(secreto),determinarCapicua(secreto));    //Muestro la lista de numeros generada en 2da instancia (PARES o IMPARES, MULTIPLOS O NO DE 3, DIVISIBLES O NO POR 11, CAPICUAS O NO CAPICUAS)
            op5=true;
            if(hacerPregunta()==true)
            {
                validarIngreso(numeroPresentado);                                   //Modulo que valida el ingreso correcto del numero en el rango 100-999
                if(numeroPresentado==secreto)
                {
                    mostrarRespuesta(4,true);                                       //Modulo que mostrara la respuesta de gano y su respectivo premio
                    mostrarSecreto(secreto);
                    op1=false;
                }
                else
                {
                    mostrarRespuesta(0,false);
                    mostrarSecreto(secreto);
                    op1=false;
                }
            }
            else
            {
                mostrarRespuesta(-3,false);                                         //Modulo que mostrara el mensaje de perdio
            }
        }
        else
            mostrarRespuesta(-1,false);
        break;

    case 6:
        if(op1==true && op2==true && op3==true && op4==true && op5==true)           //Condicion que valida que la primer, 2da, 3er, 4ta y 5ta bandera esten verdaderas
        {
            mostrarRespuesta(-4,false);                                             //Llamo al modulo para presentar un mensaje hacia el usuario, (siguiendo la tematica del juego)
            validarIngreso(numeroPresentado);                                       //Modulo que valida el ingreso correcto del numero en el rango 100-999
            if(numeroPresentado==secreto)
            {
                mostrarRespuesta(4,true);                                           //Modulo que mostrara la respuesta de gano y su respectivo premio
                mostrarSecreto(secreto);                                            //Modulo que mostrara el numero secreto
                op1=false;
            }
            else
            {
                mostrarRespuesta(-2,false);                                         //Modulo que mostrara el mensaje de perdio por no adivinar mostrando todas las pistas(Tematica del juego)
                mostrarSecreto(secreto);
                op1=false;
            }
        }
        else
            mostrarRespuesta(-1,false);                                             //Modulo que mostrara la respuesta de no ingreso de anteriores opciones
        break;

    case 7:
        cout<<"\n***JUEGO FINALIZADO :D***\n";
        break;
    default:
        cout<<" OPCION INCORRECTA "<<endl;
    }
}


//Modulo que genera un numero ramdom aleatorio entre el rango [100-999]
int generarNumRamdom()
{
    return 100 + obtenerModulo(rand() , 900);
}

//Modulo que listara los numeros que coincidan con el numero secreto(Par o impar)
void listarCoincidenciasPar(bool resultadoPar)
{
    for(int i=100; i<=999; i++)
        if(determinarPar(i)==resultadoPar)          //Condicion que mostrara los pares o impares segun el valor logico que traiga de validar el numero secreto
            cout<<i<<" ";
}

//Modulo que listara los numeros que coincidan con el numero secreto(Par o impar y ademas sean o no multiplos de 3)
void listarCoincidenciasMultiplo3(bool resultadoPar,bool resultadoMultiploDe3)
{
    for(int i=100; i<=999; i++)
        if(determinarPar(i)==resultadoPar && determinarMultiploDe3(i)==resultadoMultiploDe3 ) //Condicion que mostrara los pares o impares, y multiplos o no de 3, segun el valor logico que traiga de validar el numero secreto
            cout<<i<<" ";
}

//Modulo que listara los numeros que coincidan con el numero secreto(Par o impar, sean o no multiplos de 3 y ademas divisibles o no por 11)
void listarCoincidenciasDivisiblePor11(bool resultadoPar, bool resultadoMultiplo3, bool ResultadoDivisiblePor11)
{
    for(int i=100; i<=999; i++)
        if(determinarPar(i)==resultadoPar && determinarMultiploDe3(i)==resultadoMultiplo3 && determinarDivisiblePor11(i)==ResultadoDivisiblePor11) //Condicion que mostrara los pares o impares, multiplos o no de 3, y divisibles o no por 11, segun el valor logico que traiga de validar el numero secreto
            cout<<i<<" ";
}

//Modulo que listara los numeros que coincidan con el numero secreto(Par o impar, sean o no multiplos de 3, divisibles o no por 11 y ademas sean o no capicuas)
void listarCoincidenciasCapicua(bool resultadoPar, bool resultadoMultiplo3, bool ResultadoDivisiblePor11, bool ResultadoCapicua)
{
    for(int i=100; i<=999; i++)
        if(determinarPar(i)==resultadoPar && determinarMultiploDe3(i)==resultadoMultiplo3 && determinarDivisiblePor11(i)==ResultadoDivisiblePor11  && determinarCapicua(i)==ResultadoCapicua) //Condicion que mostrara los pares o impares, multiplos o no de 3, divisibles o no por 11 y capicuas o no capicuas, segun el valor logico que traiga de validar el numero secreto
            cout<<i<<" ";
}

//Modulo que devolvera el resto o modulo obtenido de 2 valores pasados por parametro (Por resta sucesivas)
int obtenerModulo(int a, int b)
{
    while(a>=b)
    {
        a=a-b;      //Obtener el resto mediante restas sucesivas
    }
    return a;       //Retorno el resto obtenido(0 indica division exacta)
}

//Modulo que devolvera el cociente de 2 valores pasados por parametro (Por resta sucesivas)
int obtenerCociente(int a, int b)
{
    int cociente=0;
    while(a>=b)
    {
        a=a-b;      //Obtener el cociente mediante restas sucesivas
        cociente++;     //En cada repeticion se aumenta en uno
    }
    return cociente;       //Retorno el cociente obtenido
}

//Modulo que devolvera el producto de 2 valores pasados por parametro (Por sumas sucesivas)
int obtenerProducto(int a, int b)
{
    int resultado;
    for (int i=0; i<b; i++)   //Condicion que cumple el bucle es que el iterador no llegue a ser mayor al multiplicador
        resultado = resultado + a;  //guardo el valor del multiplicando en un acumulador
    return resultado;
}

//Modulo que devolvera true o false si el numero pasado por parametro es capicua
bool determinarCapicua(int numero)
{
    int aux=numero;
    int resto=0,numInv=0;

    while(aux>0)
    {
        resto=obtenerModulo(aux,10);    //Llamado al modulo Obtenermodulo() para obtener el modulo del valor entre 10
        aux=obtenerCociente(aux,10);
        numInv=obtenerProducto(numInv,10)+resto;
    }

    if(numInv==numero)                  //Evaluo si el numero obtenido es igual o no al numero ingresado para devolver el resultado
    {
        return true;
    }
    else
    {
        return false;
    }
}


//Modulo que determinara si el numero ingresado por parametro es multiplo o no de 3.
bool determinarMultiploDe3(int numero)
{
    if( obtenerModulo(numero,3)==0)     //Condicion que llama al modulo ObtenerModulo para validar que el numero ingresado sea divisible por 3, 0 indica division exacta
    {
        return true;
    }
    else
    {
        return false;
    }
}

//Modulo que determinara si el numero ingresado por parametro es par o impar
bool determinarPar(int numero)
{
    if ( obtenerModulo(numero,2) == 0 )     //Condicion que llama al modulo ObtenerModulo para validar que el numero ingresado sea divisible por 2, 0 indica division exacta

        return true;
    else
        return false;
}

//Modulo que determina si el numero ingresado es divisible por 11 o no
bool determinarDivisiblePor11(int num)
{
    int par=0, imp=0, resultado=0, fg=0;            //Variables auxiliares
    bool band=false,band2=true;                           //Bucle que condicion que la bandera sea verdadera para repetir siempre que el valor de la diferencia sea mayor a un digito de 2 cifras
     while(v2){
            while(num != 0) {                       //Bucle que condicion que el numero ingresado sea distinto a 0 para validar el calculo de cifras pares e impares
            fg = obtenerModulo(num , 10);           //variable auxiliar que guarda el numero modulo 10(los digitos)
            num = obtenerCociente(num , 10);        //variable que se actualizara con  (elimina los digitos)
            if(!band) {
                imp = imp + fg;                     //Variable que guardara la suma de impares
                band = true;                        //Cambio de estado de la bandera
            }else {
                par = par + fg;
                band = false;
            }
            resultado=abs(imp-par);                 //Suma de valores obtenidos
            }
             if(resultado>=10){                     //Si la suma de los digitos es mayor a 2, se actualiza el valor del num y repite el proceso.
                num=resultado;
                imp=0;
                par=0;
             }else{
                band2=false;                        //Al terminar la validacion cambia el estado a false
             }
     }
    if(resultado ==0)         //Condicion que valida el resultado final para devolver true, o false
        return true;
    else
        return false;
}

//Modulo que validara el ingreso del numero del usuario SOLO numeros permitidos en el rango [100-999]
void validarIngreso( int &numero)
{
    do
    {
        cout<<"\nIngrese su numero: "<<endl;
        cin>>numero;
        if(numero<100 || numero>999)
        {
            cout<<"\nSu numero debe ser de 3 cifras!, entre 100 y 999"<<endl;
        }
    }
    while(numero<100 || numero>999); //condicion que valida SOLO numeros permitidos en el rango [100-999]
}

//Modulo que interactua con el usuario, presenta 2 opciones, 1 Para probar suerte o 2 para obtener mas pistas
bool hacerPregunta()
{
    int respuesta;
    do
    {
        cout<<"\nDIGITE 1: Probar suerte  O  2: Obtener mas pistas:";
        cin>>respuesta;
    }
    while(respuesta<1 || respuesta>2);  //Condicion que valida que el numero ingresado sea 1 o 2 solamente
    if(respuesta==1)
        return true;                    //Devuelve true si elige probar suerte
    if(respuesta==2)
        return false;                   //Devuelve false si elige obtener mas pistas
return false;
}

//Modulo que presentara distintos mensajes segun los parametros recibidos, desde mensajes con tematicas para el usuario, hasta mensajes de premios
void mostrarRespuesta(int intento,bool respuesta)
{
    if(intento==-4 && respuesta==false)
    {
        cout<<"\nEL ADIVINO DICE: YA NO HAY MAS PISTAS, DEBES ARRIESGARTE MUAHAHAHA >:D\n"<<endl;
    }
    if(intento==-3 && respuesta==false)
    {
        cout<<"\nYA NO HAY MAS PISTAS, DEBES ARRIESGARTE\n"<<endl;
    }
    if(intento==-2 && respuesta==false)
    {
        cout<<"\nNO ADIVINASTE. USASTE TODAS LAS PISTAS. TE QUEDARAS PARA SIEMPRE EN EL BOSQUE Y SERAS LA COMIDA DE LOS LOBOS AHAHA!!\n";
        cout<<endl;
    }
    if(intento==-1 && respuesta==false)
    {
        cout<<"\nGENERE EL NUMERO O USE LAS PISTAS ANTERIORES PRIMERO\n"<<endl;
        cout<<endl;
    }
    if(intento==0 && respuesta==false)
    {
        cout<<"\nNO adivinaste. seras la comida de los lobos\n"<<endl;
    }
    if(intento==1 && respuesta==true)
    {
        cout<<"\nAdivinaste!!!"<<endl;
        cout<<"\nEl adivino te obsequiara un mapa, una linterna, comida, un caballo y oro.\n"<<endl;
    }
    if(intento==2 && respuesta==true)
    {
        cout<<"\nAdivinaste!!!"<<endl;
        cout<<"\nEl adivino te obsequiara un mapa, una linterna, comida y plata..\n"<<endl;
    }
    if(intento==3 && respuesta==true)
    {
        cout<<"\nAdivinaste!!!"<<endl;
        cout<<"\nEl adivino te obsequiara un mapa, un media ración de comida, una manta y bronce.\n"<<endl;
    }
    if(intento==4 && respuesta==true)
    {
        cout<<"\nAdivinaste!!!"<<endl;
        cout<<"\nEl adivino te obsequiara un mapa, y un pequeño pan.\n"<<endl;
    }
}

//Modulo puramente creado para mostrar al usuario en forma textual la pista sobre el numero secreto, recibe por parametro un indice y un valor logico (se envian segun el valor que se evalue del numero secreto)
void verIndicacion(int indice, bool valor)
{
    if (indice==1 && valor==true)
        cout<<"PISTA: El valor secreto se sabe que es PAR, y se encuentra en esta lista\n"<<endl;
    if (indice==1 && valor==false)
        cout<<"PISTA: El valor secreto se sabe que es IMPAR, y se encuentra en esta lista\n"<<endl;
    if (indice==2 && valor==true)
        cout<<"PISTA: El valor secreto se sabe que es MULTIPLO DE 3, y se encuentra en esta lista\n"<<endl;
    if (indice==2 && valor==false)
        cout<<"PISTA: El valor secreto se sabe que NO es MULTIPLO DE 3, y se encuentra en esta lista\n"<<endl;
    if (indice==3 && valor==true)
        cout<<"PISTA: El valor secreto se sabe que es MULTIPLO DE 11, y se encuentra en esta lista\n"<<endl;
    if (indice==3 && valor==false)
        cout<<"PISTA: El valor secreto se sabe que NO es MULTIPLO DE 11, y se encuentra en esta lista\n"<<endl;
    if (indice==4 && valor==true)
        cout<<"PISTA: El valor secreto se sabe que es CAPICUA, y se encuentra en esta lista\n"<<endl;
    if (indice==4 && valor==false)
        cout<<"PISTA: El valor secreto se sabe que NO es CAPICUA, y se encuentra en esta lista\n"<<endl;
}

//Modulo que mostrara en forma dinamica el menu de opciones desplegado para que el usuario pueda elegir una opcion a su gusto
void mostrarMenu()
{
    cout<<"\t\t\t******************ADIVINA ADIVINADOR****************"<<endl;
    cout<<"\t\t\t*  1- Generar valor aleatorio de 3 cifras          *"<<endl;
    cout<<"\t\t\t*  2- Obtener pista si el valor es par o impar     *"<<endl;
    cout<<"\t\t\t*  3- Obtener pista si el valor es multiplo de 3   *"<<endl;
    cout<<"\t\t\t*  4- Obtener pista si el valor es multiplo de 11. *"<<endl;
    cout<<"\t\t\t*  5- Obtener pista si el valor es capicua.        *"<<endl;
    cout<<"\t\t\t*  6- Arriesgar o morir!!!                         *"<<endl;
    cout<<"\t\t\t*  7- Salir del juego                              *"<<endl;
    cout<<"\t\t\t****************************************************"<<endl;
    cout<<"Elija una opcion:  ";
}

//Modulo que finalmente presentara el numero secreto, recibe el numero secreto por parametro y lo enseña
void mostrarSecreto(int secreto)
{
    cout<<"\n***********************************\n"<<endl;
    cout<<"**** EL valor secreto era: "<<secreto<<" ****"<<endl;
    cout<<"\n***********************************\n"<<endl;

}
