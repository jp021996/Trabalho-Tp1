#include "entidades.hpp"

/*
ATTRIBUTES AND METHODS OF THE CLASS Leitor
*/
//definition of the method to set the name of the reader
void Leitor::setNome(const string& str){
    nome.setNome(str);
}

//definition of the method to get the name of the reader
string Leitor::getNome() const{
    return nome.getNome();
}

//definition of the method to set the last name of the reader
void Leitor::setSobrenome(const string& str){
    sobrenome.setNome(str);
}

//definition of the method to get the last name of the reader
string Leitor::getSobrenome() const{
    return sobrenome.getNome();
}

//definition of the method to set the email of the reader
void Leitor::setEmail(const string& str){
    email.setEmail(str);
}

//definition of the method to get the email of the reader
string Leitor::getEmail() const{
    return email.getEmail();
}

//definition of the method to set the password
void Leitor::setSenha(const string& str){
    senha.setSenha(str);
}

//definition of the method to get the password
string Leitor::getSenha() const{
    return senha.getSenha();
}

/*
ATTRIBUTES AND METHODS OF THE CLASS Desenvolvedor
*/
//definition of the method to set the date
void Desenvolvedor::setData(const string& str){
    data.setData(str);
}

//definition of the method to get the date
string Desenvolvedor::getData() const{
    return data.getData();
}

/*
ATTRIBUTES AND METHODS OF THE CLASS Administrador
*/
//definition of the method to set the telephone
void Administrador::setTelefone(const string& str){
    telefone.setTelefone(str);
}

//definition of the method to get the telephone
string Administrador::getTelefone() const{
    return telefone.getTelefone();
}

//definition of the method to set the address
void Administrador::setEndereco(const string& str){
    endereco.setEndereco(str);
}

//definition of the method to get the address
string Administrador::getEndereco() const{
    return endereco.getEndereco();
}

/*
ATTRIBUTES AND METHODS OF THE CLASS Vocabulario
*/
//definition of the method to set the name
void Vocabulario::setNome(const string& str){
    nome.setNome(str);
}

//definition of the method to get the name
string Vocabulario::getNome()const{
    return nome.getNome();
}

//definition of the method to set the language
void Vocabulario::setIdioma(const string& str){
    idioma.setIdioma(str);
}

//definition of the method to get language
string Vocabulario::getIdioma()const{
    return idioma.getIdioma();
}

//definition of the method to set the date
void Vocabulario::setData(const string& str){
    data.setData(str);
}

//definition of the method to get the date
string Vocabulario::getData()const{
    return data.getData();
}

/*
ATTRIBUTES AND METHODS OF THE CLASS Termo
*/
//definition of the method to set the name
void Termo::setNome(const string& str){
    nome.setNome(str);
}

//definition of the method to get the name
string Termo::getNome()const{
    return nome.getNome();
}

//definition of the method to set the preference
void Termo::setPreferencia(const string& str){
    preferencia.setPreferencia(str);
}

//definition of the method to get the preference
string Termo::getPreferencia()const{
    return preferencia.getPreferencia();
}

//definition of the method to set the date
void Termo::setData(const string& str){
    data.setData(str);
}

//definition of the method to get the date
string Termo::getData()const{
    return data.getData();
}

/*
ATTRIBUTES AND METHODS OF THE CLASS Definicao
*/
//definition of the method to set the definition text
void Definicao::setTexto(const string& str){
    texto.setTexto(str);
}

//definition of the method to get the definition text
string Definicao::getTexto()const {
    return texto.getTexto();
}

//definition of the method to set the date
void Definicao::setData(const string& str){
    data.setData(str);
}

//definition of the method to get the date
string Definicao::getData()const {
    return data.getData();
}
