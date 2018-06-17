#include "testes.hpp"

using namespace std;

/*
METHODS AND ATTRIBUTES OF THE CLASS TUNomeGeral
*/

//defining the NOME_VALIDO
const string TUNomeGeral::NOME_VALIDO = "Carlos";
//defining the NOME_PRIMEIRA_LETRA_INVALIDA
const string TUNomeGeral::NOME_PRIMEIRA_LETRA_INVALIDA = "carlos";
//defining the NOME_CARACTER_INVALIDO
const string TUNomeGeral::NOME_CARACTER_INVALIDO = "Car!los";
//defining the NOME_LONGO
const string TUNomeGeral::NOME_LONGO = "CarlosGabrielAttaAustriaco";

//defining the method setUp to allocate the memory to object and
//set the attribute estado
void TUNomeGeral::setUp(){
    nomegeral = new Nome();
    estado = SUCESSO;
}

//defining the method tearDown to desallocate the
//memory of the object
void TUNomeGeral::tearDown(){
    delete nomegeral;
}

//defining the method testarCenarioCorreto setting the NomeGeral
//with the attribute NOME_VALIDO
void TUNomeGeral::testarCenarioCorreto(){
    try{
        nomegeral->setNome(NOME_VALIDO);
        if(nomegeral->getNome() != NOME_VALIDO){
            estado = FALHA;
        }
    }
    catch(invalid_argument& e){
        cout << e.what() << endl;
        estado = FALHA;
    }
}

//defining the method testarCenarioIncorreto setting the NomeGeral
//with the attributes:
//NOME_PRIMEIRA_LETRA_INVALIDA
//NOME_CARACTER_INVALIDO
//NOME_LONGO
void TUNomeGeral::testarCenarioIncorreto(const string& str){
    try{
        nomegeral->setNome(str);
        estado = FALHA;
    }
    catch(invalid_argument& e){
        return;
    }
}

//defining the method run that will test the code
int TUNomeGeral::run(){
    setUp();
    testarCenarioCorreto();
    testarCenarioIncorreto(NOME_PRIMEIRA_LETRA_INVALIDA);
    testarCenarioIncorreto(NOME_CARACTER_INVALIDO);
    testarCenarioIncorreto(NOME_LONGO);
    tearDown();

    return estado;
}

/*
METHODS AND ATTRIBUTES OF THE CLASS TUTelefone
*/
//defining the TELEFONE_VALIDO
const string TUTelefone::TELEFONE_VALIDO = "61 98199-3449";
//defining the TELEFONE_SEM_ESPACO
const string TUTelefone::TELEFONE_SEM_ESPACO = "6198199-3449";
//defining the TELEFONE_SEM_HIFEN
const string TUTelefone::TELEFONE_SEM_HIFEN = "61 981993449";
//defining the TELEFONE_DDD_INCORRETO
const string TUTelefone::TELEFONE_DDD_INCORRETO = "a1 98199-3449";
//defining the TELEFONE_MUITO_NUMERO
const string TUTelefone::TELEFONE_MUITO_NUMERO = "61 98199-34499";

//defining the method setUp to allocate the memory to object and
//set the attribute estado
void TUTelefone::setUp(){
    telefone = new Telefone();
    estado = SUCESSO;
}

//defining the method tearDown to desallocate the
//memory of the object
void TUTelefone::tearDown(){
    delete telefone;
}

//defining the method testarCenarioCorreto setting the telefone
//with the attribute TELEFONE_VALIDO
void TUTelefone::testarCenarioCorreto(){
    try{
        telefone->setTelefone(TELEFONE_VALIDO);
        if(telefone->getTelefone() != TELEFONE_VALIDO){
            estado = FALHA;
        }
    }
    catch(invalid_argument& e){
        cout << e.what() << endl;
        estado = FALHA;
    }
}

//defining the method testarCenarioIncorreto setting the Telefone
//with the attributes:
//TELEFONE_SEM_ESPACO
//TELEFONE_SEM_HIFEN
//TELEFONE_DDD_INCORRETO
//TELEFONE_MUITO_NUMERO
void TUTelefone::testarCenarioIncorreto(const string& str){
    try{
        telefone->setTelefone(str);
        estado = FALHA;
    }
    catch(invalid_argument& e){
        return;
    }
}

//defining the method run that will test the code
int TUTelefone::run(){
    setUp();
    testarCenarioCorreto();
    testarCenarioIncorreto(TELEFONE_SEM_ESPACO);
    testarCenarioIncorreto(TELEFONE_SEM_HIFEN);
    testarCenarioIncorreto(TELEFONE_DDD_INCORRETO);
    testarCenarioIncorreto(TELEFONE_MUITO_NUMERO);
    tearDown();

    return estado;
}

/*
METHODS AND ATTRIBUTES OF THE CLASS TUEndereco
*/
//defining the ENDERECO_VALIDO
const string TUEndereco::ENDERECO_VALIDO = "SEPS 713, Bl. C";
//defining the ENDERECO_COMECO_ESPACO
const string TUEndereco::ENDERECO_COMECO_ESPACO = " SEPS 713, Bl. C";
//defining the ENDERECO_FIM_ESPACO
const string TUEndereco::ENDERECO_FIM_ESPACO = "SEPS 713, Bl. C ";
//defining the ENDERECO_LONGO
const string TUEndereco::ENDERECO_LONGO = "SEPS 713, Bl. C, AP. 16";
//defining the ENDERECO_ESPACO_SEGUIDO
const string TUEndereco::ENDERECO_ESPACO_SEGUIDO = "SEPS  713, Bl. C";
//defining the ENDERECO_CARACTER_INVALIDO
const string TUEndereco::ENDERECO_CARACTER_INVALIDO = "SEPS 7/13, Bl. C";

//defining the method setUp to allocate the memory to object and
//set the attribute estado
void TUEndereco::setUp(){
    endereco = new Endereco();
    estado = SUCESSO;
}

//defining the method tearDown to desallocate the
//memory of the object
void TUEndereco::tearDown(){
    delete endereco;
}

//defining the method testarCenarioCorreto setting the endereco
//with the attribute ENDERECO_VALIDO
void TUEndereco::testarCenarioCorreto(){
    try{
        endereco->setEndereco(ENDERECO_VALIDO);
        if(endereco->getEndereco() != ENDERECO_VALIDO){
            estado = FALHA;
        }
    }
    catch(invalid_argument& e){
        cout << e.what() << endl;
        estado = FALHA;
    }
}

