#ifndef MSGUS_H_INCLUDED
#define MSGUS_H_INCLUDED

#include "stubs.hpp"

//definition of the class that will access the data base to simulate the service of
//registering of the system
class ServicoGestao : public IS_GestaoUsuario{
    //the object of the registering stub
    Stub_MS_Gestao stub_MS_Gestao;

public:
    //declaration of the methods foreseen on the interface
    //declaration of the methods to register the user
    ResultadoCadastro cadastrarLeitor(const Leitor&) throw(runtime_error);
    ResultadoCadastro cadastrarDesenvolvedor(const Desenvolvedor&) throw(runtime_error);
    ResultadoCadastro cadastrarAdministrador(const Administrador&) throw(runtime_error);

    //declaration of the method to remove the user
    Resultado remover(const Email&) throw(runtime_error);

    //declaration of the method to edit the reader
    Resultado editarLeitor(const Leitor&) throw(runtime_error);
    //declaration of the method to edit the developer
    Resultado editarDesenvolvedor(const Desenvolvedor&) throw(runtime_error);
    //declaration of the method to edit the administer
    Resultado editarAdministrador(const Administrador&) throw(runtime_error);
};
#endif // MSGUS_H_INCLUDED
