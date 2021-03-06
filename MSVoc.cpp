#include "MSVoc.hpp"


ResultadoLista ServicoGestaoVocab::listarVocabs() throw(runtime_error) {
    //the object to be the result of the registering
    ResultadoLista resultado;
    //the object that make the SQL comand
    ComandoSQL comando;

    //create a query to show all the vocabs
    string query;


    query = "SELECT Nome FROM Vocabulario;";

    //put the query into the object
    comando.setComandoSQL(query);

    //execute the command to create the table
    try {
    comando.executar();

        if(comando.listaResultado.size() <= 0){
            resultado.setValor(ResultadoVocab::FALHA);
            return resultado;
        }else{
            resultado.setValor(ResultadoLista::SUCESSO);
            return resultado;
        }

    }
    catch (EErroPersistencia& e){
        cerr << e.what();
        resultado.setValor(Resultado::FALHA);
        return resultado;
    }

}

ResultadoVocab ServicoGestaoVocab::dadosVocab(const string& nomeVocab) throw(runtime_error) {
    //the object to be the result of the registering
    ResultadoVocab resultado;

    //the object that make the SQL comand
    ComandoSQL comando;

    //create a query to show all the vocabs
    string query;


    query = "SELECT * FROM Vocabulario WHERE Nome = '" +nomeVocab+"';";

    //put the query into the object
    comando.setComandoSQL(query);

    //execute the command to create the table
    try {
    comando.executar();

    query = "SELECT Desenvolvedor FROM VocabDesenvolvedor WHERE Vocabulario= '" +nomeVocab+"';";
    //put the query into the object
    comando.setComandoSQL(query);
    comando.executar();

        if(comando.listaResultado.size()== 0){
        resultado.setValor(ResultadoVocab::FALHA);

        }else{
            resultado.setValor(ResultadoVocab::SUCESSO);
        }

    }
    catch (EErroPersistencia& e){
        cerr << e.what();
        resultado.setValor(ResultadoVocab::FALHA);
        return resultado;
    }

    return resultado;
}

ResultadoTermo ServicoGestaoVocab::consultarTermo(const string& nomeTermo) throw(runtime_error) {
    //the object to be the result of the registering
    ResultadoTermo resultado;

    //the object that make the SQL comand
    ComandoSQL comando;

    //create a query to show all the vocabs
    string query;


    query = "SELECT * FROM Termo WHERE Nome = '" +nomeTermo+"';";

    //put the query into the object
    comando.setComandoSQL(query);

    //execute the command to create the table
    try {
        comando.executar();

    query = "SELECT Definicao FROM TermoDef WHERE Termo= '" +nomeTermo+"';";
    //put the query into the object
    comando.setComandoSQL(query);
    comando.executar();

        if(comando.listaResultado.size()== 0){
        resultado.setValor(ResultadoVocab::FALHA);

        }else{
            resultado.setValor(ResultadoVocab::SUCESSO);
        }

    }
    catch (EErroPersistencia& e){
        cerr << e.what();
        resultado.setValor(ResultadoVocab::FALHA);
        return resultado;
    }

    return resultado;
}

ResultadoDefinicao ServicoGestaoVocab::consultarDefinicao(const string& termo) throw(runtime_error) {
    //the object to be the result of the registering
    ResultadoDefinicao resultado;

      //the object that make the SQL comand
    ComandoSQL comando;

    //create a query to show all the vocabs
    string query;


    query = "SELECT * FROM Definicao WHERE (SElECT Definicao FROM TermoDef Where Termo = '" +termo+"');";

    //put the query into the object
    comando.setComandoSQL(query);

    //execute the command to create the table
    try {
        comando.executar();

        if(comando.listaResultado.size()== 0){
        resultado.setValor(ResultadoVocab::FALHA);

        }else{
            resultado.setValor(ResultadoVocab::SUCESSO);
        }

    }
    catch (EErroPersistencia& e){
        cerr << e.what();
        resultado.setValor(ResultadoVocab::FALHA);
        return resultado;
    }


    return resultado;
}

