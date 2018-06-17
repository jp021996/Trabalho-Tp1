#include "dominios.hpp"

using namespace std;

/*
METHODS AND ATTRIBUTES OF THE CLASS NomeGeral
*/

void NomeGeral::setNome(const string& str) throw(invalid_argument){
    validar(str);
    nome = str;
}

string NomeGeral::getNome() const{
    return nome;
}

//definition of the method relative to check if the rules of
//the name are correct
void NomeGeral::validar(const string& str) throw(invalid_argument){
    string::const_iterator it = str.begin();

    //check the size
    if(str.size() > MAXSIZE){
        throw invalid_argument("TAMANHO EXCEDIDO!");
    }

    //check if the first letter is uppercase
    if((str[0] < 'A') || str[0] > 'Z'){
        throw invalid_argument("PRIMEIRA LETRA DEVE SER MAIUSCULA");
    }

    //check if there is any prohibited character
    for(; it != str.end(); ++it){
        //verify if the letter is uppercase
        if((*it >= 'A') && (*it <= 'Z')){
            continue;
        }
        //verify if the letter is lowercase
        if((*it >= 'a') && (*it <= 'z')){
            continue;
        }

        throw invalid_argument("CARACTER INVALIDO");
    }
}

/*
METHODS AND ATRIBUTES OF THE CLASS Telefone
*/

//definition of the method relative to set the telephone
void Telefone::setTelefone(const string& str) throw(invalid_argument){
    validar(str);
    telefone = str;
}

//definition of the method relative to get the telephone
string Telefone::getTelefone() const{
    return telefone;
}

//definition of the method relative to check if the
//number of telephone is correct
void Telefone::validar(const string& str) throw(invalid_argument){
    string::const_iterator it = str.begin();
    unsigned int counter;


    //check the DDD
    if((*it < '0') || (*it > '9')){
        throw invalid_argument("DDD INCORRETO");
    }
    ++it;
    if((*it < '0') || (*it > '9')){
        throw invalid_argument("DDD INCORRETO");
    }

    //check the space after the DDD
    ++it;
    if(*it != ' '){
        throw invalid_argument("FORMATO INCORRETO");
    }
    //check the numbers after the space and before the -
    for(counter = 0; counter < MAX_SIZE1; ++counter){
       ++it;
       if((*it < '0') || (*it > '9')){
            throw invalid_argument("TELEFONE INCORRETO");
       }
    }

    //check if there is a - after the part of the telephone
    ++it;
    if(*it != '-'){
        throw invalid_argument("FORMATO INCORRETO");
    }

    //check the numbers after the -
    for(counter = 0; counter < MAX_SIZE2; ++counter){
       ++it;
       if((*it < '0') || (*it > '9')){
            throw invalid_argument("TELEFONE INCORRETO");
       }
    }

    //check if there is anything after the end of the regular telephone
    if(str.size() > MAX_SIZE){
        throw invalid_argument("TELEFONE INCORRETO");
    }
}

/*
METHODS AND ATTRIBUTES OF THE CLASS Endereco
*/

//definition of the method relative to set the address
void Endereco::setEndereco(const string& str){
    validar(str);
    endereco = str;
}

//definition of the method relative to get the address
string Endereco::getEndereco() const{
    return endereco;
}

//definition of the method relative to check if
//the address is correct
void Endereco::validar(const string& str) throw(invalid_argument){
    string::const_iterator it = str.begin();

    //check if the length is valid
    if(str.size() > MAX){
        throw invalid_argument("TAMANHO EXCEDIDO");
    }

    //check if the first character is a space
    if(*it == ' '){
        throw invalid_argument("COMECO COM ESPACO");
    }

    //check the characters along the address
    for(; it != str.end(); ++it){
        //checking if the character is a number
        if((*it >= '0') && (*it <= '9')){
            continue;
        }

        //checking if the character is a uppercase letter
        if((*it >= 'A') && (*it <= 'Z')){
            continue;
        }

        //checking if the character is a lowercase letter
        if((*it >= 'a') && (*it <= 'z')){
            continue;
        }

        //checking if the character is a . or ,
        if((*it == '.') || (*it == ',')){
            continue;
        }

        //checking if the last character is a space
        if(*(str.end()-1) == ' '){
            throw invalid_argument("FORMATO INCORRETO");
        }

        //checking if there are two spaces in a row
        if(*it == ' '){
            if(*(it+1) == ' '){
                throw invalid_argument("FORMATO INCORRETO");
            }
            else{
                continue;
            }
        }

        //if passes of all these tests, the character is invalid
        throw invalid_argument("CARACTER INVALIDO");
    }
}

/*
ATTRIBUTES AND METHODS OF THE CLASS Data
*/
//definition of the method relative to set the date
void Data::setData(const string& str){
    validar(str);
    data = str;
}

//definition of the method relative to get the date
string Data::getData() const{
    return data;
}

