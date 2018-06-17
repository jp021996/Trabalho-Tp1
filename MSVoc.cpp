#include "MSVoc.hpp"


ResultadoLista ServicoGestaoVocab::listarVocabs() throw(runtime_error) {
    //the object to be the result of the registering
    ResultadoLista resultado;

    //go to the stub class and register
    resultado = stub_MS_GestaoVocab.listarVocabs();

    return resultado;
}

ResultadoVocab ServicoGestaoVocab::dadosVocab(const string& nomeVocab) throw(runtime_error) {
    //the object to be the result of the registering
    ResultadoVocab resultado;

    //go to the stub class and register
    resultado = stub_MS_GestaoVocab.dadosVocab(nomeVocab);

    return resultado;
}

ResultadoTermo ServicoGestaoVocab::consultarTermo(const string& nomeTermo) throw(runtime_error) {
    //the object to be the result of the registering
    ResultadoTermo resultado;

    //go to the stub class and register
    resultado = stub_MS_GestaoVocab.consultarTermo(nomeTermo);

    return resultado;
}

ResultadoDefinicao ServicoGestaoVocab::consultarDefinicao(const string& textoDef) throw(runtime_error) {
    //the object to be the result of the registering
    ResultadoDefinicao resultado;

    //go to the stub class and register
    resultado = stub_MS_GestaoVocab.consultarDefinicao(textoDef);

    return resultado;
}

ResultadoEspecifico ServicoGestaoVocab::desenvolvedorDeVocab(const string& nomeVocab) throw(runtime_error) {
    //the object to be the result of the registering
    ResultadoEspecifico resultado;

    //go to the stub class and register
    resultado = stub_MS_GestaoVocab.desenvolvedorDeVocab(nomeVocab);

    return resultado;
}

ResultadoVocab ServicoGestaoVocab::criarTermo(const Termo& novoTermo, const string& nomeVocab) throw(runtime_error) {
    //the object to be the result of the registering
    ResultadoVocab resultado;

    //go to the stub class and register
    resultado = stub_MS_GestaoVocab.criarTermo(novoTermo, nomeVocab);

    return resultado;
}

ResultadoTermo ServicoGestaoVocab::editarTermo(const Termo& termo, const Termo& novoTermo) throw(runtime_error) {
    //the object to be the result of the registering
    ResultadoTermo resultado;

    //go to the stub class and register
    resultado = stub_MS_GestaoVocab.editarTermo(termo, novoTermo);

    return resultado;
}

ResultadoTermo ServicoGestaoVocab::excluirTermo(const Termo& termo) throw(runtime_error) {
    //the object to be the result of the registering
    ResultadoTermo resultado;

    //go to the stub class and register
    resultado = stub_MS_GestaoVocab.excluirTermo(termo);

    return resultado;
}

ResultadoDefinicao ServicoGestaoVocab::criarDefinicao(const Definicao& definicao) throw(runtime_error) {
    //the object to be the result of the registering
    ResultadoDefinicao resultado;

    //go to the stub class and register
    resultado = stub_MS_GestaoVocab.criarDefinicao(definicao);

    return resultado;
}

ResultadoDefinicao ServicoGestaoVocab::editarDefinicao(const Definicao& antigaDef,const Definicao& novaDef) throw(runtime_error) {
    //the object to be the result of the registering
    ResultadoDefinicao resultado;

    //go to the stub class and register
    resultado = stub_MS_GestaoVocab.editarDefinicao(antigaDef, novaDef);

    return resultado;
}

Resultado ServicoGestaoVocab::excluirDefinicao(const Definicao& definicao) throw(runtime_error) {
    //the object to be the result of the registering
    Resultado resultado;

    //go to the stub class and register
    resultado = stub_MS_GestaoVocab.excluirDefinicao(definicao);

    return resultado;
}

ResultadoVocab ServicoGestaoVocab::criarVocabulario(const Vocabulario& vocab, const Definicao& defVocab) throw(runtime_error) {
    //the object to be the result of the registering
    ResultadoVocab resultado;

    //go to the stub class and register
    resultado = stub_MS_GestaoVocab.criarVocabulario(vocab, defVocab);

    return resultado;
}

Resultado ServicoGestaoVocab::editarDefinicaoVocab(const Vocabulario& vocab, const Definicao& defVocab) throw(runtime_error) {
    //the object to be the result of the registering
    Resultado resultado;

    //go to the stub class and register
    resultado = stub_MS_GestaoVocab.editarDefinicaoVocab(vocab, defVocab);

    return resultado;
}

Resultado ServicoGestaoVocab::editarIdiomaVocab(const Vocabulario& vocab, const Idioma& idioma) throw(runtime_error) {
    //the object to be the result of the registering
    Resultado resultado;

    //go to the stub class and register
    resultado = stub_MS_GestaoVocab.editarIdiomaVocab(vocab,idioma);

    return resultado;
}

Resultado ServicoGestaoVocab::excluirVocabulario(const Vocabulario& vocab) throw(runtime_error) {
    //the object to be the result of the registering
    Resultado resultado;

    //go to the stub class and register
    resultado = stub_MS_GestaoVocab.excluirVocabulario(vocab);

    return resultado;
}
