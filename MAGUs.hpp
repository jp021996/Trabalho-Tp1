#ifndef MAGUS_H_INCLUDED
#define MAGUS_H_INCLUDED

#include "interfaces.hpp"

//definition of the class that presents the registering to the user
class ApresentacaoGestao : public IA_GestaoUsuario {
    //Reference to the service module of registering
    IS_GestaoUsuario *link_MA_MS_GestaoUsuario;

public:
    //method to register the reader user calling the service module
    ResultadoCadastro cadastrarLeitor(Leitor&) throw(runtime_error);
    //method to register the developer user calling the service module
    ResultadoCadastro cadastrarDesenvolvedor(Desenvolvedor&) throw(runtime_error);
    //method to register the administer user calling the service module
    ResultadoCadastro cadastrarAdministrador(Administrador&) throw(runtime_error);

    //method to execute the management of the user account
    Resultado executar(ResultadoAutenticacao&) throw(runtime_error);

    //method to set the interface between the presentation module and the service module
    void setLink_MA_MS_GestaoUsuario(IS_GestaoUsuario*);

    //void executar(const Email&);
};

#endif // MAGUS_H_INCLUDED
