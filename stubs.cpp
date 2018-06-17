#include "stubs.hpp"

//Definition of the method of the stub class of the logic of service controller of authentication.
ResultadoAutenticacao Stub_MS_Autenticacao::autenticar(const Email &email, const Senha &senha) throw(runtime_error){
    //creating the object to check if the authentication was a success or a failure
    ResultadoAutenticacao resultado;
    //creating objects to put on the result
    Leitor *leitor;
    Desenvolvedor *desenvolvedor;
    Administrador *administrador;

    //Show the received data
    cout << endl << "Stub_IS_Autenticacao::autenticar" << endl ;

    cout << "Email = " << email.getEmail() << endl ;
    cout << "Senha     = " << senha.getSenha()     << endl ;

    //Different behaviors depending from the values of the email
    if (email.getEmail() == TRIGGER_FALHA_EMAIL || senha.getSenha() == TRIGGER_FALHA_SENHA){
        resultado.setValor(ResultadoAutenticacao::FALHA);
    }
    else if(email.getEmail() == TRIGGER_SUCESSO_EMAIL_LEITOR && senha.getSenha() == TRIGGER_SUCESSO_SENHA_LEITOR){
        resultado.setValor(ResultadoAutenticacao::SUCESSO);
        //creating the object leitor inside the object resultado
        resultado.criarLeitor();

        //allocating memory
        leitor = new Leitor();

        //defining the parameters of leitor
        leitor->setNome(NOME_LEITOR);
        leitor->setSobrenome(SOBRENOME_LEITOR);
        leitor->setEmail(email.getEmail());
        leitor->setSenha(senha.getSenha());
        //set leitor
        resultado.setLeitor(*leitor);
        resultado.setTipo(1);

        //deallocating memory
        delete leitor;
    }
    else if(email.getEmail() == TRIGGER_SUCESSO_EMAIL_DESENVOLVEDOR && senha.getSenha() == TRIGGER_SUCESSO_SENHA_DESENVOLVEDOR){
        resultado.setValor(ResultadoAutenticacao::SUCESSO);
        //creating the object desenvolvedor inside the object resultado
        resultado.criarDesenvolvedor();

        //allocating memory
        desenvolvedor = new Desenvolvedor();

        //defining the parameters of desenvolvedor
        desenvolvedor->setNome(NOME_DESENVOLVEDOR);
        desenvolvedor->setSobrenome(SOBRENOME_DESENVOLVEDOR);
        desenvolvedor->setEmail(email.getEmail());
        desenvolvedor->setSenha(senha.getSenha());
        //set leitor
        resultado.setDesenvolvedor(*desenvolvedor);
        resultado.setTipo(2);

        //deallocating memory
        delete desenvolvedor;
    }

    else if(email.getEmail() == TRIGGER_SUCESSO_EMAIL_ADMINISTRADOR && senha.getSenha() == TRIGGER_SUCESSO_SENHA_ADMINISTRADOR){
        resultado.setValor(ResultadoAutenticacao::SUCESSO);
        //creating the object administrador inside the object resultado
        resultado.criarAdministrador();

        //allocating memory
        administrador = new Administrador();

        //defining the parameters of leitor
        administrador->setNome(NOME_ADMINISTRADOR);
        administrador->setSobrenome(SOBRENOME_ADMINISTRADOR);
        administrador->setData(DATA_ADMINISTRADOR);
        administrador->setEndereco(ENDERECO_ADMINISTRADOR);
        administrador->setTelefone(TELEFONE_ADMINISTRADOR);
        administrador->setEmail(email.getEmail());
        administrador->setSenha(senha.getSenha());
        //set administrador
        resultado.setAdministrador(*administrador);
        resultado.setTipo(3);

        //deallocating memory
        delete administrador;
    }

    else if (email.getEmail() == TRIGGER_ERRO_SISTEMA_EMAIL || senha.getSenha() == TRIGGER_ERRO_SISTEMA_SENHA){
        resultado.setValor(ResultadoAutenticacao::FALHA);
        throw runtime_error("ERRO DE SISTEMA");
    }
    else{
        resultado.setValor(ResultadoAutenticacao::FALHA);
        throw runtime_error("TRIGGER INVALIDO");
    }

    return resultado;
}

