#include <iostream>
using namespace std;

void enigma(int &m, int &n);
void misterio(int &a, int &b);
void secreto(int x, int y);
bool primo(int n);

main()
{
	int num1, num2;
	enigma(num1, num2);
	misterio(num1, num2);
	secreto(num1, num2);
}

//ingreso de valores positivos o 0 
void enigma(int &m, int &n)
{
	do
	{
		cout << "Ingrese valor: ";
		cin >> m;
		cout << "Ingrese valor: ";
		cin >> n;
	} while ((m < 0) || (n < 0));
}

//ordenar los valores ingresados de menor a mayor
void misterio(int &a, int &b)
{
	if (a != b)
	{
		if ((a - b) > 0)
		{
			a = a - b;
			b = b + a;
			a = b - a;
		}
	}
}

//mostrar todos los impares en el rango de x a y
void secreto(int x, int y)
{
	int i;
	for (i = x; i <= y; i++)
		if (primo(i))
			cout << i<< "... ";
	
	cout << endl;
}


bool primo(int n){
	int i=2;
	bool prim=(n%i)!=0;
	while(i<n && prim)
	{
		prim=(n%i)!=0;
		i++;
		
	}	
	return prim; //true si es primo, false si no es primo
}
	