//defining the method testarCenarioIncorreto setting the Endereco
//with the attributes:
//TELEFONE_COMECO_ESPACO
//ENDERECO_FIM_ESPACO
//ENDERECO_LONGO
//ENDERECO_ESPACO_SEGUIDO
//ENDERECO_CARACTER_INVALIDO
void TUEndereco::testarCenarioIncorreto(const string& str){
    try{
        endereco->setEndereco(str);
        estado = FALHA;
    }
    catch(invalid_argument& e){
        return;
    }
}

//defining the method run that will test the code
int TUEndereco::run(){
    setUp();
    testarCenarioCorreto();
    testarCenarioIncorreto(ENDERECO_COMECO_ESPACO);
    testarCenarioIncorreto(ENDERECO_FIM_ESPACO);
    testarCenarioIncorreto(ENDERECO_LONGO);
    testarCenarioIncorreto(ENDERECO_ESPACO_SEGUIDO);
    testarCenarioIncorreto(ENDERECO_CARACTER_INVALIDO);
    tearDown();

    return estado;
}

/*
ATTRIBUTES AND METHODS OF THE CLASS TUData
*/
//defining DATA_VALIDA
const string TUData::DATA_VALIDA = "11/03/1996";
//defining DATA_LONGA
const string TUData::DATA_LONGA = "11/03/19966";
//defining DATA_BARRA_ERRADA
const string TUData::DATA_BARRA_ERRADA = "11/03a1996";
//defining DATA_CARACTER_INVALIDO_DIA
const string TUData::DATA_CARACTER_INVALIDO_DIA = "1A/03/1996";
//defining DATA_CARACTER_INVALIDO_MES
const string TUData::DATA_CARACTER_INVALIDO_MES = "11/A3/1996";
//defining DATA_CARACTER_INVALIDO_ANO
const string TUData::DATA_CARACTER_INVALIDO_ANO = "11/03/19A6";
//defining DATA_DIA_INVALIDO
const string TUData::DATA_DIA_INVALIDO = "31/04/1996";
//defining DATA_BISSEXTO_INVALIDO
const string TUData::DATA_BISSEXTO_INVALIDO = "29/02/2001";
//defining DATA_MES_INVALIDO
const string TUData::DATA_MES_INVALIDO = "11/15/1996";
//defining DATA_ANO_INVALIDO
const string TUData::DATA_ANO_INVALIDO = "11/03/1895";

//defining the method setUp to allocate the memory to object and
//set the attribute estado
void TUData::setUp(){
    data = new Data();
    estado = SUCESSO;
}

//defining the method tearDown to desallocate the
//memory of the object
void TUData::tearDown(){
    delete data;
}

//defining the method testarCenarioCorreto setting the data
//with the attribute DATA_VALIDA
void TUData::testarCenarioCorreto(){
    try{
        data->setData(DATA_VALIDA);
        if(data->getData() != DATA_VALIDA){
            estado = FALHA;
        }
    }
    catch(invalid_argument& e){
        cout << e.what() << endl;
        estado = FALHA;
    }
}

//defining the method testarCenarioIncorreto setting the Data
//with the attributes:
//DATA_LONGA
//DATA_BARRA_ERRADA
//DATA_CARACTER_INVALIDO_DIA
//DATA_CARACTER_INVALIDO_MES
//DATA_CARACTER_INVALIDO_ANO
//DATA_DIA_INVALIDO
//DATA_BISSEXTO_INVALIDO
//DATA_MES_INVALIDO
//DATA_ANO_INVALIDO
void TUData::testarCenarioIncorreto(const string& str){
    try{
        data->setData(str);
        estado = FALHA;
    }
    catch(invalid_argument& e){
        return;
    }
}

//defining the method run that will test the code
int TUData::run(){
    setUp();
    testarCenarioCorreto();
    testarCenarioIncorreto(DATA_LONGA);
    testarCenarioIncorreto(DATA_BARRA_ERRADA);
    testarCenarioIncorreto(DATA_CARACTER_INVALIDO_DIA);
    testarCenarioIncorreto(DATA_CARACTER_INVALIDO_MES);
    testarCenarioIncorreto(DATA_CARACTER_INVALIDO_ANO);
    testarCenarioIncorreto(DATA_DIA_INVALIDO);
    testarCenarioIncorreto(DATA_BISSEXTO_INVALIDO);
    testarCenarioIncorreto(DATA_MES_INVALIDO);
    testarCenarioIncorreto(DATA_ANO_INVALIDO);
    tearDown();

    return estado;
}

/*
ATTRIBUTES AND METHODS OF THE CLASS TUEmail
*/
//definition of EMAIL_VALIDO
const string TUEmail::EMAIL_VALIDO = "cgaa.1103@gmail-com";
//definition of EMAIL_SEM_ARROBA
const string TUEmail::EMAIL_SEM_ARROBA = "cgaa1103gmail-com";
//definition of EMAIL_LOCAL_COMECO_PONTO
const string TUEmail::EMAIL_LOCAL_COMECO_PONTO = ".cgaa1103@gmail-com";
//definition of EMAIL_LOCAL_FIM_PONTO
const string TUEmail::EMAIL_LOCAL_FIM_PONTO = "cgaa1103.@gmail-com";
//definition of EMAIL_LOCAL_CARACTER_INVALIDO
const string TUEmail::EMAIL_LOCAL_CARACTER_INVALIDO = "cgaa(1103@gmail-com";
//definition of the EMAIL_DOMINIO_COMECO_HIFEN
const string TUEmail::EMAIL_DOMINIO_COMECO_HIFEN = "cgaa1103@-gmail-com";
//definition of the EMAIL_DOMINIO_FIM_HIFEN
const string TUEmail::EMAIL_DOMINIO_FIM_HIFEN = "cgaa1103@gmail-com-";
//definition of the EMAIL_DOMINIO_CARACTER_INVALIDO
const string TUEmail::EMAIL_DOMINIO_CARACTER_INVALIDO = "cgaa1103@gmail-c(om";
//definition of the EMAIL_DOMINIO_NUMERO
const string TUEmail::EMAIL_DOMINIO_NUMERO = "cgaa1103@123123123";

//defining the method setUp to allocate the memory to object and
//set the attribute estado
void TUEmail::setUp(){
    email = new Email();
    estado = SUCESSO;
}

//defining the method tearDown to desallocate the
//memory of the object
void TUEmail::tearDown(){
    delete email;
}