//Definition of the method of the stub class of the logic of service controller of registering the reader
ResultadoCadastro Stub_MS_Gestao::cadastrarLeitor(const Leitor& leitor) throw(runtime_error){
    //creating the object to check if the registering was a success or a failure
    ResultadoCadastro resultado;

    //Show the received data
    cout << endl << "Stub_IS_Cadastro::cadastrar" << endl ;

    cout << "Nome = " << leitor.getNome() << endl;
    cout << "Sobrenome = " << leitor.getSobrenome() << endl;
    cout << "Email = " << leitor.getEmail() << endl ;
    cout << "Senha = " << leitor.getSenha()     << endl ;

    //Different behaviors depending from the values of the reader
    if (leitor.getNome() == TRIGGER_FALHA_NOME || leitor.getSobrenome() == TRIGGER_FALHA_SOBRENOME ||
        leitor.getEmail() == TRIGGER_FALHA_EMAIL || leitor.getSenha() == TRIGGER_FALHA_SENHA){
        resultado.setValor(ResultadoCadastro::FALHA);
    }
    else if (leitor.getNome() == TRIGGER_SUCESSO_NOME && leitor.getSobrenome() == TRIGGER_SUCESSO_SOBRENOME &&
        leitor.getEmail() == TRIGGER_SUCESSO_EMAIL && leitor.getSenha() == TRIGGER_SUCESSO_SENHA){
        resultado.setValor(ResultadoCadastro::SUCESSO);
        resultado.criarLeitor();
        resultado.setLeitor(leitor);
    }
    else if (leitor.getNome() == TRIGGER_ERRO_SISTEMA_NOME || leitor.getSobrenome() == TRIGGER_ERRO_SISTEMA_SOBRENOME ||
        leitor.getEmail() == TRIGGER_ERRO_SISTEMA_EMAIL || leitor.getSenha() == TRIGGER_ERRO_SISTEMA_SENHA){
        resultado.setValor(ResultadoCadastro::FALHA);
        throw runtime_error("ERRO DE SISTEMA");
    }
    else{
        resultado.setValor(ResultadoCadastro::FALHA);
        throw runtime_error("TRIGGER INVALIDO");
    }

    return resultado;
}

//Definition of the method of the stub class of the logic of service controller of registering the developer
ResultadoCadastro Stub_MS_Gestao::cadastrarDesenvolvedor(const Desenvolvedor& desenvolvedor) throw(runtime_error){
    //creating the object to check if the registering was a success or a failure
    ResultadoCadastro resultado;

    //Show the received data
    cout << endl << "Stub_IS_Cadastro::cadastrar" << endl ;

    cout << "Nome = " << desenvolvedor.getNome() << endl;
    cout << "Sobrenome = " << desenvolvedor.getNome() << endl;
    cout << "Email = " << desenvolvedor.getEmail() << endl ;
    cout << "Senha = " << desenvolvedor.getSenha()     << endl ;
    cout << "Data de nascimento = " << desenvolvedor.getData() << endl;

    //Different behaviors depending from the values of the developer
    if (desenvolvedor.getNome() == TRIGGER_FALHA_NOME || desenvolvedor.getSobrenome() == TRIGGER_FALHA_SOBRENOME ||
        desenvolvedor.getEmail() == TRIGGER_FALHA_EMAIL || desenvolvedor.getSenha() == TRIGGER_FALHA_SENHA ||
        desenvolvedor.getData() == TRIGGER_FALHA_DATA){
        resultado.setValor(ResultadoCadastro::FALHA);
    }
    else if (desenvolvedor.getNome() == TRIGGER_SUCESSO_NOME && desenvolvedor.getSobrenome() == TRIGGER_SUCESSO_SOBRENOME &&
        desenvolvedor.getEmail() == TRIGGER_SUCESSO_EMAIL && desenvolvedor.getSenha() == TRIGGER_SUCESSO_SENHA &&
             desenvolvedor.getData() == TRIGGER_SUCESSO_DATA){
        resultado.setValor(ResultadoCadastro::SUCESSO);
        resultado.setDesenvolvedor(desenvolvedor);
    }
    else if (desenvolvedor.getNome() == TRIGGER_ERRO_SISTEMA_NOME || desenvolvedor.getSobrenome() == TRIGGER_ERRO_SISTEMA_SOBRENOME ||
        desenvolvedor.getEmail() == TRIGGER_ERRO_SISTEMA_EMAIL || desenvolvedor.getSenha() == TRIGGER_ERRO_SISTEMA_SENHA ||
             desenvolvedor.getData() == TRIGGER_ERRO_SISTEMA_DATA){
        resultado.setValor(ResultadoCadastro::FALHA);
        throw runtime_error("ERRO DE SISTEMA");
    }
    else{
        resultado.setValor(ResultadoCadastro::FALHA);
        throw runtime_error("TRIGGER INVALIDO");
    }

    return resultado;
}

