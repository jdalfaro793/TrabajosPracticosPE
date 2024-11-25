#include <iostream>
using namespace std;
void enigma(int &m, int &n);
void misterio(int &a, int &b);
void secreto(int x, int y);
main()
{ int num1,num2;
enigma(num1,num2);
misterio(num1,num2);
secreto(num1,num2);
}


void enigma(int &m, int &n)
{
	do{
		cout << "Ingrese valor: ";
		cin >> m;
		cout << "Ingrese valor: ";
		cin >> n;
	} while(m<0 || n<0);
}

void misterio(int &a, int &b)
{ if (a!=b)
{ if (a-b>0)
{ a=a-b;
b=b+a;
a=b-a;
}
else
	  if (b-a>0)
{ b=b-a;
a=a+b;
b=a-b;
}
}
}
void secreto(int x,int y)
{ int i;
for(i=x;i<=y;i++)
	if (i%2==1)
		cout << i;
cout << endl;
}
