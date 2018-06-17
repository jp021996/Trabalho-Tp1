#include "controladores.hpp"
#include "stubs.hpp"

//definition of the method to get the data after the login
void Controle::getDadosLogin(){
        cout << endl << "email: " << emailUsuario->getEmail() << endl;
        cout << "senha: " << senhaUsuario->getSenha() << endl;
}

//definition of the method to get the informations of the reader
//after the registering
void Controle::getDadosCadastroLeitor(){
    cout << "DADOS CADASTRADOS" << endl;
    cout << "Nome: " << leitor->getNome() << endl;
    cout << "Sobrenome: " << leitor->getSobrenome() << endl;
    cout << "Email: " << leitor->getEmail() << endl;
    cout << "Senha: " << leitor->getSenha() << endl;
}

//definition of the method to get the informations of the developer
//after the registering
void Controle::getDadosCadastroDesenvolvedor(){
    cout << "DADOS CADASTRADOS" << endl;
    cout << "Nome: " << desenvolvedor->getNome() << endl;
    cout << "Sobrenome: " << desenvolvedor->getSobrenome() << endl;
    cout << "Email: " << desenvolvedor->getEmail() << endl;
    cout << "Senha: " << desenvolvedor->getSenha() << endl;
    cout << "Data de nascimento: " << desenvolvedor->getData() << endl;
}

//definition of the method to get the informations of the administer
//after the registering
void Controle::getDadosCadastroAdministrador(){
    cout << "DADOS CADASTRADOS" << endl;
    cout << "Nome: " << administrador->getNome() << endl;
    cout << "Sobrenome: " << administrador->getSobrenome() << endl;
    cout << "Email: " << administrador->getEmail() << endl;
    cout << "Senha: " << administrador->getSenha() << endl;
    cout << "Data de nascimento: " << administrador->getData() << endl;
    cout << "Telefone: " << administrador->getTelefone() << endl;
    cout << "Endereco: " << administrador->getEndereco() << endl;
}