//Definition of the method of the stub class of the logic of service controller of registering the administer
ResultadoCadastro Stub_MS_Gestao::cadastrarAdministrador(const Administrador& administrador) throw(runtime_error){
    //creating the object to check if the registering was a success or a failure
    ResultadoCadastro resultado;

    //Show the received data
    cout << endl << "Stub_IS_GestaoUsuario::cadastrar" << endl ;

    cout << "Nome = " << administrador.getNome() << endl;
    cout << "Sobrenome = " << administrador.getNome() << endl;
    cout << "Email = " << administrador.getEmail() << endl ;
    cout << "Senha = " << administrador.getSenha()     << endl ;
    cout << "Data de nascimento = " << administrador.getData() << endl;
    cout << "Telefone = " << administrador.getTelefone() << endl;
    cout << "Endereco = " << administrador.getEndereco() << endl;

    //Different behaviors depending from the values of the administer
    if (administrador.getNome() == TRIGGER_FALHA_NOME || administrador.getSobrenome() == TRIGGER_FALHA_SOBRENOME ||
        administrador.getEmail() == TRIGGER_FALHA_EMAIL || administrador.getSenha() == TRIGGER_FALHA_SENHA ||
        administrador.getData() == TRIGGER_FALHA_DATA || administrador.getTelefone() == TRIGGER_FALHA_TELEFONE ||
        administrador.getEndereco() == TRIGGER_FALHA_ENDERECO){
        resultado.setValor(ResultadoCadastro::FALHA);
    }
    else if (administrador.getNome() == TRIGGER_SUCESSO_NOME && administrador.getSobrenome() == TRIGGER_SUCESSO_SOBRENOME &&
        administrador.getEmail() == TRIGGER_SUCESSO_EMAIL && administrador.getSenha() == TRIGGER_SUCESSO_SENHA &&
             administrador.getData() == TRIGGER_SUCESSO_DATA && administrador.getTelefone() == TRIGGER_SUCESSO_TELEFONE &&
             administrador.getEndereco() == TRIGGER_SUCESSO_ENDERECO){
        resultado.setValor(ResultadoCadastro::SUCESSO);
        resultado.setAdministrador(administrador);
    }
    else if (administrador.getNome() == TRIGGER_ERRO_SISTEMA_NOME || administrador.getSobrenome() == TRIGGER_ERRO_SISTEMA_SOBRENOME ||
        administrador.getEmail() == TRIGGER_ERRO_SISTEMA_EMAIL || administrador.getSenha() == TRIGGER_ERRO_SISTEMA_SENHA ||
             administrador.getData() == TRIGGER_ERRO_SISTEMA_DATA || administrador.getTelefone() == TRIGGER_ERRO_SISTEMA_TELEFONE ||
             administrador.getEndereco() == TRIGGER_ERRO_SISTEMA_ENDERECO){
        resultado.setValor(ResultadoCadastro::FALHA);
        throw runtime_error("ERRO DE SISTEMA");
    }
    else{
        resultado.setValor(ResultadoCadastro::FALHA);
        throw runtime_error("TRIGGER INVALIDO");
    }

    return resultado;
}

Resultado Stub_MS_Gestao::remover(const Email& email) throw(runtime_error){
    //creating the object to check if the removing was a success or a failure
    Resultado resultado;
    //interact with the user if he wants to remove with success or failure
    short opcao;

    while(true){
        cout << endl << "Stub_IS_GestaoUsuario::remover" << endl ;
        cout << "Email = " << email.getEmail() << endl;
        cout << "(1) - Remover com sucesso" << endl;
        cout << "(2) - Remover com falha" << endl;
        cout << "(3) - Erro de sistema" << endl;
        cin >> opcao;

        if (opcao == 1){
            resultado.setValor(Resultado::SUCESSO);
            break;
        }
        else if (opcao == 2){
            resultado.setValor(Resultado::FALHA);
            break;
        }
        else if (opcao == 3){
            resultado.setValor(Resultado::FALHA);
            throw runtime_error("Erro de sistema");
        }
        else{
            cout << "Opcao invalida" << endl;
            cout << "Deseja continuar?" << endl;
            cout << "(1) - SIM" << endl;
            cout << "(2) - NAO" << endl;
            cout << "Escolha: ";
            cin >> opcao;
            if (opcao == 1){
                continue;
            }
            else{
                resultado.setValor(Resultado::CANCELAR);
                break;
            }
        }
    }

    return resultado;
}