ResultadoEspecifico ServicoGestaoVocab::desenvolvedorDeVocab(const string& nomeVocab, const string& email) throw(runtime_error) {
    //the object to be the result of the registering
    ResultadoEspecifico resultado;
    int voltas,i;

     //the object that make the SQL comand
    ComandoSQL comando;

    //create a query to show all the vocabs
    string query;


    query = "SELECT Desenvolvedor FROM VocabDesenvolvedor WHERE Vocabulario = '" +nomeVocab+"';";

    //put the query into the object
    comando.setComandoSQL(query);

    //execute the command to create the table
    try {
        comando.executar();
        voltas = comando.listaResultado.size();

                    for(i=0;i<voltas; i++){
                        comando.listaResultado.pop_back();
                        }

            if(voltas >= 10){
                    resultado.setValor(ResultadoEspecifico::FALHA_2);
                    return resultado;

            }else{
                query = "SELECT Nome FROM Vocabulario WHERE Nome = '"+nomeVocab+"';";
                comando.setComandoSQL(query);
                comando.executar();
                voltas = comando.listaResultado.size();
                for(i=0;i<voltas; i++){
                    comando.listaResultado.pop_back();
                }
                if(voltas == 0){
                    resultado.setValor(ResultadoEspecifico::FALHA);
                    return resultado;
                }else{
                    query = "INSERT INTO VocabDesenvolvedor VALUES('"+nomeVocab+"', '"+email+"');";
                    comando.setComandoSQL(query);
                    comando.executar();;
                    resultado.setValor(ResultadoEspecifico::SUCESSO);
                }
            }

    }
    catch (EErroPersistencia& e){
        cerr << e.what();
        resultado.setValor(ResultadoVocab::FALHA);
        return resultado;
    }


    return resultado;
}


ResultadoVocab ServicoGestaoVocab::criarTermo(const Termo& novoTermo, const string& nomeVocab, const string& email) throw(runtime_error) {

    //the object to be the result of the registering
    ResultadoVocab resultado;

    //the object that make the SQL comand
    ComandoSQL comando;
    //Voltas is rhw number of loops in for, and i is the count
    int i, voltas, j;

    //create a query to show all the vocabs
    string query;


    query = "SELECT Nome FROM Termo WHERE Nome = '" +novoTermo.getNome()+"';";

    //put the query into the object
    comando.setComandoSQL(query);

    //execute the command to create the table
    try {
    comando.executar();

        if(comando.listaResultado.size()>= 1){
                comando.listaResultado.pop_back();
                throw runtime_error("J� existe um termo com este nome");

        }else{
            query = "SELECT Nome FROM Vocabulario WHERE Nome = '"+nomeVocab+"';";
            comando.setComandoSQL(query);
            comando.executar();
            if(comando.listaResultado.size() == 0){
                resultado.setValor(ResultadoVocab::FALHA);
                return resultado;
            }else{
                query = "SELECT Desenvolvedor FROM VocabDesenvolvedor WHERE Vocabulario = '"+nomeVocab+"';";
                comando.setComandoSQL(query);
                comando.executar();
                voltas = comando.listaResultado.size();
                for(i=0;i<voltas;i++){
                    if(comando.listaResultado.back().getValorColuna() != email){
                        comando.listaResultado.pop_back();
                        resultado.setValor(ResultadoVocab::PERMISSAO_NEGADA);
                    }else{
                        voltas = comando.listaResultado.size();
                        for(j=0;j<voltas;j++){
                            comando.listaResultado.pop_back();
                        }
                        query = "INSERT INTO Termo VALUES('" +novoTermo.getNome()+"','" +novoTermo.getData()+"', '', '" +nomeVocab+"');";
                        comando.setComandoSQL(query);
                        comando.executar();
                        resultado.setValor(ResultadoVocab::SUCESSO);
                        break;

                    }

                }
            }

        }

    }
    catch (EErroPersistencia& e){
        cerr << e.what();
        resultado.setValor(ResultadoVocab::FALHA);
        return resultado;
    }


    return resultado;
}

