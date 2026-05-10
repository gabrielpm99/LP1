#include "Voo.hpp"
#include "Astronauta.hpp"

Voo::Voo() {
    this->estadoVoo = PLANEJADO;
    this->cpfsPassageiros = {};
}

bool Voo::checarCodigoVoo(int novoCodigoVoo) {
    // COMPARA O novoCodigoVoo COM TODOS OS VOOS JÁ CADASTRADOS. SE ENCONTRAR, RETORNA FALSO
    for (int i = 0; i < voosCadastrados.size(); i++)
    {
        if (novoCodigoVoo == voosCadastrados[i])
        {
            return false;
        }
    }
    return true;
}

int Voo::checarCpfsCadastrados(string cpfPassageiro) {
    // COMPARA O cpfPassageiro COM TODOS OS CPFS CADASTRADOS NO VOO. SE ENCONTRAR, RETORNA FALSO
    for (int i = 0; i < cpfsPassageiros.size(); i++)
    {
        if (cpfsPassageiros[i] == cpfPassageiro)
        {
            return i;
        }
    }
    return -1;
}

bool Voo::cadastrar(int codigoVoo) {
    if (checarCodigoVoo(codigoVoo))
    {
        this->codigoVoo = codigoVoo;
        this->voosCadastrados.push_back(codigoVoo);

        cout << "VOO " << codigoVoo << " CADASTRADO COM SUCESSO" << endl;

        return true;
    }
    else
    {
        cout << "ERRO: Voo já cadastrado" << endl;

        return false;
    }
}

void Voo::addPassageiro(string cpf) {
    // CHECA SE O CPF JÁ FOI CADASTRADO ANTERIORMENTE
    if (checarCpfsCadastrados(cpf) != -1)
    {
        cout << "ERRO: Passageiro já cadastrado" << endl;
    }
    else
    {
        this->cpfsPassageiros.push_back(cpf);

        Astronauta* ast = buscarAstronauta(cpf);

        cout << "PASSAGEIRO " << ast->getNome() << " ADICIONADO COM SUCESSO" << endl;
    }
}

void Voo::removerAstronauta(string cpf) {
    // BUSCA O INDICE DO PASSAGEIRO NO VOO
    int indicePassageiro = checarCpfsCadastrados(cpf);

    // CHECA SE O PASSAGEIRO ESTÁ CADASTRADO NO VOO
    if (indicePassageiro != -1)
    {
        // APAGA O PASSAGEIRO
        cpfsPassageiros.erase(cpfsPassageiros.begin() + indicePassageiro);

        Astronauta* ast = buscarAstronauta(cpf);

        cout << "PASSAGEIRO " << ast->getNome() << " REMOVIDO COM SUCESSO" << endl;
    }
    else
    {
        cout << "ERRO: Passageiro não cadastrado" << endl;
    }
}

void Voo::lancarVoo() {
    int qtdPassageiros = cpfsPassageiros.size();
    bool todosPassageirosDisponiveis = true;
    bool todosPassageirosExistem = true;

    if (qtdPassageiros >= 1)
    {
        for (int i = 0; i < qtdPassageiros; i++)
        {
            Astronauta *passageiro = buscarAstronauta(cpfsPassageiros[i]);

            // CHECA SE O PASSAGEIRO EXISTE
            if ((passageiro != nullptr))
            {
                if (!(passageiro->getVivo()))
                {
                    cout << "ERRO: Passageiro morto" << endl;
                    todosPassageirosDisponiveis = false;
                    break;
                }
                else if (!(passageiro->getDisponivel()))
                {
                    cout << "ERRO: Passageiro indisponível" << endl;
                    todosPassageirosDisponiveis = false;
                    break;
                }
            } else {
             todosPassageirosExistem = false;
            }
        }

        if(todosPassageirosDisponiveis && todosPassageirosExistem) {
            for (int i = 0; i < qtdPassageiros; i++)
            {
                Astronauta *passageiro = buscarAstronauta(cpfsPassageiros[i]);

                passageiro->setDisponivel(false);
                passageiro->addVoos(this->codigoVoo);
            }

            this->estadoVoo = EM_CURSO;

            cout << "VOO " << codigoVoo << " LANÇADO COM SUCESSO" << endl;
        }
    } else {
        cout << "VOO " << codigoVoo << " NÃO TEM PASSAGEIROS" << endl;
    }
}

void Voo::explodirVoo() {
    int qtdPassageiros = cpfsPassageiros.size();

    if (qtdPassageiros >= 1)
    {
        for (int i = 0; i < qtdPassageiros; i++)
        {
            Astronauta *passageiro = buscarAstronauta(cpfsPassageiros[i]);

            // CHECA SE O PASSAGEIRO EXISTE
            if ((passageiro != nullptr))
            {
                passageiro->setVivo(false);
            }
        }

        this->estadoVoo = 3;

        cout << "VOO " << codigoVoo << " EXPLODIDO COM SUCESSO" << endl;
    }
}

void Voo::finalizarVoo() {
    int qtdPassageiros = cpfsPassageiros.size();

    if (qtdPassageiros >= 1)
    {
        for (int i = 0; i < qtdPassageiros; i++)
        {
            Astronauta *passageiro = buscarAstronauta(cpfsPassageiros[i]);

            // CHECA SE O PASSAGEIRO EXISTE
            if ((passageiro != nullptr))
            {
                passageiro->setDisponivel(true);
            }
        }

        this->estadoVoo = 2;

        cout << "VOO " << codigoVoo << " FINALIZADO COM SUCESSO" << endl;
    }
}

// FUNÇÕES GET
int Voo::getCodigoVoo() {
    return this->codigoVoo;
}

int Voo::getEstadoVoo() {
    return this->estadoVoo;
}

vector<string> Voo::getPassageiros() {
    return this->cpfsPassageiros;
}