//definition of the method to edit the reader
Resultado Stub_MS_Gestao::editarLeitor(const Leitor& leitor) throw(runtime_error){
    //creating the object to check if the edition was a success or a failure
    Resultado resultado;

        cout << endl << "Stub_IS_GestaoUsuario::editarLeitor" << endl ;
        cout << "Nome = " << leitor.getNome() << endl;
        cout << "Sobrenome " << leitor.getSobrenome() << endl;
        cout << "Email = " << leitor.getEmail() << endl;
        cout << "Senha = " << leitor.getSenha() << endl;
        system("pause");

        if (leitor.getNome() == TRIGGER_FALHA_NOME || leitor.getSobrenome() == TRIGGER_FALHA_SOBRENOME ||
            leitor.getEmail() == TRIGGER_FALHA_EMAIL || leitor.getSenha() == TRIGGER_FALHA_SENHA){
            resultado.setValor(Resultado::FALHA);
            }
        else if (leitor.getNome() == TRIGGER_ERRO_SISTEMA_NOME || leitor.getSobrenome() == TRIGGER_ERRO_SISTEMA_SOBRENOME ||
            leitor.getEmail() == TRIGGER_ERRO_SISTEMA_EMAIL || leitor.getSenha() == TRIGGER_ERRO_SISTEMA_SENHA){
            resultado.setValor(Resultado::FALHA);
            throw runtime_error("Erro de sistema");
            }
        else{
            resultado.setValor(Resultado::SUCESSO);
        }

    return resultado;
}

//definition of the method to edit the developer
Resultado Stub_MS_Gestao::editarDesenvolvedor(const Desenvolvedor& desenvolvedor) throw(runtime_error){
    //creating the object to check if the edition was a success or a failure
    Resultado resultado;

        cout << endl << "Stub_IS_GestaoUsuario::editarDesenvolvedor" << endl ;
        cout << "Nome = " << desenvolvedor.getNome() << endl;
        cout << "Sobrenome " << desenvolvedor.getSobrenome() << endl;
        cout << "Email = " << desenvolvedor.getEmail() << endl;
        cout << "Senha = " << desenvolvedor.getSenha() << endl;
        cout << "Data = " << desenvolvedor.getData() << endl;
        system("pause");

        if (desenvolvedor.getNome() == TRIGGER_FALHA_NOME || desenvolvedor.getSobrenome() == TRIGGER_FALHA_SOBRENOME ||
            desenvolvedor.getEmail() == TRIGGER_FALHA_EMAIL || desenvolvedor.getSenha() == TRIGGER_FALHA_SENHA ||
            desenvolvedor.getData() == TRIGGER_FALHA_DATA){
            resultado.setValor(Resultado::FALHA);
            }
        else if (desenvolvedor.getNome() == TRIGGER_ERRO_SISTEMA_NOME || desenvolvedor.getSobrenome() == TRIGGER_ERRO_SISTEMA_SOBRENOME ||
            desenvolvedor.getEmail() == TRIGGER_ERRO_SISTEMA_EMAIL || desenvolvedor.getSenha() == TRIGGER_ERRO_SISTEMA_SENHA ||
                 desenvolvedor.getData() == TRIGGER_ERRO_SISTEMA_DATA){
            resultado.setValor(Resultado::FALHA);
            throw runtime_error("Erro de sistema");
            }
        else{
            resultado.setValor(Resultado::SUCESSO);
        }

    return resultado;
}

//definition of the method to edit the administer
Resultado Stub_MS_Gestao::editarAdministrador(const Administrador& administrador) throw(runtime_error){
    //creating the object to check if the edition was a success or a failure
    Resultado resultado;

        cout << endl << "Stub_IS_GestaoUsuario::editarAdministrador" << endl ;
        cout << "Nome = " << administrador.getNome() << endl;
        cout << "Sobrenome " << administrador.getSobrenome() << endl;
        cout << "Email = " << administrador.getEmail() << endl;
        cout << "Senha = " << administrador.getSenha() << endl;
        cout << "Data = " << administrador.getData() << endl;
        cout << "Endereco = " << administrador.getEndereco() << endl;
        cout << "Telefone = " << administrador.getTelefone() << endl;
        system("pause");

        if (administrador.getNome() == TRIGGER_FALHA_NOME || administrador.getSobrenome() == TRIGGER_FALHA_SOBRENOME ||
            administrador.getEmail() == TRIGGER_FALHA_EMAIL || administrador.getSenha() == TRIGGER_FALHA_SENHA ||
            administrador.getData() == TRIGGER_FALHA_DATA || administrador.getEndereco() == TRIGGER_FALHA_ENDERECO ||
            administrador.getTelefone() == TRIGGER_FALHA_TELEFONE){
            resultado.setValor(Resultado::FALHA);
            }
        else if (administrador.getNome() == TRIGGER_ERRO_SISTEMA_NOME || administrador.getSobrenome() == TRIGGER_ERRO_SISTEMA_SOBRENOME ||
            administrador.getEmail() == TRIGGER_ERRO_SISTEMA_EMAIL || administrador.getSenha() == TRIGGER_ERRO_SISTEMA_SENHA ||
                 administrador.getData() == TRIGGER_ERRO_SISTEMA_DATA || administrador.getEndereco() == TRIGGER_ERRO_SISTEMA_ENDERECO ||
                 administrador.getTelefone() == TRIGGER_ERRO_SISTEMA_TELEFONE){
            resultado.setValor(Resultado::FALHA);
            throw runtime_error("Erro de sistema");
            }
        else{
            resultado.setValor(Resultado::SUCESSO);
        }

    return resultado;
}

