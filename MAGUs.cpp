#include "MAGUs.hpp"

/*
DEFINITION AND METHODS OF THE CLASS ApresentacaoGestao
*/
//definition of the method to set the interface between the presentation and the service module
void inline ApresentacaoGestaoUsuario::setLink_MA_MS_GestaoUsuario(IS_GestaoUsuario *link_MA_MS_GestaoUsuario){
        this->link_MA_MS_GestaoUsuario = link_MA_MS_GestaoUsuario;
}

//definition of the method to register the reader
ResultadoCadastro ApresentacaoGestaoUsuario::cadastrarLeitor(Leitor& leitor) throw(runtime_error){
    //creating the object the check if the registering was a success or a failure
    ResultadoCadastro resultado;

    //get the informations of the user
    string entradaNome;
    string entradaSobrenome;
    string entradaEmail;
    string entradaSenha;
    //if the user wants to try again
    int novo;
    //true = try again, false = not try again
    bool again = true;

    //solicit the user the informations
    while(true){
        //clean the screen
        system("cls");
        cout << endl << "Cadastro do usuario." << endl << endl;

        //get the informations from the user
        try {
            cout << "Digite o seu nome: ";
            cin >> entradaNome;
            leitor.setNome(entradaNome);
            cout << "Digite o seu sobrenome: ";
            cin >> entradaSobrenome;
            leitor.setSobrenome(entradaSobrenome);
            cout << "Digite seu email: ";
            cin >> entradaEmail;
            leitor.setEmail(entradaEmail);
            cout << "Digite sua senha: ";
            cin >> entradaSenha;
            leitor.setSenha(entradaSenha);
            break;
        }

        //if the user types the informations in an invalid format
        catch (const invalid_argument &exp) {
            cerr << endl << exp.what() <<endl;

            //ask to the user if he/she wants to try again
            cout << "(1) SIM" << endl << "(0) NÃO" << endl;
            cout << "Deseja tentar novamente? ";
            cin >> novo;

            if(novo == 0){
                again = false;
            }
            else if(novo == 1){
                again = true;
            }
            else{
                cout << "Opcao invalida. Saindo. " << endl;
                system("pause");
                again = false;
            }
        }

        //leaving the registering part
        if (!again){
            resultado.setValor(ResultadoCadastro::CANCELAR);
            break;
        }
    }

    //Solicit authentication
    if(again){
            resultado = link_MA_MS_GestaoUsuario->cadastrarLeitor(leitor);

        //check if the result of the authentication is a failure or a success
        if(resultado.getValor() == ResultadoCadastro::FALHA){
            cout << endl << "Falha no cadastro." << endl;
            system("pause");
        }else{
            cout << endl << "Cadastro feito com sucesso." ;
            system("pause");
        }
    }

    return resultado;
}

//definition of the method to register the developer
ResultadoCadastro ApresentacaoGestaoUsuario::cadastrarDesenvolvedor(Desenvolvedor& desenvolvedor) throw(runtime_error){
    //creating the object the check if the registering was a success or a failure
    ResultadoCadastro resultado;

    //get the informations of the user
    string entradaNome;
    string entradaSobrenome;
    string entradaEmail;
    string entradaSenha;
    string entradaData;

    //if the user wants to try again
    int novo;
    //true = try again, false = not try again
    bool again = true;

    //solicit the user the informations
    while(true){
        //clean the screen
        system("cls");
        cout << endl << "Cadastro do usuario." << endl << endl;

        //get the informations from the user
        try {
            cout << "Digite o seu nome: ";
            cin >> entradaNome;
            desenvolvedor.setNome(entradaNome);
            cout << "Digite o seu sobrenome: ";
            cin >> entradaSobrenome;
            desenvolvedor.setSobrenome(entradaSobrenome);
            cout << "Digite seu email: ";
            cin >> entradaEmail;
            desenvolvedor.setEmail(entradaEmail);
            cout << "Digite sua senha: ";
            cin >> entradaSenha;
            desenvolvedor.setSenha(entradaSenha);
            cout << "Digite a data de nascimento: ";
            cin >> entradaData;
            desenvolvedor.setData(entradaData);
            break;
        }

        //if the user types the informations in an invalid format
        catch (const invalid_argument &exp) {
            cerr << endl << exp.what() <<endl;

            //ask to the user if he/she wants to try again
            cout << "(1) SIM" << endl << "(0) NÃO" << endl;
            cout << "Deseja tentar novamente? ";
            cin >> novo;

            if(novo == 0){
                again = false;
            }
            else if(novo == 1){
                again = true;
            }
            else{
                cout << "Opcao invalida. Saindo. " << endl;
                system("pause");
                again = false;
            }
        }

        //leaving the registering part
        if (!again){
            resultado.setValor(ResultadoCadastro::CANCELAR);
            break;
        }
    }

    //Solicit authentication
    if(again){
            resultado = link_MA_MS_GestaoUsuario->cadastrarDesenvolvedor(desenvolvedor);

        //check if the result of the authentication is a failure or a success
        if(resultado.getValor() == ResultadoCadastro::FALHA){
            cout << endl << "Falha no cadastro." << endl;
            system("pause");
        }else{
            cout << endl << "Cadastro feito com sucesso." ;
            system("pause");
        }
    }

    return resultado;
}

