#include <iostream> //Biblioteca Padrão
#include <string> //Biblioteca necessária para a criação de arrays na tipagem string
#include <windows.h> //Biblioteca necessária para a acentuação no programa
#include <cstdlib> //Biblioteca necessária para a limpa de linhas no código e para o comando "rand()" (randomizer)
#include <algorithm> //Biblioteca necessária para transformar caracteres minúsculos em maisculos
#include <ctime> //Biblioteca necessária para gerar seleções randomicas, pois fornece sementes 

using namespace std;

//Função necessária para realizar o switch nas raças e classes
enum Racas { HUMANO, ANAO, DRACONIANO, VAMPIRO, ELFO, INVALIDA };
enum Classes { GUERREIRO, MAGO, ASSASSINO, BARBARO, DRUIDA, INCORRETA };

//Realizo uma atribuição de cada raça para um enum, na expectativa de assemelhar o comando switch a strings
static Racas getRaca(string escolhaRaca) {

	if (escolhaRaca == "humano") return HUMANO;
	if (escolhaRaca == "anão") return ANAO;
	if (escolhaRaca == "draconiano") return DRACONIANO;
	if (escolhaRaca == "vampiro") return VAMPIRO;
	if (escolhaRaca == "elfo") return ELFO;
	return INVALIDA;

}

static Classes getClasse(string escolhaClasse) {

	if (escolhaClasse == "guerreiro") return GUERREIRO;
	if (escolhaClasse == "mago") return MAGO;
	if (escolhaClasse == "assassino") return ASSASSINO;
	if (escolhaClasse == "bárbaro") return BARBARO;
	if (escolhaClasse == "druida") return DRUIDA;
	return INCORRETA;

}

void configurarConsole() {

	//Comando utilizado para o programa ler acentos
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);

}