///
///
///



ResultadoLista Stub_MS_GestaoVocab::listarVocabs() throw(runtime_error){

    vector<string> lista;
    int opcao;
    ResultadoLista resultado;

    cout << "Stub_MS_GestaoVocab::listarVocabs()" <<endl<<endl;

    cout << "Que caso deseja testar?"<<endl;
    cout << "(1) Lista nao vazia \n(2) Lista vazia \n(3) Erro de sistema"<<endl;
    cout << "Escolha: ";
    cin >> opcao;
    cout << endl;

    if(opcao==1){

        lista.push_back(vocabTeste1.getNome());
        lista.push_back(vocabTeste2.getNome());
        lista.push_back(vocabTeste3.getNome());
        lista.push_back(vocabTeste4.getNome());

        resultado.listaVocab = lista;
        resultado.setValor(Resultado::SUCESSO);
    }
    if(opcao==2){
        lista.clear();
        resultado.listaVocab = lista;
        resultado.setValor(Resultado::SUCESSO);
    }
    if(opcao==3){
        resultado.setValor(Resultado::FALHA);
        throw runtime_error("ERRO DE SISTEMA");
    }
    if(opcao!=1 && opcao!=2 && opcao!=3){
        cout << "Opcao invalida."<<endl;
        resultado.setValor(Resultado::SUCESSO);
    }

    return resultado;
}

ResultadoVocab Stub_MS_GestaoVocab::dadosVocab (const string &nomeVocab) throw(runtime_error){

    ResultadoVocab resultado;

    if(nomeVocab == vocabTeste1.getNome()){

        string nomeAdm = TRIGGER_NOME_ADMIN_VOCAB;
        vector<string> nomesTermosVocab;
        vector<string> nomesDesenvolvedores;

        nomesTermosVocab.push_back(termoTeste1.getNome());
        nomesTermosVocab.push_back(termoTeste2.getNome());
        nomesTermosVocab.push_back(termoTeste3.getNome());

        nomesDesenvolvedores.push_back(TRIGGER_NOME_DESENVOLVEDOR_1_VOCAB);
        nomesDesenvolvedores.push_back(TRIGGER_NOME_DESENVOLVEDOR_2_VOCAB);

        resultado.setDados(nomeAdm, nomesTermosVocab, nomesDesenvolvedores);

        resultado.setVocab(vocabTeste1);
        resultado.setValor(Resultado::SUCESSO);

        return resultado;
    }
    else if(nomeVocab == vocabTeste2.getNome()){
        resultado.setValor(Resultado::FALHA);
        return resultado;
    }
    else if(nomeVocab == vocabTeste3.getNome()){
        throw runtime_error("ERRO DE SISTEMA");
    }
    else{
        cout << "Trigger inválido! Os triggers válidos são:" << endl;
        cout << "SUCESSO:          '" << vocabTeste1.getNome() << "'" << endl;
        cout << "FALHA:            '" << vocabTeste2.getNome() << "'" << endl;
        cout << "ERRO DE SISTEMA:  '" << vocabTeste3.getNome() << "'" << endl;
        return resultado;
    }

}

ResultadoTermo Stub_MS_GestaoVocab::consultarTermo(const string& nomeTermo) throw(runtime_error){

    ResultadoTermo resultado;

    if(nomeTermo == termoTeste1.getNome()){
        string nomeVocabTermo = vocabTeste1.getNome();
        vector<Definicao> nomesDefinicoesTermo;

        nomesDefinicoesTermo.push_back(defTeste1);
        nomesDefinicoesTermo.push_back(defTeste2);

        resultado.setDados(nomeVocabTermo, nomesDefinicoesTermo);

        resultado.setTermo(termoTeste1);
        resultado.setValor(Resultado::SUCESSO);

    }
    else if(nomeTermo == termoTeste2.getNome()){
        resultado.setValor(Resultado::FALHA);
    }
    else if(nomeTermo == termoTeste3.getNome()){
        throw runtime_error("ERRO DE SISTEMA");
    }
    else{
        cout << "Trigger inválido! Os triggers válidos são:" << endl;
        cout << "SUCESSO:          '" << termoTeste1.getNome() << "'" << endl;
        cout << "FALHA:            '" << termoTeste2.getNome() << "'" << endl;
        cout << "ERRO DE SISTEMA:  '" << termoTeste3.getNome() << "'" << endl;
    }

    return resultado;
}