ResultadoTermo ServicoGestaoVocab::editarTermo(const Termo& termo, const Termo& novoTermo) throw(runtime_error) {
    //the object to be the result of the registering
    ResultadoTermo resultado;

    //the object that make the SQL comand
    ComandoSQL comando;

    //create a query to show all the vocabs
    string query;

    query = "SELECT Nome FROM Termo WHERE Nome = '"+termo.getNome()+"';";

    //put the query into the object
    comando.setComandoSQL(query);

    //execute the command to create the table
    try {
        comando.executar();
        if(comando.listaResultado.size() == 0){
            throw runtime_error("O Termo que deseja editar n�o existe");
        }else{

        comando.listaResultado.pop_back();
         query = "UPDATE Termo SET Nome = '"+novoTermo.getNome()+"', Data = '"+novoTermo.getData()+"'  WHERE Nome = '" +termo.getNome()+"';";
         comando.setComandoSQL(query);

            resultado.setValor(ResultadoTermo::SUCESSO);
        }
    }
    catch (EErroPersistencia& e){
        cerr << e.what();
        resultado.setValor(ResultadoTermo::FALHA);
        return resultado;
    }

    return resultado;
}

ResultadoTermo ServicoGestaoVocab::excluirTermo(const Termo& termo) throw(runtime_error) {
    //the object to be the result of the registering
    ResultadoTermo resultado;

    //the object that make the SQL comand
    ComandoSQL comando;

    //create a query to show all the vocabs
    string query;


    query = "DELETE FROM Termo WHERE Nome = '" +termo.getNome()+"';";

    //put the query into the object
    comando.setComandoSQL(query);

    //execute the command to create the table
    try {
        comando.executar();

            resultado.setValor(ResultadoTermo::SUCESSO);
    }
    catch (EErroPersistencia& e){
        cerr << e.what();
        resultado.setValor(ResultadoTermo::FALHA);
        return resultado;
    }

    return resultado;
}

