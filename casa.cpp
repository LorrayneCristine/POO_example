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
#include "casa.h"

using namespace std;

/* implementacao dos construtores da classe Casa */

Casa::Casa(int id, float valor, string proprietario, string rua, string bairro, string cidade, 
	int numero, int quartos, int banheiros, int andares, int sala_jantar) {

	setAll(id, valor, proprietario, rua, bairro, cidade, numero, quartos, banheiros);
	this->andares = andares;
	this->sala_jantar = sala_jantar;
}

/* implementacao dos getters e setters da classe Casa */

int Casa::getAndares() const {
	return andares;
}
void Casa::setAndares(int andares) {
	this->andares = andares;
}

bool Casa::getSalaJantar() const {
	return sala_jantar;
}
void Casa::setSalaJantar(bool sala_jantar) {
	this->sala_jantar = sala_jantar;
}

void Casa::setAllCasa(int id, float valor, string proprietario, string rua, string bairro, string cidade, int numero,
	int quartos, int banheiros, int andares, bool sala_jantar) {

	setAll(id, valor, proprietario, rua, bairro, cidade, numero, quartos, banheiros);
	this->andares = andares;
	this->sala_jantar = sala_jantar;
}


ostream &operator<<(ostream &os, const Casa &c) {
	os << "-----\n" << c.getProprietario() << "\n\t" << fixed<<setprecision(2)<<c.getValor() << "\n\t" <<
		c.getQuartos() << "\n\t" << c.getRua() << "\n\t" << c.getBairro() << "\n\t" << c.getCidade() <<
		"\n\t" << "Numero de andares: " << c.getAndares() << "\n";
	return os;
}