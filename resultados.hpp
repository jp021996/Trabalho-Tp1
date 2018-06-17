#ifndef RESULTADOS_H_INCLUDED
#define RESULTADOS_H_INCLUDED

#include "entidades.hpp"
#include <vector>
#include <string>

#include <string>

using namespace std;

//Declaration of the classes that give the result of each operation

//definition of the class Resultado that will be the "father" of all other
//results classes
class Resultado{
protected:
    //the attribute that will receive the result
    int valor;
    Leitor *leitor;
    Desenvolvedor *desenvolvedor;
    Administrador *administrador;
    //account type
    int tipo;
public:
    //the constants referents to success, failure or canceling the operation
    const static int SUCESSO = 0;
    const static int FALHA = 1;
    const static int CANCELAR = 2;

    //method to set the result
    void setValor(int valor){
        this->valor = valor;
    }

    //method to get the result
    int getValor() const {
        return valor;
    }

    void criarLeitor(){
        leitor = new Leitor();
    }

    void criarDesenvolvedor(){
        desenvolvedor = new Desenvolvedor();
    }

    void criarAdministrador(){
        administrador = new Administrador();
    }

    void setLeitor(const Leitor &leitorUsuario){
        *leitor = leitorUsuario;
    }

    void setDesenvolvedor(const Desenvolvedor &desenvolvedorUsuario){
        *desenvolvedor = desenvolvedorUsuario;
    }

    void setAdministrador(const Administrador &administradorUsuario){
        *administrador = administradorUsuario;
    }

    Leitor getLeitor() const{
        return *leitor;
    }

    Desenvolvedor getDesenvolvedor() const{
        return *desenvolvedor;
    }

    Administrador getAdministrador() const {
        return *administrador;
    }

    //method to set the type of the account
    void setTipo(const int& tipo){
        this->tipo = tipo;
    }

    //method to get the type of the account
    int getTipo() const{
        return tipo;
    }
};

//class that defines the result of the authentication of the user
class ResultadoAutenticacao : public Resultado {

};

//class that defines the result of the initialization part of the program
class ResultadoInicializacao : public Resultado{
    //attribute that defines if the user wants to leave the program
    bool sair = false;

public:
    //the method to modify the attribute if the user wants to leave
    void setSair(bool sair){
        this->sair = sair;
    }
    //the method to get the attribute if the user wants to leave
    bool getSair() const{
        return this->sair;
    }

};

class ResultadoCadastro: public Resultado{

};


class ResultadoVocab : public Resultado{
private:
    Vocabulario vocab;
    Definicao defVocab;
    vector<Termo> termosVocab;
    vector<string> nomesTermosVocab;
    vector<string> nomesDesenvolvedores;
    string nomeAdm;

public:
    const static int PERMISSAO_NEGADA = 2;

    void setVocab(const Vocabulario &vocab){
        this->vocab = vocab;
    }
    Vocabulario getVocab() const{
        return vocab;
    }

    void setDefVocab(const Definicao &defVocab){
        this->defVocab = defVocab;
    }
    Definicao getDefVocab() const{
        return defVocab;
    }

    void setDados(const string &nomeAdm, const vector<string>nomesTermosVocab, const vector<string> nomesDesenvolvedores){
        this->nomeAdm = nomeAdm;
        this->nomesTermosVocab = nomesTermosVocab;
        this->nomesDesenvolvedores = nomesDesenvolvedores;
    }

    void setTermos(const vector<Termo> &termosVocab){
        this->termosVocab = termosVocab;
    }
    vector<Termo> getTermos() const{
        return termosVocab;
    }

    string getNomeAdm() const{
        return nomeAdm;
    }

    vector<string> getNomesTermosVocab() const{
        return nomesTermosVocab;
    }

    vector<string> getNomesDesenvolvedores() const{
        return nomesDesenvolvedores;
    }

};

class ResultadoTermo : public Resultado{
private:
    Termo termo;
    string nomeVocabTermo;
    vector<Definicao> definicoesTermo;

public:
    void setTermo(const Termo &termo){
        this->termo = termo;
    }
    Termo getTermo() const{
        return termo;
    }

    void setDados(string nomeVocabTermo, vector<Definicao> definicoesTermo){
        this->nomeVocabTermo = nomeVocabTermo;
        this->definicoesTermo = definicoesTermo;
    }
    string getNomeVocabTermo() const{
        return this->nomeVocabTermo;
    }

    vector<Definicao> getDefinicoesTermo() const {
        return this->definicoesTermo;
    }
};

class ResultadoDefinicao : public Resultado{
private:
    Definicao definicao;
    vector<Termo> termosDef;

public:
    void setDefinicao(const Definicao &definicao){
        this->definicao = definicao;
    }
    Definicao getDefinicao() const{
        return definicao;
    }

    void setDados(vector<Termo> termosDef){
        this->termosDef = termosDef;
    }

    vector<Termo> getTermosDef() const {
        return this->termosDef;
    }


};

class ResultadoLista : public Resultado{

public:

    vector<string> listaVocab;

};

class ResultadoEspecifico : public Resultado{


public:
    const static int FALHA_2 = 2;

};




#endif // RESULTADOS_H_INCLUDED
