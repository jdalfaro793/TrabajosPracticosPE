#include <iostream>
using namespace std;


main(){
	int cifra,num,numOriginal, suma=0;
	cout<<"ingrese numero: ";
	cin>>num;
	numOriginal=num;
	while(num>0){
		cifra=num%10;
		num=num/10;
		suma=suma+cifra;
	}
	
	
	if(suma>=10){
		num=0;
		num=suma;
		suma=0;
		while(num>0){
			cifra=num%10;
			num=num/10;
			suma=suma+cifra;
		}		
	}

	if(suma==3 || suma==6 || suma==9){
		cout<<"El numero: "<<numOriginal<<" Es multiplo de 3"<<endl;
	}else{
		cout<<"El numero: "<<numOriginal<<" No es multiplo de 3"<<endl;		
	}

	
}