//definition of the method that executes the program
//after the user authenticates
void Controle::executar(ResultadoAutenticacao& autenticado){
    //the option of the user
    short opcao;
    //check if the operation was a success or a failure
    Resultado resultado;

    while (true){
        system("cls");
        cout << "Usuario autenticado" << endl << endl;
        cout << "(1) - Gerenciar Conta" << endl;
        cout << "(2) - Gerenciar Vocabulario" << endl;
        cout << "(0) - Sair" << endl;
        cout << endl << "Escolha: ";
        cin >> opcao;

        //management of account
        if (opcao == 1){
            //the interfaces between the modules of control and user management
            IA_GestaoUsuario *link_ctrl_MA_GestaoUsuario = new ApresentacaoGestao();
            IS_GestaoUsuario *link_MA_MS_GestaoUsuario = new ServicoGestao();

            //create the link between the presentation module and the service module
            link_ctrl_MA_GestaoUsuario->setLink_MA_MS_GestaoUsuario(link_MA_MS_GestaoUsuario);

            try{
                resultado = link_ctrl_MA_GestaoUsuario->executar(autenticado);
            }
            catch (runtime_error& e){
                cerr << e.what() << endl;
            }

            if (resultado.getValor() == Resultado::SUCESSO){
                cout << "Conta gerenciada com sucesso" << endl;

                //deallocating the interfaces
                delete link_ctrl_MA_GestaoUsuario;
                delete link_MA_MS_GestaoUsuario;

                continue;
            }

            //check if the user wants to try again if the management is a failure
            else if (resultado.getValor() == Resultado::FALHA){
                cout << "Falha no gerenciamento de vocabulario" << endl;
                cout << "Deseja tentar novamente? " << endl;
                cout << "(1) - Sim" << endl;
                cout << "(2) - Nao" << endl;
                cout << "Digite a opcao: ";
                cin >> opcao;

                //go to the loop again
                if (opcao == 1){
                    //deallocating the interfaces
                    delete link_ctrl_MA_GestaoUsuario;
                    delete link_MA_MS_GestaoUsuario;

                    continue;
                 }
                 //leaving the execute method
                 else{
                    //deallocating the interfaces
                    delete link_ctrl_MA_GestaoUsuario;
                    delete link_MA_MS_GestaoUsuario;

                    break;
                 }
            }
            else{
                //deallocating the interfaces
                delete link_ctrl_MA_GestaoUsuario;
                delete link_MA_MS_GestaoUsuario;

                break;
            }
        }
        if(opcao == 2){
                        //the interfaces between the modules of control and user management
            IA_GestaoVocab *link_ctrl_MA_GestaoVocab = new ApresentacaoGestaoVocab();
            IS_GestaoVocab *link_MA_MS_GestaoVocab = new ServicoGestaoVocab();


            //create the link between the presentation module and the service module
            link_ctrl_MA_GestaoVocab->setLink_MA_MS_GestaoVocab(link_MA_MS_GestaoVocab);

            try{
                resultado = link_ctrl_MA_GestaoVocab->executar(autenticado);
            }
            catch (runtime_error& e){
                cerr << e.what() << endl;
            }

            if (resultado.getValor() == Resultado::SUCESSO){
                cout << "Gestao de vocabularios feita com sucesso. " << endl;

                //deallocating the interfaces
                delete link_ctrl_MA_GestaoVocab;
                delete link_MA_MS_GestaoVocab;

                continue;
            }

            //check if the user wants to try again if the management is a failure
            else if (resultado.getValor() == Resultado::FALHA){
                cout << "Falha no gerenciamento da vocabularios. Realizando Logout." << endl;
                cout << "Deseja tentar novamente? " << endl;
                cout << "(1) - Sim" << endl;
                cout << "(2) - Nao" << endl;
                cout << "Digite a opcao: ";
                cin >> opcao;

                //go to the loop again
                if (opcao == 1){
                    //deallocating the interfaces
                    delete link_ctrl_MA_GestaoVocab;
                    delete link_MA_MS_GestaoVocab;

                    continue;
                 }
                 //leaving the execute method
                 else{
                    //deallocating the interfaces
                    delete link_ctrl_MA_GestaoVocab;
                    delete link_MA_MS_GestaoVocab;

                    break;
                 }
            }
            else{
                //deallocating the interfaces
                delete link_ctrl_MA_GestaoVocab;
                delete link_MA_MS_GestaoVocab;

                break;
            }

        } // end if (opcao==2)
        if(opcao == 0){

            cout << "Realizando Lougout. ";
            system("PAUSE");
            break;
        }
        if(opcao <0 || opcao>2){
            cout << "Opcao invalida. ";
            system("PAUSE");
            continue;
        }
    }

}

//definition of the method login
ResultadoAutenticacao Controle::login(){
    //link between the module of control and
    //the modules of authentication of the user and the stub
    IA_Autenticacao *link_ctrl_MA_Autenticacao = new OpcaoAutenticar();
    IS_Autenticacao *link_MA_MS_Autenticacao = new ServicoAutenticar();

    //Link between the module of control of authentication and its stub
    link_ctrl_MA_Autenticacao->setLink_MA_MS_Autenticacao(link_MA_MS_Autenticacao);

    //creating the object resultado to check if the authentication occurred with success or failure
    ResultadoAutenticacao resultado;

    while(true){
        //Simulate the presentation screen (the initial screen) of the system
        try{
            //illustrate the solicitation of the service of authentication
            resultado = link_ctrl_MA_Autenticacao->autenticar(*emailUsuario,*senhaUsuario);
        }
        catch(const runtime_error &exp){
            cout << "Erro de sistema." << endl;
            system("pause");
        }
        // Check the authentication result
        if(resultado.getValor() == ResultadoAutenticacao::SUCESSO || resultado.getValor() == ResultadoAutenticacao::CANCELAR ||
           resultado.getValor() == ResultadoAutenticacao::FALHA) {
            break;
        }
    }

    //deallocate the memory of the interfaces
    delete link_ctrl_MA_Autenticacao;
    delete link_MA_MS_Autenticacao;

    return resultado;
}

