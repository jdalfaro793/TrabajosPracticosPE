#include <iostream>

using namespace std;

int caracter(char c);
int numero(char c);
int producto(int a, int b);
int cociente(int a, int b);
int potencia(int a, int b);
int resto(int a, int b);
int factorial(int num);
int cuadrado(int n);
int contar_digitos(int num);
int inverso(int n);
bool capicua(int n); //devuelve true si es capicua o no
bool primo(int n); //devuelve true si es primo o no
int fibo(int ter);
bool isfibo(int num1);

int main()
{
	char operador;
	int num1, num2;

	cout << "\n-----------------------------"<< endl;
	cout << "-----Calculadora-----"<< endl;

	cout << "\na: ";
	cin >> num1;

	cout << "\nb: ";
	cin >> num2;

	cout << "\nIngrese Operador: "<<endl;
	cout<<"(+) suma"<<endl;
	cout<<"(-) resta"<<endl;
	cout<<"(*) producto"<<endl;
	cout<<"(/) division decimal"<<endl;
	cout<<"(d) division entera"<<endl;
	cout<<"(m) modulo"<<endl;
	cout<<"(^) potencia"<<endl;
	cout<<"(~) raiz cuadrada"<<endl;
	cout<<"(!) factorial"<<endl;
	
	cin >> operador;

	switch (operador)
	{
	case '+':
		cout << "\nSuma de "<<num1<<"+"<<num2<<" es: "<<num1 + num2 << endl;
		break;
	case '-':
		cout << "\nResta de "<<num1<<"-"<<num2<<" es: "<< num1 - num2 << endl;
		break;
	case '*':
		cout << "\nProducto de "<<num1<<"*"<<num2<<" es: " << producto(num1, num2)<< endl;
		break;
	case '/':
		cout << "\nDivision decimal de "<<num1<<"/"<<num2<<" es: " << (num1*1.0)/(num2*1.0)<<endl;
		break;
	case 'd':
		if (num2 != 0)
			cout << "\nDivision entera de "<<num1<<" div "<<num2<<" es: " <<cociente(num1, num2)<<endl;
		else
			cout << "\nError: No se puede dividir por cero." << endl;
		break;
	case 'm':
		if (num2 != 0)
			cout << "\nEl modulo de "<<num1<<" mod "<<num2<< " es: " <<resto(num1, num2)<<endl;
		else
			cout << "\nError: No se puede dividir por cero." << endl;
		break;
	case '!':
		cout << "\nFactorial de "<<num1<<" es: " <<factorial(num1)<<endl;
		cout << "\nFactorial de "<<num2<<" es: " <<factorial(num2)<<endl;
		break;
	case '^':
		cout << "\nPotencia de "<<num1<<"^"<<num2<<" es: " << potencia(num1,num2)<<endl;
		break;
		
	case '~':
		cout << "\nCuadrado de a es: " <<cuadrado(num1)<<endl;
		cout << "\nCuadrado de b es: " <<cuadrado(num2)<<endl;
		break;
	default:
		cout << "\nOperador no valido." << endl;
	}


	return 0;
}

bool isfibo(int n) {
	if (n < 1) return false; // 0 y números negativos no pertenecen a la serie de Fibonacci
	int i = 1;
	int fib_term = fibo(i);
	while (fib_term <= n) {
		if (fib_term == n) return true; // Verdadero, pertenece a la serie de Fibonacci
		i++;
		fib_term = fibo(i);
	}
	return false; // Falso, no pertenece a la serie de Fibonacci
}


int fibo(int ter){
	int i=2, aux=0,t1=1,t2=1;
	if (ter ==1 || ter ==2) return t1; //1 1 2 3 5 8 13 .... 
	
	while (i<ter){
		aux=t1+t2;
		t1=t2;
		t2=aux;
		i++;
	}
	return aux;
}
	
	
	bool primo(int n){
		int i=2;
		bool prim=resto(n,i)!=0;
		while(i<n && prim)
		{
			prim=resto(n,i)!=0;
			i++;
			
		}	
		return prim; //true si es primo, false si no es primo
	}
		
		
		
		bool capicua(int n){
			
			int valor= inverso(n);
			
			return valor==n;
			
		}
			
			
			int inverso(int n)
			{
				int acum = 0;
				int r;
				int signo = 1;
				
				while (n != 0)
				{
					r = resto(n, 10);
					acum = producto(acum, 10) + r;
					n = cociente(n, 10);
				}
				
				acum = producto(acum, signo);
				
				return acum;
			}
			
			int contar_digitos(int num)
			{
				num = abs(num);
				int i = 0;
				
				while (num > 0)
				{
					num = cociente(num, 10);
					i++;
				}
				return i;
			}
			
			int caracter(char c)
			{
				int respuesta;
				
				if (c >= 'a' && c <= 'z')
				{
					respuesta = 1;
				}
				else if (c >= 'A' && c <= 'Z')
				{
					respuesta = 2;
				}
				else if (c >= '0' && c <= '9')
				{
					respuesta = 3;
				}
				else
						 respuesta = 4;
				
				return respuesta;
			}
			
			int numero(char c1)
			{
				
				int c;
				
				switch (c1)
				{
				case '0':
					c = 0;
					break;
				case '1':
					c = 1;
					break;
				case '2':
					c = 2;
					break;
				case '3':
					c = 3;
					break;
				case '4':
					c = 4;
					break;
				case '5':
					c = 5;
					break;
				case '6':
					c = 6;
					break;
				case '7':
					c = 7;
					break;
				case '8':
					c = 8;
					break;
				case '9':
					c = 9;
					break;
				default:
					c = -1;
				}
				
				return c;
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
			
			// potencia con base y exponente respetando los signos (exponente par -> resultado positivo, exponente impar->mantiene el signo de la base)
			int potencia(int a, int b)
			{
				
				int total = 1;
				int i = 0;
				
				if ((b % 2 == 0) && (a < 0))
					a = producto(a, -1);
				
				// Manejar el caso cuando b = 0
				
				do
				{
					if (b > 0)
					{
						
						total = producto(total, a);
					}
					i++;
				} while (i < b); // ajustar la condiciï¿½n del ciclo
				
				return total;
			}
			
			int factorial(int num)
			{
				int fact = 1;
				
				while (num > 0)
				{
					fact = producto(fact, num);
					num--;
				}
				
				return fact;
			}
			
			int cuadrado(int n)
			{
				
				int suma = 0, i = 1;
				
				if (n < 0)
					n = n * (-1);
				
				while (n > 0)
				{
					suma = suma + i;
					i = i + 2;
					n--;
				}
				
				return suma;
			}
			
