//#include "teste.hpp"
#include <locale.h>

#include "controladores.hpp"

using namespace std;

/*
    CARLOS GABRIEL ATTA AUSTRIACO - 14/0036954
    JOAO VITOR DE MELO PEIXOTO - 14/0056408
*/

//start of the main function
int main(){
    //allow the use of characters on UTF-8
    setlocale(LC_ALL, "Portuguese");

    Controle programa;

    programa.start();

    return 0;
}