//definition of the method to register the administer
ResultadoCadastro ApresentacaoGestaoUsuario::cadastrarAdministrador(Administrador& administrador) throw(runtime_error){
    //creating the object the check if the registering was a success or a failure
    ResultadoCadastro resultado;

    //get the informations of the user
    string entradaNome;
    string entradaSobrenome;
    string entradaEmail;
    string entradaSenha;
    string entradaData;
    string entradaTelefone;
    string entradaEndereco;

    //if the user wants to try again
    int novo;
    //true = try again, false = not try again
    bool again = true;

    //solicit the user the informations
    while(true){
        //clean the screen
        system("cls");
        cout << endl << "Cadastro do usuario." << endl << endl;

        //get the informations from the user
        try {
            cout << "Digite o seu nome: ";
            cin >> entradaNome;
            administrador.setNome(entradaNome);
            cout << "Digite o seu sobrenome: ";
            cin >> entradaSobrenome;
            administrador.setSobrenome(entradaSobrenome);
            cout << "Digite seu email: ";
            cin >> entradaEmail;
            administrador.setEmail(entradaEmail);
            cout << "Digite sua senha: ";
            cin >> entradaSenha;
            administrador.setSenha(entradaSenha);
            cout << "Digite a data de nascimento: ";
            cin >> entradaData;
            administrador.setData(entradaData);
            fflush(stdin);
            cout << "Digite o telefone: ";
            getline(cin, entradaTelefone);
            administrador.setTelefone(entradaTelefone);
            fflush(stdin);
            cout << "Digite o endereco: ";
            getline(cin, entradaEndereco);
            administrador.setEndereco(entradaEndereco);
            break;
        }

        //if the user types the informations in an invalid format
        catch (const invalid_argument &exp) {
            cerr << endl << exp.what() <<endl;

            //ask to the user if he/she wants to try again
            cout << "(1) SIM" << endl << "(0) NÃO" << endl;
            cout << "Deseja tentar novamente? ";
            cin >> novo;

            if(novo == 0){
                again = false;
            }
            else if(novo == 1){
                again = true;
            }
            else{
                cout << "Opcao invalida. Saindo. " << endl;
                system("pause");
                again = false;
            }
        }

        //leaving the registering part
        if (!again){
            resultado.setValor(ResultadoCadastro::CANCELAR);
            break;
        }
    }

    //Solicit authentication
    if(again){
            resultado = link_MA_MS_GestaoUsuario->cadastrarAdministrador(administrador);

        //check if the result of the authentication is a failure or a success
        if(resultado.getValor() == ResultadoCadastro::FALHA){
            cout << endl << "Falha no cadastro." << endl;
            system("pause");
        }else{
            cout << endl << "Cadastro feito com sucesso." ;
            system("pause");
        }
    }

    return resultado;
}

