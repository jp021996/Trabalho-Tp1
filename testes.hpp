#include "entidades.hpp"

/*
CLASSES THAT WILL TEST THE DOMAINS
*/
/**a class that will test all possibilites of
the class NomeGeral*/
class TUNomeGeral{
    ///the attribute of the valid name
    static const string NOME_VALIDO;
    ///the attribute of the name with the invalid first letter
    static const string NOME_PRIMEIRA_LETRA_INVALIDA;
    ///the attribute of the name with a invalid character
    static const string NOME_CARACTER_INVALIDO;
    ///the attribute of the name with a very long name
    static const string NOME_LONGO;

    ///creating the object of the class NomeGeral
    Nome *nomegeral;

    ///state of the test
    int estado;

    ///creating the method to start the test
    void setUp();
    ///creating the method to desallocate the memory of the object
    void tearDown();
    ///test the success cenary
    void testarCenarioCorreto();
    ///test the fail cenary
    void testarCenarioIncorreto(const string&);

public:
    //success is going ti be represented by the number 1 and the
    //failure by the number 0
    const static int SUCESSO = 1;
    const static int FALHA = 0;

    ///the method that run the test
    int run();
};

/**a class that will test all possibilites of
the class Telefone*/
class TUTelefone{
    ///the attribute of the valid telephone
    static const string TELEFONE_VALIDO;
    ///the attribute of the invalid telephone without the space after DDD
    static const string TELEFONE_SEM_ESPACO;
    ///the attribute of the invalid telephone without the -
    static const string TELEFONE_SEM_HIFEN;
    ///the attribute of the invalid telephone with the wrong DDD
    static const string TELEFONE_DDD_INCORRETO;
    ///the attribute of the invalid telephone with more numbers than the usual
    static const string TELEFONE_MUITO_NUMERO;

    ///creating the object of the class Telefone
    Telefone *telefone;

    ///state of the test
    int estado;

    ///creating the method to start the test
    void setUp();
    ///creating the method to desallocate the memory of the object
    void tearDown();
    ///test the success cenary
    void testarCenarioCorreto();
    ///test the fail cenary
    void testarCenarioIncorreto(const string&);

public:
    //success is going ti be represented by the number 1 and the
    //failure by the number 0
    const static int SUCESSO = 1;
    const static int FALHA = 0;

    ///the method that run the test
    int run();
};

/**a class that will test all possibilites of
the class Endereco*/
class TUEndereco{
    ///the attribute of the valid address
    static const string ENDERECO_VALIDO;
    ///the attribute of the invalid address starting with a space
    static const string ENDERECO_COMECO_ESPACO;
    ///the attribute of the invalid address ending with a space
    static const string ENDERECO_FIM_ESPACO;
    ///the attribute of the invalid address with long address
    static const string ENDERECO_LONGO;
    ///the attribute of the invalid address with two spaces in a row
    static const string ENDERECO_ESPACO_SEGUIDO;
    ///the attribute of the invalid address with invalid chatacters
    static const string ENDERECO_CARACTER_INVALIDO;

    ///creating the object of the class Endereco
    Endereco *endereco;

    ///state of the test
    int estado;

    ///creating the method to start the test
    void setUp();
    ///creating the method to desallocate the memory of the object
    void tearDown();
    ///test the success cenary
    void testarCenarioCorreto();
    ///test the fail cenary
    void testarCenarioIncorreto(const string&);

public:
    //success is going ti be represented by the number 1 and the
    //failure by the number 0
    const static int SUCESSO = 1;
    const static int FALHA = 0;

    ///the method that run the test
    int run();
};

/**a class that will test all possibilites of
the class Data*/
class TUData{
    ///the attribute of the valid date
    static const string DATA_VALIDA;
    ///the attribute of the invalid date with more characters than the allowed
    static const string DATA_LONGA;
    ///the attribute of the invalid date with wrong characters on the slashes' place
    static const string DATA_BARRA_ERRADA;
    ///the attribute of the invalid date with wrong characters on the day part
    static const string DATA_CARACTER_INVALIDO_DIA;
    ///the attribute of the invalid date with wrong characters on the month part
    static const string DATA_CARACTER_INVALIDO_MES;
    ///the attribute of the invalid date with wrong characters on the year part
    static const string DATA_CARACTER_INVALIDO_ANO;
    ///the attribute of the invalid date with a day incorrect to the month
    static const string DATA_DIA_INVALIDO;
    ///the attribute of the invalid date to test the leap year
    static const string DATA_BISSEXTO_INVALIDO;
    ///the attribute of the invalid date with an invalid month
    static const string DATA_MES_INVALIDO;
    ///the attribute of the invalid date with an invalid year
    static const string DATA_ANO_INVALIDO;

