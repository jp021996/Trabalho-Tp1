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

    //get the informations of the reader
    nome = leitor.getNome();
    sobrenome = leitor.getSobrenome();
    email = leitor.getEmail();
    senha = leitor.getSenha();

    //update the query to check if the email is in one of the three tables
    query = "SELECT Email FROM Leitor \
    WHERE Email = '" + email + "' \
    UNION \
    SELECT Email from Desenvolvedor \
    WHERE Email = '" + email + "' \
    UNION \
    SELECT Email from Administrador \
    WHERE Email = '" + email + "';";

    //put the query into the object
    comando.setComandoSQL(query);

    //execute the command to create the table
    try {
        comando.executar();
    }
    catch (EErroPersistencia& e){
        cerr << e.what();
        system("pause");
        resultado.setValor(Resultado::FALHA);
        return resultado;
    }

    if(comando.listaResultado.back().getValorColuna() != ""){
        comando.listaResultado.pop_back();
        cerr << "Email ja cadastrado no sistema" << endl;
        system("pause");
        resultado.setValor(Resultado::FALHA);
        return resultado;
    }

    comando.listaResultado.pop_back();

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
        system("pause");
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

    //get the informations of the developer
    nome = desenvolvedor.getNome();
    sobrenome = desenvolvedor.getSobrenome();
    email = desenvolvedor.getEmail();
    senha = desenvolvedor.getSenha();
    data = desenvolvedor.getData();

    //update the query to check if the email is in one of the three tables
    query = "SELECT Email FROM Leitor \
    WHERE Email = '" + email + "' \
    UNION \
    SELECT Email from Desenvolvedor \
    WHERE Email = '" + email + "' \
    UNION \
    SELECT Email from Administrador \
    WHERE Email = '" + email + "';";

    //put the query into the object
    comando.setComandoSQL(query);

    //execute the command to create the table
    try {
        comando.executar();
    }
    catch (EErroPersistencia& e){
        cerr << e.what();
        system("pause");
        resultado.setValor(Resultado::FALHA);
        return resultado;
    }

    if(comando.listaResultado.back().getValorColuna() != ""){
        comando.listaResultado.pop_back();
        cerr << "Email ja cadastrado no sistema" << endl;
        system("pause");
        resultado.setValor(Resultado::FALHA);
        return resultado;
    }

    comando.listaResultado.pop_back();

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

    //get the informations of the administer
    nome = administrador.getNome();
    sobrenome = administrador.getSobrenome();
    email = administrador.getEmail();
    senha = administrador.getSenha();
    data = administrador.getData();
    telefone = administrador.getTelefone();
    endereco = administrador.getEndereco();

    //update the query to check if the email is in one of the three tables
    query = "SELECT Email FROM Leitor \
    WHERE Email = '" + email + "' \
    UNION \
    SELECT Email from Desenvolvedor \
    WHERE Email = '" + email + "' \
    UNION \
    SELECT Email from Administrador \
    WHERE Email = '" + email + "';";

    //put the query into the object
    comando.setComandoSQL(query);

    //execute the command to create the table
    try {
        comando.executar();
    }
    catch (EErroPersistencia& e){
        cerr << e.what();
        system("pause");
        resultado.setValor(Resultado::FALHA);
        return resultado;
    }

    if(comando.listaResultado.back().getValorColuna() != ""){
        comando.listaResultado.pop_back();
        cerr << "Email ja cadastrado no sistema" << endl;
        system("pause");
        resultado.setValor(Resultado::FALHA);
        return resultado;
    }

    comando.listaResultado.pop_back();

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
    //the object to access the database
    ComandoSQL comando;
    //the query to set the informations
    string query;
    //the email of the user
    string emailDatabase;

    //get the email from the database of reader
    query = "SELECT Email FROM Leitor WHERE Email = '" + email.getEmail() + "';";

    //put the query into the object
    comando.setComandoSQL(query);

    //execute the command to get the email
    try {
        comando.executar();
    }
    catch (EErroPersistencia& e){
        cerr << e.what();
        system("pause");
        resultado.setValor(Resultado::FALHA);
        return resultado;
    }

    //get the email from the database
    emailDatabase = comando.listaResultado.back().getValorColuna();
    comando.listaResultado.pop_back();

    //check if this email exists on the reader table
    if(emailDatabase != ""){
        //do the query to delete the user
        query = "DELETE FROM Leitor WHERE Email = '" + emailDatabase + "';";

        //put the query into the object
        comando.setComandoSQL(query);

        //execute the command to delete the user
        try {
            comando.executar();
            resultado.setValor(Resultado::SUCESSO);
            return resultado;
        }
        catch (EErroPersistencia& e){
            cerr << e.what();
            system("pause");
            resultado.setValor(Resultado::FALHA);
            return resultado;
        }
    }

    //get the email from the database of developer
    query = "SELECT Email FROM Desenvolvedor WHERE Email = '" + email.getEmail() + "';";

    //put the query into the object
    comando.setComandoSQL(query);

    //execute the command to get the email
    try {
        comando.executar();
    }
    catch (EErroPersistencia& e){
        cerr << e.what();
        system("pause");
        resultado.setValor(Resultado::FALHA);
        return resultado;
    }

    //get the email from the database
    emailDatabase = comando.listaResultado.back().getValorColuna();
    comando.listaResultado.pop_back();

    //check if this email exists on the developer table
    if(emailDatabase != ""){
        //do the query to delete the user
        query = "DELETE FROM Desenvolvedor WHERE Email = '" + emailDatabase + "';";

        //put the query into the object
        comando.setComandoSQL(query);

        //execute the command to delete the user
        try {
            comando.executar();
            resultado.setValor(Resultado::SUCESSO);
            return resultado;
        }
        catch (EErroPersistencia& e){
            cerr << e.what();
            system("pause");
            resultado.setValor(Resultado::FALHA);
            return resultado;
        }
    }

       //get the email from the database of administer
    query = "SELECT Email FROM Admministrador WHERE Email = '" + email.getEmail() + "';";

    //put the query into the object
    comando.setComandoSQL(query);

    //execute the command to get the email
    try {
        comando.executar();
    }
    catch (EErroPersistencia& e){
        cerr << e.what();
        system("pause");
        resultado.setValor(Resultado::FALHA);
        return resultado;
    }

    //get the email from the database
    emailDatabase = comando.listaResultado.back().getValorColuna();
    comando.listaResultado.pop_back();

    //check if this email exists on the administer table
    if(emailDatabase != ""){
        //do the query to delete the user
        query = "DELETE FROM Administrador WHERE Email = '" + emailDatabase + "';";

        //put the query into the object
        comando.setComandoSQL(query);

        //execute the command to delete the user
        try {
            comando.executar();
            resultado.setValor(Resultado::SUCESSO);
            return resultado;
        }
        catch (EErroPersistencia& e){
            cerr << e.what();
            system("pause");
            resultado.setValor(Resultado::FALHA);
            return resultado;
        }
    }
}