ResultadoDefinicao Stub_MS_GestaoVocab::consultarDefinicao(const string& textoDef) throw(runtime_error){

    ResultadoDefinicao resultado;

    size_t found1 = defTeste1.getTexto().find(textoDef);
    size_t found2 = defTeste2.getTexto().find(textoDef);
    size_t found3 = defTeste3.getTexto().find(textoDef);


    if( found2 != string::npos ){
        vector<Termo> termosDef;

        termosDef.push_back(termoTeste1);
        termosDef.push_back(termoTeste3);

        resultado.setDados(termosDef);

        resultado.setDefinicao(defTeste2);
        resultado.setValor(Resultado::SUCESSO);

    }
    else if(found1 != string::npos){
        resultado.setValor(Resultado::FALHA);
    }
    else if(found3 != string::npos){
        throw runtime_error("ERRO DE SISTEMA");
    }
    else{
        cout << "Trigger inválido! Os triggers válidos são:" << endl;
        cout << "SUCESSO:          '" << defTeste2.getTexto() << "'" << endl;
        cout << "FALHA:            '" << defTeste1.getTexto() << "'" << endl;
        cout << "ERRO DE SISTEMA:  '" << defTeste3.getTexto() << "'" << endl;
    }

    return resultado;
}

ResultadoEspecifico Stub_MS_GestaoVocab::desenvolvedorDeVocab(const string &nomeVocab) throw(runtime_error){

    ResultadoEspecifico resultado;

    if(nomeVocab == vocabTeste1.getNome()){
        resultado.setValor(ResultadoEspecifico::SUCESSO);
    }
    else if(nomeVocab == vocabTeste2.getNome()){
        resultado.setValor(ResultadoEspecifico::FALHA);
    }
    else if(nomeVocab == vocabTeste3.getNome()){
        resultado.setValor(ResultadoEspecifico::FALHA_2);
    }
    else if(nomeVocab == vocabTeste4.getNome()){
        throw runtime_error("ERRO DE SISTEMA");
    }
    else{
        cout << "Trigger inválido! Os triggers válidos são:" << endl;
        cout << "SUCESSO:          '" << vocabTeste1.getNome() << "'" << endl;
        cout << "FALHA:            '" << vocabTeste2.getNome() << "'" << endl;
        cout << "LIMITE EXCEDIDO:  '" << vocabTeste3.getNome() << "'" << endl;
        cout << "ERRO DE SISTEMA:  '" << vocabTeste4.getNome() << "'" << endl;
    }
    return resultado;
}

ResultadoVocab Stub_MS_GestaoVocab::criarTermo(const Termo& novoTermo, const string &nomeVocab) throw(runtime_error){

    ResultadoVocab resultado;

    if(nomeVocab == vocabTeste1.getNome()){

        vector<Termo> termosVocab;

        termosVocab.push_back(termoTeste1);
        termosVocab.push_back(termoTeste2);
        termosVocab.push_back(termoTeste3);

        termosVocab.push_back(novoTermo);

        resultado.setTermos(termosVocab);
        resultado.setValor(ResultadoVocab::SUCESSO);
    }
    else if(nomeVocab == vocabTeste2.getNome()){
        resultado.setValor(ResultadoVocab::FALHA);
    }
    else if(nomeVocab == vocabTeste3.getNome()){
        resultado.setValor(ResultadoVocab::PERMISSAO_NEGADA);
    }
    else if(nomeVocab == vocabTeste4.getNome()){
        throw runtime_error("ERRO DE SISTEMA");
    }
    else{
        cout << "Trigger inválido! Os triggers válidos são:" << endl;
        cout << "SUCESSO:          '" << vocabTeste1.getNome() << "'" << endl;
        cout << "FALHA:            '" << vocabTeste2.getNome() << "'" << endl;
        cout << "PERMISSAO NEGADA  '" << vocabTeste3.getNome() << "'" << endl;
        cout << "ERRO DE SISTEMA:  '" << vocabTeste4.getNome() << "'" << endl;
    }
    return resultado;
}

