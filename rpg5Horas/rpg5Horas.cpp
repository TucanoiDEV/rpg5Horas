#include <iostream>
#include <string> //Biblioteca necessária para a criação de arrays na tipagem string
#include <windows.h> //Biblioteca necessária para a acentuação no programa
#include <cstdlib> //Biblioteca necessária para a limpa de linhas no código
#include <algorithm> //Biblioteca necessária para transformar caracteres minúsculos em maisculos

using namespace std;

int main() {

	//Comando utilizado para o programa ler acentos
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);

	//Arrays para facilitar na programação de caracterização de personagem
	string racas[5] = { "Humano", "Anão", "Draconiano", "Vampiro", "Elfo" };
	string classe[5] = { "Guerreiro", "Mago", "Assassino", "Bárbaro", "Druida" };
	string arma, escolhaRaca;

	//Variáveis iniciais para mecânicas de combate do jogo
	int vida = 0, estus = 0, estamina = 0, mana = 0, reflexo = 0, arrayEscolha = 0;

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

		//Utilizado para transformar todos os caracteres em minúsculo
		transform(escolhaRaca.begin(), escolhaRaca.end(), escolhaRaca.begin(), ::tolower);

		//Utilizo o if para que seja impresso uma mensagem de "seleção inválida", assim avisando ao jogador que sua raça não foi identificada
		if (escolhaRaca != "humano" && escolhaRaca != "anão" && escolhaRaca != "draconiano" && escolhaRaca != "vampiro" && escolhaRaca != "elfo") {

			cout << "Seleção inválida, por favor escolha uma das classes listadas!" << endl;

		}
		
	} while (escolhaRaca != "humano" && escolhaRaca != "anão" && escolhaRaca != "draconiano" && escolhaRaca != "vampiro" && escolhaRaca != "elfo");

	//Agora inicio a seleção de classe a partir do mesmo loop criado para raças
	cout << "Escolha sua classe:\n\n";
	for (arrayEscolha = 0;arrayEscolha < 5; arrayEscolha++) {

		cout << classe[arrayEscolha] << endl;

	}

		return 0;
}
