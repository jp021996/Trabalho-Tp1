#ifndef CONTROLADORES_H_INCLUDED
#define CONTROLADORES_H_INCLUDED

#include "dominios.hpp"
#include "resultados.hpp"
#include "MAAut.hpp"
#include "MSAut.hpp"
#include "MAGUs.hpp"
#include "MSGUs.hpp"
#include "MAVoc.hpp"
#include "MSVoc.hpp"

using namespace std;

//Definition of the class Macon to control the interaction with the user
class Controle{
    //objects to authenticate the users
    Email *emailUsuario;
    Senha *senhaUsuario;

    //objects to register a new user
    Leitor *leitor;
    Desenvolvedor *desenvolvedor;
    Administrador *administrador;

    //the attributes of the operations on the initialization
    const static int LOGIN = 1;
    const static int CADASTRO = 2;
    const static int SAIR = 0;

    //attributes of the user register
    const static int LEITOR = 1;
    const static int DESENVOLVEDOR = 2;
    const static int ADMINISTRADOR = 3;

    ResultadoCadastro cadastrar();
    ResultadoAutenticacao login(); // 0: OK  , 1: FALHOU
    ResultadoInicializacao inicializar();
    void executar(ResultadoAutenticacao&);

    void getDadosLogin();
public:
    void start();

};
#endif // CONTROLADORES_H_INCLUDED