    ///creating the object of the class Data
    Data *data;

    ///state of the test
    int estado;

    ///creating the method to start the test
    void setUp();
    ///creating the method to desallocate the memory of the object
    void tearDown();
    ///test the success cenary
    void testarCenarioCorreto();
    ///test the fail cenary
    void testarCenarioIncorreto(const string&);

public:
    //success is going ti be represented by the number 1 and the
    //failure by the number 0
    const static int SUCESSO = 1;
    const static int FALHA = 0;

    ///the method that run the test
    int run();
};

/**a class that will test all possibilites of
the class Email*/
class TUEmail{
    ///the attribute of the valid email
    static const string EMAIL_VALIDO;
    ///the attribute of the invalid email without @
    static const string EMAIL_SEM_ARROBA;
    ///the attribute of the invalid email starting with .
    static const string EMAIL_LOCAL_COMECO_PONTO;
    ///the attribute of the invalid email ending with .
    static const string EMAIL_LOCAL_FIM_PONTO;
    ///the attribute of the invalid email inthe local side with an invalid character
    static const string EMAIL_LOCAL_CARACTER_INVALIDO;
    ///the attribute of the invalid email with the domain starting with -
    static const string EMAIL_DOMINIO_COMECO_HIFEN;
    ///the attribute of the invalid email with the domain ending with -
    static const string EMAIL_DOMINIO_FIM_HIFEN;
    ///the attribute of the invalid email with the domain with an invalid character
    static const string EMAIL_DOMINIO_CARACTER_INVALIDO;
    ///the attribute of the invalid email with the domain with only numbers
    static const string EMAIL_DOMINIO_NUMERO;

    ///creating the object of the class Email
    Email *email;

    ///state of the test
    int estado;

    ///creating the method to start the test
    void setUp();
    ///creating the method to desallocate the memory of the object
    void tearDown();
    ///test the success cenary
    void testarCenarioCorreto();
    ///test the fail cenary
    void testarCenarioIncorreto(const string&);

public:
    //success is going ti be represented by the number 1 and the
    //failure by the number 0
    const static int SUCESSO = 1;
    const static int FALHA = 0;

    ///the method that run the test
    int run();
};

/**a class that will test all possibilites of
the class Senha*/
class TUSenha{
    ///the attribute of the valid password
    static const string SENHA_VALIDA;
    ///the attribute of the invalid password without an uppercase letter
    static const string SENHA_SEM_MAIUSCULA;
    ///the attribute of the invalid password with an invalid size
    static const string SENHA_LONGA;
    ///the attribute of the invalid password without lowercase letter
    static const string SENHA_SEM_MINUSCULA;
    ///the attribute of the invalid password without number
    static const string SENHA_SEM_NUMERO;

    ///creating the object of the class Senha
    Senha *senha;

    ///state of the test
    int estado;

    ///creating the method to start the test
    void setUp();
    ///creating the method to desallocate the memory of the object
    void tearDown();
    ///test the success cenary
    void testarCenarioCorreto();
    ///test the fail cenary
    void testarCenarioIncorreto(const string&);

public:
    //success is going ti be represented by the number 1 and the
    //failure by the number 0
    const static int SUCESSO = 1;
    const static int FALHA = 0;

    ///the method that run the test
    int run();
};

/**a class that will test all possibilites of
the class Texto*/
class TUTexto{
    ///the attribute of the valid definition text
    static const string TEXTO_VALIDO;
    ///the attribute of the invalid definition text because of its size
    static const string TEXTO_LONGO;

    ///creating the object of the class Definicao
    Texto *texto;

    ///state of the test
    int estado;

    ///creating the method to start the test
    void setUp();
    ///creating the method to desallocate the memory of the object
    void tearDown();
    ///test the success cenary
    void testarCenarioCorreto();
    ///test the fail cenary
    void testarCenarioIncorreto(const string&);

public:
    //success is going ti be represented by the number 1 and the
    //failure by the number 0
    const static int SUCESSO = 1;
    const static int FALHA = 0;

