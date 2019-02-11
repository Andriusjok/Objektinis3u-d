#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;
int main()
{
string vardas;
printf("Iveskite varda: \n");
char *charas;
scanf("%s",charas);
vardas=charas;
string sveikinimas={" Sveikas, "+vardas+"! "};
string eilute1;
for (int i=0;i<=sveikinimas.length()+1;i++)
{
	eilute1+='*';
}
string eilute2;
eilute2+='*';
for (int i=0;i<sveikinimas.length();i++)
{
	eilute2+=' ';
}
eilute2+='*';
string eilute3={'*'+sveikinimas+'*'};
string eilute4=eilute2;
string eilute5=eilute1; 
cout<<eilute1<<endl;
cout<<eilute2<<endl;
cout<<eilute3<<endl;
cout<<eilute4<<endl;
cout<<eilute5<<endl;
return 0;
}