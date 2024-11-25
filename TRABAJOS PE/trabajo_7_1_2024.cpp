#include <iostream>
#include <stdlib.h>
using namespace std;

int cuadrado(int n);

main()
{ 
	int n;

	cout << "Ingrese dato: ";
	cin >> n;

	cout << "Salida: " << cuadrado(n) << endl;
	system("pause");
}


int cuadrado(int n){
	int m;
	bool b;
	
	n=2*n-1;
	m=0;
	b=n>0;
	while (b==true){ 	
		m=m+n%2*n;
		n=n-1;
		if (!(n>0))
			b=false;
	}
	
	return m;
}