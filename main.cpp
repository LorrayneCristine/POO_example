/* Membros do grupo: Guilherme Augusto Anicio Drummond do Nascimento
 *					 Iago de Castro Andrade
 *					 Lorrayne Cristine Ferreira
 *					 Lucas Silva Barbosa
 *
 * Disciplina: BCC221 - Programacao orientada a objetos
 * Turma: 11
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "imovel.h"
#include "casa.h"
#include "apartamento.h"
#include "chacara.h"

#define CASA 1
#define APARTAMENTO 2
#define CHACARA 3

using namespace std;

int menu();

// exercicio 2
bool checaProprietario(vector<Imovel*> imoveis, string proprietario);

// exercicio 3
vector<Imovel*> abaixoValor(vector<Imovel*> imoveis, float valor);

// exercicio 4
vector<Imovel*> acimaQuartos(vector<Imovel*> imoveis, int quartos);

// exercicio 5
vector<Imovel*> procuraTipo(vector<Imovel*> imoveis, int id);

// exercicio 6
vector<Imovel*> checaCidade(vector<Imovel*> imoveis, string cidade);

// exercicio 7
vector<Imovel*> procuraProprietario(vector<Imovel*> imoveis, string proprietario);

// exercicio 8
void imprimeTodos(vector<Imovel*> imoveis, bool noArquivo);

int main() {
	ifstream database;
	vector<Imovel*> imoveis, resultado;
	string line, token;
	vector<string> informacoes;
	int fimString, posToken;

	database.open("database_imoveis.txt");
	
	if (database.is_open()) { //se entrar aqui o arquivo foi aberto com sucesso
		while (getline(database, line)) { //extrai caracteres de input ate o fim da linha ou arquivo  
			while (0 < line.length()) { //enquanto o tamanho da string for maior que zero continua no while
				posToken = line.find(';'); //separa os dados lidos no arquivo quando encontra ';'
				token = line.substr(0, posToken); //retorna uma sub-string
				fimString = line.length(); //pega o final da string
				line = line.substr(posToken + 1, fimString); //le da substring ate o final 
				informacoes.push_back(token); //add um ultimo elemento ao final do vetor apos o ultimo elemento
			}

			if (!informacoes.at(0).compare("casa")) { //ve se o caractere lido confere com o parametro
				imoveis.push_back(new Casa(CASA, stof(informacoes.at(1)), informacoes.at(2), informacoes.at(3), //coloca no final do vetor
					informacoes.at(4), informacoes.at(5), stoi(informacoes.at(6)), stoi(informacoes.at(7)), 
					stoi(informacoes.at(8)), stoi(informacoes.at(9)), stoi(informacoes.at(10))));

			} else if (!informacoes.at(0).compare("apartamento")) {
				imoveis.push_back(new Apartamento(APARTAMENTO, stof(informacoes.at(1)), informacoes.at(2), informacoes.at(3), 
					informacoes.at(4), informacoes.at(5), stoi(informacoes.at(6)), stoi(informacoes.at(7)), 
					stoi(informacoes.at(8)), stoi(informacoes.at(9)), stof(informacoes.at(10)), stoi(informacoes.at(11)), 
					stoi(informacoes.at(12))));

			} else if (!informacoes.at(0).compare("chacara")) {
				imoveis.push_back(new Chacara(CHACARA, stof(informacoes.at(1)), informacoes.at(2), informacoes.at(3), 
					informacoes.at(4), informacoes.at(5), stoi(informacoes.at(6)), stoi(informacoes.at(7)), 
					stoi(informacoes.at(8)), stoi(informacoes.at(9)), stoi(informacoes.at(10)), stoi(informacoes.at(11)), 
					stoi(informacoes.at(12)), stoi(informacoes.at(13))));
			}

			informacoes.clear();
		}

		int escolhaMenu; 
		do{
			escolhaMenu = menu();

			if(escolhaMenu == 1){ //escolha 1 = proprietario true/false
				string nome; 
				cout <<"\n\n\tDigite o nome referente: ";
				cin.ignore();
				getline( cin, nome ); //entrada de nome com espaco 

				cout << "\tExercicio 1 => Proprietario procurado: " << nome << endl;
				if(checaProprietario(imoveis, nome))
					cout << "\n\n\tTrue\tProprietario " << nome << " encontrado." << endl;
				else 
					cout << "\n\n\tFalse\tProprietario " << nome << " nao encontrado." << endl;
			} else if(escolhaMenu == 2){ //escolha 2 = entrada com valor de residencia, retorna valores <=
				int valorProcurado;
				cout <<"\n\n\tDigite o valor procurado: ";
				cin >> valorProcurado;

				cout << "\tExercicio 2 => Valor procurado: " << valorProcurado << endl;

				resultado = abaixoValor(imoveis, valorProcurado);
				if(resultado.size() == 0)
					cout << "\n\tNenhum imovel deste valor." << endl;
				else
					imprimeTodos(resultado, false);
			} else if(escolhaMenu == 3){ //escolha 3 = entrada com numero de quartos retorna valores >= 
				int quartosProcurados;
				cout <<"\n\n\tDigite o numero de quartos procurado: ";
				cin>> quartosProcurados;

				cout << "\tExercicio 3 => uartos procurado: " << quartosProcurados << endl;

				resultado = acimaQuartos(imoveis, quartosProcurados);
				if(resultado.size() == 0)
					cout << "\n\tNenhum imovel com esta quantidade de quartos." << endl;
				else
					imprimeTodos(resultado, false);
			} else if(escolhaMenu == 4){ //entrada com tipo de residencia
				int tipoImovel;

				cout << "\n\n\tExercicio 4 => Tipo imovel" << endl;
				cout << "\n\tEscolha a opcao: \nCASA: 1 \t APARTAMENTO: 2 \t CHARACA: 3: ";

				cin >> tipoImovel;

				resultado = procuraTipo(imoveis, tipoImovel);			
				if(resultado.size() == 0)
					cout << "\n\tNenhum imovel do tipo escolhido." << endl;
				else
					imprimeTodos(resultado, false);
			} else if(escolhaMenu == 5){ //entrada com nome da cidade com espaco
				string cidade; 
				cout <<"\n\n\tDigite a cidade referente: ";
				cin.ignore();
				getline( cin, cidade );


				cout << "\tExercicio 5 => Cidade procurada: " << cidade << endl;
				
				resultado = checaCidade(imoveis, cidade);
				if(resultado.size() == 0)
					cout << "\n\tA cidade procurada nao foi encontrada." << endl;
				else		
					imprimeTodos(resultado, false);

			} else if(escolhaMenu == 6){ //entrada com nome do proprietario com espaco
				string nome; 
				cout <<"\n\n\tDigite o nome referente: ";
				cin.ignore();
				getline( cin, nome );


				cout << "\tExercicio 6 => Proprietario procurado: " << nome << endl;

				resultado = procuraProprietario(imoveis, nome);
				if(resultado.size() == 0)
					cout << "\n\tO proprietario nao foi encontrado" << endl;
				else		
					imprimeTodos(resultado, false);

			} else if(escolhaMenu == 7){ //salva OU imprime
				bool salvarImprimir;
				cout << "\n\n\tExercicio 7" << endl;
				cout <<"\t(0)Imprimir (1)Salvar no arquivo: ";
				cin>> salvarImprimir;
				imprimeTodos(imoveis, salvarImprimir);
			} else if (escolhaMenu == 0) {
				cout << "\n\n\tAte mais.\n\n\n";
			} else {
				cout << "\n\n\tComando invalido!!\n\n\n";
			}

			if (escolhaMenu > 1 && escolhaMenu < 7) { // pergunta se quer que salva o resultado das opções de
				bool salvarImprimir;				  // 2 a 6, que são as únicas que geram novas listas, em um arquivo
				cout << "\n\n\tDeseja salvar o resultado em um arquivo?" << endl;
				cout <<"\t(0)Nao (1)Sim: ";
				cin>> salvarImprimir;
				if (salvarImprimir)
					imprimeTodos(resultado, salvarImprimir);
			}

		} while (escolhaMenu != 0);
		 

		for (auto i : imoveis) {
			delete i;
		}
		imoveis.clear();
		database.close();
	} else {
		cout << "Nao foi possivel abrir o arquivo." << endl;
	}
	
	return 0;
}


int menu(){
	int escolhaMenu;
	cout <<"\n\n\t\t Opcoes:" <<endl;
	cout <<"\n\t (1) Procurar por um proprietario que tenha imovel:" <<endl;
	cout <<"\n\t (2) Procurar por um imovel de acordo com o valor:" <<endl;
	cout <<"\n\t (3) Procurar por um imovel de acordo com o numero de quartos:" <<endl;
	cout <<"\n\t (4) Procurar por um imovel de acordo com o seu tipo:" <<endl;
	cout <<"\n\t (5) Procurar por um imovel de acordo com o sua cidade:" <<endl;
	cout <<"\n\t (6) Procurar por um imovel de acordo com o nome de seu proprietario:" <<endl;
	cout <<"\n\t (7) Listar tipos de imoveis:" <<endl;
	cout <<"\n\t (0) Sair do programa" <<endl;

	cout <<"\n\t Digite o numero referente: ";


	cin >> escolhaMenu;

	return escolhaMenu;
}


// exercicio 2
bool checaProprietario(vector<Imovel*> imoveis, string proprietario) {

	for (auto i : imoveis) {
		if (!proprietario.compare(i->getProprietario())) { //compara o nome lido com a database de proprietarios
			return true; //retorna true se o proprietario possuir algum imovel
		}
	}
	return false; 
}


// exercicio 3
vector<Imovel*> abaixoValor(vector<Imovel*> imoveis, float valor) {
	vector<Imovel*> saida;
	for (auto i : imoveis) {
		if (i->getValor() <= valor) { //checa por imoveis com valor igual ou inferior ao valor lido
			saida.push_back(i); //criacao de uma unica colecao
		}
	}

	return saida;
}


// exercicio 4
vector<Imovel*> acimaQuartos(vector<Imovel*> imoveis, int quartos) {
	vector<Imovel*> saida;

	for (auto i : imoveis) {
		if (i->getQuartos() >= quartos) { //checa por imoveis com nro de quartos igual ou superior ao nro lido
			saida.push_back(i); //criacao de uma unica colecao
		}
	}

	return saida;
}


// exercicio 5
vector<Imovel*> procuraTipo(vector<Imovel*> imoveis, int id) {
	vector<Imovel*> saida;

	for (auto i : imoveis) {
		if ((*i).getId() == id) { //checa por imoveis da mesma categoria
			saida.push_back(i);
		}
	}

	sort(saida.begin(), saida.end(), [](Imovel* im1, Imovel* im2){ return im1->getValor() < im2->getValor();});
	//algoritmo sort para ordenacao por valor em ordem crescente

	return saida;
}


// exercicio 6
vector<Imovel*> checaCidade(vector<Imovel*> imoveis, string cidade) {
	vector<Imovel*> saida;

	for (auto i : imoveis) {
		if (!cidade.compare(i->getCidade())) { //checa por imoveis na cidade especificada
			saida.push_back(i);
		}
	}

	sort(saida.begin(), saida.end(), [](Imovel* im1, Imovel* im2){ return im1->getValor() > im2->getValor();});
	//algoritmo sort para ordenacao por valor em ordem decrescente

	return saida;
}


// exercicio 7
vector<Imovel*> procuraProprietario(vector<Imovel*> imoveis, string proprietario) {
	vector<Imovel*> saida;

	for (auto i : imoveis) {
		if (!proprietario.compare(i->getProprietario())) { //checa por imoveis do proprietario especificado
			saida.push_back(i);
		}
	}

	return saida;
}


// exercicio 8
void imprimeTodos(vector<Imovel*> imoveis, bool noArquivo) {
	Casa *casa;
	Apartamento *apartamento;
	Chacara *chacara;
	ofstream saida;
	if (noArquivo) { //caso o usuario nao deseje visualizar no terminal
		saida.open("saida.txt");

		if (saida.is_open()) {
			for (auto i : imoveis) {
				if (i->getId() == 1) { //colecao de imoveis do tipo 1 - casa
					casa = dynamic_cast<Casa*>(i);
					saida << *casa; //escreve no arquivo
				} else if (i->getId() == 2) { //colecao de imoveis do tipo 2 - apartamento
					apartamento = dynamic_cast<Apartamento*>(i);
					saida << *apartamento;
				} else if (i->getId() == 3) { //colecao de imoveis do tipo 3 - chacara
					chacara = dynamic_cast<Chacara*>(i);
					saida << *chacara;
				}
			}
			saida.close();
			cout << "\n\t\tArquivo criado.\n";

		} else {
			cout << "\n\n\t\tNao foi possivel criar o arquivo para escrever a saida.\n";
		}
	} else {
		for (auto i : imoveis) {
			if (i->getId() == 1) {
				casa = dynamic_cast<Casa*>(i);
				cout << *casa; //imprime no terminal
			} else if (i->getId() == 2) {
				apartamento = dynamic_cast<Apartamento*>(i);
				cout << *apartamento;
			} else if (i->getId() == 3) {
				chacara = dynamic_cast<Chacara*>(i);
				cout << *chacara;
			}
		}
	}
}