//defining the method testarCenarioCorreto setting the email
//with the attribute EMAIL_VALIDO
void TUEmail::testarCenarioCorreto(){
    try{
        email->setEmail(EMAIL_VALIDO);
        if(email->getEmail() != EMAIL_VALIDO){
            estado = FALHA;
        }
    }
    catch(invalid_argument& e){
        cout << e.what() << endl;
        estado = FALHA;
    }
}

//defining the method testarCenarioIncorreto setting the Email
//with the attributes:
//EMAIL_SEM_ARROBA
//EMAIL_LOCAL_COMECO_PONTO
//EMAIL_LOCAL_FIM_PONTO
//EMAIL_LOCAL_CARACTER_INVALIDO
//EMAIL_DOMINIO_COMECO_HIFEN
//EMAIL_DOMINIO_FIM_HIFEN
//EMAIL_DOMINIO_NUMERO
void TUEmail::testarCenarioIncorreto(const string& str){
    try{
        email->setEmail(str);
        estado = FALHA;
    }
    catch(invalid_argument& e){
        return;
    }
}

//defining the method run that will test the code
int TUEmail::run(){
    setUp();
    testarCenarioCorreto();
    testarCenarioIncorreto(EMAIL_SEM_ARROBA);
    testarCenarioIncorreto(EMAIL_LOCAL_COMECO_PONTO);
    testarCenarioIncorreto(EMAIL_LOCAL_FIM_PONTO);
    testarCenarioIncorreto(EMAIL_LOCAL_CARACTER_INVALIDO);
    testarCenarioIncorreto(EMAIL_DOMINIO_COMECO_HIFEN);
    testarCenarioIncorreto(EMAIL_DOMINIO_FIM_HIFEN);
    testarCenarioIncorreto(EMAIL_DOMINIO_CARACTER_INVALIDO);
    testarCenarioIncorreto(EMAIL_DOMINIO_NUMERO);
    tearDown();

    return estado;
}

/*
ATTRIBUTES AND METHODS OF THE CLASS TUSenha
*/
//definition of SENHA_VALIDA
const string TUSenha::SENHA_VALIDA = "Aa110396";
//definition of SENHA_SEM_MAIUSCULA
const string TUSenha::SENHA_SEM_MAIUSCULA = "aa110396";
//definition of SENHA_LONGA
const string TUSenha::SENHA_LONGA = "Aa1103966";
//definition of SENHA_SEM_MINUSCULA
const string TUSenha::SENHA_SEM_MINUSCULA = "AA110396";
//definition of SENHA_SEM_NUMERO
const string TUSenha::SENHA_SEM_NUMERO = "Aaaaaaaa";

//defining the method setUp to allocate the memory to object and
//set the attribute estado
void TUSenha::setUp(){
    senha = new Senha();
    estado = SUCESSO;
}

//defining the method tearDown to desallocate the
//memory of the object
void TUSenha::tearDown(){
    delete senha;
}

//defining the method testarCenarioCorreto setting the senha
//with the attribute SENHA_VALIDA
void TUSenha::testarCenarioCorreto(){
    try{
        senha->setSenha(SENHA_VALIDA);
        if(senha->getSenha() != SENHA_VALIDA){
            estado = FALHA;
        }
    }
    catch(invalid_argument& e){
        cout << e.what() << endl;
        estado = FALHA;
    }
}

//defining the method testarCenarioIncorreto setting the Senha
//with the attributes:
//SENHA_SEM_MAIUSCULA
//SENHA_LONGA
//SENHA_SEM_MINUSCULA
//SENHA_SEM_NUMERO
void TUSenha::testarCenarioIncorreto(const string& str){
    try{
        senha->setSenha(str);
        estado = FALHA;
    }
    catch(invalid_argument& e){
        return;
    }
}

//defining the method run that will test the code
int TUSenha::run(){
    setUp();
    testarCenarioCorreto();
    testarCenarioIncorreto(SENHA_SEM_MAIUSCULA);
    testarCenarioIncorreto(SENHA_LONGA);
    testarCenarioIncorreto(SENHA_SEM_MINUSCULA);
    testarCenarioIncorreto(SENHA_SEM_NUMERO);
    tearDown();

    return estado;
}

/*
ATTRIBUTES AND METHODS OF THE CLASS TUTexto
*/
//definition of TEXTO_VALIDO
const string TUTexto::TEXTO_VALIDO = "carlos gabriel atta austriaco";
//definition of TEXTO_LONGO
const string TUTexto::TEXTO_LONGO = "carlos gabriel atta austriaco comeu um queijo";

//defining the method setUp to allocate the memory to object and
//set the attribute estado
void TUTexto::setUp(){
    texto = new Texto();
    estado = SUCESSO;
}

//defining the method tearDown to desallocate the
//memory of the object
void TUTexto::tearDown(){
    delete texto;
}

//defining the method testarCenarioCorreto setting the definition text
//with the attribute TEXTO_VALIDO
void TUTexto::testarCenarioCorreto(){
    try{
        texto->setTexto(TEXTO_VALIDO);
        if(texto->getTexto() != TEXTO_VALIDO){
            estado = FALHA;
        }
    }
    catch(invalid_argument& e){
        cout << e.what() << endl;
        estado = FALHA;
    }
}

//defining the method testarCenarioIncorreto setting the Texto
//with the attributes:
//TEXTO_LONGO
void TUTexto::testarCenarioIncorreto(const string& str){
    try{
        texto->setTexto(str);
        estado = FALHA;
    }
    catch(invalid_argument& e){
        return;
    }
}

//defining the method run that will test the code
int TUTexto::run(){
    setUp();
    testarCenarioCorreto();
    testarCenarioIncorreto(TEXTO_LONGO);
    tearDown();

    return estado;
}

/*
ATTRIBUTES AND METHODS OF THE CLASS TUIdioma
*/
//definition of IDIOMA_VALIDO
const string TUIdioma::IDIOMA_VALIDO = "ENG";
//definition of IDIOMA_INVALIDO
const string TUIdioma::IDIOMA_INVALIDO = "ESP";

//defining the method setUp to allocate the memory to object and
//set the attribute estado
void TUIdioma::setUp(){
    idioma = new Idioma();
    estado = SUCESSO;
}

//defining the method tearDown to desallocate the
//memory of the object
void TUIdioma::tearDown(){
    delete idioma;
}

//defining the method testarCenarioCorreto setting the language
//with the attribute IDIOMA_VALIDO
void TUIdioma::testarCenarioCorreto(){
    try{
        idioma->setIdioma(IDIOMA_VALIDO);
        if(idioma->getIdioma() != IDIOMA_VALIDO){
            estado = FALHA;
        }
    }
    catch(invalid_argument& e){
        cout << e.what() << endl;
        estado = FALHA;
    }
}

