#include "Astronauta.hpp"

Astronauta::Astronauta() {
    this->ast_vivo = true;
    this->ast_disponivel = true;
}

bool Astronauta::checarCpf(string novoCpf)
{
    // COMPARA O novoCpf COM TODOS OS CPFS JÁ CADASTRADOS. SE ENCONTRAR, RETORNA FALSO
    for (int i = 0; i < cpfsCadastrados.size(); i++)
    {
        if (novoCpf == cpfsCadastrados[i])
        {
            return false;
        }
    }
    return true;
}

bool Astronauta::cadastrar(string cpf, int idade, string nome)
{
    if (checarCpf(cpf))
    {
        this->cpf = cpf;
        this->idade = idade;
        this->nome = nome;

        this->cpfsCadastrados.push_back(cpf); // ADICIONA O CPF CADASTRADO À LISTA DE cpfsCadastrados

        cout << "ASTRONAUTA " << nome << " CADASTRADO COM SUCESSO" << endl;

        return true;
    }
    else
    {
        cout << "ERRO: CPF já cadastrado" << endl;

        return false;
    }
}

void Astronauta::addVoos(int codigoVoo)
{
    this->voosParticipados.push_back(codigoVoo);
}

// FUNÇÕES GET
string Astronauta::getCpf() {
    return this->cpf;
}

bool Astronauta::getVivo()
{
    return this->ast_vivo;
}

bool Astronauta::getDisponivel()
{
    return this->ast_disponivel;
}

string Astronauta::getNome()
{
    return this->nome;
}

vector<int> Astronauta::getVoos()
{
    return this->voosParticipados;
}

// FUNÇÕES SET
void Astronauta::setDisponivel(bool estaDisponivel)
{
    this->ast_disponivel = estaDisponivel;
}

void Astronauta::setVivo(bool estaVivo)
{
    this->ast_vivo = estaVivo;
}