//definition of the method to edit the reader
Resultado ServicoGestao::editarLeitor(const Leitor& leitor, const string& str) throw(runtime_error){
    //the object to be the result if the edition was a success or a failure
    Resultado resultado;
    //the object to access the database
    ComandoSQL comando;
    //the query to set the informations
    string query;

    //creating the query to update the reader
    query = "UPDATE Leitor \
    SET Nome = '" + leitor.getNome() + "', \
    SobreNome = '" + leitor.getSobrenome() + "', \
    Email = '" + leitor.getEmail() + "', \
    Senha = '" + leitor.getSenha() + "' \
    WHERE Email = '" + str + "';";

    //put the query into the object
    comando.setComandoSQL(query);

    //execute the command to create the table
    try {
        comando.executar();
    }
    catch (EErroPersistencia& e){
        cerr << e.what();
        system("pause");
        resultado.setValor(Resultado::FALHA);
        return resultado;
    }

    resultado.setValor(Resultado::SUCESSO);

    return resultado;
}

//definition of the method to edit the developer
Resultado ServicoGestao::editarDesenvolvedor(const Desenvolvedor& desenvolvedor, const string& str) throw(runtime_error){
    //the object to be the result if the edition was a success or a failure
    Resultado resultado;
    //the object to access the database
    ComandoSQL comando;
    //the query to set the informations
    string query;

    //creating the query to update the reader
    query = "UPDATE Desenvolvedor \
    SET Nome = '" + desenvolvedor.getNome() + "', \
    SobreNome = '" + desenvolvedor.getSobrenome() + "', \
    Email = '" + desenvolvedor.getEmail() + "', \
    Senha = '" + desenvolvedor.getSenha() + "', \
    Data = '" + desenvolvedor.getData() + "' \
    WHERE Email = '" + str + "';";

    //put the query into the object
    comando.setComandoSQL(query);

    //execute the command to create the table
    try {
        comando.executar();
    }
    catch (EErroPersistencia& e){
        cerr << e.what();
        system("pause");
        resultado.setValor(Resultado::FALHA);
        return resultado;
    }

    resultado.setValor(Resultado::SUCESSO);

    return resultado;
}

//definition of the method to edit the administer
Resultado ServicoGestao::editarAdministrador(const Administrador& administrador, const string& str) throw(runtime_error){
    //the object to be the result if the edition was a success or a failure
    Resultado resultado;
    //the object to access the database
    ComandoSQL comando;
    //the query to set the informations
    string query;

    //creating the query to update the administer
    query = "UPDATE Administrador \
    SET Nome = '" + administrador.getNome() + "', \
    SobreNome = '" + administrador.getSobrenome() + "', \
    Email = '" + administrador.getEmail() + "', \
    Senha = '" + administrador.getSenha() + "', \
    Data = '" + administrador.getData() + "', \
    Telefone = '" + administrador.getTelefone() + "', \
    Endereco = '" + administrador.getEndereco() + "' \
    WHERE Email = '" + str + "';";

    //put the query into the object
    comando.setComandoSQL(query);

    //execute the command to create the table
    try {
        comando.executar();
    }
    catch (EErroPersistencia& e){
        cerr << e.what();
        system("pause");
        resultado.setValor(Resultado::FALHA);
        return resultado;
    }

    resultado.setValor(Resultado::SUCESSO);

    return resultado;
}
