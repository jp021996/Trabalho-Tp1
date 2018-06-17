#ifndef MSVOC_H_INCLUDED
#define MSVOC_H_INCLUDED

#include "stubs.hpp"

//definition of the class that will access the data base to simulate the service of
//registering of the system
class ServicoGestaoVocab : public IS_GestaoVocab{
    //the object of the registering stub
    Stub_MS_GestaoVocab stub_MS_GestaoVocab;

public:
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
#endif // MSVOC_H_INCLUDED