//method to initialize the program
ResultadoInicializacao Controle::inicializar(){
    //the option of the user
    int opcao;

    //the objects that will define the result of
    //initialization, authentication and the user register
    ResultadoInicializacao resultadoInicializacao;
    ResultadoAutenticacao resultadoAutenticacao;
    ResultadoCadastro resultadoCadastro;

    //clean the screen
    system("cls");
    //showing the initial menu to the user and get the option
    cout << "***** INICIALIZANDO PROGRAMA ***** " << endl << endl;
    cout << "(1) Login " << endl << "(2) Cadastrar" << endl << "(0) Sair" << endl;
    cout << "Opcao escolhida: ";
    cin >> opcao;

    //start the execution of the program
    while(true){
        switch(opcao){
        //the default if the login, even if the user types an different option
        //than the specified
            default:
                //allocate memory to the objects of the user
                emailUsuario = new Email();
                senhaUsuario = new Senha();

                //get the result of the authentication
                resultadoAutenticacao = login();

                //if the login is a success, the initialization is a success too
                if (resultadoAutenticacao.getValor()==ResultadoAutenticacao::SUCESSO){
                    resultadoInicializacao.setValor(Resultado::SUCESSO);
                }
                //if the login is a failure or it was canceled, the initialization is a failure
                if (resultadoAutenticacao.getValor()==ResultadoAutenticacao::FALHA || resultadoAutenticacao.getValor()==ResultadoAutenticacao::CANCELAR){
                    resultadoInicializacao.setValor(Resultado::FALHA);
                }

                if(resultadoAutenticacao.getValor() == ResultadoAutenticacao::SUCESSO){

                    executar(resultadoAutenticacao);

                }

                //deallocate the memory of the user objects
                delete emailUsuario;
                delete senhaUsuario;

                break;

        //register the user
        case CADASTRO:
            //do the register of the user and get the result
            resultadoCadastro = cadastrar();

                //if the registering is a success, the initialization is a success
                if(resultadoCadastro.getValor()==ResultadoAutenticacao::SUCESSO){
                    resultadoInicializacao.setValor(Resultado::SUCESSO);
                }
                //if the registering is a failure, the initialization is a failure
                if(resultadoCadastro.getValor()==ResultadoCadastro::FALHA || resultadoCadastro.getValor()==ResultadoCadastro::CANCELAR){
                    resultadoInicializacao.setValor(Resultado::FALHA);
                }

                break;


        case SAIR:
            resultadoInicializacao.setValor(Resultado::SUCESSO);
            resultadoInicializacao.setSair(true);
            break;
        }

        if (resultadoInicializacao.getValor()==ResultadoInicializacao::SUCESSO || resultadoAutenticacao.getValor()==ResultadoAutenticacao::CANCELAR ||
            resultadoCadastro.getValor() == ResultadoCadastro::CANCELAR)
            break;
    }

    return resultadoInicializacao;


}

