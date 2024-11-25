#include <iostream>
#include <math.h>
#include <stdio.h>

/** Alumno: Alfaro Josue Dario  - LU:3490 - DNI:41042253  -  APU-SSJ**/
using namespace std;

void ingreso(float &b,float &c);
float pitagoras(float b,float c);
float raiz(float n);
void mostrar(float res);

main()
{ float hipo,catb,catc;
  cout << "*** CALCULO DE PITAGORAS ***" << endl;
  ingreso(catb,catc);
  hipo=pitagoras(catb,catc);
  mostrar(hipo);

}

void ingreso(float &b,float &c)
{ bool pos;
	do
	{
		cout << "Ingrese cateto b: ";
		cin >> b;
		cout << "Ingrese cateto c: ";
		cin >> c;
		pos=b>0&&c>0;
		if (pos==false)
			cout << "Debe ingresar valores positivos" << endl;
	}while(pos==false);
}



float pitagoras(float b,float c)
{
	return raiz(pow(b,2)+pow(c,2));
}


                                                                                                                                        //7.3 y 5.6
float raiz(float n)
{
    int i,result,aux;
    bool b=true;
    do{
        if(result<=n){
            aux=result;
            i++;
            result=i*i;
        }
        else{
            b=false;
        }
    }while(b);

    i=i-1;
    return (n+aux)/(2*i);
}

void mostrar(float res)
{
	cout << "Hipotenusa del triangulo: " << res << endl;
}