//defining the method testarCenarioIncorreto setting the Idioma
//with the attribute:
//IDIOMA_INVALIDO
void TUIdioma::testarCenarioIncorreto(const string& str){
    try{
        idioma->setIdioma(str);
        estado = FALHA;
    }
    catch(invalid_argument& e){
        return;
    }
}

//defining the method run that will test the code
int TUIdioma::run(){
    setUp();
    testarCenarioCorreto();
    testarCenarioIncorreto(IDIOMA_INVALIDO);
    tearDown();

    return estado;
}

/*
ATTRIBUTES AND METHODS OF THE CLASS TUPreferencia
*/
//definition of PREFERENCIA_VALIDA
const string TUPreferencia::PREFERENCIA_VALIDA = "NP";
//definition of PREFERENCIA_INVALIDA
const string TUPreferencia::PREFERENCIA_INVALIDA = "NA";

//defining the method setUp to allocate the memory to object and
//set the attribute estado
void TUPreferencia::setUp(){
    preferencia = new Preferencia();
    estado = SUCESSO;
}

//defining the method tearDown to desallocate the
//memory of the object
void TUPreferencia::tearDown(){
    delete preferencia;
}

//defining the method testarCenarioCorreto setting the preference
//with the attribute PREFERENCIA_VALIDA
void TUPreferencia::testarCenarioCorreto(){
    try{
        preferencia->setPreferencia(PREFERENCIA_VALIDA);
        if(preferencia->getPreferencia() != PREFERENCIA_VALIDA){
            estado = FALHA;
        }
    }
    catch(invalid_argument& e){
        cout << e.what() << endl;
        estado = FALHA;
    }
}

//defining the method testarCenarioIncorreto setting the Preferencia
//with the attribute:
//PREFERENCIA_INVALIDA
void TUPreferencia::testarCenarioIncorreto(const string& str){
    try{
        preferencia->setPreferencia(str);
        estado = FALHA;
    }
    catch(invalid_argument& e){
        return;
    }
}

//defining the method run that will test the code
int TUPreferencia::run(){
    setUp();
    testarCenarioCorreto();
    testarCenarioIncorreto(PREFERENCIA_INVALIDA);
    tearDown();

    return estado;
}

/*
ATTRIBUTES AND METHODS OD THE CLASS TULeitor
*/
//definition of NOME_VALIDO
const string TULeitor::NOME_VALIDO = "Carlos";
//definition of SOBRENOME_VALIDO
const string TULeitor::SOBRENOME_VALIDO = "Austriaco";
//definition of EMAIL_VALIDO
const string TULeitor::EMAIL_VALIDO = "cgaa1103@gmail";
//definition of SENHA_VALIDA
const string TULeitor::SENHA_VALIDA = "Aa110396";

//defining the method setUp to allocate the memory to objects and
//set the attribute estado
void TULeitor::setUp(){
    //allocate the memory of the attributes of Leitor
    nome = new Nome();
    sobrenome = new Sobrenome();
    email = new Email();
    senha = new Senha();
    //alocate the memory of the object from the class Leitor
    leitor = new Leitor();

    estado = SUCESSO;
}

//defining the method tearDown to desallocate the
//memory of the objects
void TULeitor::tearDown(){
    delete nome;
    delete sobrenome;
    delete email;
    delete senha;
    delete leitor;
}

//defining the method testarCenarioCorreto setting the Leitor
//with the attributes:
//NOME_VALIDO
//SOBRENOME_VALIDO
//EMAIL_VALIDO
//SENHA_VALIDA
void TULeitor::testarCenarioCorreto(){
    //testing the name
    try{
        nome->setNome(NOME_VALIDO);
        if(nome->getNome() != NOME_VALIDO){
            estado = FALHA;
        }
    }
    catch(invalid_argument& e){
        cout << e.what() << endl;
        estado = FALHA;
    }

    //ŧesting the last name
    if(estado == SUCESSO){
        try{
            sobrenome->setNome(SOBRENOME_VALIDO);
            if(sobrenome->getNome() != SOBRENOME_VALIDO){
                estado = FALHA;
            }
        }
        catch(invalid_argument& e){
            cout << e.what() << endl;
            estado = FALHA;
        }
    }

    //ŧesting the email
    if(estado == SUCESSO){
        try{
            email->setEmail(EMAIL_VALIDO);
            if(email->getEmail() != EMAIL_VALIDO){
                estado = FALHA;
            }
        }
        catch(invalid_argument& e){
            cout << e.what() << endl;
            estado = FALHA;
        }
    }

    //ŧesting the password
    if(estado == SUCESSO){
        try{
            senha->setSenha(SENHA_VALIDA);
            if(senha->getSenha() != SENHA_VALIDA){
                estado = FALHA;
            }
        }
        catch(invalid_argument& e){
            cout << e.what() << endl;
            estado = FALHA;
        }
    }


    //ŧesting the attribute nome inside the object leitor
    if(estado == SUCESSO){
        try{
            leitor->setNome(nome->getNome());
            if(leitor->getNome() != nome->getNome()){
                estado = FALHA;
            }
        }
        catch(invalid_argument& e){
            cout << e.what() << endl;
            estado = FALHA;
        }
    }

    //ŧesting the attribute sobrenome inside the object leitor
    if(estado == SUCESSO){
        try{
            leitor->setSobrenome(sobrenome->getNome());
            if(leitor->getSobrenome() != sobrenome->getNome()){
                estado = FALHA;
            }
        }
        catch(invalid_argument& e){
            cout << e.what() << endl;
            estado = FALHA;
        }
    }

    //ŧesting the attribute email inside the object leitor
    if(estado == SUCESSO){
        try{
            leitor->setEmail(email->getEmail());
            if(leitor->getEmail() != email->getEmail()){
                estado = FALHA;
            }
        }
        catch(invalid_argument& e){
            cout << e.what() << endl;
            estado = FALHA;
        }
    }

    //ŧesting the attribute senha inside the object leitor
    if(estado == SUCESSO){
        try{
            leitor->setSenha(senha->getSenha());
            if(leitor->getSenha() != senha->getSenha()){
                estado = FALHA;
            }
        }
        catch(invalid_argument& e){
            cout << e.what() << endl;
            estado = FALHA;
        }
    }

}

//defining the method run that will test the code
int TULeitor::run(){
    setUp();
    testarCenarioCorreto();
    tearDown();

    return estado;
}

