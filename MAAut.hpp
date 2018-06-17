#ifndef MAAUT_H_INCLUDED
#define MAAUT_H_INCLUDED

#include <stdexcept>

#include "interfaces.hpp"

using namespace std;

//Definition of the class that presents the authentication to the user
class OpcaoAutenticar : public IA_Autenticacao {
    //Reference to the service module of authentication
    IS_Autenticacao *link_MA_MS_Autenticacao;

public:
    //method to authenticate the user calling the service module
    ResultadoAutenticacao autenticar(Email&, Senha&) throw(runtime_error);
    //method to set the interface between the presentation module and the service module
    void setLink_MA_MS_Autenticacao(IS_Autenticacao*);
};

void inline OpcaoAutenticar::setLink_MA_MS_Autenticacao(IS_Autenticacao *link_MA_MS_Autenticacao){

        this->link_MA_MS_Autenticacao = link_MA_MS_Autenticacao;
}
#endif // CONTROLADORES_H_INCLUDED
