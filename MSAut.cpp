#include "MSAut.hpp"

//definition of the method to authenticate the user
ResultadoAutenticacao ServicoAutenticar::autenticar(const Email &email, const Senha &senha) throw(runtime_error) {
    //the object to be the result of the authentication
    ResultadoAutenticacao resultado;
    //the object to access the database
    ComandoSQL comando;
    //the string that will carry the sql command
    string query;
    //the password of the user
    string senhaDatabase;

    //get password of the email
    query = "SELECT Senha FROM Leitor \
    WHERE Email = '" + email.getEmail() + "';";

    //put the query into the object
    comando.setComandoSQL(query);

    //execute the command to get the password
    try {
        comando.executar();
    }
    catch (EErroPersistencia& e){
        cerr << e.what();
        system("pause");
        resultado.setValor(Resultado::FALHA);
        return resultado;
    }

    //get the password from the database
    senhaDatabase = comando.listaResultado.back().getValorColuna();

    //cleaning the list
    comando.listaResultado.pop_back();

    //check if the email is on the database
    if(senhaDatabase != ""){
        if(senhaDatabase == senha.getSenha()){
            resultado.setValor(Resultado::SUCESSO);
            resultado.setTipo(1);
            return resultado;
        }
        else{
            cerr << "Senha incorreta" << endl;
            system("pause");
            resultado.setValor(Resultado::FALHA);
            return resultado;
        }
    }

    //get password of the email
    query = "SELECT Senha FROM Desenvolvedor \
    WHERE Email = '" + email.getEmail() + "';";

    //put the query into the object
    comando.setComandoSQL(query);

    //execute the command to get the password
    try {
        comando.executar();
    }
    catch (EErroPersistencia& e){
        cerr << e.what();
        system("pause");
        resultado.setValor(Resultado::FALHA);
        return resultado;
    }

    //get the password from the database
    senhaDatabase = comando.listaResultado.back().getValorColuna();

    //cleaning the list
    comando.listaResultado.pop_back();

    //check if the email is on the database
    if(senhaDatabase != ""){
        if(senhaDatabase == senha.getSenha()){
            resultado.setValor(Resultado::SUCESSO);
            resultado.setTipo(2);
            return resultado;
        }
        else{
            cerr << "Senha incorreta" << endl;
            system("pause");
            resultado.setValor(Resultado::FALHA);
            return resultado;
        }
    }

        //get password of the email
    query = "SELECT Senha FROM Administrador \
    WHERE Email = '" + email.getEmail() + "';";

    //put the query into the object
    comando.setComandoSQL(query);

    //execute the command to get the password
    try {
        comando.executar();
    }
    catch (EErroPersistencia& e){
        cerr << e.what();
        system("pause");
        resultado.setValor(Resultado::FALHA);
        return resultado;
    }

    //get the password from the database
    senhaDatabase = comando.listaResultado.back().getValorColuna();

    //cleaning the list
    comando.listaResultado.pop_back();

    //check if the email is on the database
    if(senhaDatabase != ""){
        if(senhaDatabase == senha.getSenha()){
            resultado.setValor(Resultado::SUCESSO);
            resultado.setTipo(3);
            return resultado;
        }
        else{
            cerr << "Senha incorreta" << endl;
            system("pause");
            resultado.setValor(Resultado::FALHA);
            return resultado;
        }
    }

    if(senhaDatabase == ""){
        cerr << "Email nao cadastrado" << endl;
        system("pause");
        resultado.setValor(Resultado::FALHA);
        return resultado;
    }
}