//definition of the method relative to check if
//the date is correct
void Data::validar(const string& str) throw(invalid_argument){
    string auxDia = ""; //getting the days from the string
    string auxMes = ""; //getting the months from the string
    string auxAno = ""; //getting the year from the string
    int dia;
    int mes;
    int ano;

    //throw an exception if the date is longer than the allowed
    if(str.size() > MAX){
        throw invalid_argument("FORMATO INCORRETO. DIGITE NO FORMATO: DD/MM/AAAA");
    }

    //checking the slashes
    if((str[2] != '/') || (str[5] != '/')){
        throw invalid_argument("FORMATO INCORRETO, DIGITE NO FORMATO: DD/MM/AAAA");
    }

    //checking if there is any invalid character on the days
    if((str[0] < '0') || (str[0] > '9')){
        throw invalid_argument("DIA INVALIDO");
    }

    if((str[1] < '0') || (str[1] > '9')){
        throw invalid_argument("DIA INVALIDO");
    }

    auxDia += str[0];
    auxDia += str[1];

    //checking if there is any invalid character on the months
    if((str[3] < '0') || (str[3] > '9')){
        throw invalid_argument("MES INVALIDO");
    }

    if((str[4] < '0') || (str[4] > '9')){
        throw invalid_argument("MES INVALIDO");
    }

    auxMes += str[3];
    auxMes += str[4];

    //checking if there is any invalid character on the year
    if((str[6] < '0') || (str[6] > '9')){
        throw invalid_argument("ANO INVALIDO");
    }

    if((str[7] < '0') || (str[7] > '9')){
        throw invalid_argument("ANO INVALIDO");
    }

    if((str[8] < '0') || (str[8] > '9')){
        throw invalid_argument("ANO INVALIDO");
    }

    if((str[9] < '0') || (str[9] > '9')){
        throw invalid_argument("ANO INVALIDO");
    }

    auxAno += str[6];
    auxAno += str[7];
    auxAno += str[8];
    auxAno += str[9];

    //converting the strings to int
    dia = stoi(auxDia);
    mes = stoi(auxMes);
    ano = stoi(auxAno);

    //checking if it is a valid month
    if((mes < 1) || (mes > 12)){
        throw invalid_argument("MES INVALIDO");
    }

    //checking the valid date with the relationshp between days and months
    //the months with 31 days: January, March, May, July, August, October and December
    if((mes == 1) || (mes == 3) || (mes == 5) || (mes == 7) || (mes == 8) || (mes == 10) || (mes == 12)){
        if((dia < 1) || (dia > 31)){
            throw invalid_argument("DATA INVALIDA");
        }
    }

    //the months with 30 days: April, June, September and November
    if((mes == 4) || (mes == 6) || (mes == 9) || (mes == 11)){
        if((dia < 1) || (dia > 30)){
            throw invalid_argument("DATA INVALIDA");
        }
    }

    //the February month
    if(mes == 2){
        if(bissexto(ano)){
            if((dia < 1) || (dia > 29)){
                throw invalid_argument("DATA INVALIDA");
            }
        }
        else{
            if((dia < 1) || (dia > 28)){
                throw invalid_argument("DATA INVALIDA");
            }
        }
    }

    //checking if the year is below 1900 or above 2099
    if((ano < 1900) || (ano > 2099)){
        throw invalid_argument("ANO INVALIDO");
    }

}

//definition of the method to check if the year is a leap
bool Data::bissexto(int ano){
    if((ano % 100) == 0){
        if((ano % 400) == 0){
            return true;
        }
        else{
            return false;
        }
    }

    if((ano % 4) == 0){
        return true;
    }

    return false;
}

/*
ATTRIBUTES AND METHODS OF THE CLASS Email
*/
//definition of the method relative to set the email
void Email::setEmail(const string& str){
    validar(str);
    email = str;
}

//definition of the method relative to get the email
string Email::getEmail() const{
    return email;
}

//definition of the method relative to check if the mail respects the rules
void Email::validar(const string& str) throw(invalid_argument){
    string aux1; //the first part of the email
    string aux2; //the second part of the email
    string::iterator it;
    bool state = false; //a state to verify if the domain os only numbers

    //check if there is @ in the email
    if(str.find('@', 0) == string::npos){
        throw invalid_argument("EMAIL INVALIDO");
    }

    //defining aux1 as the substring before the @
    aux1 = str.substr(0, str.find('@'));
    //defining aux2 as the substring after the @
    aux2 = str.substr(str.find('@')+1,str.size());

    //checking the characters of the aux1
    if(*aux1.begin() == '.'){
        throw invalid_argument("EMAIL INVALIDO");
    }

    if(*(aux1.end()-1) == '.'){
        throw invalid_argument("EMAIL INVALIDO");
    }

    for(it = aux1.begin(); it != aux1.end(); ++it){
        if((*it >= 'a') && (*it <= 'z')){
            continue;
        }

        if((*it >= 'A') && (*it <= 'Z')){
            continue;
        }

        if((*it >= '0') && (*it <= '9')){
            continue;
        }

        //all possibles characters
        if((*it == '!') || (*it == '#') || (*it == '$') || (*it == '%') ||
        (*it == '&') || (*it == '\'') || (*it == '*') || (*it == '+') ||
        (*it == '-') || (*it == '/') || (*it == '=') || (*it == '?') ||
        (*it == '^') || (*it == '_') || (*it == '`') || (*it == '{') ||
        (*it == '|') || (*it == '}') || (*it == '~') || (*it == ';') || (*it == '.')){
            continue;
        }

        throw invalid_argument("EMAIL INVALIDO");
    }

    //checking the characters of the aux2
    if(*aux2.begin() == '-'){
        throw invalid_argument("EMAIL INVALIDO");
    }

    if(*(aux2.end()-1) == '-'){
        throw invalid_argument("EMAIL INVALIDO");
    }

    for(it = aux2.begin(); it != aux2.end(); ++it){
        if((*it >= 'a') && (*it <= 'z')){
            state = true;
            continue;
        }

        if((*it >= 'A') && (*it <= 'Z')){
            state = true;
            continue;
        }

        if((*it >= '0') && (*it <= '9')){
            continue;
        }

        if(*it == '-'){
            state = true;
            continue;
        }

        throw invalid_argument("EMAIL INVALIDO");
    }

    //checking if there are only numbers on the aux2
    if(!state){
        throw invalid_argument("EMAIL INVALIDO");
    }
}

