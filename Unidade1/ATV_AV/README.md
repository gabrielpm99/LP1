# Atividade Avaliativa

## Conteúdo do repositório

### Este repositório contém a resolução da atividade avaliativa da Unidade 1

### Funcionalidades:

- Cadastro de astronautas (CADASTRAR_ASTRONAUTA)
- Cadastro de voos (CADASTRAR_VOO)
- Inserção de astronauta em um voo (ADICIONAR_ASTRONAUTA)
- Remoção de astronauta de um voo (REMOVER_ASTRONAUTA)
- Lançamento de voo (LANCAR_VOO)
- Explosão de voo (EXPLODIR_VOO)
- Finalização do voo (FINALIZAR_VOO)
- Listagem de todos os voos (LISTAR_VOOS)
- Listagem de todos os astronautas mortos (LISTAR_MORTOS)

## Requisitos

- Para rodar os programas, é necessário que tenha instalado e configurado a linguagem C++ e o compilador g++ em sua máquina.

## Como rodar

1. Abra o terminal da sua máquina ou do seu editor de código.

2. Pelo terminal, navegue até a pasta na qual se encontram os programas.

3. Para compilar o programa, utilize o seguinte comando:

```bash
g++ main.cpp Astronauta.cpp Voo.cpp -o astronautas
```

4. Por fim, para rodar o programa, utilize este comando:

```bash
./astronautas (Linux/Mac) 
ou 
astronautas (Windows)
```

5. Caso deseje utilizar um arquivo externo como entrada para o programa, utilize este comando:

```bash
./astronautas < arquivoExterno.txt (Linux/Mac) 
ou
astronautas < arquivoExterno.txt (Windows)
```