void exibirIntroducao(string &entrada) {

	//Utilizo o loop "do-while" para garantir que o jogador não bugue o console a partir da digitação
	do {

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

}

void limparConsole() {

	cin.get(); // Espera o usuário apertar Enter
	system("cls");  // Limpa a tela (no Windows)

}

void selecionarRaca(int& arrayEscolha, string& escolhaRaca, string racas[]) {

	//Utilizo um loop para garantir que pelo menos uma raça seja escolhida sem erros
	do {

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

}

void selecionarClasse(int& arrayEscolha, string& escolhaClasse, string classe[]) {

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

}

void ataqueMagico(int& danoMagico) {

	danoMagico = rand() % 101;

}

void selecionarNome(string &nomePersonagem, string &nomePersonagem2, string &entrada) {

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

	system("cls");

}

void switchRaca(int racaEscolhida,
	int& vida, int& mana, int& estamina, int& reflexo, int& forca,
	int& danoMagico, int& cura,
	string& passiva) {

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
		passiva = "Passiva de raça Vampiro: Seu personagem recebe 100 pontos adicionais de vida, 250 pontos adicionais de mana e seu personagem cura de 0 a 50 pontos por rodada";

		break;

	case ELFO:

		mana += 500;
		passiva = "Passiva de raça Elfo: Seu personagem recebe 500 pontos adicionais de mana";

		break;
	}

}

void switchClasse(int classeEscolhida,
	int& vida, int& estamina, int& mana, int& reflexo, int& forca,
	int& danoMagico, int& atkN1, int& atkN2, int& atkN3, int armaN,
	string& atkS1, string& atkS2, string& atkS3) {
	//Mesmo processo que o switch de raça
	switch (classeEscolhida) {

	case GUERREIRO:

		vida += 500;
		estamina += 300;
		reflexo += 20;
		forca += 800;
		atkN1 += forca + armaN;
		atkN2 += 100;
		atkN3; //Número não definido, pois será utilizado uma função randômica no combate
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
		atkN3; //Número não definido, pois será utilizado uma função randômica no combate
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
		atkN3; //Número não definido, pois será utilizado uma função randômica no combate
		atkS1 = "Ataque humano";
		atkS2 = "Cura da natureza";
		atkS3 = "Concentração";

		break;

	}

}

void atributos(const string& nomePersonagem, const string& escolhaRaca, const string& escolhaClasse,
	string& arma, const string& atkS1, const string& atkS2, const string& atkS3,
	int vida, int estamina, int mana, int forca, int reflexo, int ouro, int estus, int estusMana,
	const string& passiva) {

	cout << "Seus atributos:\n\n" << endl;
	cout << "Seu nome - " << nomePersonagem << endl;
	cout << "Sua raça - " << escolhaRaca << endl;
	cout << "Sua classe - " << escolhaClasse << endl;
	cout << "Sua arma - " << arma << endl;
	cout << "Suas habilidades - " << atkS1 <<" - "<< atkS2 << " - " << atkS3 << endl;
	cout << "Pontos de vida - " << vida << endl;
	cout << "Pontos de estamina - " << estamina << endl;
	cout << "Pontos de mana - " << mana << endl;
	cout << "Pontos de força - " << forca << endl;
	cout << "Pontos de reflexo - " << reflexo << endl;
	cout << "Quantidade de ouro na bolsa - " << ouro << endl;
	cout << "Frascos de cura - " << estus << endl;
	cout << "Frascos de regeneração de mana - " << estusMana << endl;
	cout << passiva << endl;
	limparConsole();

}

void cura(int& vida) {

	// Gera um número aleatório de 0 a 50
	int revitalizar = rand() % 101 + 80;

	cout << "Você revitalizou " << revitalizar << " pontos de vida" << endl;
	vida += revitalizar;
	cout << "Vida total: " << vida << endl;
	limparConsole();

}

void danoArtorias1(int& danoChefe, int& vida) {

	// Gera um número aleatório de 1 a 3
	int mortal = rand() % 3 + 1;

	danoChefe = 70 * mortal;
	vida -= danoChefe;
	cout << "Artorias lhe dá " << mortal << " ataques com mortal(is)." << endl;
	cout << "Você recebeu: " << danoChefe << " de dano" << endl;
	cout << "Sua vida atual é: " << vida << endl;
	limparConsole();

}

void danoArtorias2(int& danoChefe, int& vida) {

	// Gera um número aleatório de 100 a 350
	danoChefe = rand() % 251 + 100;
	vida -= danoChefe;
	cout << "Artorias gira com sua espada em sua direção!" << endl;
	cout << "Você recebeu " << danoChefe << " de dano!" << endl;
	cout << "Sua vida atual é: " << vida << endl;
	limparConsole();

}

void danoArtorias3(int& danoChefe, int& vida) {

	// Gera um número aleatório de 100 a 350
	danoChefe = rand() % 476 + 105;
	vida -= danoChefe;
	cout << "Artorias joga matéria abissal em você!" << endl;
	cout << "Você recebeu " << danoChefe << " de dano" << endl;
	cout << "Sua vida atual é: " << vida << endl;
	limparConsole();

}

//Crio uma função para realizar os combates
void switchArtorias(int classeEscolhida, int& vida, int& estamina,
	const string& atkS1, const string& atkS2, const string& atkS3,
	int atkN1, int atkN2, int atkN3, int forca, int danoArma, int& ataqueEscolhido, 
	int& vidaChefe, int reflexo, int& danoChefe, const string& escolhaRaca, int& mana) {

	/*Utilizo um "switch" juntamente com loops "do-while" para o combate,
	considerando as habilidades de cada classe*/
	switch (classeEscolhida) {

	case GUERREIRO:

		do {

			if (vida <= 1) {

				cout << "Você Morreu." << endl;
				limparConsole();
				break;

			}

			bool bloquear = false;
			int ataqueRandom = 0;
			int danoNum = 0;
			ataqueEscolhido = 0;

			do{
				cout << "Sua vida atual: " << vida << endl;
				cout << "Sua estamina: " << estamina << endl;
				cout << "Ataques disponíveis:\n";
				cout << "[1] " << atkS1 << endl;
				cout << "[2] " << atkS2 << endl;
				cout << "[3] " << atkS3 << endl;
				cout << "Escolha o número do ataque: " << endl;
				cin >> ataqueEscolhido;
				limparConsole();

				//Crio este loop para garantir que o jogador não digite nenhum caractere/número que não está presente nas opções
				if (cin.fail()) {
					cin.clear();            // limpa o erro
					cin.ignore(1000, '\n'); // descarta a entrada inválida
					cout << "Entrada inválida. Por favor digite um número entre 1 e 3." << endl;
					limparConsole();
					continue;
				}

				if (ataqueEscolhido != 1 && ataqueEscolhido != 2 && ataqueEscolhido != 3) {

					cout << "Ataque não identificado";
					limparConsole();

				}

			} while (ataqueEscolhido != 1 && ataqueEscolhido != 2 && ataqueEscolhido != 3);

			if (ataqueEscolhido == 1) {

				if(estamina >= 120) {

					danoNum = atkN1; //Ataque padrão
					estamina -= 25;
					mana -= 100;

				}
				else {

					//Comando utilizado para verificar a quantidade de estamina
					cout << "Você não tem estamina o suficiente para este ataque!" << endl;
					limparConsole();
					continue;

				}

			}

			else if (ataqueEscolhido == 2) {

				bloquear = true;
				estamina -= 20;

			}

			else if (ataqueEscolhido == 3) {

				if(estamina>=95) {

					cura(vida); //Chama a função cura para realizar o revitalizar
					estamina -= 95;

				}
				else {

					//Comando utilizado para verificar a quantidade de estamina
					cout << "Você não tem estamina o suficiente para este ataque!" << endl;
					limparConsole();
					continue;

				}

			}

			else {

				//Comando utilizado  para verificação do ataque utilizado
				cout << "Ataque não identificado, por favor selecione um ataque novamente [Enter]";
				limparConsole();
				continue; //Volta ao início do loop

			}

			//If utilizado´para conferir se o personagem deu dano ou não e realiza a impressão da quantidade aplicada
			if(danoNum != 0) {

				cout << "Você causou " << danoNum << " de dano!" << endl;
				vidaChefe -= danoNum;

			}
			cout << "O chefe está com " << vidaChefe << " de vida!" << endl;
			limparConsole();

			cout << "É a vez de Artorias!" << endl;
			limparConsole();

			if (bloquear == true) {

				cout << "Porém você bloqueou sua investida" << endl;
				limparConsole();

			}
			else {

				//If que invoca o ataque inimigo, em conjunto com a possibilidade de esquiva do jogador
				int reflexoTeste = rand() % 301;
				if (reflexoTeste > reflexo) {

					int ataqueRandom = rand() % 3;
					if (ataqueRandom == 0) {

						danoArtorias1(danoChefe, vida);

					}
					else if (ataqueRandom == 1) {

						danoArtorias2(danoChefe, vida);

					}
					else if (ataqueRandom == 2) {

						danoArtorias3(danoChefe, vida);

					}
					else {

						cout << "Você desviou do golpe de Artorias!" << endl;
						limparConsole();

					}

				}
				else {

					cout << "Você desviou do ataque de Artorias!" << endl;
					limparConsole();

				}

				if (escolhaRaca == "vampiro") {

					//Mmomento em que a passiva da raça vampiro é aplicada
					cout << "Você recebeu 30 pontos de vida devido à sua passiva de raça" << endl;
					vida += 30;
					limparConsole();

				}
			}

			//Comando utilizado para adicionar estamina ao final do turno
			estamina += 50;
			cout << "Você recebeu 50 pontos de estamina" << endl;
			limparConsole();

		} while (vidaChefe > 0);

		if (vidaChefe <= 0) {

			cout << "Você derrotou Artorias!!!" << endl;

		}
		break;

		case MAGO:

			do {

				if (vida <= 1) {

					cout << "Você Morreu." << endl;
					limparConsole();
					break;

				}

				bool bloquear = false;
				int ataqueRandom = 0;
				int danoNum = 0;
				ataqueEscolhido = 0;

				do {
					cout << "Sua vida atual: " << vida << endl;
					cout << "Sua estamina: " << estamina << endl;
					cout << "Sua mana: " << mana << endl;
					cout << "Ataques disponíveis:\n";
					cout << "[1] " << atkS1 << endl;
					cout << "[2] " << atkS2 << endl;
					cout << "[3] " << atkS3 << endl;
					cout << "Escolha o número do ataque: " << endl;
					cin >> ataqueEscolhido;
					limparConsole();

					//Crio este loop para garantir que o jogador não digite nenhum caractere/número que não está presente nas opções
					if (cin.fail()) {
						cin.clear();            // limpa o erro
						cin.ignore(1000, '\n'); // descarta a entrada inválida
						cout << "Entrada inválida. Por favor digite um número entre 1 e 3." << endl;
						limparConsole();
						continue;
					}

					if (ataqueEscolhido != 1 && ataqueEscolhido != 2 && ataqueEscolhido != 3) {

						cout << "Ataque não identificado";
						limparConsole();

					}

				} while (ataqueEscolhido != 1 && ataqueEscolhido != 2 && ataqueEscolhido != 3);

				if (ataqueEscolhido == 1) {

					if (estamina >= 120) {

						danoNum = atkN1; //Ataque padrão
						estamina -= 120;
						mana -= 370;

					}
					else {

						//Comando utilizado para verificar a quantidade de estamina
						cout << "Você não tem estamina/mana o suficiente para este ataque!" << endl;
						limparConsole();
						continue;

					}

				}

				else if (ataqueEscolhido == 2) {

					bloquear = true;
					mana -= 50;

				}

				else if (ataqueEscolhido == 3) {

					if (estamina >= 95) {

						cura(vida); //Chama a função cura para realizar o revitalizar
						estamina -= 95;

					}
					else {

						//Comando utilizado para verificar a quantidade de estamina
						cout << "Você não tem estamina o suficiente para este ataque!" << endl;
						limparConsole();
						continue;

					}

				}

				else {

					//Comando utilizado  para verificação do ataque utilizado
					cout << "Ataque não identificado, por favor selecione um ataque novamente [Enter]";
					limparConsole();
					continue; //Volta ao início do loop

				}

				//If utilizado´para conferir se o personagem deu dano ou não e realiza a impressão da quantidade aplicada
				if (danoNum != 0) {

					cout << "Você causou " << danoNum << " de dano!" << endl;
					vidaChefe -= danoNum;

				}
				cout << "O chefe está com " << vidaChefe << " de vida!" << endl;
				limparConsole();

				cout << "É a vez de Artorias!" << endl;
				limparConsole();

				if (bloquear == true) {

					cout << "Você adicionou 450 pontos de escudo com barreira mágica" << endl;
					limparConsole();

				}

				//If que invoca o ataque inimigo, em conjunto com a possibilidade de esquiva do jogador
				int reflexoTeste = rand() % 301;
				if (reflexoTeste > reflexo) {

					int ataqueRandom = rand() % 3;
					if (ataqueRandom == 0) {

						danoArtorias1(danoChefe, vida);

					}
					else if (ataqueRandom == 1) {

						danoArtorias2(danoChefe, vida);

					}
					else if (ataqueRandom == 2) {

						danoArtorias3(danoChefe, vida);

					}
					else {

						cout << "Você desviou do golpe de Artorias!" << endl;
						limparConsole();

					}

				}
				else {

					cout << "Você desviou do ataque de Artorias!" << endl;
					limparConsole();

				}

				if (escolhaRaca == "vampiro") {

					//Mmomento em que a passiva da raça vampiro é aplicada
					cout << "Você recebeu 30 pontos de vida devido à sua passiva de raça" << endl;
					vida += 30;
					limparConsole();

				}

				//Comando utilizado para adicionar estamina ao final do turno
				estamina += 50;
				cout << "Você recebeu 50 pontos de estamina" << endl;
				limparConsole();

			} while (vidaChefe > 0);

			if (vidaChefe <= 0) {

				cout << "Você derrotou Artorias!!!" << endl;

			}
			break;

	}

}

int main() {

	// Inicializa o gerador de números aleatórios com base no tempo atual
	srand(time(0));

	configurarConsole();

	//Arrays para facilitar na programação de caracterização de personagem
	string racas[5] = { "Humano", "Anão", "Draconiano", "Vampiro", "Elfo" };
	string classe[5] = { "Guerreiro", "Mago", "Assassino", "Bárbaro", "Druida" };
	string arma, escolhaRaca, escolhaClasse, nomePersonagem,
		nomePersonagem2, entrada, passiva, atkS1, atkS2, atkS3;

	//Variáveis iniciais para mecânicas de combate do jogo
	int vida = 0, estamina = 0, mana = 0, reflexo = 0, arrayEscolha = 0, 
		forca = 0, danoMagico = 0, cura = 0, atkN1 = 0, atkN2 = 0, 
		atkN3 = 0, ouro = 1000, armaN = 0, danoArma = 0,
		danoChefe = 0, ataqueEscolhido = 0, vidaChefe = 5000;

	exibirIntroducao(entrada);

	selecionarRaca(arrayEscolha, escolhaRaca, racas);

	selecionarClasse(arrayEscolha, escolhaClasse, classe);

	//Trago a função de transcrição de raças para criar um switch
	Racas racaEscolhida = getRaca(escolhaRaca);

	switchRaca(racaEscolhida, vida, mana, estamina, reflexo, forca, danoMagico, cura, passiva);

	//Mesmo processo que o enum Raça
	Classes classeEscolhida = getClasse(escolhaClasse);

	switchClasse(classeEscolhida, vida, estamina, mana, reflexo, forca,
		danoMagico, atkN1, atkN2, atkN3, armaN,
		atkS1, atkS2, atkS3);

	selecionarNome(nomePersonagem, nomePersonagem2, entrada);

	//atributos(nomePersonagem, escolhaRaca, escolhaClasse, arma, atkS1, atkS2, atkS3,
		//vida, estamina, mana, forca, reflexo, ouro, estus, estusMana, passiva);

	switchArtorias(classeEscolhida, vida, estamina, atkS1, atkS2, atkS3, atkN1, atkN2, atkN3,
		forca, danoArma, ataqueEscolhido,vidaChefe,  reflexo, danoChefe, escolhaRaca, mana);

		return 0;
}
