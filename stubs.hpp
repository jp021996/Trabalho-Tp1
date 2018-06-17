#ifndef STUBS_H_INCLUDED
#define STUBS_H_INCLUDED

#include "interfaces.hpp"
#include "entidades.hpp"

#include <string>
#include <stdexcept>
#include <iostream>
#include <vector>

using namespace std;

//Declaration of the class stub of the interface IS_Autenticacao
class Stub_MS_Autenticacao : public IS_Autenticacao{
public:
    //definition of values to be used like triggers for errors notifications
    const string TRIGGER_SUCESSO_EMAIL_LEITOR = "leitor@lei";
    const string TRIGGER_SUCESSO_SENHA_LEITOR = "Leit1103";
    const string NOME_LEITOR = "Leitor";
    const string SOBRENOME_LEITOR = "Leitor";
    const string TRIGGER_SUCESSO_EMAIL_DESENVOLVEDOR = "dsv@dsv";
    const string TRIGGER_SUCESSO_SENHA_DESENVOLVEDOR = "Dese1103";
    const string NOME_DESENVOLVEDOR = "Desenvolvedor";
    const string SOBRENOME_DESENVOLVEDOR = "Desenvolvedor";
    const string DATA_DESENVOLVEDOR = "11/01/1991";
    const string TRIGGER_SUCESSO_EMAIL_ADMINISTRADOR = "adm@adm";
    const string TRIGGER_SUCESSO_SENHA_ADMINISTRADOR = "Admi1103";
    const string NOME_ADMINISTRADOR = "Administrador";
    const string SOBRENOME_ADMINISTRADOR = "Admnistrador";
    const string DATA_ADMINISTRADOR = "11/03/1991";
    const string ENDERECO_ADMINISTRADOR = "Maranhao";
    const string TELEFONE_ADMINISTRADOR = "11 91111-1111";
    const string TRIGGER_FALHA_EMAIL = "jvmelop@gmail";
    const string TRIGGER_FALHA_SENHA = "Senha123";
    const string TRIGGER_ERRO_SISTEMA_EMAIL = "erro@gmail";
    const string TRIGGER_ERRO_SISTEMA_SENHA = "Erro1103";

    //attributes of the user register
    const static int LEITOR = 1;
    const static int DESENVOLVEDOR = 2;
    const static int ADMINISTRADOR = 3;

    //declaration of the method of the virtual class on the interface IS_Autenticacao
    ResultadoAutenticacao autenticar(const Email&, const Senha&) throw(runtime_error);
};

//Declaration of the class stub of the interface IS_GestaoUsuario
class Stub_MS_Gestao : public IS_GestaoUsuario{
public:
    //definition of values to be used like triggers for errors notifications
    const string TRIGGER_SUCESSO_NOME = "Joao";
    const string TRIGGER_SUCESSO_SOBRENOME = "Vitor";
    const string TRIGGER_SUCESSO_DATA = "09/02/1996";
    const string TRIGGER_SUCESSO_ENDERECO = "Taguatinga";
    const string TRIGGER_SUCESSO_TELEFONE = "61 98119-7229";
    const string TRIGGER_SUCESSO_EMAIL = "jvmelop@gmail";
    const string TRIGGER_SUCESSO_SENHA = "Aa110396";
    const string TRIGGER_FALHA_NOME = "Carlos";
    const string TRIGGER_FALHA_SOBRENOME = "Gabriel";
    const string TRIGGER_FALHA_DATA = "11/03/1996";
    const string TRIGGER_FALHA_ENDERECO = "Asa Sul";
    const string TRIGGER_FALHA_TELEFONE = "61 98199-3449";
    const string TRIGGER_FALHA_EMAIL = "cgaa1103@gmail";
    const string TRIGGER_FALHA_SENHA = "Senha123";
    const string TRIGGER_ERRO_SISTEMA_NOME = "Erro";
    const string TRIGGER_ERRO_SISTEMA_SOBRENOME = "Erro";
    const string TRIGGER_ERRO_SISTEMA_DATA = "11/01/2001";
    const string TRIGGER_ERRO_SISTEMA_TELEFONE = "61 91111-1111";
    const string TRIGGER_ERRO_SISTEMA_EMAIL = "erro@gmail";
    const string TRIGGER_ERRO_SISTEMA_SENHA = "Erro1234";
    const string TRIGGER_ERRO_SISTEMA_ENDERECO = "Erro";

