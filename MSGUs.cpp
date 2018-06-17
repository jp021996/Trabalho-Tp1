#include "MSGUs.hpp"

//definition of the method to register the reader user
ResultadoCadastro ServicoGestao::cadastrarLeitor(const Leitor& leitor) throw(runtime_error) {
    //the object to be the result of the registering
    ResultadoCadastro resultado;

    //go to the stub class and register
    resultado = stub_MS_Gestao.cadastrarLeitor(leitor);

    return resultado;
}

//definition of the method to register the developer user
ResultadoCadastro ServicoGestao::cadastrarDesenvolvedor(const Desenvolvedor& desenvolvedor) throw(runtime_error) {
    //the object to be the result of the registering
    ResultadoCadastro resultado;

    //go to the stub class and register
    resultado = stub_MS_Gestao.cadastrarDesenvolvedor(desenvolvedor);

    return resultado;
}

//definition of the method to register the administer user
ResultadoCadastro ServicoGestao::cadastrarAdministrador(const Administrador& administrador) throw(runtime_error) {
    //the object to be the result of the registering
    ResultadoCadastro resultado;

    //go to the stub class and register
    resultado = stub_MS_Gestao.cadastrarAdministrador(administrador);

    return resultado;
}

//definition of the method to remove its account
Resultado ServicoGestao::remover(const Email& email) throw(runtime_error){
    //the object to be the result if the remove was a success or a failure
    Resultado resultado;

    //go to the stub class and remove
    resultado = stub_MS_Gestao.remover(email);

    return resultado;
}

//definition of the method to edit the reader
Resultado ServicoGestao::editarLeitor(const Leitor& leitor) throw(runtime_error){
    //the object to be the result if the edition was a success or a failure
    Resultado resultado;

    //go to the stub class and edit
    resultado = stub_MS_Gestao.editarLeitor(leitor);

    return resultado;
}

//definition of the method to edit the developer
Resultado ServicoGestao::editarDesenvolvedor(const Desenvolvedor& desenvolvedor) throw(runtime_error){
    //the object to be the result if the edition was a success or a failure
    Resultado resultado;

    //go to the stub class and edit
    resultado = stub_MS_Gestao.editarDesenvolvedor(desenvolvedor);

    return resultado;
}

//definition of the method to edit the administer
Resultado ServicoGestao::editarAdministrador(const Administrador& administrador) throw(runtime_error){
    //the object to be the result if the edition was a success or a failure
    Resultado resultado;

    //go to the stub class and edit
    resultado = stub_MS_Gestao.editarAdministrador(administrador);

    return resultado;
}