//definition of the method to register the user
ResultadoCadastro Controle::cadastrar(){
    //link between the module of control and
    //the modules of authentication of the user and the stub
    IA_GestaoUsuario *link_ctrl_MA_GestaoUsuario = new ApresentacaoGestao();
    IS_GestaoUsuario *link_MA_MS_GestaoUsuario = new ServicoGestao();
    //the type of account
    int tipoConta;
    //the object to define the result of the registering
    ResultadoCadastro resultado;

    //Link between the module of control of authentication and its stub
    link_ctrl_MA_GestaoUsuario->setLink_MA_MS_GestaoUsuario(link_MA_MS_GestaoUsuario);

    //start of registering
    while(true){
        //clean the screen
        system("cls");
        cout << "**********  GESTOR DE VOCABULÁRIOS CONTROLADOS  **********" << endl;
        cout << "**********              CRIAR CONTA             **********" << endl << endl;

        //get from the user the type of account
        cout << "Tipos de conta:"<<endl;
        cout << "(1)Leitor" << endl;
        cout << "(2)Desenvolvedor" << endl;
        cout << "(3)Administrador" << endl<<endl;
        cout << "Escolhe o tipo de conta que deseja criar: ";
        cin >> tipoConta;

        //check if it is an valid option
        if (tipoConta!=1 && tipoConta!=2 && tipoConta!=3){
            cout << "Opcao invalida. "<<endl<<endl;
            system("PAUSE");

            continue;
        }

        try{
            switch(tipoConta){
            case LEITOR:
                //allocating memory to the object Leitor
                leitor = new Leitor();

                try{
                    resultado = link_ctrl_MA_GestaoUsuario->cadastrarLeitor(*leitor);
                }
                //in case of system error
                catch (runtime_error& e){
                    cerr << e.what() << endl;
                    system("pause");
                }
                if (resultado.getValor() == ResultadoCadastro::SUCESSO){
                    cout << endl << "CADASTRANDO LEITOR -> DADOS INSERIDOS -> ..... USUARIO CADASTRADO." << endl;
                    system("PAUSE");
                    cout << "Cadastro realizado com sucesso" << endl;

                    //show the user the informations
                    getDadosCadastroLeitor();

                    system("pause");
                }
                //deallocating memory of the object Leitor
                delete leitor;

                break;

            case DESENVOLVEDOR:
                //allocating memory to the object desenvolvedor
                desenvolvedor = new Desenvolvedor();

                try{
                    resultado = link_ctrl_MA_GestaoUsuario->cadastrarDesenvolvedor(*desenvolvedor);
                }
                //in case of system error
                catch (runtime_error& e){
                    cerr << e.what() << endl;
                    system("pause");
                }
                if (resultado.getValor() == ResultadoCadastro::SUCESSO){
                    cout << endl << "CADASTRANDO DESENVOLVEDOR -> DADOS INSERIDOS -> ..... USUARIO CADASTRADO." << endl;
                    resultado.setValor(ResultadoCadastro::SUCESSO);
                    system("PAUSE");

                    //show the user the informations
                    getDadosCadastroDesenvolvedor();

                    system("pause");
                }

                //deallocating the memory of the developer object
                delete desenvolvedor;

                break;

            case ADMINISTRADOR:
                //allocating memory to the object administrador
                administrador = new Administrador();

                try{
                    resultado = link_ctrl_MA_GestaoUsuario->cadastrarAdministrador(*administrador);
                }
                //in case of system error
                catch (runtime_error& e){
                    cerr << e.what() << endl;
                    system("pause");
                }
                if (resultado.getValor() == ResultadoCadastro::SUCESSO){
                    cout << endl << "CADASTRANDO ADMINISTRADOR -> DADOS INSERIDOS -> ..... USUARIO CADASTRADO." << endl;
                    resultado.setValor(ResultadoCadastro::SUCESSO);
                    system("PAUSE");

                    //show the user the informations
                    getDadosCadastroAdministrador();

                    system("pause");
                }

                //deallocating the memory of the object administrador
                delete administrador;

                break;

            default:

                cout << endl << "OPCAO INVALIDA, RETORNANDO. " << endl;
                resultado.setValor(ResultadoCadastro::CANCELAR);
                system("PAUSE");

            }

        }catch(invalid_argument& e){
            cout << endl<< "ERRO NO CADASTRO." << endl;
            resultado.setValor(ResultadoCadastro::FALHA);
        }

    return resultado;

    }
}

//definition of the method to start the program
void Controle::start(){
    //object to check if the initialization occurred with success or failure
    ResultadoInicializacao resultadoInicializacao;

    //start of the program
    while(true){
        //initialize
        resultadoInicializacao = this->inicializar();

        //check if the user wants to leave the program
        if (resultadoInicializacao.getSair()){
            cout << endl << "FINALIZANDO PROGRAMA..." << endl;
            break;
        }
    }

}