    //declaration of the methods of the virtual class on the interface IS_GestaoUsuario
    //registering methods
    ResultadoCadastro cadastrarLeitor(const Leitor&) throw(runtime_error);
    ResultadoCadastro cadastrarDesenvolvedor(const Desenvolvedor&) throw(runtime_error);
    ResultadoCadastro cadastrarAdministrador(const Administrador&) throw(runtime_error);

    //remove user method
    Resultado remover(const Email&) throw(runtime_error);

    //edit reader user method
    Resultado editarLeitor(const Leitor&) throw(runtime_error);
    //edit developer user method
    Resultado editarDesenvolvedor(const Desenvolvedor&) throw(runtime_error);
    //edit administer user method
    Resultado editarAdministrador(const Administrador&) throw(runtime_error);
};


class Stub_MS_GestaoVocab : public IS_GestaoVocab{
private:

    const string TRIGGER_NOME_ADMIN_VOCAB = "AdminTeste";
    const string TRIGGER_NOME_DESENVOLVEDOR_1_VOCAB = "DesenvUm";
    const string TRIGGER_NOME_DESENVOLVEDOR_2_VOCAB = "DesenvDois";
    const string TRIGGER_NOME_NOVO_VOCAB_SUCESSO = "VocabSucesso";
    const string TRIGGER_NOME_NOVO_VOCAB_FALHA = "VocabFalha";
    const string TRIGGER_NOME_NOVO_VOCAB_ERRO = "VocabErro";

    Vocabulario vocabTeste1, vocabTeste2, vocabTeste3, vocabTeste4;
    Termo termoTeste1, termoTeste2, termoTeste3;
    Definicao defTeste1, defTeste2, defTeste3;

public:

    Stub_MS_GestaoVocab(){
        vocabTeste1.setNome("Planets");      vocabTeste1.setData("15/03/2001");   vocabTeste1.setIdioma("ENG");
        vocabTeste2.setNome("Internet");     vocabTeste2.setData("09/07/2017");   vocabTeste2.setIdioma("GER");
        vocabTeste3.setNome("Cerrado");      vocabTeste3.setData("30/01/2007");   vocabTeste3.setIdioma("POR");
        vocabTeste4.setNome("Metais");      vocabTeste4.setData("25/10/1980");   vocabTeste4.setIdioma("POR");

        termoTeste1.setNome("Jupiter");     termoTeste1. setData("16/03/2001");   termoTeste1.setPreferencia("PT");
        termoTeste2.setNome("Earth");       termoTeste2. setData("20/03/2001");   termoTeste2.setPreferencia("PT");
        termoTeste3.setNome("Saturn");      termoTeste3. setData("01/04/2001");   termoTeste3.setPreferencia("NP");

        defTeste1.setTexto("The biggest in solar system.");     defTeste1.setData("17/03/2001");
        defTeste2.setTexto("Predominantly made of gas.");       defTeste2.setData("18/03/2001");
        defTeste3.setTexto("Terms related to planets.");        defTeste3.setData("20/09/2009");
    }

    //declaration of the methods foreseen on the interface
    //declaration of the methods to register the user
    ResultadoLista listarVocabs() throw(runtime_error);
    ResultadoVocab dadosVocab(const string&) throw(runtime_error);
    ResultadoTermo consultarTermo (const string&) throw(runtime_error);
    ResultadoDefinicao consultarDefinicao (const string&) throw(runtime_error);
    //
    ResultadoEspecifico desenvolvedorDeVocab(const string&) throw(runtime_error);
    ResultadoVocab criarTermo(const Termo&, const string&) throw(runtime_error);
    ResultadoTermo editarTermo(const Termo&, const Termo&) throw(runtime_error);
    ResultadoTermo excluirTermo(const Termo&) throw(runtime_error);
    ResultadoDefinicao criarDefinicao(const Definicao&) throw(runtime_error);
    ResultadoDefinicao editarDefinicao(const Definicao&, const Definicao&) throw(runtime_error);
    Resultado excluirDefinicao(const Definicao&) throw(runtime_error);
    //
    ResultadoVocab criarVocabulario(const Vocabulario&, const Definicao&) throw(runtime_error);
    Resultado editarDefinicaoVocab(const Vocabulario&, const Definicao&) throw(runtime_error);
    Resultado editarIdiomaVocab(const Vocabulario&, const Idioma&) throw(runtime_error);
    Resultado excluirVocabulario(const Vocabulario&) throw(runtime_error);


};

#endif // STUBS_H_INCLUDED
