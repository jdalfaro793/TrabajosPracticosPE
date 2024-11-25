#include <iostream>
using namespace std;
main()
{ int dato, suma=0;
  bool band;
  cout<<"Ingrese valor: ";
  cin>>dato;
  band=dato>9 || dato <-9;
  
  cout<<"band: "<<band;
  while(band)
     { suma=0;
       while(dato!=0)
         { suma=suma+dato%10;
           dato=dato/10;
         }
      if(suma<0)
         suma=suma*(-1);
     dato=suma;
     band=dato>9;
  }
 if(suma==3 || suma==6 || suma==9)
     cout<<"multiplo de 3"<<endl;
 else
    cout<<"no es m	últiplo de 3"<<endl;
}
