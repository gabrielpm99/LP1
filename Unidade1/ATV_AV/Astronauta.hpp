#ifndef ASTRONAUTA_HPP
#define ASTRONAUTA_HPP

#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Astronauta {
private:
    string cpf;
    int idade;
    string nome;
    bool ast_vivo;
    bool ast_disponivel;
    vector<int> voosParticipados;

    static inline vector<string> cpfsCadastrados;

public:
    Astronauta();

    static bool checarCpf(string novoCpf);

    bool cadastrar(string cpf, int idade, string nome);

    void addVoos(int codigoVoo);

    
    // FUNÇÕES GET
    string getCpf();

    bool getVivo();

    bool getDisponivel();

    string getNome();

    vector<int> getVoos();


    // FUNÇÕES SET
    void setDisponivel(bool estaDisponivel);

    void setVivo(bool estaVivo);
};

// Avisa ao compilador que o vetor global de astronautas e a função buscarAstronauta estão em outro arquivo
extern vector<Astronauta> astronautas;
Astronauta* buscarAstronauta(string cpf);

#endif
