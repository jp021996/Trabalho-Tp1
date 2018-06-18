#include "MSVoc.hpp"


ResultadoLista ServicoGestaoVocab::listarVocabs() throw(runtime_error) {
    //the object to be the result of the registering
    ResultadoLista resultado;
    //the object that make the SQL comand
    ComandoSQL comando;
    //counter and number of loops that for will make
    int i, voltas;

    //create a query to show all the vocabs
    string query;


    query = "SELECT Nome FROM Vocabulario";

    //put the query into the object
    comando.setComandoSQL(query);

    //execute the command to create the table
    try {
    comando.executar();

    voltas = comando.listaResultado.size();

    cout << "O número de vocabulários é: " << voltas<< endl;
        //print on the scream the vocabs
        for(i=0;i<voltas; i++){
            cout << comando.listaResultado.back().getNomeColuna() << " : " << comando.listaResultado.back().getValorColuna() << endl;
            comando.listaResultado.pop_back();
        }
        resultado.setValor(ResultadoLista::SUCESSO);

    }
    catch (EErroPersistencia& e){
        cerr << e.what();
        resultado.setValor(Resultado::FALHA);
        return resultado;
    }


    return resultado;
}

ResultadoVocab ServicoGestaoVocab::dadosVocab(const string& nomeVocab) throw(runtime_error) {
    //the object to be the result of the registering
    ResultadoVocab resultado;

    return resultado;
}

ResultadoTermo ServicoGestaoVocab::consultarTermo(const string& nomeTermo) throw(runtime_error) {
    //the object to be the result of the registering
    ResultadoTermo resultado;

    return resultado;
}

ResultadoDefinicao ServicoGestaoVocab::consultarDefinicao(const string& textoDef) throw(runtime_error) {
    //the object to be the result of the registering
    ResultadoDefinicao resultado;

    return resultado;
}

ResultadoEspecifico ServicoGestaoVocab::desenvolvedorDeVocab(const string& nomeVocab) throw(runtime_error) {
    //the object to be the result of the registering
    ResultadoEspecifico resultado;

    return resultado;
}

ResultadoVocab ServicoGestaoVocab::criarTermo(const Termo& novoTermo, const string& nomeVocab) throw(runtime_error) {
    //the object to be the result of the registering
    ResultadoVocab resultado;

    return resultado;
}

ResultadoTermo ServicoGestaoVocab::editarTermo(const Termo& termo, const Termo& novoTermo) throw(runtime_error) {
    //the object to be the result of the registering
    ResultadoTermo resultado;

    return resultado;
}

ResultadoTermo ServicoGestaoVocab::excluirTermo(const Termo& termo) throw(runtime_error) {
    //the object to be the result of the registering
    ResultadoTermo resultado;

    return resultado;
}

ResultadoDefinicao ServicoGestaoVocab::criarDefinicao(const Definicao& definicao) throw(runtime_error) {
    //the object to be the result of the registering
    ResultadoDefinicao resultado;

    return resultado;
}

ResultadoDefinicao ServicoGestaoVocab::editarDefinicao(const Definicao& antigaDef,const Definicao& novaDef) throw(runtime_error) {
    //the object to be the result of the registering
    ResultadoDefinicao resultado;

    return resultado;
}

Resultado ServicoGestaoVocab::excluirDefinicao(const Definicao& definicao) throw(runtime_error) {
    //the object to be the result of the registering
    Resultado resultado;

    return resultado;
}

ResultadoVocab ServicoGestaoVocab::criarVocabulario(const Vocabulario& vocab, const Definicao& defVocab) throw(runtime_error) {
    //the object to be the result of the registering
    ResultadoVocab resultado;

    return resultado;
}

Resultado ServicoGestaoVocab::editarDefinicaoVocab(const Vocabulario& vocab, const Definicao& defVocab) throw(runtime_error) {
    //the object to be the result of the registering
    Resultado resultado;

    return resultado;
}

Resultado ServicoGestaoVocab::editarIdiomaVocab(const Vocabulario& vocab, const Idioma& idioma) throw(runtime_error) {
    //the object to be the result of the registering
    Resultado resultado;

    return resultado;
}

Resultado ServicoGestaoVocab::excluirVocabulario(const Vocabulario& vocab) throw(runtime_error) {
    //the object to be the result of the registering
    Resultado resultado;

    return resultado;
}
