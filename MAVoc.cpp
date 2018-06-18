#include "MAVoc.hpp"


Resultado ApresentacaoGestaoVocab::executar(ResultadoAutenticacao &autenticado) throw(runtime_error){

    const int LEITOR = 1;
    const int DSV = 2;
    const int ADM = 3;
    int tipo = autenticado.getTipo();
    Resultado resultado;
    Email email;

    switch(tipo){
    case LEITOR:
        email.setEmail( autenticado.getLeitor().getEmail() );
        resultado = executarLeitor(email);
        break;
    case DSV:
        email.setEmail( autenticado.getDesenvolvedor().getEmail() );
        resultado = executarDesenvolvedor(email);
        break;
    case ADM:
        email.setEmail( autenticado.getAdministrador().getEmail() );
        resultado = executarAdministrador(email);
        break;
    }

    return resultado;
}

Resultado ApresentacaoGestaoVocab::executarLeitor(const Email &email) throw(runtime_error){

    int opcao, voltas, i;
    Resultado resultado;
    ComandoSQL comando;

    const int LISTAR_VOCABS = 1;
    const int MOSTRAR_DADOS = 2;
    const int CONSULTAR_TERMO = 3;
    const int CONSULTAR_DEFINICAO = 4;
    const int SAIR = 0;

    while(true){

        system("CLS");
        cout << "************* LEITOR - GESTAO DE VOCABULARIO *************"<<endl<<endl;
        cout << "(1) Listar todos vocabularios" << endl;
        cout << "(2) Exibir dados de um vocabulario" << endl;
        cout << "(3) Consultar termo" << endl;
        cout << "(4) Constultar definicao de termo" << endl;
        cout << "(0) Sair" << endl;
        cout << endl << "Opcao escolhida: ";
        cin >> opcao;
        cout << endl;


        if (opcao == LISTAR_VOCABS){

            ResultadoLista resultadoLista;

            resultadoLista = link_MA_MS_GestaoVocab->listarVocabs();

            if(resultadoLista.getValor() == ResultadoLista::FALHA){
                cout << "Ocorreu uma falha no programa" << endl;
                cout << comando.listaResultado.size();
            }else{
                voltas = comando.listaResultado.size();

                cout << "O número de vocabulários é: " << voltas<< endl;

                 //print on the scream the name of vocabs
                for(i=0;i<voltas; i++){
                    cout << comando.listaResultado.back().getNomeColuna() << " : " << comando.listaResultado.back().getValorColuna() << endl;
                    comando.listaResultado.pop_back();
                }
            }

            cout << endl;
            system("PAUSE");

        }
        if(opcao == MOSTRAR_DADOS){

            string nomeVocab;
            ResultadoVocab resultadoVocab;

            cout << "Digite o nome do vocabulario desejado: ";
            cin >> nomeVocab;
            cout << endl;

            try{

                resultadoVocab = link_MA_MS_GestaoVocab->dadosVocab(nomeVocab);

                if(resultadoVocab.getValor() == ResultadoVocab::SUCESSO){
                    resultado.setValor(Resultado::SUCESSO);


                    voltas = comando.listaResultado.size();
                    cout << voltas << endl;

                    cout << "Dados do Vocabulario: "<<endl;
                    //print on the scream the data of vocabs
                    for(i=0;i<voltas; i++){
                        cout << comando.listaResultado.back().getNomeColuna() << " : " << comando.listaResultado.back().getValorColuna() << endl;
                        comando.listaResultado.pop_back();
                        }

                    cout << endl;
                }
                if(resultadoVocab.getValor() == ResultadoVocab::FALHA){
                    resultado.setValor(Resultado::FALHA);
                    cout << endl << "Não há nenhum vocabulário com nome '"<<nomeVocab<<"' registrado. ";
                }

                system("PAUSE");

            }
            catch(invalid_argument excecao){
                resultado.setValor(Resultado::FALHA);
                cerr << endl << excecao.what() <<endl;
                return resultado;
            }

        }
        if(opcao == CONSULTAR_TERMO){

            ResultadoTermo resultadoTermo;
            string nomeTermo;

            cout << "Digite o nome do termo a ser buscado: ";
            cin >> nomeTermo;

            try{
                resultadoTermo = link_MA_MS_GestaoVocab->consultarTermo(nomeTermo);

                if(resultadoTermo.getValor() == ResultadoTermo::SUCESSO){
                    resultado.setValor(Resultado::SUCESSO);

                    int numeroDefinicoes = resultadoTermo.getDefinicoesTermo().size();

                    cout << "Dados do Termo: "<<endl;
                    cout << "> Nome: " << resultadoTermo.getTermo().getNome() << endl;
                    cout << "> Data: " << resultadoTermo.getTermo().getData() << endl;
                    cout << "> Vocabulario: " << resultadoTermo.getNomeVocabTermo() << endl;
                    cout << "> Definicoes (" << numeroDefinicoes << "): "<<endl;
                    for(int i=0; i<numeroDefinicoes; i++){
                        cout << "    - '"<< resultadoTermo.getDefinicoesTermo()[i].getTexto()  << "'"<< endl;
                    }
                    cout << endl;
                }
                if(resultadoTermo.getValor() == Resultado::FALHA){
                    resultado.setValor(Resultado::FALHA);
                    cout << endl << "Não há nenhum termo com nome '"<<nomeTermo<<"' registrado. "<<endl;
                }

                system("PAUSE");
            }
            catch(invalid_argument excecao){
                resultado.setValor(Resultado::FALHA);
                cerr << endl << excecao.what() <<endl;
                return resultado;
            }


        }

        if(opcao == CONSULTAR_DEFINICAO){

            ResultadoDefinicao resultadoDefinicao;
            string textoDef;

            fflush(stdin);
            cout << "Digite um trecho do texto a ser pesquisado: ";
            getline(cin,textoDef);
            //fflush(stdin);

            try{
                resultadoDefinicao = link_MA_MS_GestaoVocab->consultarDefinicao(textoDef);

                if(resultadoDefinicao.getValor() == Resultado::SUCESSO){
                    resultado.setValor(Resultado::SUCESSO);

                    int numeroTermosDef = resultadoDefinicao.getTermosDef().size();

                    cout << "> Texto da definicao: '"<< resultadoDefinicao.getDefinicao().getTexto() <<"'"<<endl;
                    cout << "> Data da definicao: " << resultadoDefinicao.getDefinicao().getData() << endl;
                    cout << "> Numero de termos associados (" << numeroTermosDef << "): "  << endl;
                    for(int i=0; i<numeroTermosDef; i++){
                        cout << "     "<<i+1<<") "<< resultadoDefinicao.getTermosDef()[i].getNome();
                        cout << "[Data: " << resultadoDefinicao.getTermosDef()[i].getData() <<"] ";
                        cout << "[Preferencia: " << resultadoDefinicao.getTermosDef()[i].getPreferencia()<<"]"<<endl;
                    }
                    cout << endl;
                }
                if(resultadoDefinicao.getValor() == ResultadoDefinicao::FALHA){
                    resultado.setValor(Resultado::FALHA);
                    cout << endl << "Nenhuma definicao foi encontrada." << endl;
                }

                system("PAUSE");
            }
            catch(invalid_argument excecao){
                resultado.setValor(Resultado::FALHA);
                cerr << endl << excecao.what() <<endl;
                return resultado;
            }




        }

        if(opcao == SAIR){
            resultado.setValor(Resultado::SUCESSO);
        }
        if(opcao <0 || opcao>4){
            resultado.setValor(Resultado::FALHA);
            continue;
        }

    }

    return resultado;


}