/*
ATTRIBUTES AND METHODS OD THE CLASS TUDesenvolvedor
*/
//definition of NOME_VALIDO
const string TUDesenvolvedor::NOME_VALIDO = "Carlos";
//definition of SOBRENOME_VALIDO
const string TUDesenvolvedor::SOBRENOME_VALIDO = "Austriaco";
//definition of EMAIL_VALIDO
const string TUDesenvolvedor::EMAIL_VALIDO = "cgaa1103@gmail";
//definition of SENHA_VALIDA
const string TUDesenvolvedor::SENHA_VALIDA = "Aa110396";
//definition of DATA_VALIDA
const string TUDesenvolvedor::DATA_VALIDA = "11/03/1996";

//defining the method setUp to allocate the memory to objects and
//set the attribute estado
void TUDesenvolvedor::setUp(){
    //allocate the memory of the attributes of Desenvolvedor
    nome = new Nome();
    sobrenome = new Sobrenome();
    email = new Email();
    senha = new Senha();
    data = new Data();
    //alocate the memory of the object from the class Leitor
    desenvolvedor = new Desenvolvedor();

    estado = SUCESSO;
}

//defining the method tearDown to desallocate the
//memory of the objects
void TUDesenvolvedor::tearDown(){
    delete nome;
    delete sobrenome;
    delete email;
    delete senha;
    delete data;
    delete desenvolvedor;
}

//defining the method testarCenarioCorreto setting the Desenvolvedor
//with the attributes:
//NOME_VALIDO
//SOBRENOME_VALIDO
//EMAIL_VALIDO
//SENHA_VALIDA
//DATA_VALIDA
void TUDesenvolvedor::testarCenarioCorreto(){
    //testing the name
    try{
        nome->setNome(NOME_VALIDO);
        if(nome->getNome() != NOME_VALIDO){
            estado = FALHA;
        }
    }
    catch(invalid_argument& e){
        cout << e.what() << endl;
        estado = FALHA;
    }

    //ŧesting the last name
    if(estado == SUCESSO){
        try{
            sobrenome->setNome(SOBRENOME_VALIDO);
            if(sobrenome->getNome() != SOBRENOME_VALIDO){
                estado = FALHA;
            }
        }
        catch(invalid_argument& e){
            cout << e.what() << endl;
            estado = FALHA;
        }
    }

    //ŧesting the email
    if(estado == SUCESSO){
        try{
            email->setEmail(EMAIL_VALIDO);
            if(email->getEmail() != EMAIL_VALIDO){
                estado = FALHA;
            }
        }
        catch(invalid_argument& e){
            cout << e.what() << endl;
            estado = FALHA;
        }
    }

    //ŧesting the password
    if(estado == SUCESSO){
        try{
            senha->setSenha(SENHA_VALIDA);
            if(senha->getSenha() != SENHA_VALIDA){
                estado = FALHA;
            }
        }
        catch(invalid_argument& e){
            cout << e.what() << endl;
            estado = FALHA;
        }
    }

    //ŧesting the date
    if(estado == SUCESSO){
        try{
            data->setData(DATA_VALIDA);
            if(data->getData() != DATA_VALIDA){
                estado = FALHA;
            }
        }
        catch(invalid_argument& e){
            cout << e.what() << endl;
            estado = FALHA;
        }
    }

    //ŧesting the attribute nome inside the object desenvolvedor
    if(estado == SUCESSO){
        try{
            desenvolvedor->setNome(nome->getNome());
            if(desenvolvedor->getNome() != nome->getNome()){
                estado = FALHA;
            }
        }
        catch(invalid_argument& e){
            cout << e.what() << endl;
            estado = FALHA;
        }
    }

    //ŧesting the attribute sobrenome inside the object desenvolvedor
    if(estado == SUCESSO){
        try{
            desenvolvedor->setSobrenome(sobrenome->getNome());
            if(desenvolvedor->getSobrenome() != sobrenome->getNome()){
                estado = FALHA;
            }
        }
        catch(invalid_argument& e){
            cout << e.what() << endl;
            estado = FALHA;
        }
    }

    //ŧesting the attribute email inside the object desenvolvedor
    if(estado == SUCESSO){
        try{
            desenvolvedor->setEmail(email->getEmail());
            if(desenvolvedor->getEmail() != email->getEmail()){
                estado = FALHA;
            }
        }
        catch(invalid_argument& e){
            cout << e.what() << endl;
            estado = FALHA;
        }
    }

    //ŧesting the attribute senha inside the object desenvolvedor
    if(estado == SUCESSO){
        try{
            desenvolvedor->setSenha(senha->getSenha());
            if(desenvolvedor->getSenha() != senha->getSenha()){
                estado = FALHA;
            }
        }
        catch(invalid_argument& e){
            cout << e.what() << endl;
            estado = FALHA;
        }
    }

    //ŧesting the attribute data inside the object desenvolvedor
    if(estado == SUCESSO){
        try{
            desenvolvedor->setData(data->getData());
            if(desenvolvedor->getData() != data->getData()){
                estado = FALHA;
            }
        }
        catch(invalid_argument& e){
            cout << e.what() << endl;
            estado = FALHA;
        }
    }
}

//defining the method run that will test the code
int TUDesenvolvedor::run(){
    setUp();
    testarCenarioCorreto();
    tearDown();

    return estado;
}

/*
ATTRIBUTES AND METHODS OF THE CLASS TUAdministrador
*/
//definition of NOME_VALIDO
const string TUAdministrador::NOME_VALIDO = "Carlos";
//definition of SOBRENOME_VALIDO
const string TUAdministrador::SOBRENOME_VALIDO = "Austriaco";
//definition of EMAIL_VALIDO
const string TUAdministrador::EMAIL_VALIDO = "cgaa1103@gmail";
//definition of SENHA_VALIDA
const string TUAdministrador::SENHA_VALIDA = "Aa110396";
//definition of DATA_VALIDA
const string TUAdministrador::DATA_VALIDA = "11/03/1996";
//definition of TELEFONE_VALIDO
const string TUAdministrador::TELEFONE_VALIDO = "61 98199-3449";
//definition of ENDERECO VALIDO
const string TUAdministrador::ENDERECO_VALIDO = "SEPS 713 Qd. 5";

//defining the method setUp to allocate the memory to objects and
//set the attribute estado
void TUAdministrador::setUp(){
    //allocate the memory of the attributes of Administrador
    nome = new Nome();
    sobrenome = new Sobrenome();
    email = new Email();
    senha = new Senha();
    data = new Data();
    telefone = new Telefone();
    endereco = new Endereco();

    //alocate the memory of the object from the class Administrador
    administrador = new Administrador();

    estado = SUCESSO;
}