    ///the method that run the test
    int run();
};

/**a class that will test all possibilites of
the class Idioma*/
class TUIdioma{
    ///the attribute of the valid language
    static const string IDIOMA_VALIDO;
    ///the attribute of the invalid language with another string diferent from defined
    static const string IDIOMA_INVALIDO;

    ///creating the object of the class Idioma
    Idioma *idioma;

    ///state of the test
    int estado;

    ///creating the method to start the test
    void setUp();
    ///creating the method to desallocate the memory of the object
    void tearDown();
    ///test the success cenary
    void testarCenarioCorreto();
    ///test the fail cenary
    void testarCenarioIncorreto(const string&);

public:
    //success is going ti be represented by the number 1 and the
    //failure by the number 0
    const static int SUCESSO = 1;
    const static int FALHA = 0;

    ///the method that run the test
    int run();
};

/**a class that will test all possibilites of
the class Preferencia*/
class TUPreferencia{
    ///the attribute of the valid preference
    static const string PREFERENCIA_VALIDA;
    ///the attribute of the invalid preference with another string diferent from defined
    static const string PREFERENCIA_INVALIDA;

    ///creating the object of the class Preferencia
    Preferencia *preferencia;

    ///state of the test
    int estado;

    ///creating the method to start the test
    void setUp();
    ///creating the method to desallocate the memory of the object
    void tearDown();
    ///test the success cenary
    void testarCenarioCorreto();
    ///test the fail cenary
    void testarCenarioIncorreto(const string&);

public:
    //success is going ti be represented by the number 1 and the
    //failure by the number 0
    const static int SUCESSO = 1;
    const static int FALHA = 0;

    ///the method that run the test
    int run();
};

/*
CLASSES THAT WILL TEST THE ENTITIES
*/
/**a class that will test all the possibilites of the
class Leitor*/
class TULeitor{
    ///the attribute of the valid name
    const static string NOME_VALIDO;
    ///the attribute of the valid last name
    const static string SOBRENOME_VALIDO;
    ///the attribute of the valid email
    const static string EMAIL_VALIDO;
    ///the attribute of the valid password
    const static string SENHA_VALIDA;

    //create the objects of the attributes of the class Leitor
    Nome *nome;
    Sobrenome *sobrenome;
    Email *email;
    Senha *senha;

    ///create the object of the class Leitor
    Leitor *leitor;

    ///state of the test
    int estado;

    ///creating the method to start the test
    void setUp();
    ///creating the method to desallocate the memory of the objects
    void tearDown();
    ///test the success cenary
    void testarCenarioCorreto();

public:
    //success is going ti be represented by the number 1 and the
    //failure by the number 0
    const static int SUCESSO = 1;
    const static int FALHA = 0;

    ///the method that run the test
    int run();
};

/**a class that will test all the possibilites of the
class Desenvolvedor*/
class TUDesenvolvedor{
    ///the attribute of the valid name
    const static string NOME_VALIDO;
    ///the attribute of the valid last name
    const static string SOBRENOME_VALIDO;
    ///the attribute of the valid email
    const static string EMAIL_VALIDO;
    ///the attribute of the valid password
    const static string SENHA_VALIDA;
    ///the attribute of the valid date
    const static string DATA_VALIDA;

    //create the objects of the attributes of the class Administrador
    Nome *nome;
    Sobrenome *sobrenome;
    Email *email;
    Senha *senha;
    Data *data;

    ///create the object of the class Desenvolvedor
    Desenvolvedor *desenvolvedor;

    ///state of the test
    int estado;

    ///creating the method to start the test
    void setUp();
    ///creating the method to desallocate the memory of the objects
    void tearDown();
    ///test the success cenary
    void testarCenarioCorreto();

public:
    //success is going ti be represented by the number 1 and the
    //failure by the number 0
    const static int SUCESSO = 1;
    const static int FALHA = 0;

    ///the method that run the test
    int run();
};

/**a class that will test all the possibilites of the
class Administrador*/
class TUAdministrador{
    ///the attribute of the valid name
    const static string NOME_VALIDO;
    ///the attribute of the valid last name
    const static string SOBRENOME_VALIDO;
    ///the attribute of the valid email
    const static string EMAIL_VALIDO;
    ///the attribute of the valid password
    const static string SENHA_VALIDA;
    ///the attribute of the valid date
    const static string DATA_VALIDA;
    ///the attribute of the valid telephone
    const static string TELEFONE_VALIDO;
    ///the attribute of the valid adress
    const static string ENDERECO_VALIDO;