Resultado ApresentacaoGestaoVocab::executarDesenvolvedor(const Email &email) throw(runtime_error){

    int opcao;
    Resultado resultado;

    const int LISTAR_VOCABS = 1;
    const int MOSTRAR_DADOS = 2;
    const int CONSULTAR_TERMO = 3;
    const int CONSULTAR_DEFINICAO = 4;
    const int CADASTRAR_DESENV_VOCAB = 5;
    const int CRIAR_TERMO = 6;
    const int EXCLUIR_TERMO = 7;
    const int EDITAR_TERMO = 8;
    const int CRIAR_DEF_TERMO = 9;
    const int EXCLUIR_DEF_TERMO = 10;
    const int EDITAR_DEF_TERMO = 11;


    const int SAIR = 0;

    while(true){

        system("CLS");
        cout << "************* DESENVOLVEDOR - GESTAO DE VOCABULARIO *************"<<endl<<endl;
        cout << "(1) Listar todos vocabularios" << endl;
        cout << "(2) Exibir dados de um vocabulario" << endl;
        cout << "(3) Consultar termo" << endl;
        cout << "(4) Constultar definicao de termo" << endl;
        cout << "(5) Cadastrar como desenvolvedor de vocabulario controlado" << endl;
        cout << "(6) Criar termo" << endl;
        cout << "(7) Excluir Termo" << endl;
        cout << "(8) Editar Termo" << endl;
        cout << "(9) Criar definicao de termo" << endl;
        cout << "(10) Excluir definicao de termo" << endl;
        cout << "(11) Editar definicao de termo" << endl;
        cout << "(0) Sair" << endl;
        cout << endl << "Opcao escolhida: ";
        cin >> opcao;
        cout << endl;


        if (opcao == LISTAR_VOCABS){
            int tam;
            ResultadoLista resultadoLista;
            vector<string> listaVocab;

            resultadoLista = link_MA_MS_GestaoVocab->listarVocabs();

            resultado.setValor(Resultado::SUCESSO);

            listaVocab = resultadoLista.listaVocab;

            tam = listaVocab.size();

            cout << endl << "Foram encontrados " << tam << " vocabularios." << endl;

            for(int i=0; i<tam; i++){
                cout <<"> "<<listaVocab[i] << endl;
            }
            cout << endl;
            system("PAUSE");

        }
        if(opcao == MOSTRAR_DADOS){

            string nomeVocab;
            ResultadoVocab resultadoVocab;

            cout << "Digite o nome do vocabulario desejado: ";
            cin >> nomeVocab;
            cout << endl;

            try{

                resultadoVocab = link_MA_MS_GestaoVocab->dadosVocab(nomeVocab);

                if(resultadoVocab.getValor() == ResultadoVocab::SUCESSO){
                    resultado.setValor(Resultado::SUCESSO);

                    int numeroTermos = resultadoVocab.getNomesTermosVocab().size();
                    int numeroDesenv = resultadoVocab.getNomesDesenvolvedores().size();

                    cout << "Dados do Vocabulario: "<<endl;
                    cout << "> Nome: " << resultadoVocab.getVocab().getNome() << endl;
                    cout << "> Idioma: " << resultadoVocab.getVocab().getIdioma() << endl;
                    cout << "> Data: " << resultadoVocab.getVocab().getData() << endl;
                    cout << "> Administrador: " << resultadoVocab.getNomeAdm() << endl;
                    cout << "> Desenvolvedores (" << numeroDesenv << "): "<<endl;
                    for(int i=0; i<numeroDesenv; i++){
                        cout << "    - "<< resultadoVocab.getNomesDesenvolvedores()[i] << endl;
                    }
                    cout << "> Termos (" << numeroTermos << "): "<<endl;
                    for(int i=0; i<numeroTermos; i++){
                        cout << "    - "<< resultadoVocab.getNomesTermosVocab()[i]  << endl;
                    }
                    cout << endl;
                }
                if(resultadoVocab.getValor() == ResultadoVocab::FALHA){
                    resultado.setValor(Resultado::FALHA);
                    cout << endl << "Não há nenhum vocabulário com nome '"<<nomeVocab<<"' registrado. ";
                }

                system("PAUSE");

            }
            catch(invalid_argument excecao){
                resultado.setValor(Resultado::FALHA);
                cerr << endl << excecao.what() <<endl;
                return resultado;
            }

        }
        if(opcao == CONSULTAR_TERMO){

            ResultadoTermo resultadoTermo;
            string nomeTermo;

            cout << "Digite o nome do termo a ser buscado: ";
            cin >> nomeTermo;

            try{
                resultadoTermo = link_MA_MS_GestaoVocab->consultarTermo(nomeTermo);

                if(resultadoTermo.getValor() == ResultadoTermo::SUCESSO){
                    resultado.setValor(Resultado::SUCESSO);

                    int numeroDefinicoes = resultadoTermo.getDefinicoesTermo().size();

                    cout << "Dados do Termo: "<<endl;
                    cout << "> Nome: " << resultadoTermo.getTermo().getNome() << endl;
                    cout << "> Data: " << resultadoTermo.getTermo().getData() << endl;
                    cout << "> Vocabulario: " << resultadoTermo.getNomeVocabTermo() << endl;
                    cout << "> Definicoes (" << numeroDefinicoes << "): "<<endl;
                    for(int i=0; i<numeroDefinicoes; i++){
                        cout << "    - '"<< resultadoTermo.getDefinicoesTermo()[i].getTexto()  << "'"<< endl;
                    }
                    cout << endl;
                }
                if(resultadoTermo.getValor() == Resultado::FALHA){
                    resultado.setValor(Resultado::FALHA);
                    cout << endl << "Não há nenhum termo com nome '"<<nomeTermo<<"' registrado. "<<endl;
                }

                system("PAUSE");
            }
            catch(invalid_argument excecao){
                resultado.setValor(Resultado::FALHA);
                cerr << endl << excecao.what() <<endl;
                return resultado;
            }


        }

        if(opcao == CONSULTAR_DEFINICAO){

            ResultadoDefinicao resultadoDefinicao;
            string textoDef;

            fflush(stdin);
            cout << "Digite um trecho do texto a ser pesquisado: ";
            getline(cin,textoDef);
            fflush(stdin);

            try{
                resultadoDefinicao = link_MA_MS_GestaoVocab->consultarDefinicao(textoDef);

                if(resultadoDefinicao.getValor() == Resultado::SUCESSO){
                    resultado.setValor(Resultado::SUCESSO);

                    int numeroTermosDef = resultadoDefinicao.getTermosDef().size();

                    cout << "> Texto da definicao: '"<< resultadoDefinicao.getDefinicao().getTexto() <<"'"<<endl;
                    cout << "> Data da definicao: " << resultadoDefinicao.getDefinicao().getData() << endl;
                    cout << "> Numero de termos associados (" << numeroTermosDef << "): "  << endl;
                    for(int i=0; i<numeroTermosDef; i++){
                        cout << "     "<<i+1<<") "<< resultadoDefinicao.getTermosDef()[i].getNome();
                        cout << "[Data: " << resultadoDefinicao.getTermosDef()[i].getData() <<"] ";
                        cout << "[Preferencia: " << resultadoDefinicao.getTermosDef()[i].getPreferencia()<<"]"<<endl;
                    }
                    cout << endl;
                }
                if(resultadoDefinicao.getValor() == ResultadoDefinicao::FALHA){
                    resultado.setValor(Resultado::FALHA);
                    cout << endl << "Nenhuma definicao foi encontrada." << endl;
                }

                system("PAUSE");
            }
            catch(invalid_argument excecao){
                resultado.setValor(Resultado::FALHA);
                cerr << endl << excecao.what() <<endl;
                return resultado;
            }

        }

        if(opcao == CADASTRAR_DESENV_VOCAB){

            ResultadoEspecifico resultadoEspecifico;
            string nomeVocab;

            cout << "Digite o nome do vocabulario que deseja desenvolver: ";
            cin >> nomeVocab;

            try{

                resultadoEspecifico = link_MA_MS_GestaoVocab->desenvolvedorDeVocab(nomeVocab);

                if(resultadoEspecifico.getValor() == ResultadoEspecifico::SUCESSO){
                    resultado.setValor(Resultado::SUCESSO);
                    cout << "Usuario '"<< email.getEmail() <<"' cadastrado como desenvolvedor de '" << nomeVocab <<"' com sucesso."<<endl<<endl;
                    system("PAUSE");
                }
                if(resultadoEspecifico.getValor() == ResultadoEspecifico::FALHA){
                    resultado.setValor(Resultado::FALHA);
                    cout << "Nenhum vocabulário '" << nomeVocab << "' foi encontrado."<<endl<<endl;
                    system("PAUSE");
                }
                if(resultadoEspecifico.getValor() == ResultadoEspecifico::FALHA_2){
                    resultado.setValor(Resultado::SUCESSO);
                    cout << "O vocabulário '" << nomeVocab << "' já possui o limite de 5 desenvolvedores."<<endl<<endl;
                    system("PAUSE");
                }

            }
            catch(runtime_error excecao){
                resultado.setValor(Resultado::FALHA);
                cerr << endl << excecao.what() <<endl;
                return resultado;
            }

        }
        if(opcao == CRIAR_TERMO){

            ResultadoVocab resultadoVocab;
            string nomeVocab;
            string nomeTermo;
            string dataTermo;
            Termo novoTermo;

            while(true){
                cout << "Digite o nome do vocabulário onde o termo será adicionado: ";
                cin >> nomeVocab;
                cout << "Digite o nome do novo termo: ";
                cin >> nomeTermo;
                cout << "Digite a data do novo termo: ";
                cin >> dataTermo;

                try{
                    novoTermo.setNome(nomeTermo);
                    novoTermo.setData(dataTermo);
                    break;
                }catch(invalid_argument exp){
                    cerr << exp.what() << endl;
                    continue;
                }
            }

            try{

                resultadoVocab = link_MA_MS_GestaoVocab->criarTermo(novoTermo, nomeVocab);

                if(resultadoVocab.getValor() == ResultadoVocab::SUCESSO){
                    resultado.setValor(Resultado::SUCESSO);

                    int numeroTermos = resultadoVocab.getTermos().size();

                    cout << "O novo termo '"<< novoTermo.getNome() <<"' foi adicionado ao vocabulário '" << nomeVocab <<"' com sucesso."<<endl<<endl;

                    cout << " > Nome do vocabulário: " << nomeVocab << endl;
                    cout << " > Termos (" << numeroTermos << "):"<<endl;
                    for(int i=0; i<numeroTermos; i++){
                        cout << "    - '"<< resultadoVocab.getTermos()[i].getNome()  << "'"<< endl;
                    }


                    system("PAUSE");
                }
                if(resultadoVocab.getValor() == ResultadoVocab::FALHA){
                    cout << "O vocabulário '"<< nomeVocab <<"' não existe."<<endl<<endl;
                    system("PAUSE");
                }
                if(resultadoVocab.getValor() == ResultadoVocab::PERMISSAO_NEGADA){
                    cout << "Você não é desenvolvedor do vocabulário '"<< nomeVocab <<"'."<<endl<<endl;
                    system("PAUSE");
                }

            }
            catch (runtime_error exp){
                resultado.setValor(Resultado::FALHA);
                cerr << endl << exp.what() <<endl;
                return resultado;
            }


        }
        if(opcao == EXCLUIR_TERMO){
            ResultadoTermo resultadoTermo;
            string nomeTermo;
            Termo termo;
            while(true){
                cout << "Digite o nome do termo que deseja excluir: ";
                cin >> nomeTermo;
                try{
                    termo.setNome(nomeTermo);
                    break;
                }
                catch(invalid_argument& e){
                    cerr << e.what() << endl;
                    continue;
                }

            }

            try{
                resultadoTermo = link_MA_MS_GestaoVocab->excluirTermo(termo);

                if(resultadoTermo.getValor() == ResultadoVocab::SUCESSO){
                    resultado.setValor(Resultado::SUCESSO);

                    cout << "O termo foi excluido com sucesos" << endl;

                    system("PAUSE");
            }
                if(resultadoTermo.getValor() == ResultadoVocab::FALHA){
                cout << "O termo "<< nomeTermo <<" não existe."<<endl<<endl;
                system("PAUSE");
                }


            }

            catch(runtime_error& e){
                resultado.setValor(Resultado::FALHA);
                cerr << endl << e.what() <<endl;
                return resultado;
            }
        }
        if(opcao == EDITAR_TERMO){
            ResultadoTermo resultadoTermo;
            string nomeOriginal;
            string nomeTermo;
            string dataTermo;
            string classeTermo;
            Termo termoAntigo;
            Termo termoNovo;

            while(true){
                cout << "Digite o nome do termo que gostaria de editar: ";
                cin >> nomeOriginal;
                cout << "Digite o novo nome do termo: ";
                cin >> nomeTermo;
                cout << "Digite a nova data do termo: ";
                cin >> dataTermo;
                cout << "Digite a nova classe do termo: ";
                cin >> classeTermo;

                try{
                    termoNovo.setNome(nomeTermo);
                    termoNovo.setData(dataTermo);
                    termoNovo.setPreferencia(classeTermo);
                    break;
                }
                catch (invalid_argument& e){
                    cerr << e.what() << endl;
                    continue;
                }
            }

                try{
                termoAntigo.setNome(nomeOriginal);

                resultadoTermo = link_MA_MS_GestaoVocab->editarTermo(termoAntigo, termoNovo);

                if(resultadoTermo.getValor() == ResultadoVocab::SUCESSO){
                    resultado.setValor(Resultado::SUCESSO);

                    cout << "O termo foi editado com sucesso" << endl;
                    cout << "Nome do termo: " << resultadoTermo.getTermo().getNome() << endl;
                    cout << "Data do termo: " << resultadoTermo.getTermo().getData() << endl;
                    cout << "Classe do termo: " << resultadoTermo.getTermo().getPreferencia() << endl;


                    system("PAUSE");
                }
                if(resultadoTermo.getValor() == ResultadoVocab::FALHA){
                    cout << "O termo "<< nomeOriginal <<" não existe."<<endl<<endl;
                    system("PAUSE");
                }

            }
            catch (runtime_error exp){
                resultado.setValor(Resultado::FALHA);
                cerr << endl << exp.what() <<endl;
                return resultado;
            }

        }

        if(opcao == CRIAR_DEF_TERMO){

        }
        if(opcao == EXCLUIR_DEF_TERMO){

            Resultado resultadoDefinicao;
            Definicao definicao;
            string textoDef;
            bool correto = false;

            while(true){

                try{
                    fflush(stdin);
                    cout << "Digite o texto da definição que deseja excluir: ";
                    getline(cin,textoDef);
                    fflush(stdin);
                    definicao.setTexto(textoDef);

                    correto = true;
                    break;
                }
                catch(invalid_argument exp){
                    cerr << exp.what() << endl;
                    continue;
                }

            }


            if(correto==true){

                try{
                    resultadoDefinicao = link_MA_MS_GestaoVocab->excluirDefinicao(definicao);

                    if(resultadoDefinicao.getValor() == ResultadoDefinicao::SUCESSO){
                        resultado.setValor(Resultado::SUCESSO);
                        cout << "A definição foi excluida com sucesso."<<endl;
                    }
                    if(resultadoDefinicao.getValor() == ResultadoDefinicao::FALHA){
                        resultado.setValor(Resultado::FALHA);
                        cout << "A definição não foi encontrada."<<endl;
                    }
                    system("PAUSE");
                }
                catch(runtime_error exp){
                    resultado.setValor(Resultado::FALHA);
                    cerr << endl << exp.what() <<endl;
                    system("PAUSE");
                    return resultado;
                }
            }
        }
        if(opcao == EDITAR_DEF_TERMO){

            ResultadoDefinicao resultadoDefinicao;
            Definicao antigaDefinicao;
            Definicao novaDefinicao;
            string antigoTextoDef;
            string novoTextoDef;
            string novaDataDef;
            bool correto = false;

            while(true){

                try{
                    fflush(stdin);
                    cout << "Digite o atual texto da definição que deseja editar: ";
                    getline(cin,antigoTextoDef);
                    fflush(stdin);
                    cout << "Digite o novo texto da definição que deseja editar: ";
                    getline(cin,novoTextoDef);
                    fflush(stdin);
                    cout << "Digite a nova data da definição que deseja editar: ";
                    cin >> novaDataDef;
                    antigaDefinicao.setTexto(antigoTextoDef);
                    novaDefinicao.setTexto(novoTextoDef);
                    novaDefinicao.setData(novaDataDef);

                    correto = true;
                    break;

                }
                catch(invalid_argument exp){
                    cerr << exp.what() << endl;
                    continue;
                }
            }


            if(correto==true){

                try{
                    resultadoDefinicao = link_MA_MS_GestaoVocab->editarDefinicao(antigaDefinicao,novaDefinicao);

                    if(resultadoDefinicao.getValor() == ResultadoDefinicao::SUCESSO){
                        resultado.setValor(Resultado::SUCESSO);
                        cout << "A definição foi alterada com sucesso."<<endl;
                        cout << "Novos dados: "<<endl;
                        cout << " > Texto: "<< resultadoDefinicao.getDefinicao().getTexto() <<endl;
                        cout << " > Data: "<< resultadoDefinicao.getDefinicao().getData() <<endl;
                    }
                    if(resultadoDefinicao.getValor() == ResultadoDefinicao::FALHA){
                        resultado.setValor(Resultado::FALHA);
                        cout << "A definição não foi encontrada."<<endl;
                    }
                    system("PAUSE");
                }
                catch(runtime_error exp){
                    resultado.setValor(Resultado::FALHA);
                    cerr << endl << exp.what() <<endl;
                    system("PAUSE");
                    return resultado;
                }
            }
        }


        if(opcao == SAIR){
            resultado.setValor(Resultado::SUCESSO);
            return resultado;
        }
        if(opcao <0 || opcao>11){
            resultado.setValor(Resultado::FALHA);
            continue;
        }

    }

    return resultado;


}



