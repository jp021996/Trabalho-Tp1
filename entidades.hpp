#ifndef ENTIDADES_H_INCLUDED
#define ENTIDADES_H_INCLUDED

#include "dominios.hpp"

///class that define the reader
class Leitor{
protected:
    //the attributes of the reader
    Nome nome;
    Sobrenome sobrenome;
    Email email;
    Senha senha;

public:
    ///the method to set the name of the reader
    void setNome(const string&);
    ///the method to get the name of the reader
    string getNome()const;
    ///the method to set the last name of the reader
    void setSobrenome(const string&);
    ///the method to get the last name of the reader
    string getSobrenome() const;
    ///the method to set the email of the reader
    void setEmail(const string&);
    ///the method to get the email of the reader
    string getEmail() const;
    ///the method to set the password of the reader
    void setSenha(const string&);
    ///the method to get the password of the reader
    string getSenha() const;
};

///class that define the developer
class Desenvolvedor : public Leitor{
protected:
    /*the developer will contain the same attributes of the reader
    the attributes of the developer*/
    Data data;

public:
    ///the method to set the date
    void setData(const string&);
    ///the method to get the date
    string getData() const;
};

///class that define the administrator
class Administrador : public Desenvolvedor{
    /*the administrator will contain the same attributes of the developer
    the attributes of the administrator*/
    Telefone telefone;
    Endereco endereco;

public:
    ///the method to set the telephone
    void setTelefone(const string&);
    ///the method to get the telephone
    string getTelefone()const;
    ///the method to set the address
    void setEndereco(const string&);
    ///the method to get the address
    string getEndereco() const;
};

///class that define the controled vocabulary
class Vocabulario{
    //the attributes of the controled vocabulary
    Nome nome;
    Idioma idioma;
    Data data;

public:
    ///the method to set the name
    void setNome(const string&);
    ///the method to get the name
    string getNome() const;
    ///the method to set the language
    void setIdioma(const string&);
    ///the method to get the language
    string getIdioma()const;
    ///the method to set the date
    void setData(const string&);
    ///the method to get the date
    string getData()const;
};

///class that define the term
class Termo{
    //the attributes of the term
    Nome nome;
    Preferencia preferencia;
    Data data;

public:
    ///the method to set the name
    void setNome(const string&);
    ///the method to get the name
    string getNome()const;
    ///the method to set the preference
    void setPreferencia(const string&);
    ///the method to get the preference
    string getPreferencia()const;
    ///the method to set the date
    void setData(const string&);
    ///the method to get the date
    string getData()const;
};

///class that define the definition of the term
class Definicao{
    //attributes of the definition
    Texto texto;
    Data data;

public:
    ///the method to set the definition text
    void setTexto(const string&);
    ///the method to get the definition text
    string getTexto() const;
    ///the method to set the date
    void setData(const string&);
    ///the method to get the date
    string getData()const ;
};
#endif // ENTIDADES_H_INCLUDED
