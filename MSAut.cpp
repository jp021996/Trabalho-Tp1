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
    //the pointers to objects
    Leitor *leitor;
    Desenvolvedor *desenvolvedor;
    Administrador *administrador;

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



    //check if the email is on the database
    if(senhaDatabase != ""){
    //cleaning the list
    comando.listaResultado.pop_back();
        if(senhaDatabase == senha.getSenha()){
            resultado.setValor(Resultado::SUCESSO);
            resultado.setTipo(1);

            //creating the reader
            leitor = new Leitor();
            leitor->setEmail(email.getEmail());
            leitor->setSenha(senha.getSenha());

            resultado.criarLeitor();
            resultado.setLeitor(*leitor);

            //deallocating memory of the reader
            delete leitor;

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

    //check if the email is on the database
    if(senhaDatabase != ""){
            //cleaning the list
            comando.listaResultado.pop_back();
        if(senhaDatabase == senha.getSenha()){
            resultado.setValor(Resultado::SUCESSO);
            resultado.setTipo(2);

            //creating the developer
            desenvolvedor = new Desenvolvedor();
            desenvolvedor->setEmail(email.getEmail());
            desenvolvedor->setSenha(senha.getSenha());

            resultado.criarDesenvolvedor();
            resultado.setDesenvolvedor(*desenvolvedor);

            //deallocating memory of the developer
            delete desenvolvedor;

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

    //check if the email is on the database
    if(senhaDatabase != ""){
        //cleaning the list
        comando.listaResultado.pop_back();
        if(senhaDatabase == senha.getSenha()){
            resultado.setValor(Resultado::SUCESSO);
            resultado.setTipo(3);

            //creating the administer
            administrador = new Administrador();
            administrador->setEmail(email.getEmail());
            administrador->setSenha(senha.getSenha());

            resultado.criarAdministrador();
            resultado.setAdministrador(*administrador);

            //deallocating memory of the developer
            delete administrador;

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