Resultado ApresentacaoGestaoVocab::executarAdministrador(const Email &email) throw(runtime_error){

    int opcao;
    Resultado resultado;

    const int LISTAR_VOCABS = 1;
    const int MOSTRAR_DADOS = 2;
    const int CONSULTAR_TERMO = 3;
    const int CONSULTAR_DEFINICAO = 4;
    const int CADASTRAR_DESENV_VOCAB = 5;
    const int CRIAR_TERMO = 6;
    const int EDITAR_TERMO = 7;
    const int EXCLUIR_TERMO = 8;
    const int CRIAR_DEF_TERMO = 9;
    const int EDITAR_DEF_TERMO = 10;
    const int EXCLUIR_DEF_TERMO = 11;
    const int CRIAR_VOCAB = 12;
    const int EDITAR_DEF_VOCAB = 13;
    const int ALTERAR_IDIOMA_VOCAB = 14;
    const int EXCLUIR_VOCAB = 15;

    const int SAIR = 0;

    while(true){

        system("CLS");
        cout << "************* ADMINISTRADOR - GESTAO DE VOCABULARIO *************"<<endl<<endl;
        cout << "(1) Listar todos vocabularios" << endl;
        cout << "(2) Exibir dados de um vocabulario" << endl;
        cout << "(3) Consultar termo" << endl;
        cout << "(4) Constultar definicao de termo" << endl;
        cout << "(5) Cadastrar como desenvolvedor de vocabulario controlado" << endl;
        cout << "(6) Criar termo" << endl;
        cout << "(7) Excluir Termo" << endl;
        cout << "(8) Editar Termo" << endl;
        cout << "(9) Criar definicao de termo" << endl;
        cout << "(10) Excluir definicao de termo" << endl;
        cout << "(11) Editar definicao de termo" << endl;
        cout << "(12) Criar vocabulário" << endl;
        cout << "(13) Editar definição do vocabulário" << endl;
        cout << "(14) Alterar idioma do vocabulário" << endl;
        cout << "(15) Excluir vocabulário" << endl;
        cout << "(0) Sair" << endl;
        cout << endl << "Opcao escolhida: ";
        cin >> opcao;
        cout << endl;


        if (opcao == LISTAR_VOCABS){
            int tam;
            ResultadoLista resultadoLista;
            vector<string> listaVocab;

            resultadoLista = link_MA_MS_GestaoVocab->listarVocabs();

            resultado.setValor(Resultado::SUCESSO);

            listaVocab = resultadoLista.listaVocab;

            tam = listaVocab.size();

            cout << endl << "Foram encontrados " << tam << " vocabularios." << endl;

            for(int i=0; i<tam; i++){
                cout <<"> "<<listaVocab[i] << endl;
            }
            cout << endl;
            system("PAUSE");

        }
        if(opcao == MOSTRAR_DADOS){

            string nomeVocab;
            ResultadoVocab resultadoVocab;

            cout << "Digite o nome do vocabulario desejado: ";
            cin >> nomeVocab;
            cout << endl;

            try{

                resultadoVocab = link_MA_MS_GestaoVocab->dadosVocab(nomeVocab);

                if(resultadoVocab.getValor() == ResultadoVocab::SUCESSO){
                    resultado.setValor(Resultado::SUCESSO);

                    int numeroTermos = resultadoVocab.getNomesTermosVocab().size();
                    int numeroDesenv = resultadoVocab.getNomesDesenvolvedores().size();

                    cout << "Dados do Vocabulario: "<<endl;
                    cout << "> Nome: " << resultadoVocab.getVocab().getNome() << endl;
                    cout << "> Idioma: " << resultadoVocab.getVocab().getIdioma() << endl;
                    cout << "> Data: " << resultadoVocab.getVocab().getData() << endl;
                    cout << "> Administrador: " << resultadoVocab.getNomeAdm() << endl;
                    cout << "> Desenvolvedores (" << numeroDesenv << "): "<<endl;
                    for(int i=0; i<numeroDesenv; i++){
                        cout << "    - "<< resultadoVocab.getNomesDesenvolvedores()[i] << endl;
                    }
                    cout << "> Termos (" << numeroTermos << "): "<<endl;
                    for(int i=0; i<numeroTermos; i++){
                        cout << "    - "<< resultadoVocab.getNomesTermosVocab()[i]  << endl;
                    }
                    cout << endl;
                }
                if(resultadoVocab.getValor() == ResultadoVocab::FALHA){
                    resultado.setValor(Resultado::FALHA);
                    cout << endl << "Não há nenhum vocabulário com nome '"<<nomeVocab<<"' registrado. ";
                }

                system("PAUSE");

            }
            catch(invalid_argument excecao){
                resultado.setValor(Resultado::FALHA);
                cerr << endl << excecao.what() <<endl;
                return resultado;
            }

        }
        if(opcao == CONSULTAR_TERMO){

            ResultadoTermo resultadoTermo;
            string nomeTermo;

            cout << "Digite o nome do termo a ser buscado: ";
            cin >> nomeTermo;

            try{
                resultadoTermo = link_MA_MS_GestaoVocab->consultarTermo(nomeTermo);

                if(resultadoTermo.getValor() == ResultadoTermo::SUCESSO){
                    resultado.setValor(Resultado::SUCESSO);

                    int numeroDefinicoes = resultadoTermo.getDefinicoesTermo().size();

                    cout << "Dados do Termo: "<<endl;
                    cout << "> Nome: " << resultadoTermo.getTermo().getNome() << endl;
                    cout << "> Data: " << resultadoTermo.getTermo().getData() << endl;
                    cout << "> Vocabulario: " << resultadoTermo.getNomeVocabTermo() << endl;
                    cout << "> Definicoes (" << numeroDefinicoes << "): "<<endl;
                    for(int i=0; i<numeroDefinicoes; i++){
                        cout << "    - '"<< resultadoTermo.getDefinicoesTermo()[i].getTexto()  << "'"<< endl;
                    }
                    cout << endl;
                }
                if(resultadoTermo.getValor() == Resultado::FALHA){
                    resultado.setValor(Resultado::FALHA);
                    cout << endl << "Não há nenhum termo com nome '"<<nomeTermo<<"' registrado. "<<endl;
                }

                system("PAUSE");
            }
            catch(invalid_argument excecao){
                resultado.setValor(Resultado::FALHA);
                cerr << endl << excecao.what() <<endl;
                return resultado;
            }


        }

        if(opcao == CONSULTAR_DEFINICAO){

            ResultadoDefinicao resultadoDefinicao;
            string textoDef;

            fflush(stdin);
            cout << "Digite um trecho do texto a ser pesquisado: ";
            getline(cin,textoDef);
            fflush(stdin);

            try{
                resultadoDefinicao = link_MA_MS_GestaoVocab->consultarDefinicao(textoDef);

                if(resultadoDefinicao.getValor() == Resultado::SUCESSO){
                    resultado.setValor(Resultado::SUCESSO);

                    int numeroTermosDef = resultadoDefinicao.getTermosDef().size();

                    cout << "> Texto da definicao: '"<< resultadoDefinicao.getDefinicao().getTexto() <<"'"<<endl;
                    cout << "> Data da definicao: " << resultadoDefinicao.getDefinicao().getData() << endl;
                    cout << "> Numero de termos associados (" << numeroTermosDef << "): "  << endl;
                    for(int i=0; i<numeroTermosDef; i++){
                        cout << "     "<<i+1<<") "<< resultadoDefinicao.getTermosDef()[i].getNome();
                        cout << "[Data: " << resultadoDefinicao.getTermosDef()[i].getData() <<"] ";
                        cout << "[Preferencia: " << resultadoDefinicao.getTermosDef()[i].getPreferencia()<<"]"<<endl;
                    }
                    cout << endl;
                }
                if(resultadoDefinicao.getValor() == ResultadoDefinicao::FALHA){
                    resultado.setValor(Resultado::FALHA);
                    cout << endl << "Nenhuma definicao foi encontrada." << endl;
                }

                system("PAUSE");
            }
            catch(invalid_argument excecao){
                resultado.setValor(Resultado::FALHA);
                cerr << endl << excecao.what() <<endl;
                return resultado;
            }

        }

        if(opcao == CADASTRAR_DESENV_VOCAB){

            ResultadoEspecifico resultadoEspecifico;
            string nomeVocab;

            cout << "Digite o nome do vocabulario que deseja desenvolver: ";
            cin >> nomeVocab;

            try{

                resultadoEspecifico = link_MA_MS_GestaoVocab->desenvolvedorDeVocab(nomeVocab);

                if(resultadoEspecifico.getValor() == ResultadoEspecifico::SUCESSO){
                    resultado.setValor(Resultado::SUCESSO);
                    cout << "Usuario '"<< email.getEmail() <<"' cadastrado como desenvolvedor de '" << nomeVocab <<"' com sucesso."<<endl<<endl;
                    system("PAUSE");
                }
                if(resultadoEspecifico.getValor() == ResultadoEspecifico::FALHA){
                    resultado.setValor(Resultado::FALHA);
                    cout << "Nenhum vocabulário '" << nomeVocab << "' foi encontrado."<<endl<<endl;
                    system("PAUSE");
                }
                if(resultadoEspecifico.getValor() == ResultadoEspecifico::FALHA_2){
                    resultado.setValor(Resultado::SUCESSO);
                    cout << "O vocabulário '" << nomeVocab << "' já possui o limite de 5 desenvolvedores."<<endl<<endl;
                    system("PAUSE");
                }

            }
            catch(runtime_error excecao){
                resultado.setValor(Resultado::FALHA);
                cerr << endl << excecao.what() <<endl;
                return resultado;
            }

        }
        if(opcao == CRIAR_TERMO){

            ResultadoVocab resultadoVocab;
            string nomeVocab;
            string nomeTermo;
            string dataTermo;
            Termo novoTermo;

            while(true){
                cout << "Digite o nome do vocabulário onde o termo será adicionado: ";
                cin >> nomeVocab;
                cout << "Digite o nome do novo termo: ";
                cin >> nomeTermo;
                cout << "Digite a data do novo termo: ";
                cin >> dataTermo;

                try{
                    novoTermo.setNome(nomeTermo);
                    novoTermo.setData(dataTermo);
                    break;
                }catch(invalid_argument exp){
                    cerr << exp.what() << endl;
                    continue;
                }
            }

            try{

                resultadoVocab = link_MA_MS_GestaoVocab->criarTermo(novoTermo, nomeVocab);

                if(resultadoVocab.getValor() == ResultadoVocab::SUCESSO){
                    resultado.setValor(Resultado::SUCESSO);

                    int numeroTermos = resultadoVocab.getTermos().size();

                    cout << "O novo termo '"<< novoTermo.getNome() <<"' foi adicionado ao vocabulário '" << nomeVocab <<"' com sucesso."<<endl<<endl;

                    cout << " > Nome do vocabulário: " << nomeVocab << endl;
                    cout << " > Termos (" << numeroTermos << "):"<<endl;
                    for(int i=0; i<numeroTermos; i++){
                        cout << "    - '"<< resultadoVocab.getTermos()[i].getNome()  << "'"<< endl;
                    }


                    system("PAUSE");
                }
                if(resultadoVocab.getValor() == ResultadoVocab::FALHA){
                    cout << "O vocabulário '"<< nomeVocab <<"' não existe."<<endl<<endl;
                    system("PAUSE");
                }
                if(resultadoVocab.getValor() == ResultadoVocab::PERMISSAO_NEGADA){
                    cout << "Você não é desenvolvedor do vocabulário '"<< nomeVocab <<"'."<<endl<<endl;
                    system("PAUSE");
                }

            }
            catch (runtime_error exp){
                resultado.setValor(Resultado::FALHA);
                cerr << endl << exp.what() <<endl;
                return resultado;
            }


        }
        if(opcao == EXCLUIR_TERMO){
            ResultadoTermo resultadoTermo;
            string nomeTermo;
            Termo termo;
            while(true){
                cout << "Digite o nome do termo que deseja excluir: ";
                cin >> nomeTermo;
                try{
                    termo.setNome(nomeTermo);
                    break;
                }
                catch(invalid_argument& e){
                    cerr << e.what() << endl;
                    continue;
                }

            }

            try{
                resultadoTermo = link_MA_MS_GestaoVocab->excluirTermo(termo);

                if(resultadoTermo.getValor() == ResultadoVocab::SUCESSO){
                    resultado.setValor(Resultado::SUCESSO);

                    cout << "O termo foi excluido com sucesos" << endl;

                    system("PAUSE");
            }
                if(resultadoTermo.getValor() == ResultadoVocab::FALHA){
                cout << "O termo "<< nomeTermo <<" não existe."<<endl<<endl;
                system("PAUSE");
                }


            }

            catch(runtime_error& e){
                resultado.setValor(Resultado::FALHA);
                cerr << endl << e.what() <<endl;
                return resultado;
            }
        }
        if(opcao == EDITAR_TERMO){
            ResultadoTermo resultadoTermo;
            string nomeOriginal;
            string nomeTermo;
            string dataTermo;
            string classeTermo;
            Termo termoAntigo;
            Termo termoNovo;

            while(true){
                cout << "Digite o nome do termo que gostaria de editar: ";
                cin >> nomeOriginal;
                cout << "Digite o novo nome do termo: ";
                cin >> nomeTermo;
                cout << "Digite a nova data do termo: ";
                cin >> dataTermo;
                cout << "Digite a nova classe do termo: ";
                cin >> classeTermo;

                try{
                    termoNovo.setNome(nomeTermo);
                    termoNovo.setData(dataTermo);
                    termoNovo.setPreferencia(classeTermo);
                    break;
                }
                catch (invalid_argument& e){
                    cerr << e.what() << endl;
                    continue;
                }
            }

            try{
                termoAntigo.setNome(nomeOriginal);

                resultadoTermo = link_MA_MS_GestaoVocab->editarTermo(termoAntigo, termoNovo);

                if(resultadoTermo.getValor() == ResultadoVocab::SUCESSO){
                    resultado.setValor(Resultado::SUCESSO);

                cout << "O termo foi editado com sucesso" << endl;
                cout << "Nome do termo: " << resultadoTermo.getTermo().getNome() << endl;
                cout << "Data do termo: " << resultadoTermo.getTermo().getData() << endl;
                cout << "Classe do termo: " << resultadoTermo.getTermo().getPreferencia() << endl;


                system("PAUSE");
                }
                    if(resultadoTermo.getValor() == ResultadoVocab::FALHA){
                    cout << "O termo "<< nomeOriginal <<" não existe."<<endl<<endl;
                    system("PAUSE");
                }

            }
            catch (runtime_error exp){
                resultado.setValor(Resultado::FALHA);
                cerr << endl << exp.what() <<endl;
                return resultado;
            }

        }
        if(opcao == CRIAR_DEF_TERMO){

            ResultadoDefinicao resultadoDefinicao;
            Definicao definicao;
            string textoDef;
            string dataDef;

            while(true){
                fflush(stdin);
                cout << "Digite o texto da nova definição: ";
                getline(cin,textoDef);
                fflush(stdin);
                cout << "Digite a data da definição: ";
                cin >> dataDef;

                try{
                    definicao.setTexto(textoDef);
                    definicao.setData(dataDef);
                    break;
                }catch(invalid_argument exp){
                    cerr << exp.what() << endl;
                    continue;
                }
            }

            try{

                resultadoDefinicao = link_MA_MS_GestaoVocab->criarDefinicao(definicao);

                if(resultadoDefinicao.getValor() == ResultadoDefinicao::SUCESSO){
                    resultado.setValor(Resultado::SUCESSO);
                    cout << "A nova definição foi criada com sucesso."<<endl<<endl;

                }
                system("PAUSE");
            }
            catch (runtime_error exp){
                resultado.setValor(Resultado::FALHA);
                cerr << endl << exp.what() <<endl;
                return resultado;
            }

        }

        if(opcao == EXCLUIR_DEF_TERMO){

            Resultado resultadoDefinicao;
            Definicao definicao;
            string textoDef;
            bool correto = false;

            while(true){

                try{
                    fflush(stdin);
                    cout << "Digite o texto da definição que deseja excluir: ";
                    getline(cin,textoDef);
                    fflush(stdin);
                    definicao.setTexto(textoDef);

                    correto = true;
                    break;
                }
                catch(invalid_argument exp){
                    cerr << exp.what() << endl;
                    continue;
                }

            }


            if(correto==true){

                try{
                    resultadoDefinicao = link_MA_MS_GestaoVocab->excluirDefinicao(definicao);

                    if(resultadoDefinicao.getValor() == ResultadoDefinicao::SUCESSO){
                        resultado.setValor(Resultado::SUCESSO);
                        cout << "A definição foi excluida com sucesso."<<endl;
                    }
                    if(resultadoDefinicao.getValor() == ResultadoDefinicao::FALHA){
                        resultado.setValor(Resultado::FALHA);
                        cout << "A definição não foi encontrada."<<endl;
                    }
                    system("PAUSE");
                }
                catch(runtime_error exp){
                    resultado.setValor(Resultado::FALHA);
                    cerr << endl << exp.what() <<endl;
                    system("PAUSE");
                    return resultado;
                }
            }
        }
        if(opcao == EDITAR_DEF_TERMO){

            ResultadoDefinicao resultadoDefinicao;
            Definicao antigaDefinicao;
            Definicao novaDefinicao;
            string antigoTextoDef;
            string novoTextoDef;
            string novaDataDef;
            bool correto = false;

            while(true){

                try{
                    fflush(stdin);
                    cout << "Digite o atual texto da definição que deseja editar: ";
                    getline(cin,antigoTextoDef);
                    fflush(stdin);
                    cout << "Digite o novo texto da definição que deseja editar: ";
                    getline(cin,novoTextoDef);
                    fflush(stdin);
                    cout << "Digite a nova data da definição que deseja editar: ";
                    cin >> novaDataDef;
                    antigaDefinicao.setTexto(antigoTextoDef);
                    novaDefinicao.setTexto(novoTextoDef);
                    novaDefinicao.setData(novaDataDef);

                    correto = true;
                    break;

                }
                catch(invalid_argument exp){
                    cerr << exp.what() << endl;
                    continue;
                }
            }


            if(correto==true){

                try{
                    resultadoDefinicao = link_MA_MS_GestaoVocab->editarDefinicao(antigaDefinicao,novaDefinicao);

                    if(resultadoDefinicao.getValor() == ResultadoDefinicao::SUCESSO){
                        resultado.setValor(Resultado::SUCESSO);
                        cout << "A definição foi alterada com sucesso."<<endl;
                        cout << "Novos dados: "<<endl;
                        cout << " > Texto: "<< resultadoDefinicao.getDefinicao().getTexto() <<endl;
                        cout << " > Data: "<< resultadoDefinicao.getDefinicao().getData() <<endl;
                    }
                    if(resultadoDefinicao.getValor() == ResultadoDefinicao::FALHA){
                        resultado.setValor(Resultado::FALHA);
                        cout << "A definição não foi encontrada."<<endl;
                    }
                    system("PAUSE");
                }
                catch(runtime_error exp){
                    resultado.setValor(Resultado::FALHA);
                    cerr << endl << exp.what() <<endl;
                    system("PAUSE");
                    return resultado;
                }
            }
        }
        if(opcao == CRIAR_VOCAB){

            ResultadoVocab resultadoVocab;
            Vocabulario vocab;
            Definicao defVocab;
            string nomeVocab;
            string idiomaVocab;
            string dataVocab;
            string textoDefVocab;
            bool correto = false;

            while(true){
                try{
                    cout <<endl<<"Digite o nome do novo vocabulário: ";
                    cin >> nomeVocab;
                    vocab.setNome(nomeVocab);
                    cout << "Digite o idioma do novo vocabulário: ";
                    cin >> idiomaVocab;
                    vocab.setIdioma(idiomaVocab);
                    cout << "Digite a data do novo vocabulário: ";
                    cin >> dataVocab;
                    vocab.setData(dataVocab);
                    fflush(stdin);
                    cout << "Digite o texto da definição do vocabulário: ";
                    getline(cin, textoDefVocab);
                    fflush(stdin);
                    defVocab.setTexto(textoDefVocab);
                    defVocab.setData(dataVocab);

                    correto = true;
                    break;
                }
                catch(invalid_argument exp){
                    cerr << exp.what() << ". Tente novamente.";
                    system("PAUSE");
                }
            }

            if (correto == true){

                try{

                    resultadoVocab = link_MA_MS_GestaoVocab->criarVocabulario(vocab,defVocab);

                    if(resultadoVocab.getValor() == ResultadoVocab::SUCESSO){
                        resultado.setValor(Resultado::SUCESSO);

                        cout << endl << "O vocabulário foi criado com sucesso."<< endl<<endl;

                    }
                    if(resultadoVocab.getValor() == ResultadoVocab::FALHA){
                        resultado.setValor(Resultado::FALHA);

                        cout << endl << "Você já atingiu o limite de 5 vocabulários criados."<< endl<<endl;
                    }
                    system("PAUSE");
                }
                catch(runtime_error exp){
                    resultado.setValor(Resultado::FALHA);
                    cerr << endl << exp.what() <<endl;
                    return resultado;
                }
            }

        }


        if(opcao == EDITAR_DEF_VOCAB){

            Resultado resultadoEditar;
            Vocabulario vocab;
            Definicao defVocab;
            string nomeVocab;
            string textoDefVocab;
            string dataDefVocab;
            bool correto = false;

            while(true){
                try{
                    cout <<endl<<"Digite o nome do vocabulário que deseja editar a definição: ";
                    cin >> nomeVocab;
                    vocab.setNome(nomeVocab);
                    fflush(stdin);
                    cout << "Digite o novo texto da definição do vocabulário: ";
                    getline(cin, textoDefVocab);
                    fflush(stdin);
                    defVocab.setTexto(textoDefVocab);
                    cout << "Digite a nova data da definição do vocabulário: ";
                    cin >> dataDefVocab;
                    defVocab.setData(dataDefVocab);

                    correto = true;
                    break;
                }
                catch(invalid_argument exp){
                    cerr << exp.what() << ". Tente novamente.";
                    system("PAUSE");
                }
            }

            if (correto == true){

                try{

                    resultadoEditar = link_MA_MS_GestaoVocab->editarDefinicaoVocab(vocab,defVocab);

                    if(resultadoEditar.getValor() == Resultado::SUCESSO){
                        resultado.setValor(Resultado::SUCESSO);

                        cout << endl <<"A definição foi alterada com sucesso."<< endl<<endl;

                    }
                    if(resultadoEditar.getValor() == Resultado::FALHA){
                        resultado.setValor(Resultado::FALHA);

                        cout << endl <<"O vocabulário inserido não existe."<< endl<<endl;
                    }
                    system("PAUSE");
                }
                catch(runtime_error exp){
                    resultado.setValor(Resultado::FALHA);
                    cerr << endl << exp.what() <<endl;
                    return resultado;
                }
            }

        }
        if(opcao == ALTERAR_IDIOMA_VOCAB){

            Resultado resultadoEditar;
            Vocabulario vocab;
            Idioma idiomaVocab;
            string nomeVocab;
            string siglaIdioma;
            bool correto = false;

            while(true){
                try{
                    cout <<endl<<"Digite o nome do vocabulário que deseja editar o idioma: ";
                    cin >> nomeVocab;
                    vocab.setNome(nomeVocab);
                    cout << "Digite o novo idioma do vocabulário: ";
                    cin >> siglaIdioma;
                    idiomaVocab.setIdioma(siglaIdioma);

                    correto = true;
                    break;
                }
                catch(invalid_argument exp){
                    cerr << exp.what() << ". Tente novamente.";
                    system("PAUSE");
                }
            }

            if (correto == true){

                try{

                    resultadoEditar = link_MA_MS_GestaoVocab->editarIdiomaVocab(vocab,idiomaVocab);

                    if(resultadoEditar.getValor() == Resultado::SUCESSO){
                        resultado.setValor(Resultado::SUCESSO);

                        cout << endl <<"O idioma foi alterado com sucesso."<< endl<<endl;

                    }
                    if(resultadoEditar.getValor() == Resultado::FALHA){
                        resultado.setValor(Resultado::FALHA);

                        cout << endl <<"O vocabulário inserido não existe."<< endl<<endl;
                    }

                    system("PAUSE");
                }
                catch(runtime_error exp){
                    resultado.setValor(Resultado::FALHA);
                    cerr << endl << exp.what() <<endl;
                    return resultado;
                }
            }

        }
        if(opcao == EXCLUIR_VOCAB){

            Resultado resultadoExcluir;
            Vocabulario vocab;
            string nomeVocab;
            bool correto = false;

            while(true){
                try{
                    cout <<endl<<"Digite o nome do vocabulário que deseja excluir: ";
                    cin >> nomeVocab;
                    vocab.setNome(nomeVocab);

                    correto = true;
                    break;
                }
                catch(invalid_argument exp){
                    cerr << exp.what() << ". Tente novamente.";
                    system("PAUSE");
                }
            }

            if (correto == true){

                try{

                    resultadoExcluir = link_MA_MS_GestaoVocab->excluirVocabulario(vocab);

                    if(resultadoExcluir.getValor() == Resultado::SUCESSO){
                        resultado.setValor(Resultado::SUCESSO);

                        cout << endl <<"O vocabulário foi excluído com sucesso."<< endl<<endl;

                    }
                    if(resultadoExcluir.getValor() == Resultado::FALHA){
                        resultado.setValor(Resultado::FALHA);

                        cout << endl <<"O vocabulário digitado não existe."<< endl<<endl;
                    }
                    system("PAUSE");
                }
                catch(runtime_error exp){
                    resultado.setValor(Resultado::FALHA);
                    cerr << endl << exp.what() <<endl;
                    return resultado;
                }
            }
        }

        if(opcao == SAIR){
            resultado.setValor(Resultado::SUCESSO);
            return resultado;
        }
        if(opcao <0 || opcao>15){
            resultado.setValor(Resultado::FALHA);
            continue;
        }

    }

    return resultado;


}
