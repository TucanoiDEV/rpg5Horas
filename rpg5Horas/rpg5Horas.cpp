#include <iostream>
#include <string> //Biblioteca necessária para a criação de arrays na tipagem string
#include <windows.h> //Biblioteca necessária para a acentuação no programa
#include <cstdlib> //Biblioteca necessária para a limpa de linhas no código

using namespace std;

int main() {

	//Comando utilizado para o programa ler acentos
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);

	//Arrays para facilitar na programação de caracterização de personagem
	string racas[5] = { "Humano", "Anão", "Draconiano", "Vampiro", "Elfo" };
	string classe[5] = { "Guerreiro", "Mago", "Assassino", "Bárbaro", "Druida" };
	string arma;

	//Variáveis iniciais para mecânicas de combate do jogo
	int vida = 0, estus = 0, estamina = 0, mana = 0, reflexo = 0, escolhaRaca = 0, arrayEscolha = 0;

	//Introdução à criação de personagem, utilizo o cin.get() para captar o "enter" do jogador e utilizo o system("cls") para limpar o console
	cout << "Bem vindo ao meu primeiro RPG de turno!";
	cin.get();
	system("cls");

	//Nesse caso utilizo um loop pelo for para imprimir as raças na tela do jogador 
	cout << "Escolha sua raça:\n\n";
	for (arrayEscolha = 0; arrayEscolha < 5; arrayEscolha++) {
		cout << racas[arrayEscolha] << endl;
	}

	//Utilizo um loop para garantir que pelo menos uma raça seja escolhida sem erros
	do{
		//Uso o comando cin para captar a raça do jogador
		cout << "\n";
		cin >> escolhaRaca;

		
	} while (escolhaRaca != "humano" || escolhaRaca != "anão" || escolhaRaca != "draconiano" || escolhaRaca != "vampiro" || escolhaRaca != "elfo")

		return 0;
}