ResultadoDefinicao ServicoGestaoVocab::criarDefinicao(const Definicao& definicao) throw(runtime_error) {
    //the object to be the result of the registering
    ResultadoDefinicao resultado;
        //the object that make the SQL comand
    ComandoSQL comando;
    //create a query to show all the vocabs
    string query;
    //the length of the list
    int tam;
    //a regular counter
    int counter;

    //creating the query to get the id
    query = "SELECT Id FROM Definicao;";

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

    tam = comando.listaResultado.size();

    if(tam != 0){
        for(counter = 0; counter < tam; counter++){
            cout << comando.listaResultado.back().getValorColuna() << endl;
            comando.listaResultado.pop_back();
        }
    }

    //creating the query to add the vocabulary
    query = "INSERT INTO Definicao VALUES(" + to_string(tam+1) + ",'" +
    definicao.getData() + "','" + definicao.getTexto() + "');";

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

ResultadoDefinicao ServicoGestaoVocab::editarDefinicao(const Definicao& antigaDef,const Definicao& novaDef) throw(runtime_error) {
    //the object to be the result of the registering
    ResultadoDefinicao resultado;

    //the object that make the SQL comand
    ComandoSQL comando;

    //create a query to show all the vocabs
    string query;

    query = "SELECT Id FROM Definicao WHERE Id = '"+antigaDef.getTexto()+"';";

    //put the query into the object
    comando.setComandoSQL(query);

    //execute the command to create the table
    try {
        comando.executar();
        if(comando.listaResultado.size() == 0){
            resultado.setValor(ResultadoDefinicao::FALHA);
        }else{

        comando.listaResultado.pop_back();
         query = "UPDATE Definicao SET TextoDefinicao = '"+novaDef.getTexto()+"', Data = '"+novaDef.getData()+"'  WHERE Id = '" +antigaDef.getTexto()+"';";
         comando.setComandoSQL(query);

            resultado.setValor(ResultadoTermo::SUCESSO);
        }
    }
    catch (EErroPersistencia& e){
        cerr << e.what();
        resultado.setValor(ResultadoTermo::FALHA);
        return resultado;
    }

    return resultado;
}

Resultado ServicoGestaoVocab::excluirDefinicao(const Nome& nome) throw(runtime_error) {
    //the object to be the result of the registering
    Resultado resultado;

    //the object that make the SQL comand
    ComandoSQL comando;

    //create a query to show all the vocabs
    string query;


    query = "SELECT Nome FROM Termo WHERE Nome = '" +nome.getNome()+"';";

    //put the query into the object
    comando.setComandoSQL(query);

    //execute the command to create the table
    try {
        comando.executar();
        if(comando.listaResultado.size()== 0){
            resultado.setValor(Resultado::FALHA);
            return resultado;
        }
        comando.listaResultado.pop_back();

         query = "DELETE FROM Definicao WHERE Id IN (SELECT Definicao FROM TermoDef WHERE Termo = '" +nome.getNome()+"');";
         comando.setComandoSQL(query);
         comando.executar();

        query = "DELET FROM TermoDef WHERE Termo = '" +nome.getNome()+"');";

            resultado.setValor(ResultadoTermo::SUCESSO);
    }
    catch (EErroPersistencia& e){
        cerr << e.what();
        resultado.setValor(ResultadoTermo::FALHA);
        return resultado;
    }

    return resultado;
}

ResultadoVocab ServicoGestaoVocab::criarVocabulario(const Vocabulario& vocab, const Definicao& defVocab, const string& str) throw(runtime_error) {
    //the object to be the result of the registering
    ResultadoVocab resultado;
    //the object that make the SQL comand
    ComandoSQL comando;
    //create a query to show all the vocabs
    string query;
    //the length of the list
    int tam;
    //a regular counter
    int counter;

    //creating the query to get the id
    query = "SELECT Id FROM Definicao;";

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

    tam = comando.listaResultado.size();

    if(tam != 0){
        for(counter = 0; counter < tam; counter++){
            comando.listaResultado.pop_back();
        }
    }

    //creating the query to add the vocabulary
    query = "INSERT INTO Definicao VALUES(" + to_string(tam+1) + ",'" +
    defVocab.getData() + "','" + defVocab.getTexto() + "');";

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

    //creating the query to add the vocabulary
    query = "INSERT INTO Vocabulario VALUES('" +
    vocab.getNome() + "','" + to_string(tam+1) +
    "','" + vocab.getData() + "','" + vocab.getIdioma() +
    "','" + str + "');";

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

Resultado ServicoGestaoVocab::editarDefinicaoVocab(const Vocabulario& vocab, const Definicao& defVocab) throw(runtime_error) {
    //the object to be the result of the registering
    Resultado resultado;
    //the object that make the SQL comand
    ComandoSQL comando;
    //create a query to show all the vocabs
    string query;
    //the id the of the vocabulary
    string id;

    //creating the query to update the definition text of the vocabulary
    query = "SELECT Definicao FROM Vocabulario WHERE Nome = '" + vocab.getNome() + "';";

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

    //getting the id of the definition of the vocabulary
    id = comando.listaResultado.back().getValorColuna();
    cout << id << endl;
    //removing the item of the list
    comando.listaResultado.pop_back();

    query = "UPDATE Definicao SET Data = '" + defVocab.getData() + "'," +
    "TextoDefinicao = '" + defVocab.getTexto() + "' WHERE Id = " + id + ";";

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

Resultado ServicoGestaoVocab::editarIdiomaVocab(const Vocabulario& vocab, const Idioma& idioma) throw(runtime_error) {
    //the object to be the result of the registering
    Resultado resultado;
    //the object that make the SQL command
    ComandoSQL comando;
    //create a query to show all the vocabs
    string query;
    //name of database
    string nomeDatabase = "";

    query = "SELECT Nome \
    FROM Vocabulario \
    WHERE Nome = '" + vocab.getNome() + "';";

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

    nomeDatabase = comando.listaResultado.back().getValorColuna();

    if(nomeDatabase == ""){
        resultado.setValor(Resultado::FALHA);
        return resultado;
    }

    comando.listaResultado.pop_back();

    //creating the query to update the definition text of the vocabulary
    query = "UPDATE Vocabulario SET Idioma = '" + idioma.getIdioma() + "' WHERE Nome = '" +
    vocab.getNome() + "';";

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

Resultado ServicoGestaoVocab::excluirVocabulario(const Vocabulario& vocab) throw(runtime_error) {
    //the object to be the result of the registering
    Resultado resultado;
     //the object that make the SQL command
    ComandoSQL comando;
    //create a query to show all the vocabs
    string query;
    //name of database
    string nomeDatabase = "";

    query = "SELECT Nome \
    FROM Vocabulario \
    WHERE Nome = '" + vocab.getNome() + "';";

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

    nomeDatabase = comando.listaResultado.back().getValorColuna();

    if(nomeDatabase == ""){
        resultado.setValor(Resultado::FALHA);
        return resultado;
    }

    comando.listaResultado.pop_back();

    query = "DELETE FROM Vocabulario WHERE Nome = '" + vocab.getNome() + "';";

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
