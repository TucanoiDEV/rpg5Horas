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
	string arma, escolhaRaca, escolhaClasse, nomePersonagem, nomePersonagem2;

	//Variáveis iniciais para mecânicas de combate do jogo
	int vida = 0, estus = 0, estamina = 0, mana = 0, reflexo = 0, arrayEscolha = 0;

	//Introdução à criação de personagem, utilizo o cin.get() para captar o "enter" do jogador e utilizo o system("cls") para limpar o console
	cout << "Bem vindo ao meu primeiro RPG de turno!";
	cin.get();
	system("cls");

	//Utilizo um loop para garantir que pelo menos uma raça seja escolhida sem erros
	do{

		//Nesse caso utilizo um loop pelo for para imprimir as raças na tela do jogador 
		cout << "Escolha sua raça:\n\n";
		for (arrayEscolha = 0; arrayEscolha < 5; arrayEscolha++) {

			cout << racas[arrayEscolha] << endl;

		}

		//Uso o comando cin para captar a raça do jogador
		cout << "\n";
		cin >> escolhaRaca;

		//Utilizado para transformar todos os caracteres em minúsculo
		transform(escolhaRaca.begin(), escolhaRaca.end(), escolhaRaca.begin(), ::tolower);

		//Utilizo o if para que seja impresso uma mensagem de "seleção inválida", assim avisando ao jogador que sua raça não foi identificada
		if (escolhaRaca != "humano" && escolhaRaca != "anão" && escolhaRaca != "draconiano" && escolhaRaca != "vampiro" && escolhaRaca != "elfo") {

			cout << "\n\nSeleção inválida, por favor escolha uma das classes listadas!" << endl;
			cin.ignore();
			cin.get();
			system("cls");

		}
		
	} while (escolhaRaca != "humano" && escolhaRaca != "anão" && escolhaRaca != "draconiano" && escolhaRaca != "vampiro" && escolhaRaca != "elfo");
	system("cls");

	//Utilizo um loop para garantir que pelo menos uma classe seja escolhida sem erros
	do {

		//Agora inicio a seleção de classe a partir do mesmo loop criado para raças
		cout << "Escolha sua classe:\n\n";
		for (arrayEscolha = 0;arrayEscolha < 5; arrayEscolha++) {

			cout << classe[arrayEscolha] << endl;

		}

		//Uso o comando cin para captar a classe do jogador
		cout << "\n";
		cin >> escolhaClasse;

		//Utilizado para transformar todos os caracteres em minúsculo
		transform(escolhaClasse.begin(), escolhaClasse.end(), escolhaClasse.begin(), ::tolower);

		//Utilizo o if para que seja impresso uma mensagem de "seleção inválida", assim avisando ao jogador que sua classe não foi identificada
		if (escolhaClasse != "guerreiro" && escolhaClasse != "mago" && escolhaClasse != "assassino" && escolhaClasse != "bárbaro" && escolhaClasse != "druida") {

			cout << "\n\nSeleção inválida, por favor escolha uma das classes listadas!" << endl;
			cin.ignore();
			cin.get();
			system("cls");

		}

	} while (escolhaClasse != "guerreiro" && escolhaClasse != "mago" && escolhaClasse != "assassino" && escolhaClasse != "bárbaro" && escolhaClasse != "druida");
	system("cls");

	//Utilizo um loop "do-while" para descobrir o nome do personagem do jogador e garantir que o nome foi digitado da maneira correta
	do{

		//Faço a verificação a partir de duas perguntas na esperança que o jogador responda o mesmo que elas para assim gerar o fim do loop
		cout << "Digite o nome do seu personagem: ";
		cin >> nomePersonagem;
		cout << "\nConfirme o nome do seu personagem: ";
		cin >> nomePersonagem2;

		//Utilizo um if para informar que a confirmação de nome está diferente
		if (nomePersonagem != nomePersonagem2) {

			cout << "\n\nOs nomes digitados são diferentes.\nPor favor insira o mesmo nome e lembre-se de levar em consideração letras maiúsculas e minúsculas!";
			cin.ignore();
			cin.get();
			system("cls");

		}

	} while (nomePersonagem != nomePersonagem2);

		return 0;
}