ResultadoTermo Stub_MS_GestaoVocab::editarTermo(const Termo& termo, const Termo& novoTermo) throw(runtime_error){

    ResultadoTermo resultado;

    if(termo.getNome() == termoTeste1.getNome()){
        string nomeVocabTermo = vocabTeste1.getNome();
        vector<Definicao> nomesDefinicoesTermo;

        nomesDefinicoesTermo.push_back(defTeste1);
        nomesDefinicoesTermo.push_back(defTeste2);

        resultado.setTermo(novoTermo);
        resultado.setValor(ResultadoTermo::SUCESSO);
    }
    else if(termo.getNome() == termoTeste2.getNome()){
        resultado.setValor(Resultado::FALHA);
    }
    else if(termo.getNome() == termoTeste3.getNome()){
        throw runtime_error("ERRO DE SISTEMA");
    }
    else{
        cout << "Trigger inválido! Os triggers válidos são:" << endl;
        cout << "SUCESSO:          '" << termoTeste1.getNome() << "'" << endl;
        cout << "FALHA:            '" << termoTeste2.getNome() << "'" << endl;
        cout << "ERRO DE SISTEMA:  '" << termoTeste3.getNome() << "'" << endl;
    }

    return resultado;
}

ResultadoTermo Stub_MS_GestaoVocab::excluirTermo(const Termo& termo) throw(runtime_error){

    ResultadoTermo resultado;

    if(termo.getNome() == termoTeste1.getNome()){
        resultado.setValor(ResultadoTermo::SUCESSO);
    }
    else if(termo.getNome() == termoTeste2.getNome()){
        resultado.setValor(Resultado::FALHA);
    }
    else if(termo.getNome() == termoTeste3.getNome()){
        throw runtime_error("ERRO DE SISTEMA");
    }
    else{
        cout << "Trigger inválido! Os triggers válidos são:" << endl;
        cout << "SUCESSO:          '" << termoTeste1.getNome() << "'" << endl;
        cout << "FALHA:            '" << termoTeste2.getNome() << "'" << endl;
        cout << "ERRO DE SISTEMA:  '" << termoTeste3.getNome() << "'" << endl;
    }

    return resultado;
}

ResultadoDefinicao Stub_MS_GestaoVocab::criarDefinicao(const Definicao& definicao) throw(runtime_error){

    ResultadoDefinicao resultado;

    resultado.setValor(ResultadoVocab::SUCESSO);

    return resultado;
}

ResultadoDefinicao Stub_MS_GestaoVocab::editarDefinicao(const Definicao& antigaDef, const Definicao& novaDef) throw(runtime_error){

    ResultadoDefinicao resultado;

    size_t found1 = defTeste1.getTexto().find(antigaDef.getTexto());
    size_t found2 = defTeste2.getTexto().find(antigaDef.getTexto());
    size_t found3 = defTeste3.getTexto().find(antigaDef.getTexto());


    if( found1 != string::npos ){
        defTeste1.setTexto(novaDef.getTexto());
        defTeste1.setData(novaDef.getData());

        resultado.setDefinicao(defTeste1);
        resultado.setValor(ResultadoVocab::SUCESSO);
    }
    else if( found2 != string::npos ){
        resultado.setValor(ResultadoVocab::FALHA);
    }
    else if( found3 != string::npos ){
        throw runtime_error("ERRO DE SISTEMA");
    }
    else{
        cout << "Trigger inválido! Os triggers válidos são:" << endl;
        cout << "SUCESSO:          '" << defTeste1.getTexto() << "'" << endl;
        cout << "FALHA:            '" << defTeste2.getTexto() << "'" << endl;
        cout << "ERRO DE SISTEMA:  '" << defTeste3.getTexto() << "'" << endl;
    }
    return resultado;
}

Resultado Stub_MS_GestaoVocab::excluirDefinicao(const Definicao& definicao) throw(runtime_error){

    Resultado resultado;

    size_t found1 = defTeste1.getTexto().find(definicao.getTexto());
    size_t found2 = defTeste2.getTexto().find(definicao.getTexto());
    size_t found3 = defTeste3.getTexto().find(definicao.getTexto());

    if( found1 != string::npos ){
        resultado.setValor(ResultadoVocab::SUCESSO);
    }
    else if( found2 != string::npos ){
        resultado.setValor(ResultadoVocab::FALHA);
    }
    else if( found3 != string::npos ){
        throw runtime_error("ERRO DE SISTEMA");
    }
    else{
        cout << "Trigger inválido! Os triggers válidos são:" << endl;
        cout << "SUCESSO:          '" << defTeste1.getTexto() << "'" << endl;
        cout << "FALHA:            '" << defTeste2.getTexto() << "'" << endl;
        cout << "ERRO DE SISTEMA:  '" << defTeste3.getTexto() << "'" << endl;
    }
    return resultado;
}

