#include <iostream>
#include <string> //Biblioteca necessária para a criação de arrays na tipagem string
#include <windows.h> //Biblioteca necessária para a acentuação no programa
#include <cstdlib> //Biblioteca necessária para a limpa de linhas no código
#include <algorithm> //Biblioteca necessária para transformar caracteres minúsculos em maisculos
#include <random> //Biblioteca necessária para gerar seleções randomicas

using namespace std;

//Função necessária para realizar o switch nas raças
enum Racas { HUMANO, ANAO, DRACONIANO, VAMPIRO, ELFO, INVALIDA };

//Realizo uma atribuição de cada raça para um enum, na expectativa de assemelhar o comando switch a strings
static Racas getRaca(string escolhaRaca) {

	if (escolhaRaca == "humano") return HUMANO;
	if (escolhaRaca == "anão") return ANAO;
	if (escolhaRaca == "draconiano") return DRACONIANO;
	if (escolhaRaca == "vampiro") return VAMPIRO;
	if (escolhaRaca == "elfo") return ELFO;
	return INVALIDA;

}

//Função necessária para realizar o switch nas raças
enum Classes { GUERREIRO, MAGO, ASSASSINO, BARBARO, DRUIDA, INCORRETA };

//Realizo uma atribuição de cada classe para um enum, na expectativa de assemelhar o comando switch a strings
static Classes getClasse(string escolhaClasse) {

	if (escolhaClasse == "guerreiro") return GUERREIRO;
	if (escolhaClasse == "mago") return MAGO;
	if (escolhaClasse == "assassino") return ASSASSINO;
	if (escolhaClasse == "bárbaro") return BARBARO;
	if (escolhaClasse == "druida") return DRUIDA;
	return INCORRETA;

}

