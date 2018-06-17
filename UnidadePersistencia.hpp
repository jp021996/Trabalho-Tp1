#ifndef UnidadePersistenciaH
#define UnidadePersistenciaH

#include <list>

#include <iostream>
#include <conio.h>
#include <string>
#include <stdio.h>

#include "sqlite3.h"

using namespace std;

class EErroPersistencia {
private:
        string mensagem;
public:
        EErroPersistencia(string);
        string what();
};


class ElementoResultado {
private:
        string nomeColuna;
        string valorColuna;
public:
        void setNomeColuna(const string&);
        string getNomeColuna() const{
            return nomeColuna;
        }
        void setValorColuna(const string&);
        string getValorColuna() const{
            return valorColuna;
        }
};

class ComandoSQL {
private:
        const char *nomeBancoDados;
        sqlite3 *bd;
        char *mensagem;
        int rc;
        void conectar() throw (EErroPersistencia);
        void desconectar() throw (EErroPersistencia);
        static int callback(void *, int, char **, char **);
        string comandoSQL;

public:
        static list<ElementoResultado> listaResultado;
        ComandoSQL() {
             //Informa o nome do banco de dados.
             nomeBancoDados = "teste.db";
        }
        void executar() throw (EErroPersistencia);

        void setComandoSQL(string);
};

#endif
