/* Membros do grupo: Guilherme Augusto Anicio Drummond do Nascimento
 *					 Iago de Castro Andrade
 *					 Lorrayne Cristine Ferreira
 *					 Lucas Silva Barbosa
 *
 * Disciplina: BCC221 - Programacao orientada a objetos
 * Turma: 11
 */

#include <iostream>
#include <iomanip>
#include <string>
#include "imovel.h"
#include "chacara.h"

using namespace std;

/* implementacao dos construtores da classe Chacara */

Chacara::Chacara(int id, float valor, string proprietario, string rua, string bairro, string cidade, int numero, int quartos,
	int banheiros, int salao_festa, int salao_jogos, int campo_futebol, int churrasqueira, int piscina) {

	setAll(id, valor, proprietario, rua, bairro, cidade, numero, quartos, banheiros);
	this->salao_festa = salao_festa;
	this->salao_jogos = salao_jogos;
	this->campo_futebol = campo_futebol;
	this->churrasqueira = churrasqueira;
	this->piscina = piscina;
}

/* implementacao dos getters e setters da classe Chacara */

bool Chacara::getSalaoFesta() const {
	return salao_festa;
}
void Chacara::setSalaoFesta(bool salao_festa) {
	this->salao_festa = salao_festa;
}

bool Chacara::getSalaoJogos() const {
	return salao_jogos;
}
void Chacara::setSalaoJogos(bool salao_jogou) {
	this->salao_jogos = salao_jogos;
}

bool Chacara::getCampoFutebol() const {
	return campo_futebol;
}
void Chacara::setCampoFutebol(bool campo_futebol) {
	this->campo_futebol = campo_futebol;
}

bool Chacara::getChurrasqueira() const {
	return churrasqueira;
}
void Chacara::setChurrasqueira(bool churrasqueira) {
	this->churrasqueira = churrasqueira;
}

bool Chacara::getPiscina() const {
	return piscina;
}
void Chacara::setPiscina(bool piscina) {
	this->piscina = piscina;
}

void Chacara::setAllChacara(int id, float valor, string proprietario, string rua, string bairro, string cidade, int numero, int quartos,
	int banheiros, bool salao_festa, bool salao_jogos, bool campo_futebol, bool churrasqueira, bool piscina) {

	setAll(id, valor, proprietario, rua, bairro, cidade, numero, quartos, banheiros);
	this->salao_festa = salao_festa;
	this->salao_jogos = salao_jogos;
	this->campo_futebol = campo_futebol;
	this->churrasqueira = churrasqueira;
	this->piscina = piscina;
}

ostream &operator<<(ostream &os, const Chacara &c) {
	os << "-----\n" << c.getProprietario() << "\n\t" << fixed<<setprecision(2)<<c.getValor() << "\n\t" <<
		c.getQuartos() << "\n\t" << c.getRua() << "\n\t" << c.getBairro() << "\n\t" << c.getCidade() << 
		"\n\t";// << c.getPiscina() << "\n";
	if (c.getPiscina()) {
		os << "Tem piscina.\n";
	} else {
		os << "Nao tem piscina.\n";
	}
	return os;
}