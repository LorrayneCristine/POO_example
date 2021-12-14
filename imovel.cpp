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

using namespace std;

/* implementacao dos construtores da classe Imovel */

Imovel::Imovel(int id, float valor, string proprietario, string rua, string bairro, string cidade, int numero, 
	           int quartos, int banheiros) {

	this->id = id;
	this->valor = valor;
	this->proprietario = proprietario;
	this->rua = rua;
	this->bairro = bairro;
	this->cidade = cidade;
	this->numero = numero;
	this->quartos = quartos;
	this->banheiros = banheiros;
}

/* implementacao dos getters e setters da classe Imovel */

int Imovel::getId() const {
	return id;
}
void Imovel::setId(int id) {
	this->id = id;
}

float Imovel::getValor() const {
	return valor;
}
void Imovel::setValor(float valor) {
	this->valor = valor;
}

string Imovel::getProprietario() const {
	return proprietario;
}
void Imovel::setProprietario(string proprietario) {
	this->proprietario = proprietario;
}

string Imovel::getRua() const {
	return rua;
}
void Imovel::setRua(string rua) {
	this->rua = rua;
}

string Imovel::getBairro() const {
	return bairro;
}
void Imovel::setBairro(string bairro) {
	this->bairro = bairro;
}

string Imovel::getCidade() const {
	return cidade;
}
void Imovel::setCidade(string cidade) {
	this->cidade = cidade;
}

int Imovel::getNumero() const {
	return numero;
}
void Imovel::setNumero(int numero) {
	this->numero = numero;
}

int Imovel::getQuartos() const {
	return quartos;
}	
void Imovel::setQuartos(int quartos) {
	this->quartos = quartos;
}

int Imovel::getBanheiros() const {
	return banheiros;
}
void Imovel::setBanheiros(int banheiros) {
	this->banheiros = banheiros;
}

void Imovel::setAll(int id, float valor, string proprietario, string rua, string bairro, string cidade, int numero,
	int quartos, int banheiros) {

	this->id = id;
	this->valor = valor;
	this->proprietario = proprietario;
	this->rua = rua;
	this->bairro = bairro;
	this->cidade = cidade;
	this->numero = numero;
	this->quartos = quartos;
	this->banheiros = banheiros;
}

ostream &operator<<(ostream& os, const Imovel& i) {
	os << "-----\n" << i.getProprietario() << "\n\t" << fixed<<setprecision(2)<<i.getValor() << "\n\t" <<
		i.getQuartos() << "\n\t" << i.getRua() << "\n\t" << i.getBairro() << "\n\t" << i.getCidade() << "\n";
	return os;
}