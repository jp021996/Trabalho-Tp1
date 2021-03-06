#ifndef MSAUT_H_INCLUDED
#define MSAUT_H_INCLUDED

#include "interfaces.hpp"
#include "UnidadePersistencia.hpp"

//definition of the class that will access the data base to simulate the service of
//authentication of the system
class ServicoAutenticar : public IS_Autenticacao{
public:

    //declaration of the method foreseen on the interface
    ResultadoAutenticacao autenticar(const Email&, const Senha&) throw(runtime_error);

};
#endif // MSAUT_H_INCLUDED
