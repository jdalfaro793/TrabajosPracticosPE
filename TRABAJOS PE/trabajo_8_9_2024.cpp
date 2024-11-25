#include <iostream>

using namespace std;

int resto(int a, int b);
int producto(int a, int b);
int cociente(int a, int b);
bool primo(int n);
void fprimo(int n);
void ingreso(int &n);

main()
{
	int n;
	ingreso(n);
	fprimo(n);
}

void ingreso(int &n)
{
	do
	{
		cout << "ingrese valor: " << endl;
		cin >> n;
		cout << endl;
	} while (n <= 0);
}

void fprimo(int n)
{
	int i = 1;
	while (n > 1)
	{
		if (resto(n, i) == 0 && primo(i))
		{
			cout << n << "|" << i << endl;
			n = cociente(n, i);
		}
		else
		{
			i++;
		}
	}
}

bool primo(int n)
{
	
	if (n <= 1)
	{
		return false; // Los números menores o iguales a 1 no son primos
	}
	
	int i = 2;
	while (i <= cociente(n, 2))
	{
		if (resto(n, i) == 0)
		{
			return false; // Si encontramos un divisor, n no es primo
		}
		i++;
	}
	return true; // Si no encontramos divisores, n es primo
}

// producto de a por b, respetando los signos -1*-3=3 .. -2*1=-2 .. 4*3=12 ..
int producto(int a, int b)
{
	
	int i;
	bool band;
	int acum;
	
	int signo = 1;
	
	// Ajustar el signo del resultado
	if ((a < 0 && b > 0) || (a > 0 && b < 0))
	{
		signo = -1;
	}
	
	// Hacer a y b positivos
	if (a < 0)
	{
		a = a * -1;
	}
	if (b < 0)
	{
		b = b * -1;
	}
	
	i = 0;
	
	band = i < b;
	acum = 0;
	while (band)
	{
		acum = acum + a;
		i++;
		band = i < b;
	}
	
	return acum * signo;
}

// cociente entero entre dos numeros a y b , respetando regla de signos 7/2=7-2 .. 5-2 .. 3-2 ..
int cociente(int a, int b)
{
	
	int signo = 1;
	
	// Ajustar el signo del resultado
	if ((a < 0 && b > 0) || (a > 0 && b < 0))
	{
		signo = -1;
	}
	
	// Hacer a y b positivos
	if (a < 0)
	{
		a = producto(a, -1);
	}
	if (b < 0)
	{
		b = producto(b, -1);
	}
	
	int i = 0;
	
	do
	{
		if (a >= b)
		{
			a = a - b;
			i++;
		}
		
	} while (!(a < b));
	
	return producto(i, signo);
}

int resto(int a, int b)
{
	bool neg = false;
	
	// Ajustar el signo del resultado
	if ((a < 0 && b > 0) || (a < 0 && b < 0))
		neg = true;
	
	a = abs(a);
	b = abs(b);
	
	// Realizar resta sucesiva
	while (a >= b)
	{
		a = a - b;
	}
	
	if (neg)
		a = producto(a, -1);
	
	return a;
}