//defining the method tearDown to desallocate the
//memory of the objects
void TUAdministrador::tearDown(){
    delete nome;
    delete sobrenome;
    delete email;
    delete senha;
    delete data;
    delete telefone;
    delete endereco;
    delete administrador;
}

//defining the method testarCenarioCorreto setting the Administrador
//with the attributes:
//NOME_VALIDO
//SOBRENOME_VALIDO
//EMAIL_VALIDO
//SENHA_VALIDA
//DATA_VALIDA
//TELEFONE_VALIDO
//ENDERECO_VALIDO
void TUAdministrador::testarCenarioCorreto(){
    //testing the name
    try{
        nome->setNome(NOME_VALIDO);
        if(nome->getNome() != NOME_VALIDO){
            estado = FALHA;
        }
    }
    catch(invalid_argument& e){
        cout << e.what() << endl;
        estado = FALHA;
    }

    //ŧesting the last name
    if(estado == SUCESSO){
        try{
            sobrenome->setNome(SOBRENOME_VALIDO);
            if(sobrenome->getNome() != SOBRENOME_VALIDO){
                estado = FALHA;
            }
        }
        catch(invalid_argument& e){
            cout << e.what() << endl;
            estado = FALHA;
        }
    }

    //ŧesting the email
    if(estado == SUCESSO){
        try{
            email->setEmail(EMAIL_VALIDO);
            if(email->getEmail() != EMAIL_VALIDO){
                estado = FALHA;
            }
        }
        catch(invalid_argument& e){
            cout << e.what() << endl;
            estado = FALHA;
        }
    }

    //ŧesting the password
    if(estado == SUCESSO){
        try{
            senha->setSenha(SENHA_VALIDA);
            if(senha->getSenha() != SENHA_VALIDA){
                estado = FALHA;
            }
        }
        catch(invalid_argument& e){
            cout << e.what() << endl;
            estado = FALHA;
        }
    }

    //ŧesting the date
    if(estado == SUCESSO){
        try{
            data->setData(DATA_VALIDA);
            if(data->getData() != DATA_VALIDA){
                estado = FALHA;
            }
        }
        catch(invalid_argument& e){
            cout << e.what() << endl;
            estado = FALHA;
        }
    }

    //ŧesting the telephone
    if(estado == SUCESSO){
        try{
            telefone->setTelefone(TELEFONE_VALIDO);
            if(telefone->getTelefone() != TELEFONE_VALIDO){
                estado = FALHA;
            }
        }
        catch(invalid_argument& e){
            cout << e.what() << endl;
            estado = FALHA;
        }
    }

    //ŧesting the address
    if(estado == SUCESSO){
        try{
            endereco->setEndereco(ENDERECO_VALIDO);
            if(endereco->getEndereco() != ENDERECO_VALIDO){
                estado = FALHA;
            }
        }
        catch(invalid_argument& e){
            cout << e.what() << endl;
            estado = FALHA;
        }
    }

    //ŧesting the attribute nome inside the object administrador
    if(estado == SUCESSO){
        try{
            administrador->setNome(nome->getNome());
            if(administrador->getNome() != nome->getNome()){
                estado = FALHA;
            }
        }
        catch(invalid_argument& e){
            cout << e.what() << endl;
            estado = FALHA;
        }
    }

    //ŧesting the attribute sobrenome inside the object administrador
    if(estado == SUCESSO){
        try{
            administrador->setSobrenome(sobrenome->getNome());
            if(administrador->getSobrenome() != sobrenome->getNome()){
                estado = FALHA;
            }
        }
        catch(invalid_argument& e){
            cout << e.what() << endl;
            estado = FALHA;
        }
    }

    //ŧesting the attribute email inside the object administrador
    if(estado == SUCESSO){
        try{
            administrador->setEmail(email->getEmail());
            if(administrador->getEmail() != email->getEmail()){
                estado = FALHA;
            }
        }
        catch(invalid_argument& e){
            cout << e.what() << endl;
            estado = FALHA;
        }
    }

    //ŧesting the attribute senha inside the object administrador
    if(estado == SUCESSO){
        try{
            administrador->setSenha(senha->getSenha());
            if(administrador->getSenha() != senha->getSenha()){
                estado = FALHA;
            }
        }
        catch(invalid_argument& e){
            cout << e.what() << endl;
            estado = FALHA;
        }
    }

    //ŧesting the attribute data inside the object administrador
    if(estado == SUCESSO){
        try{
            administrador->setData(data->getData());
            if(administrador->getData() != data->getData()){
                estado = FALHA;
            }
        }
        catch(invalid_argument& e){
            cout << e.what() << endl;
            estado = FALHA;
        }
    }

    //ŧesting the attribute telefone inside the object administrador
    if(estado == SUCESSO){
        try{
            administrador->setTelefone(telefone->getTelefone());
            if(administrador->getTelefone() != telefone->getTelefone()){
                estado = FALHA;
            }
        }
        catch(invalid_argument& e){
            cout << e.what() << endl;
            estado = FALHA;
        }
    }

    //ŧesting the attribute endereco inside the object administrador
    if(estado == SUCESSO){
        try{
            administrador->setEndereco(endereco->getEndereco());
            if(administrador->getEndereco() != endereco->getEndereco()){
                estado = FALHA;
            }
        }
        catch(invalid_argument& e){
            cout << e.what() << endl;
            estado = FALHA;
        }
    }
}

//defining the method run that will test the code
int TUAdministrador::run(){
    setUp();
    testarCenarioCorreto();
    tearDown();

    return estado;
}

/*
ATTRIBUTES AND METHODS OF THE CLASS TUVocabulario
*/
//definition of NOME_VALIDO
const string TUVocabulario::NOME_VALIDO = "Carlos";
//definition of IDIOMA_VALIDO
const string TUVocabulario::IDIOMA_VALIDO = "ENG";
//definition of DATA_VALIDA
const string TUVocabulario::DATA_VALIDA = "11/03/1996";

//defining the method setUp to allocate the memory to objects and
//set the attribute estado
void TUVocabulario::setUp(){
    //allocate the memory of the attributes of Vocabulario
    nome = new Nome();
    idioma = new Idioma();
    data = new Data();

    //alocate the memory of the object from the class Vocabulario
    vocabulario = new Vocabulario();

    estado = SUCESSO;
}

//defining the method tearDown to desallocate the
//memory of the objects
void TUVocabulario::tearDown(){
    delete nome;
    delete idioma;
    delete data;
    delete vocabulario;
}

