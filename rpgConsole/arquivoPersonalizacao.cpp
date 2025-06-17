#include "arquivoPersonalizacao.h"
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

using namespace std;

//Fun��o necess�ria para realizar o switch nas ra�as e classes
enum Racas { HUMANO, ANAO, DRACONIANO, VAMPIRO, ELFO, INVALIDA };
enum Classes { GUERREIRO, MAGO, ASSASSINO, BARBARO, DRUIDA, INCORRETA };

//Realizo uma atribui��o de cada ra�a para um enum, na expectativa de assemelhar o comando switch a strings
 Racas getRaca(string escolhaRaca) {

	if (escolhaRaca == "humano") return HUMANO;
	if (escolhaRaca == "an�o") return ANAO;
	if (escolhaRaca == "draconiano") return DRACONIANO;
	if (escolhaRaca == "vampiro") return VAMPIRO;
	if (escolhaRaca == "elfo") return ELFO;
	return INVALIDA;

}

 Classes getClasse(string escolhaClasse) {

	if (escolhaClasse == "guerreiro") return GUERREIRO;
	if (escolhaClasse == "mago") return MAGO;
	if (escolhaClasse == "assassino") return ASSASSINO;
	if (escolhaClasse == "b�rbaro") return BARBARO;
	if (escolhaClasse == "druida") return DRUIDA;
	return INCORRETA;

}

void exibirIntroducao(string& entrada) {

	//Utilizo o loop "do-while" para garantir que o jogador n�o bugue o console a partir da digita��o
	do {

		//Introdu��o � cria��o de personagem, utilizo o cin.get() para captar o "enter" do jogador e utilizo o system("cls") para limpar o console
		cout << "Bem vindo ao meu primeiro RPG de turno!" << endl;
		getline(cin, entrada);
		//Utilizo o if para garantir que o jogador n�o vai digitar algo ao inv�s da tecla "ENTER"
		if (!entrada.empty()) {

			cout << "Voc� digitou algo! Por favor, apenas aperte ENTER sem escrever nada." << endl;
			cin.ignore();
			system("cls");

		}

	} while (!entrada.empty());
	system("cls");

}

void limparConsole() {

	cin.get(); // Espera o usu�rio apertar Enter
	system("cls");  // Limpa a tela (no Windows)

}

void selecionarRaca(int& arrayEscolha, string& escolhaRaca, string racas[]) {

	//Utilizo um loop para garantir que pelo menos uma ra�a seja escolhida sem erros
	do {

		//Nesse caso utilizo um loop pelo for para imprimir as ra�as na tela do jogador 
		cout << "Escolha sua ra�a:\n\n";
		for (arrayEscolha = 0; arrayEscolha < 5; arrayEscolha++) {

			cout << racas[arrayEscolha] << endl;

		}

		//Uso o comando cin para captar a ra�a do jogador
		cout << "\n";
		cin >> escolhaRaca;

		//Utilizado para transformar todos os caracteres em min�sculo
		transform(escolhaRaca.begin(), escolhaRaca.end(), escolhaRaca.begin(), ::tolower);

		//Utilizo o if para que seja impresso uma mensagem de "sele��o inv�lida", assim avisando ao jogador que sua ra�a n�o foi identificada
		if (escolhaRaca != "humano" && escolhaRaca != "an�o" && escolhaRaca != "draconiano" && escolhaRaca != "vampiro" && escolhaRaca != "elfo") {

			cout << "\n\nSele��o inv�lida, por favor escolha uma das classes listadas!\n[Pressione ENTER]" << endl;
			cin.ignore();
			cin.get();
			system("cls");

		}

	} while (escolhaRaca != "humano" && escolhaRaca != "an�o" && escolhaRaca != "draconiano" && escolhaRaca != "vampiro" && escolhaRaca != "elfo");
	system("cls");

}

void selecionarClasse(int& arrayEscolha, string& escolhaClasse, string classe[]) {

	//Utilizo um loop para garantir que pelo menos uma classe seja escolhida sem erros
	do {

		//Agora inicio a sele��o de classe a partir do mesmo loop criado para ra�as
		cout << "Escolha sua classe:\n\n";
		for (arrayEscolha = 0; arrayEscolha < 5; arrayEscolha++) {

			cout << classe[arrayEscolha] << endl;

		}

		//Uso o comando cin para captar a classe do jogador
		cout << "\n";
		cin >> escolhaClasse;

		//Utilizado para transformar todos os caracteres em min�sculo
		transform(escolhaClasse.begin(), escolhaClasse.end(), escolhaClasse.begin(), ::tolower);

		//Utilizo o if para que seja impresso uma mensagem de "sele��o inv�lida", assim avisando ao jogador que sua classe n�o foi identificada
		if (escolhaClasse != "guerreiro" && escolhaClasse != "mago" && escolhaClasse != "assassino" && escolhaClasse != "b�rbaro" && escolhaClasse != "druida") {

			cout << "\n\nSele��o inv�lida, por favor escolha uma das classes listadas!\n[Pressione ENTER]" << endl;
			cin.ignore();
			cin.get();
			system("cls");

		}

	} while (escolhaClasse != "guerreiro" && escolhaClasse != "mago" && escolhaClasse != "assassino" && escolhaClasse != "b�rbaro" && escolhaClasse != "druida");
	system("cls");

}

