#include <iostream>
#include <string>
#include <vector>
#include "Astronauta.hpp"
#include "Voo.hpp"
using namespace std;

// VETOR astronautas GLOBAL
vector<Astronauta> astronautas;


// FUNÇÃO QUE BUSCA UM ASTRONAUTA ESPECÍFICO PELO CPF
Astronauta* buscarAstronauta(string cpf) {
    for(int i = 0; i < astronautas.size(); i++) {
        if(astronautas[i].getCpf() == cpf) {
            return &astronautas[i];
        }
    }

    return nullptr; // RETORNA nullptr (EQUIVALENTE AO NULL)
}

// VETOR voos GLOBAL
vector<Voo> voos;


// FUNÇÃO QUE BUSCA UM VOO ESPECÍFICO PELO CÓDIGO DO VOO
Voo* buscarVoo(int codigoVoo) {
        for(int i = 0; i < voos.size(); i++) {
            if(voos[i].getCodigoVoo() == codigoVoo) {
                return &voos[i];
            }
        }

        return nullptr; // RETORNA nullptr (EQUIVALENTE AO NULL)
    }


int main() {
    string comando;

    // INICIALIZAÇÃO DO SISTEMA ESPACIAL
    cout << "==========================================================" << endl;
    cout << "              BEM-VINDO AO SISTEMA ESPACIAL" << endl;
    cout << endl;
    cout << "                 AGUARDANDO COMANDOS..." << endl;
    cout << "===========================================================" << endl;

    // LOOP QUE LÊ OS COMANDOS ATÉ QUE SEJA DIGITADO "FIM"
    while(cin >> comando) {
        if(comando == "FIM") {
            cout << "ENCERRANDO SISTEMA..." << endl;
            break;
        }

        if(comando == "CADASTRAR_ASTRONAUTA") {
            string cpf;
            int idade;
            string nome;

            cin >> cpf >> idade; // RECEBE O CPF E A IDADE DO ASTRONAUTA
            getline(cin >> ws, nome); // RECEBE O NOME DO ASTRONAUTA (IGNORANDO ESPAÇOS)

            // CRIA UM NOVO ASTRONAUTA
            Astronauta astronauta;
            // CADASTRA OS DADOS DO ASTRONAUTA
            bool foiCadastrado = astronauta.cadastrar(cpf, idade, nome);
            // CHECA SE O ASTRONAUTA FOI CADASTRADO E ADICIONA O ASTRONAUTA NO VETOR GLOBAL DE ASTRONAUTAS
            if(foiCadastrado) {
                astronautas.push_back(astronauta);
            }
        }

        if(comando == "CADASTRAR_VOO") {
            int codigoVoo;

            cin >> codigoVoo; // RECEBE O CÓDIGO DO VOO

            // CRIA UM NOVO VOO
            Voo novoVoo;
            // CADASTRA O CODIGO DO VOO
            bool foiCadastrado = novoVoo.cadastrar(codigoVoo);
            // CHECA SE O VOO FOI CADASTRADO E ADICIONA O VOO NO VETOR GLOBAL DE VOOS
            if(foiCadastrado) {
                voos.push_back(novoVoo);
            }
        }

        if(comando == "ADICIONAR_ASTRONAUTA") {
            string ast_cpf;
            int codigoVoo;

            // RECEBE O CPF DO ASTRONAUTA E O CÓDIGO DO VOO
            cin >> ast_cpf >> codigoVoo;

            // BUSCA O VOO PELO CÓDIGO DO VOO
            Voo* voo = buscarVoo(codigoVoo);
            // BUSCA O ASTRONAUTA PELO CPF
            Astronauta* ast = buscarAstronauta(ast_cpf);
            
            // CHECA SE O VOO E O ASTRONAUTA EXISTEM
            if((voo != nullptr)) {
                if((ast != nullptr)) {
                    // CHECA SE O VOO ESTÁ CADASTRADO
                    if((voo->getCodigoVoo() != 0)) {
                        // CHECA SE O ASTRONAUTA ESTÁ CADASTRADO
                        if((ast->getCpf() != "")){
                            // CHECA O ESTADO DO VOO E SE O ASTRONAUTA ESTÁ VIVO
                            if((voo->getEstadoVoo() == 0)) {
                                if((ast->getVivo() == true)){
                                    // ADICIONA O ASTRONAUTA AO VOO
                                    voo->addPassageiro(ast_cpf);
                                } else {
                                    cout << "ERRO: O astronauta está morto (RIP)" << endl;
                                }
                            } else {
                                cout << "ERRO: O voo não está em planejamento" << endl;
                            }
                        } else {
                            cout << "ERRO: O astronauta não está cadastrado" << endl;
                        }
                    } else {
                        cout << "ERRO: O voo não está cadastrado" << endl;
                    }
                } else {
                    cout << "ERRO: O astronauta não existe" << endl;
                }
            } else {
                cout << "ERRO: O voo não existe" << endl;
            }
        }

        if(comando == "REMOVER_ASTRONAUTA") {
            string cpf;
            int codigoVoo;

            // RECEBE O CPF DO ASTRONAUTA E O CÓDIGO DO VOO
            cin >> cpf >> codigoVoo;

            // BUSCA O VOO PELO CÓDIGO DO VOO
            Voo* voo = buscarVoo(codigoVoo);
            // BUSCA O ASTRONAUTA PELO CPF
            Astronauta* ast = buscarAstronauta(cpf);

            // CHECA SE O VOO E O ASTRONAUTA EXISTEM
            if((voo != nullptr)){
                if((ast != nullptr)) {
                    // CHECA SE O VOO ESTÁ CADASTRADO
                    if((voo->getCodigoVoo() != 0)) {
                        // CHECA SE O ASTRONAUTA ESTÁ CADASTRADO
                        if((ast->getCpf() != "")){
                            // CHECA SE O VOO ESTÁ PLANEJADO
                            if(voo->getEstadoVoo() == 0) {
                                // REMOVE O ASTRONAUTA
                                voo->removerAstronauta(cpf);
                            } else {
                                cout << "ERRO: O voo não está em planejamento" << endl;
                            }
                        } else {
                            cout << "ERRO: O astronauta não está cadastrado" << endl;
                        }
                    } else {
                        cout << "ERRO: O voo não está cadastrado" << endl;
                    }
                } else {
                    cout << "ERRO: O astronauta não existe" << endl;
                }
            } else {
                cout << "ERRO: O voo não existe" << endl;
            }
        }

        if(comando == "LANCAR_VOO") {
            int codigoVoo;

            // RECEBE O CÓDIGO DO VOO
            cin >> codigoVoo;

            // BUSCA O VOO PELO CÓDIGO DO VOO
            Voo* voo = buscarVoo(codigoVoo);
            
            // CHECA SE O VOO EXISTE
            if((voo != nullptr)){
                // CHECA SE O VOO ESTÁ CADASTRADO
                if((voo->getCodigoVoo() != 0)) {
                    // CHECA SE O VOO ESTÁ PLANEJADO
                    if(voo->getEstadoVoo() == 0) {
                        // LANÇA O VOO
                        voo->lancarVoo();
                    } else {
                        cout << "ERRO: O voo não está em planejamento" << endl;
                    }
                } else {
                    cout << "ERRO: O voo não está cadastrado" << endl;
                }
            } else {
                cout << "ERRO: O voo não existe" << endl;
            }
        }

        if(comando == "EXPLODIR_VOO") {
            int codigoVoo;

            // RECEBE O CÓDIGO DO VOO
            cin >> codigoVoo;

            // BUSCA O VOO PELO CÓDIGO DO VOO
            Voo* voo = buscarVoo(codigoVoo);
            
             // CHECA SE O VOO EXISTE
            if((voo != nullptr)){
                // CHECA SE O VOO ESTÁ CADASTRADO
                if((voo->getCodigoVoo() != 0)) {
                    // CHECA SE O VOO ESTÁ EM CURSO
                    if(voo->getEstadoVoo() == 1) {
                        // EXPLODE O VOO
                        voo->explodirVoo();
                    } else {
                        cout << "ERRO: O voo não está em curso" << endl;
                    }
                } else {
                    cout << "ERRO: O voo não está cadastrado" << endl;
                }
            } else {
                cout << "ERRO: O voo não existe" << endl;
            }
        }

        if(comando == "FINALIZAR_VOO") {
            int codigoVoo;

            // RECEBE O CÓDIGO DO VOO
            cin >> codigoVoo;

            // BUSCA O VOO PELO CÓDIGO DO VOO
            Voo* voo = buscarVoo(codigoVoo);
            
            // CHECA SE O VOO EXISTE
            if((voo != nullptr)){
                // CHECA SE O VOO ESTÁ CADASTRADO
                if((voo->getCodigoVoo() != 0)) {
                    // CHECA SE O VOO ESTÁ EM CURSO
                    if(voo->getEstadoVoo() == 1) {
                        // FINALIZA O VOO
                        voo->finalizarVoo();
                    } else {
                        cout << "ERRO: O voo não está em curso" << endl;
                    }
                } else {
                    cout << "ERRO: O voo não está cadastrado" << endl;
                }
            } else {
                cout << "ERRO: O voo não existe" << endl;
            }
        }

        if(comando == "LISTAR_VOOS") {
            int qtdEstados = 4;
            vector<string> estados = {"Planejado", "Em curso", "Finalizado com sucesso", "Finalizado com explosão"};

            // PERCORRE TODOS OS PÓSSIVEIS ESTADOS
            for(int i = 0; i < qtdEstados; i++) {
                // IMPRIME O ESTADO ATUAL SENDO ANALISADO
                cout << "-- " << estados[i] << " --" << endl;
                
                // PERCORRE TODOS OS VOOS DO VETOR GLOBAL DE VOOS
                for(int j = 0; j < voos.size(); j++) {
                    Voo vooAtual = voos[j];
                    // PEGA OS PASSAGEIROS DO VOO
                    vector<string> passageiros = vooAtual.getPassageiros();

                    // CHECA SE O ESTADO DO VOO É IGUAL AO ESTADO QUE ESTÁ SENDO ANALISADO
                    if(vooAtual.getEstadoVoo() == i) {
                        // CASO SEJA, IMPRIME AS INFORMAÇÕES DO VOO
                        cout << "Código do voo: " << vooAtual.getCodigoVoo() << endl;
                        cout << "Estado do voo: " << estados[vooAtual.getEstadoVoo()] << endl;
                        cout << "Tripulantes:" << endl;
                        // PERCORRE TODOS OS PASSAGEIROS DO VOO
                        for(int k = 0; k < passageiros.size(); k++) {
                            string cpfPassageiro = passageiros[k];
                            
                            // BUSCA O PASSAGEIRO PELO CPF
                            Astronauta* passageiroAtual = buscarAstronauta(cpfPassageiro);
                            
                             // CHECA SE O PASSAGEIRO EXISTE
                            if((passageiroAtual != nullptr)){
                                // IMPRIME AS INFORMAÇÕES DO PASSAGEIRO
                                cout << "   CPF: " << passageiroAtual->getCpf() << endl;
                                cout << "   Nome: " << passageiroAtual->getNome() << "\n" << endl;
                            }
                        }
                    }
                }
            }
        }

        if(comando == "LISTAR_MORTOS") {
            cout << "-- MORTOS --" << endl;

            // PERCORRE TODOS OS ASTRONAUTAS DO VETOR GLOBAL DE ASTRONAUTAS
            for(int i = 0; i < astronautas.size(); i++) {
                Astronauta astAtual = astronautas[i];
                // PEGA TODOS OS VOOS REALIZADOS PELO ASTRONAUTA
                vector<int> astVoos = astAtual.getVoos();

                // CHECA SE O PASSAGEIRO ESTÁ MORTO
                if(astAtual.getVivo() == false) {
                    // CASO ESTEJA, IMPRIME AS INFORMAÇÕES DO ASTRONAUTA
                    cout << "CPF: " << astAtual.getCpf() << endl;
                    cout << "Nome: " << astAtual.getNome() << endl;
                    cout << "Voos participados:" << endl;
                    // PERCORRE TODOS OS VOOS PARTICIPADOS PELO ASTRONAUTA
                    for(int j = 0; j < astVoos.size(); j++) {
                        // IMPRIME O VOO
                        cout << "   " << astVoos[j] << endl;
                    }
                    cout << endl;
                }
            }
        }

        cout << endl;
    }

    return 0;
}