//defining the method testarCenarioCorreto setting the Vocabulario
//with the attributes:
//NOME_VALIDO
//IDIOMA_VALIDO
//DATA_VALIDA
void TUVocabulario::testarCenarioCorreto(){
    //testing the name
    try{
        nome->setNome(NOME_VALIDO);
        if(nome->getNome() != NOME_VALIDO){
            estado = FALHA;
        }
    }
    catch(invalid_argument& e){
        cout << e.what() << endl;
        estado = FALHA;
    }

    //ŧesting the language
    if(estado == SUCESSO){
        try{
            idioma->setIdioma(IDIOMA_VALIDO);
            if(idioma->getIdioma() != IDIOMA_VALIDO){
                estado = FALHA;
            }
        }
        catch(invalid_argument& e){
            cout << e.what() << endl;
            estado = FALHA;
        }
    }

    //ŧesting the date
    if(estado == SUCESSO){
        try{
            data->setData(DATA_VALIDA);
            if(data->getData() != DATA_VALIDA){
                estado = FALHA;
            }
        }
        catch(invalid_argument& e){
            cout << e.what() << endl;
            estado = FALHA;
        }
    }

    //ŧesting the attribute nome inside the object vocabulario
    if(estado == SUCESSO){
        try{
            vocabulario->setNome(nome->getNome());
            if(vocabulario->getNome() != nome->getNome()){
                estado = FALHA;
            }
        }
        catch(invalid_argument& e){
            cout << e.what() << endl;
            estado = FALHA;
        }
    }

    //ŧesting the attribute idioma inside the object vocabulario
    if(estado == SUCESSO){
        try{
            vocabulario->setIdioma(idioma->getIdioma());
            if(vocabulario->getIdioma() != idioma->getIdioma()){
                estado = FALHA;
            }
        }
        catch(invalid_argument& e){
            cout << e.what() << endl;
            estado = FALHA;
        }
    }

    //ŧesting the attribute data inside the object vocabulario
    if(estado == SUCESSO){
        try{
            vocabulario->setData(data->getData());
            if(vocabulario->getData() != data->getData()){
                estado = FALHA;
            }
        }
        catch(invalid_argument& e){
            cout << e.what() << endl;
            estado = FALHA;
        }
    }
}

//defining the method run that will test the code
int TUVocabulario::run(){
    setUp();
    testarCenarioCorreto();
    tearDown();

    return estado;
}

/*
ATTRIBUTES AND METHODS OF THE CLASS TUTermo
*/
//definition of NOME_VALIDO
const string TUTermo::NOME_VALIDO = "Carlos";
//definition of PREFERENCIA_VALIDA
const string TUTermo::PREFERENCIA_VALIDA = "NP";
//definition of DATA_VALIDA
const string TUTermo::DATA_VALIDA = "11/03/1996";

//defining the method setUp to allocate the memory to objects and
//set the attribute estado
void TUTermo::setUp(){
    //allocate the memory of the attributes of Termo
    nome = new Nome();
    preferencia = new Preferencia();
    data = new Data();

    //alocate the memory of the object from the class Termo
    termo = new Termo();

    estado = SUCESSO;
}

//defining the method tearDown to desallocate the
//memory of the objects
void TUTermo::tearDown(){
    delete nome;
    delete preferencia;
    delete data;
    delete termo;
}

//defining the method testarCenarioCorreto setting the Termo
//with the attributes:
//NOME_VALIDO
//PREFERENCIA_VALIDA
//DATA_VALIDA
void TUTermo::testarCenarioCorreto(){
    //testing the name
    try{
        nome->setNome(NOME_VALIDO);
        if(nome->getNome() != NOME_VALIDO){
            estado = FALHA;
        }
    }
    catch(invalid_argument& e){
        cout << e.what() << endl;
        estado = FALHA;
    }

    //ŧesting the preference
    if(estado == SUCESSO){
        try{
            preferencia->setPreferencia(PREFERENCIA_VALIDA);
            if(preferencia->getPreferencia() != PREFERENCIA_VALIDA){
                estado = FALHA;
            }
        }
        catch(invalid_argument& e){
            cout << e.what() << endl;
            estado = FALHA;
        }
    }

    //ŧesting the date
    if(estado == SUCESSO){
        try{
            data->setData(DATA_VALIDA);
            if(data->getData() != DATA_VALIDA){
                estado = FALHA;
            }
        }
        catch(invalid_argument& e){
            cout << e.what() << endl;
            estado = FALHA;
        }
    }

    //ŧesting the attribute nome inside the object termo
    if(estado == SUCESSO){
        try{
            termo->setNome(nome->getNome());
            if(termo->getNome() != nome->getNome()){
                estado = FALHA;
            }
        }
        catch(invalid_argument& e){
            cout << e.what() << endl;
            estado = FALHA;
        }
    }

    //ŧesting the attribute preferencia inside the object termo
    if(estado == SUCESSO){
        try{
            termo->setPreferencia(preferencia->getPreferencia());
            if(termo->getPreferencia() != preferencia->getPreferencia()){
                estado = FALHA;
            }
        }
        catch(invalid_argument& e){
            cout << e.what() << endl;
            estado = FALHA;
        }
    }

    //ŧesting the attribute data inside the object termo
    if(estado == SUCESSO){
        try{
            termo->setData(data->getData());
            if(termo->getData() != data->getData()){
                estado = FALHA;
            }
        }
        catch(invalid_argument& e){
            cout << e.what() << endl;
            estado = FALHA;
        }
    }
}

//defining the method run that will test the code
int TUTermo::run(){
    setUp();
    testarCenarioCorreto();
    tearDown();

    return estado;
}

/*
ATTRIBUTES AND METHODS OF THE CLASS TUDefinicao
*/
//definition of TEXTO_VALIDO
const string TUDefinicao::TEXTO_VALIDO = "Carlos Gabriel Atta";
//definition of DATA_VALIDA
const string TUDefinicao::DATA_VALIDA = "11/03/1996";

//defining the method setUp to allocate the memory to objects and
//set the attribute estado
void TUDefinicao::setUp(){
    //allocate the memory of the attributes of Definicao
    texto = new Texto();
    data = new Data();

    //alocate the memory of the object from the class Definicao
    definicao = new Definicao();

    estado = SUCESSO;
}

//defining the method tearDown to desallocate the
//memory of the objects
void TUDefinicao::tearDown(){
    delete texto;
    delete data;
    delete definicao;
}

