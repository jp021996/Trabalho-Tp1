#include "MSAut.hpp"

//definition of the method to authenticate the user
ResultadoAutenticacao ServicoAutenticar::autenticar(const Email &email, const Senha &senha) throw(runtime_error) {
    //the object to be the result of the authentication
    ResultadoAutenticacao resultado;

    //go to the stub class and authenticate
    resultado = stub_MS_Autenticacao.autenticar(email,senha);


    return resultado;
}