//definition of the method that will execute the user management account
Resultado ApresentacaoGestaoUsuario::executar(ResultadoAutenticacao& autenticado) throw(runtime_error){
    //creating the object the check if the management was a success or a failure
    Resultado resultado;
    //the option of the user
    short opcao;
    //the email of the user
    Email email;
    //the new information
    string entrada;
    //type of the user
    int tipo = autenticado.getTipo();

    //creating pointers to the types of users
    Leitor *leitor;
    Desenvolvedor *desenvolvedor;
    Administrador *administrador;

    //the user is a reader
    if (tipo == 1){
        leitor = new Leitor();
        *leitor = autenticado.getLeitor();
        email.getEmail() = leitor->getEmail();
    }

    //the user is a developer
    if (tipo == 2){
        desenvolvedor = new Desenvolvedor();
        *desenvolvedor = autenticado.getDesenvolvedor();
        email.getEmail() = desenvolvedor->getEmail();
    }

    //the user is an administer
    if (tipo == 3){
        administrador = new Administrador();
        *administrador = autenticado.getAdministrador();
        email.getEmail() = administrador->getEmail();
    }

    while(true){
        cout << "Gestao de usuario" << endl << endl;
        cout << "(1) - remover conta" << endl;
        cout << "(2) - editar conta" << endl;
        cout << "Digite a sua opcao: ";
        cin >> opcao;

        //remove the user
        if (opcao == 1){
            resultado = link_MA_MS_GestaoUsuario->remover(email);
            break;
        }

        //edit the user
        else if (opcao == 2){
            //in the case if the user is a reader
            if(tipo == 1){
                system("cls");
                cout << "Quais das opcoes abaixo deseja editar?" << endl;
                cout << "(1) - Nome" << endl;
                cout << "(2) - Sobrenome" << endl;
                cout << "(3) - Email" << endl;
                cout << "(4) - Senha" << endl;
                cout << "Digite a sua opcao: ";
                cin >> opcao;

                //in the case if the reader wants to edit its name
                if(opcao == 1){
                    cout << "Digite o nome desejado: ";
                    cin >> entrada;
                    try {
                        leitor->setNome(entrada);
                    }
                    catch (invalid_argument& e){
                        cerr << e.what() << endl;
                        cout << "Deseja tentar novamente? " << endl;
                        cout << "(1) - SIM" << endl;
                        cout << "(2) - NAO" << endl;
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

                //in the case if the reader wants to edit its last name
                if(opcao == 2){
                    cout << "Digite o sobrenome desejado: ";
                    cin >> entrada;
                    try {
                        leitor->setSobrenome(entrada);
                    }
                    catch (invalid_argument& e){
                        cerr << e.what() << endl;
                        cout << "Deseja tentar novamente? " << endl;
                        cout << "(1) - SIM" << endl;
                        cout << "(2) - NAO" << endl;
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

                //in the case if the reader wants to edit its email
                if(opcao == 3){
                    cout << "Digite o email desejado: ";
                    cin >> entrada;
                    try {
                        leitor->setEmail(entrada);
                    }
                    catch (invalid_argument& e){
                        cerr << e.what() << endl;
                        cout << "Deseja tentar novamente? " << endl;
                        cout << "(1) - SIM" << endl;
                        cout << "(2) - NAO" << endl;
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

                //in the case if the reader wants to edit its password
                if(opcao == 4){
                    cout << "Digite o nome desejado: ";
                    cin >> entrada;
                    try {
                        leitor->setSenha(entrada);
                    }
                    catch (invalid_argument& e){
                        cerr << e.what() << endl;
                        cout << "Deseja tentar novamente? " << endl;
                        cout << "(1) - SIM" << endl;
                        cout << "(2) - NAO" << endl;
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

                try{
                    resultado = link_MA_MS_GestaoUsuario->editarLeitor(*leitor);
                    break;
                }
                //in the case of system error
                catch (runtime_error& e){
                    cerr << e.what() << endl;
                    break;
                }
            }

            //in the case if the user is a developer
            if(tipo == 2){
                system("cls");
                cout << "Quais das opcoes abaixo deseja editar?" << endl;
                cout << "(1) - Nome" << endl;
                cout << "(2) - Sobrenome" << endl;
                cout << "(3) - Email" << endl;
                cout << "(4) - Senha" << endl;
                cout << "(5) - Data de nascimento" << endl;
                cout << "Digite a sua opcao: ";
                cin >> opcao;

                //in the case if the developer wants to edit its name
                if(opcao == 1){
                    cout << "Digite o nome desejado: ";
                    cin >> entrada;
                    try {
                        desenvolvedor->setNome(entrada);
                    }
                    catch (invalid_argument& e){
                        cerr << e.what() << endl;
                        cout << "Deseja tentar novamente? " << endl;
                        cout << "(1) - SIM" << endl;
                        cout << "(2) - NAO" << endl;
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

                //in the case if the developer wants to edit its last name
                if(opcao == 2){
                    cout << "Digite o sobrenome desejado: ";
                    cin >> entrada;
                    try {
                        desenvolvedor->setSobrenome(entrada);
                    }
                    catch (invalid_argument& e){
                        cerr << e.what() << endl;
                        cout << "Deseja tentar novamente? " << endl;
                        cout << "(1) - SIM" << endl;
                        cout << "(2) - NAO" << endl;
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

                //in the case if the developer wants to edit its email
                if(opcao == 3){
                    cout << "Digite o email desejado: ";
                    cin >> entrada;
                    try {
                        desenvolvedor->setEmail(entrada);
                    }
                    catch (invalid_argument& e){
                        cerr << e.what() << endl;
                        cout << "Deseja tentar novamente? " << endl;
                        cout << "(1) - SIM" << endl;
                        cout << "(2) - NAO" << endl;
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

                //in the case if the developer wants to edit its password
                if(opcao == 4){
                    cout << "Digite a senha desejado: ";
                    cin >> entrada;
                    try {
                        desenvolvedor->setSenha(entrada);
                    }
                    catch (invalid_argument& e){
                        cerr << e.what() << endl;
                        cout << "Deseja tentar novamente? " << endl;
                        cout << "(1) - SIM" << endl;
                        cout << "(2) - NAO" << endl;
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

                //in the case if the developer wants to edit its date
                if(opcao == 5){
                    cout << "Digite a data de nascimento: ";
                    cin >> entrada;
                    try {
                        desenvolvedor->setData(entrada);
                    }
                    catch (invalid_argument& e){
                        cerr << e.what() << endl;
                        cout << "Deseja tentar novamente? " << endl;
                        cout << "(1) - SIM" << endl;
                        cout << "(2) - NAO" << endl;
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

                try{
                    resultado = link_MA_MS_GestaoUsuario->editarDesenvolvedor(*desenvolvedor);
                    break;
                }
                //in the case of system error
                catch (runtime_error& e){
                    cerr << e.what() << endl;
                    break;
                }
            }

             //in the case if the user is an administer
            if(tipo == 3){
                system("cls");
                cout << "Quais das opcoes abaixo deseja editar?" << endl;
                cout << "(1) - Nome" << endl;
                cout << "(2) - Sobrenome" << endl;
                cout << "(3) - Email" << endl;
                cout << "(4) - Senha" << endl;
                cout << "(5) - Data de nascimento" << endl;
                cout << "(6) - Endreco" << endl;
                cout << "(7) - Telefone" << endl;
                cout << "Digite a sua opcao: ";
                cin >> opcao;

                //in the case if the administer wants to edit its name
                if(opcao == 1){
                    cout << "Digite o nome desejado: ";
                    cin >> entrada;
                    try {
                        administrador->setNome(entrada);
                    }
                    catch (invalid_argument& e){
                        cerr << e.what() << endl;
                        cout << "Deseja tentar novamente? " << endl;
                        cout << "(1) - SIM" << endl;
                        cout << "(2) - NAO" << endl;
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

                //in the case if the administer wants to edit its last name
                if(opcao == 2){
                    cout << "Digite o sobrenome desejado: ";
                    cin >> entrada;
                    try {
                        administrador->setSobrenome(entrada);
                    }
                    catch (invalid_argument& e){
                        cerr << e.what() << endl;
                        cout << "Deseja tentar novamente? " << endl;
                        cout << "(1) - SIM" << endl;
                        cout << "(2) - NAO" << endl;
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

                //in the case if the administer wants to edit its email
                if(opcao == 3){
                    cout << "Digite o email desejado: ";
                    cin >> entrada;
                    try {
                        administrador->setEmail(entrada);
                    }
                    catch (invalid_argument& e){
                        cerr << e.what() << endl;
                        cout << "Deseja tentar novamente? " << endl;
                        cout << "(1) - SIM" << endl;
                        cout << "(2) - NAO" << endl;
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

                //in the case if the administer wants to edit its password
                if(opcao == 4){
                    cout << "Digite a senha desejado: ";
                    cin >> entrada;
                    try {
                        administrador->setSenha(entrada);
                    }
                    catch (invalid_argument& e){
                        cerr << e.what() << endl;
                        cout << "Deseja tentar novamente? " << endl;
                        cout << "(1) - SIM" << endl;
                        cout << "(2) - NAO" << endl;
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

                //in the case if the administer wants to edit its date
                if(opcao == 5){
                    cout << "Digite a data de nascimento: ";
                    cin >> entrada;
                    try {
                        administrador->setData(entrada);
                    }
                    catch (invalid_argument& e){
                        cerr << e.what() << endl;
                        cout << "Deseja tentar novamente? " << endl;
                        cout << "(1) - SIM" << endl;
                        cout << "(2) - NAO" << endl;
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

                //in the case if the administer wants to edit its address
                if(opcao == 6){
                    fflush(stdin);
                    cout << "Digite o endereco: ";
                    getline(cin, entrada);
                    try {
                        administrador->setEndereco(entrada);
                    }
                    catch (invalid_argument& e){
                        cerr << e.what() << endl;
                        cout << "Deseja tentar novamente? " << endl;
                        cout << "(1) - SIM" << endl;
                        cout << "(2) - NAO" << endl;
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

                //in the case if the administer wants to edit its telephone number
                if(opcao == 7){
                    fflush(stdin);
                    cout << "Digite o telefone: ";
                    getline(cin, entrada);
                    try {
                        administrador->setTelefone(entrada);
                    }
                    catch (invalid_argument& e){
                        cerr << e.what() << endl;
                        cout << "Deseja tentar novamente? " << endl;
                        cout << "(1) - SIM" << endl;
                        cout << "(2) - NAO" << endl;
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

                try{
                    resultado = link_MA_MS_GestaoUsuario->editarAdministrador(*administrador);
                    break;
                }
                //in the case of system error
                catch (runtime_error& e){
                    cerr << e.what() << endl;
                    break;
                }
            }
        }
    }

    //deallocating memory
    if (tipo == 1){
        delete leitor;
    }

    if (tipo == 2){
        delete desenvolvedor;
    }

    if (tipo == 3){
        delete administrador;
    }

    return resultado;
}