//defining the method testarCenarioCorreto setting the Definicao
//with the attributes:
//TEXTO_VALIDO
//DATA_VALIDA
void TUDefinicao::testarCenarioCorreto(){
    //testing the definition text
    try{
        texto->setTexto(TEXTO_VALIDO);
        if(texto->getTexto() != TEXTO_VALIDO){
            estado = FALHA;
        }
    }
    catch(invalid_argument& e){
        cout << e.what() << endl;
        estado = FALHA;
    }

    //ŧesting the date
    if(estado == SUCESSO){
        try{
            data->setData(DATA_VALIDA);
            if(data->getData() != DATA_VALIDA){
                estado = FALHA;
            }
        }
        catch(invalid_argument& e){
            cout << e.what() << endl;
            estado = FALHA;
        }
    }

    //ŧesting the attribute texto inside the object definicao
    if(estado == SUCESSO){
        try{
            definicao->setTexto(texto->getTexto());
            if(definicao->getTexto() != texto->getTexto()){
                estado = FALHA;
            }
        }
        catch(invalid_argument& e){
            cout << e.what() << endl;
            estado = FALHA;
        }
    }

    //ŧesting the attribute data inside the object definicao
    if(estado == SUCESSO){
        try{
            definicao->setData(data->getData());
            if(definicao->getData() != data->getData()){
                estado = FALHA;
            }
        }
        catch(invalid_argument& e){
            cout << e.what() << endl;
            estado = FALHA;
        }
    }
}

//defining the method run that will test the code
int TUDefinicao::run(){
    setUp();
    testarCenarioCorreto();
    tearDown();

    return estado;
}

/*
ATTRIBUTES AND METHODS OF THE CLASS TUDominio
*/
//definition of the method that will test all the domains
void TUDominio::run(){
    //testing the name
    switch(nome.run()){
        case TUNomeGeral::SUCESSO:
            cout << "NOME: SUCESSO" << endl;
            break;

        case TUNomeGeral::FALHA:
            cout << "NOME: FALHA" << endl;
    }

    //testing the last name
    switch(sobrenome.run()){
        case TUNomeGeral::SUCESSO:
            cout << "SOBRENOME: SUCESSO" << endl;
            break;

        case TUNomeGeral::FALHA:
            cout << "SOBRENOME: FALHA" << endl;
    }

    //testing the telephone
    switch(telefone.run()){
        case TUTelefone::SUCESSO:
            cout << "TELEFONE: SUCESSO" << endl;
            break;

        case TUTelefone::FALHA:
            cout << "TELEFONE: FALHA" << endl;
    }

    //testing the address
    switch(endereco.run()){
        case TUEndereco::SUCESSO:
            cout << "ENDERECO: SUCESSO" << endl;
            break;

        case TUEndereco::FALHA:
            cout << "ENDERECO: FALHA" << endl;
    }

    //testing the date
    switch(data.run()){
        case TUData::SUCESSO:
            cout << "DATA: SUCESSO" << endl;
            break;

        case TUData::FALHA:
            cout << "DATA: FALHA" << endl;
    }

    //testing the email
    switch(email.run()){
        case TUEmail::SUCESSO:
            cout << "EMAIL: SUCESSO" << endl;
            break;

        case TUEmail::FALHA:
            cout << "EMAIL: FALHA" << endl;
    }

    //testing the password
    switch(senha.run()){
        case TUSenha::SUCESSO:
            cout << "SENHA: SUCESSO" << endl;
            break;

        case TUSenha::FALHA:
            cout << "SENHA: FALHA" << endl;
    }

    //testing the definition text
    switch(texto.run()){
        case TUTexto::SUCESSO:
            cout << "TEXTO DE DEFINICAO: SUCESSO" << endl;
            break;

        case TUTexto::FALHA:
            cout << "TEXTO DE DEFINICAO: FALHA" << endl;
    }

    //testing the language
    switch(idioma.run()){
        case TUIdioma::SUCESSO:
            cout << "IDIOMA: SUCESSO" << endl;
            break;

        case TUIdioma::FALHA:
            cout << "IDIOMA: FALHA" << endl;
    }

    //testing the preference
    switch(preferencia.run()){
        case TUPreferencia::SUCESSO:
            cout << "PREFERENCIA: SUCESSO" << endl;
            break;

        case TUPreferencia::FALHA:
            cout << "PREFERENCIA: FALHA" << endl;
    }
}

/*
ATTRIBUTES AND METHODS OF THE CLASS TUEntidade
*/
//definition of the method to test all the entities
void TUEntidade::run(){
    //testing the reader
    switch(leitor.run()){
        case TULeitor::SUCESSO:
            cout << "LEITOR: SUCESSO" << endl;
            break;

        case TULeitor::FALHA:
            cout << "LEITOR: FALHA" << endl;
    }

    //testing the developer
    switch(desenvolvedor.run()){
        case TUDesenvolvedor::SUCESSO:
            cout << "DESENVOLVEDOR: SUCESSO" << endl;
            break;

        case TUDesenvolvedor::FALHA:
            cout << "DESENVOLVEDOR: FALHA" << endl;
    }

    //testing the administrator
    switch(administrador.run()){
        case TUAdministrador::SUCESSO:
            cout << "ADMINISTRADOR: SUCESSO" << endl;
            break;

        case TUAdministrador::FALHA:
            cout << "ADMINISTRADOR: FALHA" << endl;
    }

    //testing the vocabulary
    switch(vocabulario.run()){
        case TUVocabulario::SUCESSO:
            cout << "VOCABULARIO: SUCESSO" << endl;
            break;

        case TUVocabulario::FALHA:
            cout << "VOCABULARIO: FALHA" << endl;
    }

    //testing the term
    switch(termo.run()){
        case TUTermo::SUCESSO:
            cout << "TERMO: SUCESSO" << endl;
            break;

        case TUTermo::FALHA:
            cout << "TERMO: FALHA" << endl;
    }

    //testing the definition
    switch(definicao.run()){
        case TUDefinicao::SUCESSO:
            cout << "DEFINICAO: SUCESSO" << endl;
            break;

        case TUDefinicao::FALHA:
            cout << "DEFINICAO: FALHA" << endl;
    }
}

/*
ATTRIBUTES AND METHODS OF THE CLASS TU
*/
//the method that will run the tests
void TU::run(){
    //testing the domains
    cout << "TESTANDO OS DOMINIOS:" << endl;
    dominio.run();

    cout << "\n";

    //testing the entities
    cout << "TESTANDO AS ENTIDADES:" << endl;
    entidade.run();
}
