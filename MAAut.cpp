#include "MAAut.hpp"

/*
DEFINITION AND METHODS OF THE CLASS OpcaoAutenticar
*/
ResultadoAutenticacao OpcaoAutenticar::autenticar(Email& email, Senha& senha) throw(runtime_error) {
    //creating the object the check if the authentication was a success or a failure
    ResultadoAutenticacao resultado;

    string entradaEmail;
    string entradaSenha;
    int novo;
    bool again = true;

    //Solicit to the user the email and the password
    while(true) {
        system("cls");
        cout << endl << "Autenticacao de usuario." << endl << endl;

        //get the email and the password from the user
        try {
            cout << "Digite o email : ";
            cin >> entradaEmail;
            email.setEmail(entradaEmail);
            cout << "Digite a senha : ";
            cin >> entradaSenha;
            senha.setSenha(entradaSenha);
            break;
        }

        //if the user types the email or the password in an invalid format
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

        //leaving the authentication part
        if (!again){
            resultado.setValor(ResultadoAutenticacao::CANCELAR);
            break;
        }
    }

    //Solicit authentication
    if(again){
            resultado = link_MA_MS_Autenticacao->autenticar(email, senha);

        //check if the result of the authentication is a failure or a success
        if(resultado.getValor() == ResultadoAutenticacao::FALHA){
            cout << endl << "Falha na autenticacao." << endl;
            system("PAUSE");
        }else{
            cout << endl << "Autenticacao feita com sucesso. Executando programa. " ;
            system("PAUSE");
        }
    }

    return resultado;
}
