#include "MSGUs.hpp"

//definition of the method to register the reader user
ResultadoCadastro ServicoGestao::cadastrarLeitor(const Leitor& leitor) throw(runtime_error) {
    //the object to be the result of the registering
    ResultadoCadastro resultado;
    //the object to access the database
    ComandoSQL comando;
    //the query to set the informations
    string query;

    //the informations of the reader
    string nome;
    string sobrenome;
    string email;
    string senha;

    //create the table of the reader if it doesn't exist
    query = "CREATE TABLE IF NOT EXISTS Leitor (\
    Nome varchar(20), \
    SobreNome varchar(20), \
    Email varchar(30), \
    Senha varchar(8), \
    PRIMARY KEY(Email));";

    //put the query into the object
    comando.setComandoSQL(query);

    //execute the command to create the table
    try {
        comando.executar();
    }
    catch (EErroPersistencia& e){
        cerr << e.what();
        resultado.setValor(Resultado::FALHA);
        return resultado;
    }

    //get the informations of the reader
    nome = leitor.getNome();
    sobrenome = leitor.getSobrenome();
    email = leitor.getEmail();
    senha = leitor.getSenha();

    //update the query to insert the informations on the table
    query = "INSERT INTO Leitor VALUES ('" + nome +
    "','" + sobrenome + "','" + email + "','" + senha + "');";

    //put the query into the object
    comando.setComandoSQL(query);

    //execute the command to put the informations of the registering
    //into the table
    try {
        comando.executar();
    }
    catch (EErroPersistencia& e){
        cerr << e.what();
        resultado.setValor(Resultado::FALHA);
        return resultado;
    }

    //the registering was a success
    resultado.setValor(Resultado::SUCESSO);

    return resultado;
}

//definition of the method to register the developer user
ResultadoCadastro ServicoGestao::cadastrarDesenvolvedor(const Desenvolvedor& desenvolvedor) throw(runtime_error) {
    //the object to be the result of the registering
    ResultadoCadastro resultado;
    //the object to access the database
    ComandoSQL comando;
    //the query to set the informations
    string query;

    //the informations of the developer
    string nome;
    string sobrenome;
    string email;
    string senha;
    string data;

    //create the table of the developer if it doesn't exist
    query = "CREATE TABLE IF NOT EXISTS Desenvolvedor (\
    Nome varchar(20), \
    SobreNome varchar(20), \
    Data varchar(15), \
    Email varchar(30), \
    Senha varchar(8), \
    PRIMARY KEY(Email));";

    //put the query into the object
    comando.setComandoSQL(query);

    //execute the command to create the table
    try {
        comando.executar();
    }
    catch (EErroPersistencia& e){
        cerr << e.what();
        resultado.setValor(Resultado::FALHA);
        return resultado;
    }

    //get the informations of the developer
    nome = desenvolvedor.getNome();
    sobrenome = desenvolvedor.getSobrenome();
    email = desenvolvedor.getEmail();
    senha = desenvolvedor.getSenha();
    data = desenvolvedor.getData();

    //update the query to insert the informations on the table
    query = "INSERT INTO Desenvolvedor VALUES ('" + nome +
    "','" + sobrenome + "','" + data + "','" + email + "','" + senha + "');";

    //put the query into the object
    comando.setComandoSQL(query);

    //execute the command to put the informations of the registering
    //into the table
    try {
        comando.executar();
    }
    catch (EErroPersistencia& e){
        cerr << e.what();
        resultado.setValor(Resultado::FALHA);
        return resultado;
    }

    //the registering was a success
    resultado.setValor(Resultado::SUCESSO);


    return resultado;
}

//definition of the method to register the administer user
ResultadoCadastro ServicoGestao::cadastrarAdministrador(const Administrador& administrador) throw(runtime_error) {
    //the object to be the result of the registering
    ResultadoCadastro resultado;
    //the object to access the database
    ComandoSQL comando;
    //the query to set the informations
    string query;

    //the informations of the administer
    string nome;
    string sobrenome;
    string email;
    string senha;
    string data;
    string telefone;
    string endereco;

    //create the table of the administer if it doesn't exist
    query = "CREATE TABLE IF NOT EXISTS Administrador (\
    Nome varchar(20), \
    SobreNome varchar(20), \
    Telefone varchar (15), \
    Data varchar(15), \
    Endereco varchar (20), \
    Email varchar(30), \
    Senha varchar(8), \
    PRIMARY KEY(Email));";

    //put the query into the object
    comando.setComandoSQL(query);

    //execute the command to create the table
    try {
        comando.executar();
    }
    catch (EErroPersistencia& e){
        cerr << e.what();
        resultado.setValor(Resultado::FALHA);
        return resultado;
    }

    //get the informations of the administer
    nome = administrador.getNome();
    sobrenome = administrador.getSobrenome();
    email = administrador.getEmail();
    senha = administrador.getSenha();
    data = administrador.getData();
    telefone = administrador.getTelefone();
    endereco = administrador.getEndereco();

    //update the query to insert the informations on the table
    query = "INSERT INTO Administrador VALUES ('" + nome +
    "','" + sobrenome + "','" + telefone + "','" +
    data + "','" + endereco + "','" + email + "','" + senha + "');";

    //put the query into the object
    comando.setComandoSQL(query);

    //execute the command to put the informations of the registering
    //into the table
    try {
        comando.executar();
    }
    catch (EErroPersistencia& e){
        cerr << e.what();
        resultado.setValor(Resultado::FALHA);
        return resultado;
    }

    //the registering was a success
    resultado.setValor(Resultado::SUCESSO);


    return resultado;
}

//definition of the method to remove its account
Resultado ServicoGestao::remover(const Email& email) throw(runtime_error){
    //the object to be the result if the remove was a success or a failure
    Resultado resultado;

    return resultado;
}

//definition of the method to edit the reader
Resultado ServicoGestao::editarLeitor(const Leitor& leitor) throw(runtime_error){
    //the object to be the result if the edition was a success or a failure
    Resultado resultado;

    return resultado;
}

//definition of the method to edit the developer
Resultado ServicoGestao::editarDesenvolvedor(const Desenvolvedor& desenvolvedor) throw(runtime_error){
    //the object to be the result if the edition was a success or a failure
    Resultado resultado;

    return resultado;
}

//definition of the method to edit the administer
Resultado ServicoGestao::editarAdministrador(const Administrador& administrador) throw(runtime_error){
    //the object to be the result if the edition was a success or a failure
    Resultado resultado;

    return resultado;
}