/*
ATTRIBUTES AND METHODS OF THE CLASS Senha
*/

//definition of the method relative to set the password
void Senha::setSenha(const string& str){
    validar(str);
    senha = str;
}

//definition of the method relative to get the password
string Senha::getSenha() const{
    return senha;
}

//definition of the method relative to check if the mail respects the rules
void Senha::validar(const string& str) throw(invalid_argument){
    string::const_iterator it;
    //check if there is at least one uppercase, one lowercase and one number
    bool auxMaiuscula = false;
    bool auxMinuscula = false;
    bool auxNumero = false;

    //check if the size of the string is above MAX
    if(str.size() > MAX){
        throw invalid_argument("TAMANHO EXCEDIDO PARA SENHA");
    }

    //loop to verify the characters
    for(it = str.begin(); it != str.end(); ++it){
        if((*it >= 'a') && (*it <= 'z')){
            auxMinuscula = true;
            continue;
        }

        if((*it >= 'A') && (*it <= 'Z')){
            auxMaiuscula = true;
            continue;
        }

        if((*it >= '0') && (*it <= '9')){
            auxNumero = true;
            continue;
        }

        throw invalid_argument("SENHA COM CARACTER INVALIDO");
    }

    //checking if there is any uppercase, lowercase or number on the password
    if(!auxMaiuscula || !auxMinuscula || !auxNumero){
        throw invalid_argument("SENHA INVALIDA");
    }
}

/*
ATTRIBUTES AND METHODS OF THE CLASS Texto
*/

//definition of the method relative to set the definition text
void Texto::setTexto(const string& str)throw (invalid_argument){
    validar(str);
    texto = str;
}

//definition of the method relative to get the definition text
string Texto::getTexto() const{
    return texto;
}

//definition of the method relative to validate the definition text
void Texto::validar(const string& str) throw (invalid_argument){
    if(str.size() > MAX){
        throw invalid_argument("TAMANHO DE TEXTO EXCEDIDO");
    }
}

/*
ATTRIBUTES AND METHODS OF THE CLASS Idioma
*/
//definition of INGLES
const string Idioma::INGLES = "ENG";
//definition of FRANCES
const string Idioma::FRANCES = "FRA";
//definition of ALEMAO
const string Idioma::ALEMAO = "GER";
//definition of ITALIANO
const string Idioma::ITALIANO = "ITA";
//definition of PORTUGUES
const string Idioma::PORTUGUES = "POR";
//definition of ESPANHOL
const string Idioma::ESPANHOL = "SPA";


//definition of the method relative to set the language
void Idioma::setIdioma(const string& str){
    validar(str);
    idioma = str;
}

//definition of the method relative to get the language
string Idioma::getIdioma() const{
    return idioma;
}

//definition of the method relative to check if the language respects the rules
void Idioma::validar(const string& str) throw(invalid_argument){
    if((str != INGLES) && (str != FRANCES) && (str != ALEMAO) &&
    (str != ITALIANO) && (str != PORTUGUES) && (str != ESPANHOL)){
        throw invalid_argument("LINGUAGEM INCORRETA");
    }
}

/*
ATTRIBUTES AND METHODS OF THE CLASS Preferencia
*/
//definition of PT
const string Preferencia::PT = "PT";
//definition of NP
const string Preferencia::NP = "NP";

//definition of the method relative to set the preference of the term
void Preferencia::setPreferencia(const string& str){
    validar(str);
    preferencia = str;
}

//definition of the method relative to get the preference of the term
string Preferencia::getPreferencia() const{
    return preferencia;
}

//definition of the method if the preference check the rules
void Preferencia::validar(const string& str) throw(invalid_argument){
    if((str != PT) && (str != NP)){
        throw invalid_argument("PREFERENCIA INVALIDA");
    }
}
