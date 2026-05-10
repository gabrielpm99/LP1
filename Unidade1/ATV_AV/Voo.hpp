#ifndef VOO_HPP
#define VOO_HPP

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ESTADOS DE VOO
#define PLANEJADO               0
#define EM_CURSO                1
#define FINALIZADO_SUCESSO      2
#define FINALIZADO_EXPLOSAO     3


class Voo {
private:
    int codigoVoo;
    vector<string> cpfsPassageiros;
    int estadoVoo;

    static inline vector<int> voosCadastrados;

public:
    Voo();

    static bool checarCodigoVoo(int novoCodigoVoo);

    int checarCpfsCadastrados(string cpfPassageiro);

    bool cadastrar(int codigoVoo);

    void addPassageiro(string cpf);

    void removerAstronauta(string cpf);

    void lancarVoo();

    void explodirVoo();

    void finalizarVoo();


    // FUNÇÕES GET
    int getCodigoVoo();

    int getEstadoVoo();

    vector<string> getPassageiros();
};

// Avisa ao compilador que o vetor global de voos e a função buscarVoo estão em outro arquivo
extern vector<Voo> voos;
Voo* buscarVoo(int codigoVoo);

#endif
