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
#include "apartamento.h"

using namespace std;

/* implementacao dos construtores da classe Apartamento */

Apartamento::Apartamento(int id, float valor, string proprietario, string rua, string bairro, string cidade,
	int numero, int quartos, int banheiros, int andar, float taxa_condominio, int elevador, int sacada) {

	setAll(id, valor, proprietario, rua, bairro, cidade, numero, quartos, banheiros);
	this->andar = andar;
	this->taxa_condominio = taxa_condominio;
	this->elevador = elevador;
	this->sacada = sacada;
}

/* implementacao dos getters e setters da classe Apartamento */

int Apartamento::getAndar() const {
	return andar;
}
void Apartamento::setAndar(int andar) {
	this->andar = andar;
}

float Apartamento::getTaxaCondominio() const {
	return taxa_condominio;
}
void Apartamento::setTaxaCondominio(float taxa_condominio) {
	this->taxa_condominio = taxa_condominio;
}

bool Apartamento::getElevador() const {
	return elevador;
}
void Apartamento::setElevador(bool elevador) {
	this->elevador = elevador;
}

bool Apartamento::getSacada() const {
	return sacada;
}
void Apartamento::getSacada(bool sacada) {
	this->sacada = sacada;
}

void Apartamento::setAllApartamento(int id, float valor, string proprietario, string rua, string bairro, string cidade, int numero,
	int quartos, int banheiros, int andar, float taxa_condominio, bool elevador, bool sacada) {

	setAll(id, valor, proprietario, rua, bairro, cidade, numero, quartos, banheiros);
	this->andar = andar;
	this->taxa_condominio = taxa_condominio;
	this->elevador = elevador;
	this->sacada = sacada;
}


ostream &operator<<(ostream &os, const Apartamento &a) {
	os << "-----\n" << a.getProprietario() << "\n\t" << fixed<<setprecision(2)<<a.getValor() << "\n\t" <<
		a.getQuartos() << "\n\t" << a.getRua() << "\n\t" << a.getBairro() << "\n\t" << a.getCidade() <<
		"\n\t";// << a.getElevador() << "\n";
	if (a.getElevador()) {
		os << "Tem elevador.\n";
	} else {
		os << "Nao tem elevador.\n";
	}
	return os;
}