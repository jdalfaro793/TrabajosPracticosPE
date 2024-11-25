#include <iostream>
#include <string.h> // libreria de cadenas
#include <stdlib.h>
#include <stdio.h> // libreria que contiene el gets

using namespace std;

typedef char tcad[20];

using namespace std;

main()
{
    tcad cad1, cad2;
    cout << "Ingrese cadena:";
    gets(cad1); // se utiliza gets para leer una cadena completa
    cout << "Ingrese cadena:";
    gets(cad2);
	
	int caaa;
	
	cout<<"ingrese un numero"<<endl;
	
	
	cin>>caaa;
	
    if (strlen(cad1) > 0 && strlen(cad2) > 0)
    {
        if (strcmp(cad1, cad2) == 0)
            cout << "A" << endl;
        else
        {
            if (strcmp(cad1, cad2) < 0)
            {
                strcat(cad1, cad2);
                cout << "A: " << cad1 << endl;
            }
            else
                cout << "A: " << strlen(cad1) + strlen(cad2) << endl;
        }
    }
    else
        cout << "A" << endl;
	
	
	cout <<caaa<<endl;
	
    system("pause");
}