int main() {

	//Comando utilizado para o programa ler acentos
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);

	//Arrays para facilitar na programação de caracterização de personagem
	string racas[5] = { "Humano", "Anão", "Draconiano", "Vampiro", "Elfo" };
	string classe[5] = { "Guerreiro", "Mago", "Assassino", "Bárbaro", "Druida" };
	string arma, escolhaRaca, escolhaClasse, nomePersonagem, nomePersonagem2, entrada, passiva, atkS1, atkS2, atkS3;

	//Variáveis iniciais para mecânicas de combate do jogo
	int vida = 0, estus = 5, estusMana = 0, estamina = 0, mana = 0, reflexo = 0, arrayEscolha = 0, forca = 0, danoMagico = 0, cura = 0, atkN1 = 0, atkN2 = 0, atkN3 = 0, ouro = 1000, armaN = 0;

	//Utilizo o loop "do-while" para garantir que o jogador não bugue o console a partir da digitação
	do{

		//Introdução à criação de personagem, utilizo o cin.get() para captar o "enter" do jogador e utilizo o system("cls") para limpar o console
		cout << "Bem vindo ao meu primeiro RPG de turno!" << endl;
		getline(cin, entrada);
		//Utilizo o if para garantir que o jogador não vai digitar algo ao invés da tecla "ENTER"
		if (!entrada.empty()) {

			cout << "Você digitou algo! Por favor, apenas aperte ENTER sem escrever nada." << endl;
			cin.ignore();
			system("cls");

		}

	} while (!entrada.empty());
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

				cout << "\n\nSeleção inválida, por favor escolha uma das classes listadas!\n[Pressione ENTER]" << endl;
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

			cout << "\n\nSeleção inválida, por favor escolha uma das classes listadas!\n[Pressione ENTER]" << endl;
			cin.ignore();
			cin.get();
			system("cls");

		}

	} while (escolhaClasse != "guerreiro" && escolhaClasse != "mago" && escolhaClasse != "assassino" && escolhaClasse != "bárbaro" && escolhaClasse != "druida");
	system("cls");

	//Utilizo um loop "do-while" para descobrir o nome do personagem do jogador e garantir que o nome foi digitado da maneira correta
	do {

		//Faço a verificação a partir de duas perguntas na esperança que o jogador responda o mesmo que elas para assim gerar o fim do loop
		cout << "Digite o nome do seu personagem: ";
		cin >> nomePersonagem;
		cout << "\nConfirme o nome do seu personagem: ";
		cin >> nomePersonagem2;

		//Utilizo um if para informar que a confirmação de nome está diferente
		if (nomePersonagem != nomePersonagem2) {

			//Uilizo o loop neste caso para evitar bugs no console a partir da digitação do jogador
			do {
				cout << "\n\nOs nomes digitados são diferentes.\nPor favor insira o mesmo nome e lembre-se de levar em consideração letras maiúsculas e minúsculas!\nPressione [ENTER]";
				cin.ignore();
				getline(cin, entrada);
				system("cls");
			} while (!entrada.empty());

		}

	} while (nomePersonagem != nomePersonagem2);

	//Trago a função de transcrição de raças para criar um switch
	Racas racaEscolhida = getRaca(escolhaRaca);

	//Utilizo o switch para atribuir os respectivos elementos de cada raça
	switch (racaEscolhida) {

	case HUMANO:

		vida += 100;
		mana += 100;
		estamina += 100;
		reflexo += 100;
		forca += 100;
		passiva = "Passiva de raça Humano: Todos os seus atributos recebem 100 pontos";

		break;

	case ANAO:

		forca += 300;
		passiva = "Passiva de raça Anão: Seu personagem recebe 300 pontos adicionais de força";
		
		break;

	case DRACONIANO:

		vida += 150;
		danoMagico += 75;
		passiva = "Passiva de raça Draconiano: Seu personagem recebe 150 pontos adicionais de vida e 150 pontos de dano mágico";

		break;

	case VAMPIRO:

		vida += 100;
		mana += 250;
		cura = 30;
		passiva = "Passiva de raça Vampiro: Seu personagem recebe 100 pontos adicionais de vida, 250 pontos adicionais de mana e seu personagem cura 30 pontos por ataque";

		break;

	case ELFO:

		mana += 500;
		passiva = "Passiva de raça Elfo: Seu personagem recebe 500 pontos adicionais de mana";

		break;
	}

	//Mesmo processo que o enum Raça
	Classes classeEscolhida = getClasse(escolhaClasse);

	//Mesmo processo que o switch de raça
	switch (classeEscolhida) {

	case GUERREIRO:

		vida += 500;
		estamina += 300;
		reflexo += 20;
		forca += 800;
		atkN1 += forca + armaN;
		atkN2 += 100;
		atkN3;
		atkS1 = "Ataque com espada";
		atkS2 = "Bloquear";
		atkS3 = "Revitalizar";

		break;

	case MAGO:

		vida += 250;
		estamina += 450;
		mana += 700;
		forca += 100;
		reflexo += 15;
		danoMagico += 420;
		atkN1 += danoMagico + armaN;
		atkN2 += 450;
		atkN3;
		atkS1 = "Bola de fogo";
		atkS2 = "Barreira mágica";
		atkS3 = "Benção de cura";

		break;

	case ASSASSINO:

		vida += 450;
		estamina += 700;
		forca += 375;
		reflexo += 75;
		atkN1 += 150 + forca;
		atkN2 += 350;
		atkN3 += 25;
		atkS1 = "Apunhalada";
		atkS2 = "Rasgo";
		atkS3 = "Hemorragia";

		break;

	case BARBARO:

		vida += 1200;
		estamina += 500;
		forca += 795;
		atkN1 += forca + armaN;
		atkN2 += forca + armaN * 2;
		atkN3 += forca / 3;
		atkS1 = "Corte";
		atkS2 = "Corte brutal";
		atkS3 = "Berserk";

		break;

	case DRUIDA:

		vida += 195;
		estamina += 200;
		forca += 110;
		reflexo += 10;
		mana = 750;
		atkN1 += forca;
		atkN2 += 75;
		atkN3;
		atkS1 = "Ataque humano";
		atkS2 = "Cura da natureza";
		atkS3 = "Concentração";

		break;

	}

		return 0;
}