void ataqueMagico(int& danoMagico) {

	danoMagico = rand() % 101;

}

void selecionarNome(string& nomePersonagem, string& nomePersonagem2, string& entrada) {

	//Utilizo um loop "do-while" para descobrir o nome do personagem do jogador e garantir que o nome foi digitado da maneira correta
	do {

		//Fa�o a verifica��o a partir de duas perguntas na esperan�a que o jogador responda o mesmo que elas para assim gerar o fim do loop
		cout << "Digite o nome do seu personagem: ";
		cin >> nomePersonagem;
		cout << "\nConfirme o nome do seu personagem: ";
		cin >> nomePersonagem2;

		//Utilizo um if para informar que a confirma��o de nome est� diferente
		if (nomePersonagem != nomePersonagem2) {

			//Uilizo o loop neste caso para evitar bugs no console a partir da digita��o do jogador
			do {
				cout << "\n\nOs nomes digitados s�o diferentes.\nPor favor insira o mesmo nome e lembre-se de levar em considera��o letras mai�sculas e min�sculas!\nPressione [ENTER]";
				cin.ignore();
				getline(cin, entrada);
				system("cls");
			} while (!entrada.empty());

		}

	} while (nomePersonagem != nomePersonagem2);

	system("cls");

}

void switchRaca(int racaEscolhida,
	int& vida, int& mana, int& estamina, int& reflexo, int& forca,
	int& danoMagico, int& cura,
	string& passiva) {

	//Utilizo o switch para atribuir os respectivos elementos de cada ra�a
	switch (racaEscolhida) {

	case HUMANO:

		vida += 100;
		mana += 100;
		estamina += 100;
		reflexo += 100;
		forca += 100;
		passiva = "Passiva de ra�a Humano: Todos os seus atributos recebem 100 pontos";

		break;

	case ANAO:

		forca += 300;
		passiva = "Passiva de ra�a An�o: Seu personagem recebe 300 pontos adicionais de for�a";

		break;

	case DRACONIANO:

		vida += 150;
		danoMagico += 75;
		passiva = "Passiva de ra�a Draconiano: Seu personagem recebe 150 pontos adicionais de vida e 150 pontos de dano m�gico";

		break;

	case VAMPIRO:

		vida += 100;
		mana += 250;
		cura = 30;
		passiva = "Passiva de ra�a Vampiro: Seu personagem recebe 100 pontos adicionais de vida, 250 pontos adicionais de mana e seu personagem cura de 0 a 50 pontos por rodada";

		break;

	case ELFO:

		mana += 500;
		passiva = "Passiva de ra�a Elfo: Seu personagem recebe 500 pontos adicionais de mana";

		break;
	}

}

void switchClasse(int classeEscolhida,
	int& vida, int& estamina, int& mana, int& reflexo, int& forca,
	int& danoMagico, int& atkN1, int& atkN2, int& atkN3, int armaN,
	string& atkS1, string& atkS2, string& atkS3) {
	//Mesmo processo que o switch de ra�a
	switch (classeEscolhida) {

	case GUERREIRO:

		vida += 500;
		estamina += 300;
		reflexo += 20;
		forca += 800;
		atkN1 += forca + armaN;
		atkN2 += 100;
		atkN3; //N�mero n�o definido, pois ser� utilizado uma fun��o rand�mica no combate
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
		atkN3; //N�mero n�o definido, pois ser� utilizado uma fun��o rand�mica no combate
		atkS1 = "Bola de fogo";
		atkS2 = "Barreira m�gica";
		atkS3 = "Ben��o de cura";

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
		atkN3; //N�mero n�o definido, pois ser� utilizado uma fun��o rand�mica no combate
		atkS1 = "Ataque humano";
		atkS2 = "Cura da natureza";
		atkS3 = "Concentra��o";

		break;

	}

}

void atributos(const string& nomePersonagem, const string& escolhaRaca, const string& escolhaClasse,
	string& arma, const string& atkS1, const string& atkS2, const string& atkS3,
	int vida, int estamina, int mana, int forca, int reflexo, int ouro, int estus, int estusMana,
	const string& passiva) {

	cout << "Seus atributos:\n\n" << endl;
	cout << "Seu nome - " << nomePersonagem << endl;
	cout << "Sua ra�a - " << escolhaRaca << endl;
	cout << "Sua classe - " << escolhaClasse << endl;
	cout << "Sua arma - " << arma << endl;
	cout << "Suas habilidades - " << atkS1 << " - " << atkS2 << " - " << atkS3 << endl;
	cout << "Pontos de vida - " << vida << endl;
	cout << "Pontos de estamina - " << estamina << endl;
	cout << "Pontos de mana - " << mana << endl;
	cout << "Pontos de for�a - " << forca << endl;
	cout << "Pontos de reflexo - " << reflexo << endl;
	cout << "Quantidade de ouro na bolsa - " << ouro << endl;
	cout << "Frascos de cura - " << estus << endl;
	cout << "Frascos de regenera��o de mana - " << estusMana << endl;
	cout << passiva << endl;
	limparConsole();

}