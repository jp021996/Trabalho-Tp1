#ifndef DOMINIOS_H_INCLUDED
#define DOMINIOS_H_INCLUDED

#include <string>
#include <iostream>
#include <stdexcept>

using namespace std;

/**class that define any kind of name, name or surname*/
class NomeGeral{
protected:
    /** attribute relative to any kind of name */
    string nome = "";
    /** max size of any kind of name */
    const static size_t MAXSIZE = 20;
    /** validate any kind of name if it respects the rules */
    void validar(const string&) throw(invalid_argument);
public:
    /** set the name */
    void setNome(const string&) throw(invalid_argument);
    /** get the name */
    string getNome() const;
};

///classe Nome that inherits the class NomeGeral
class Nome : public NomeGeral{

};

///class Sobrenome that inherits the class NomeGeral
class Sobrenome: public NomeGeral{

};

///class that define the telephone
class Telefone{
    ///attribute relative to the telephone
    string telefone = "";
    ///attribute relative to the max numbers of the first part of telephone
    const static int MAX_SIZE1 = 5;
    ///attribute relative to the max numbers of the second part of telephone
    const static int MAX_SIZE2 = 4;
    ///attribute relative to the max numbers of the telephone
    const static size_t MAX_SIZE = 13;
    ///validate the telephone if it respects the rules
    void validar(const string&) throw(invalid_argument);
public:
    ///set the telephone
    void setTelefone(const string&) throw(invalid_argument);
    ///get the telephone
    string getTelefone() const;
};

///class that defines the address
class Endereco{
    ///attribute relative to the address
    string endereco;
    ///attribute relative to the max number of elements of the address
    const static size_t MAX = 20;
    ///validate the address if it respects the rules
    void validar(const string&) throw(invalid_argument);
public:
    ///set the address
    void setEndereco(const string&);
    ///get the address
    string getEndereco() const;
};

///class that defines the date
class Data{
    ///attribute relative to the date
    string data;
    ///attribute relative to the max number of elements of the date
    const static size_t MAX = 10;
    ///validate the date if it respects the rules
    void validar(const string&) throw(invalid_argument);
    ///check if it is a leap year
    bool bissexto(int);
public:
    ///set the date
    void setData(const string&);
    ///get the date
    string getData() const;
};

///class that defines the email
class Email{
    ///attribute relative to the email
    string email;
    ///validate the email if it respects the rules
    void validar(const string&) throw(invalid_argument);
public:
    ///set the email
    void setEmail(const string&);
    ///get the email
    string getEmail() const;
};

///class that defines the password
class Senha{
    ///attribute relative to the password
    string senha;
    ///validate the password if it respects the rules
    void validar(const string&) throw(invalid_argument);
    ///attribute relative to the max size of the password
    const static int MAX = 8;
public:
    ///set the password
    void setSenha(const string&);
    ///get the password
    string getSenha() const;
};

///class that defines the definition text
class Texto{
    ///attribute relative to the definition text
    string texto;
    ///validate the definition text if it respects the rules
    void validar(const string&) throw(invalid_argument);
    ///attribute relative to the max size of the definition text
    const static int MAX = 30;
public:
    ///set the definition text
    void setTexto(const string&)throw (invalid_argument);
    ///get the definition text
    string getTexto() const;
};

///class that defines the language
class Idioma{
    ///attribute relative to the language
    string idioma;
    ///attribute relative to the English
    static const string INGLES;
    ///attribute relative to the French
    static const string FRANCES;
    ///attribute relative to the German
    static const string ALEMAO;
    ///attribute relative to the Italian
    static const string ITALIANO;
    ///attribute relative to the Portuguese
    static const string PORTUGUES;
    ///attribute relative to the Spanish
    static const string ESPANHOL;
    ///validate the language if it respects the rules
    void validar(const string&) throw(invalid_argument);
public:
    ///set the language
    void setIdioma(const string&);
    ///get the language
    string getIdioma() const;
};

///class that defines the preference of the term
class Preferencia{
    ///attribute relative to the preference of the term
    string preferencia;
    ///attribute relative to the preferred term
    static const string PT;
    ///attribute relative to the non preferred term
    static const string NP;
    ///validate the preference if it respects the rules
    void validar(const string&) throw(invalid_argument);
public:
    ///set the preference of the term
    void setPreferencia(const string&);
    ///get the preference of the term
    string getPreferencia() const;
};
#endif // DOMINIOS_H_INCLUDED
