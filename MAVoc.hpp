#ifndef MAVOC_H_INCLUDED
#define MAAUT_H_INCLUDED

#include<stdexcept>

#include "interfaces.hpp"
#include "entidades.hpp"
#include "UnidadePersistencia.hpp"


using namespace std;

// DECLARACAO DE CLASSES CONTROLADORES

// Declara��o de classe controladora de intera��o para o servi�o de autentica��o.

class ApresentacaoGestaoVocab : public IA_GestaoVocab {

private:

    // Refer�ncia para modulo de servi�o.

    IS_GestaoVocab *link_MA_MS_GestaoVocab;

public:

    Resultado executarLeitor(const Email&) throw(runtime_error);
    Resultado executarDesenvolvedor(const Email&) throw(runtime_error);
    Resultado executarAdministrador(const Email&) throw(runtime_error);

    Resultado executar(ResultadoAutenticacao&) throw(runtime_error);

    void setLink_MA_MS_GestaoVocab(IS_GestaoVocab*);
};


void inline ApresentacaoGestaoVocab::setLink_MA_MS_GestaoVocab(IS_GestaoVocab *link_MA_MS_GestaoVocab){

        this->link_MA_MS_GestaoVocab = link_MA_MS_GestaoVocab;
}



#endif

