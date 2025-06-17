#pragma once
#include <string>
enum Racas { HUMANO, ANAO, DRACONIANO, VAMPIRO, ELFO, INVALIDA };
enum Classes { GUERREIRO, MAGO, ASSASSINO, BARBARO, DRUIDA, INCORRETA };

Racas getRaca(std::string escolhaRaca);
Classes getClasse(std::string escolhaClasse);
void selecionarRaca(int& arrayEscolha, std::string& escolhaRaca, std::string racas[]);
void selecionarClasse(int& arrayEscolha, std::string& escolhaClasse, std::string classe[]);
void selecionarNome(std::string& nomePersonagem, std::string& nomePersonagem2, std::string& entrada);

