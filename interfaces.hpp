#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include "resultados.hpp"

#include <stdexcept>

using namespace std;

//declaration advanced
class IS_Autenticacao;

//declaration of the interface between the presentation module and
//the authentication module
class IA_Autenticacao {
public:
    //Method to solicit the service
    virtual ResultadoAutenticacao autenticar(Email&, Senha&) throw(runtime_error) = 0;

    //Method to establish the link between the authentication module and its service
    virtual void setLink_MA_MS_Autenticacao(IS_Autenticacao *) = 0;

    //Virtual destructor
    virtual ~IA_Autenticacao(){}
};

//Declaration of the class that will be interface between the authentication presentation and the service
class IS_Autenticacao {
public:
    //method to do the service (authenticate)
    virtual ResultadoAutenticacao autenticar(const Email&, const Senha&) throw(runtime_error)= 0;

   //virtual destructor
    virtual ~IS_Autenticacao(){}

};

//declaration advanced
class IS_GestaoUsuario;

//definition of the interface between the presentation module and the
//user management module
class IA_GestaoUsuario {
public:
    //method to solicit the service of register the reader
    virtual ResultadoCadastro cadastrarLeitor(Leitor&) throw(runtime_error)= 0;
    //method to solicit the service of register the developer
    virtual ResultadoCadastro cadastrarDesenvolvedor(Desenvolvedor&) throw(runtime_error) = 0;
    //method to solicit the service of register the administer
    virtual ResultadoCadastro cadastrarAdministrador(Administrador&) throw(runtime_error) = 0;

    virtual Resultado executar(ResultadoAutenticacao&) throw(runtime_error) = 0;

    //method to establish the link between the presentation and the service modules
    virtual void setLink_MA_MS_GestaoUsuario(IS_GestaoUsuario *) = 0;

    //virtual destructor
    virtual ~IA_GestaoUsuario(){}
};

//definition of the interface between the user management presentation
//and its service
class IS_GestaoUsuario {
public:
    //method to solicit the registering of the reader
    virtual ResultadoCadastro cadastrarLeitor(const Leitor&) throw(runtime_error)= 0;
    //method to solicit the registering of the developer
    virtual ResultadoCadastro cadastrarDesenvolvedor(const Desenvolvedor&) throw(runtime_error)= 0;
    //method to solicit the registering of the administer
    virtual ResultadoCadastro cadastrarAdministrador(const Administrador&) throw(runtime_error)= 0;

    //method to solicit the remove of the user
    virtual Resultado remover(const Email&) throw(runtime_error) = 0;

    //method to solicit the edition of the reader user
    virtual Resultado editarLeitor(const Leitor&, const string&) throw(runtime_error) = 0;
    //method to solicit the edition of the developer user
    virtual Resultado editarDesenvolvedor(const Desenvolvedor&, const string&) throw(runtime_error) = 0;
    //method to solicit the edition of the administer user
    virtual Resultado editarAdministrador(const Administrador&, const string&) throw(runtime_error) = 0;
    //virtual destructor
    //virtual ~IS_GestaoUsuario();
    virtual ~IS_GestaoUsuario(){}
};


class IS_GestaoVocab;

class IA_GestaoVocab {
public:

    // Método por meio do qual é solicitado serviço.

    virtual Resultado executarLeitor(const Email&) throw(runtime_error)= 0;

    virtual Resultado executarDesenvolvedor(const Email&) throw(runtime_error)= 0;

    virtual Resultado executarAdministrador(const Email&) throw(runtime_error)= 0;

    virtual Resultado executar(ResultadoAutenticacao&) throw(runtime_error) = 0;

    // Método por meio do qual é estabelecida ligação (link) com a controladora de negócio.

    virtual void setLink_MA_MS_GestaoVocab(IS_GestaoVocab *) = 0;

    // Destrutor virtual.

    virtual ~IA_GestaoVocab(){}

};

class IS_GestaoVocab {

public:
    //
    virtual ResultadoLista listarVocabs() throw(runtime_error)= 0;
    virtual ResultadoVocab dadosVocab(const string&) throw(runtime_error)= 0; //SUCESSO: existe,  FALHA: nao existe
    virtual ResultadoTermo consultarTermo(const string&) throw(runtime_error)= 0; //SUCESSO: existe,  FALHA: nao existe
    virtual ResultadoDefinicao consultarDefinicao (const string&) throw(runtime_error)= 0; //SUCESSO: existe,  FALHA: nao existe
    //
    virtual ResultadoEspecifico desenvolvedorDeVocab(const string&, const string&) throw(runtime_error)= 0; //SUCESSO: existe vocab,  FALHA: nao existe vocab OU vocab ja tem 10 dsv's
    virtual ResultadoVocab criarTermo(const Termo&, const string&, const string&) throw(runtime_error)= 0;
    virtual ResultadoTermo editarTermo(const Termo&, const Termo&) throw(runtime_error)= 0; //SUCESSO: ok,    FALHA: nao existe
    virtual ResultadoTermo excluirTermo(const Termo&) throw(runtime_error)= 0; //SUCESSO: ok,    FALHA: nao existe
    virtual ResultadoDefinicao criarDefinicao(const Definicao&) throw(runtime_error)= 0; //SUCESSO: ok   //FALHA: termo nao existe OU termo com mais de 5
    virtual ResultadoDefinicao editarDefinicao(const Definicao&,const Definicao&) throw(runtime_error)= 0; //SUCESSO: ok,    FALHA: nao existe
    virtual Resultado excluirDefinicao(const Nome&) throw(runtime_error)= 0; //SUCESSO: ok,    FALHA: nao existe
    //
    virtual ResultadoVocab criarVocabulario(const Vocabulario&, const Definicao&, const string&) throw(runtime_error)= 0; // SUCESSO: ok,    FALHA: ja criou 5
    virtual Resultado editarDefinicaoVocab(const Vocabulario&, const Definicao&) throw(runtime_error)= 0;  //SUCESSO: ok,    FALHA: nao existe
    virtual Resultado editarIdiomaVocab(const Vocabulario&, const Idioma&) throw(runtime_error)= 0; //SUCESSO: ok,    FALHA: nao existe
    virtual Resultado excluirVocabulario(const Vocabulario&) throw(runtime_error)= 0; //SUCESSO: ok,    FALHA: nao existe

    virtual ~IS_GestaoVocab(){};

};

#endif // INTERFACES_H_INCLUDED