    //create the objects of the attributes of the class Administrador
    Nome *nome;
    Sobrenome *sobrenome;
    Email *email;
    Senha *senha;
    Data *data;
    Telefone *telefone;
    Endereco *endereco;

    ///create the object of the class Administrador
    Administrador *administrador;

    ///state of the test
    int estado;

    ///creating the method to start the test
    void setUp();
    ///creating the method to desallocate the memory of the objects
    void tearDown();
    ///test the success cenary
    void testarCenarioCorreto();

public:
    //success is going ti be represented by the number 1 and the
    //failure by the number 0
    const static int SUCESSO = 1;
    const static int FALHA = 0;

    ///the method that run the test
    int run();
};

/**a class that will test all the possibilites of the
class Vocabulario*/
class TUVocabulario{
    ///the attribute of the valid name
    const static string NOME_VALIDO;
    ///the attribute of the valid language
    const static string IDIOMA_VALIDO;
    ///the attribute of the valid date
    const static string DATA_VALIDA;

    //create the objects of the attributes of the class Vocabulario
    Nome *nome;
    Idioma *idioma;
    Data *data;

    ///create the object of the class Vocabulario
    Vocabulario *vocabulario;

    ///state of the test
    int estado;

    ///creating the method to start the test
    void setUp();
    ///creating the method to desallocate the memory of the objects
    void tearDown();
    ///test the success cenary
    void testarCenarioCorreto();

public:
    //success is going ti be represented by the number 1 and the
    //failure by the number 0
    const static int SUCESSO = 1;
    const static int FALHA = 0;

    ///the method that run the test
    int run();
};

/**a class that will test all the possibilites of the
class Termo*/
class TUTermo{
    ///the attribute of the valid name
    const static string NOME_VALIDO;
    ///the attribute of the valid preference
    const static string PREFERENCIA_VALIDA;
    ///the attribute of the valid date
    const static string DATA_VALIDA;

    //create the objects of the attributes of the class Termo
    Nome *nome;
    Preferencia *preferencia;
    Data *data;

    ///create the object of the class Termo
    Termo *termo;

    ///state of the test
    int estado;

    ///creating the method to start the test
    void setUp();
    ///creating the method to desallocate the memory of the objects
    void tearDown();
    ///test the success cenary
    void testarCenarioCorreto();

public:
    //success is going ti be represented by the number 1 and the
    //failure by the number 0
    const static int SUCESSO = 1;
    const static int FALHA = 0;

    ///the method that run the test
    int run();
};

/**a class that will test all the possibilites of the
class Definicao*/
class TUDefinicao{
    ///the attribute of the valid definition text
    const static string TEXTO_VALIDO;
    ///the attribute of the valid date
    const static string DATA_VALIDA;

    //create the objects of the attributes of the class Definicao
    Texto *texto;
    Data *data;

    ///create the object of the class Definicao
    Definicao *definicao;

    ///state of the test
    int estado;

    ///creating the method to start the test
    void setUp();
    ///creating the method to desallocate the memory of the objects
    void tearDown();
    ///test the success cenary
    void testarCenarioCorreto();

public:
    //success is going ti be represented by the number 1 and the
    //failure by the number 0
    const static int SUCESSO = 1;
    const static int FALHA = 0;

    ///the method that run the test
    int run();
};

///a class that will test all the domains
class TUDominio{
    //the attributes are all the objects that test the domains
    TUNomeGeral nome;
    TUNomeGeral sobrenome;
    TUTelefone telefone;
    TUEndereco endereco;
    TUData data;
    TUEmail email;
    TUSenha senha;
    TUTexto texto;
    TUIdioma idioma;
    TUPreferencia preferencia;

public:
    ///the method that will test the domains
    void run();
};

///a class that will test all the entities
class TUEntidade{
    //the attributes are all the objects that test the entitites
    TULeitor leitor;
    TUDesenvolvedor desenvolvedor;
    TUAdministrador administrador;
    TUVocabulario vocabulario;
    TUTermo termo;
    TUDefinicao definicao;

public:
    ///the method that will test the entities
    void run();
};

///a class that will test both entities and domains
class TU{
    TUDominio dominio;
    TUEntidade entidade;

public:
    ///the method that will test both domains and entitites
    void run();
};