ResultadoVocab Stub_MS_GestaoVocab::criarVocabulario(const Vocabulario& vocab, const Definicao& defVocab) throw(runtime_error){

    ResultadoVocab resultado;

    if( vocab.getNome() == TRIGGER_NOME_NOVO_VOCAB_SUCESSO ){
        resultado.setValor(ResultadoVocab::SUCESSO);
    }
    else if( vocab.getNome() == TRIGGER_NOME_NOVO_VOCAB_FALHA ){
        resultado.setValor(ResultadoVocab::FALHA);
    }
    else if( vocab.getNome() == TRIGGER_NOME_NOVO_VOCAB_ERRO ){
        throw runtime_error("ERRO DE SISTEMA");
    }
    else{
        cout << "Trigger inválido! Os triggers válidos são:" << endl;
        cout << "SUCESSO:          '" << TRIGGER_NOME_NOVO_VOCAB_SUCESSO << "'" << endl;
        cout << "FALHA:            '" << TRIGGER_NOME_NOVO_VOCAB_FALHA   << "'" << endl;
        cout << "ERRO DE SISTEMA:  '" << TRIGGER_NOME_NOVO_VOCAB_ERRO    << "'" << endl;
    }
    return resultado;
}

Resultado Stub_MS_GestaoVocab::editarDefinicaoVocab(const Vocabulario& vocab, const Definicao& defVocab) throw(runtime_error){

    Resultado resultado;

    if( vocab.getNome() == TRIGGER_NOME_NOVO_VOCAB_SUCESSO ){
        resultado.setValor(ResultadoEspecifico::SUCESSO);
    }
    else if( vocab.getNome() == TRIGGER_NOME_NOVO_VOCAB_FALHA ){
        resultado.setValor(ResultadoEspecifico::FALHA);
    }
    else if( vocab.getNome() == TRIGGER_NOME_NOVO_VOCAB_ERRO ){
        throw runtime_error("ERRO DE SISTEMA");
    }
    else{
        cout << "Trigger inválido! Os triggers válidos são:" << endl;
        cout << "SUCESSO:           '" << TRIGGER_NOME_NOVO_VOCAB_SUCESSO << "'" << endl;
        cout << "VOCAB INEXISTENTE: '" << TRIGGER_NOME_NOVO_VOCAB_FALHA   << "'" << endl;
        cout << "ERRO DE SISTEMA:   '" << TRIGGER_NOME_NOVO_VOCAB_ERRO    << "'" << endl;
    }
    return resultado;
}

Resultado Stub_MS_GestaoVocab::editarIdiomaVocab(const Vocabulario& vocab, const Idioma& idioma) throw(runtime_error){

    Resultado resultado;

    if( vocab.getNome() == TRIGGER_NOME_NOVO_VOCAB_SUCESSO ){
        resultado.setValor(Resultado::SUCESSO);
    }
    else if( vocab.getNome() == TRIGGER_NOME_NOVO_VOCAB_FALHA ){
        resultado.setValor(Resultado::FALHA);
    }
    else if( vocab.getNome() == TRIGGER_NOME_NOVO_VOCAB_ERRO ){
        throw runtime_error("ERRO DE SISTEMA");
    }
    else{
        cout << "Trigger inválido! Os triggers válidos são:" << endl;
        cout << "SUCESSO:           '" << TRIGGER_NOME_NOVO_VOCAB_SUCESSO << "'" << endl;
        cout << "VOCAB INEXISTENTE: '" << TRIGGER_NOME_NOVO_VOCAB_FALHA   << "'" << endl;
        cout << "ERRO DE SISTEMA:   '" << TRIGGER_NOME_NOVO_VOCAB_ERRO    << "'" << endl;
    }
    return resultado;
}

Resultado Stub_MS_GestaoVocab::excluirVocabulario(const Vocabulario& vocab) throw(runtime_error){

    Resultado resultado;

    if( vocab.getNome() == TRIGGER_NOME_NOVO_VOCAB_SUCESSO ){
        resultado.setValor(ResultadoEspecifico::SUCESSO);
    }
    else if( vocab.getNome() == TRIGGER_NOME_NOVO_VOCAB_FALHA ){
        resultado.setValor(ResultadoEspecifico::FALHA);
    }
    else if( vocab.getNome() == TRIGGER_NOME_NOVO_VOCAB_ERRO ){
        throw runtime_error("ERRO DE SISTEMA");
    }
    else{
        cout << "Trigger inválido! Os triggers válidos são:" << endl;
        cout << "SUCESSO:           '" << TRIGGER_NOME_NOVO_VOCAB_SUCESSO << "'" << endl;
        cout << "VOCAB INEXISTENTE: '" << TRIGGER_NOME_NOVO_VOCAB_FALHA   << "'" << endl;
        cout << "ERRO DE SISTEMA:   '" << TRIGGER_NOME_NOVO_VOCAB_ERRO    << "'" << endl;
    }
    return resultado;
}
