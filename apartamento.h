/* Membros do grupo: Guilherme Augusto Anicio Drummond do Nascimento
 *					 Iago de Castro Andrade
 *					 Lorrayne Cristine Ferreira
 *					 Lucas Silva Barbosa
 *
 * Disciplina: BCC221 - Programacao orientada a objetos
 * Turma: 11
 */

#ifndef APARTAMENTO_H
#define APARTAMENTO_H

using namespace std;

class Apartamento : public Imovel {

	int andar;
	float taxa_condominio;
	bool elevador, sacada;

public:

	Apartamento() {};
	Apartamento(int id, float valor, string proprietario, string rua, string bairro, string cidade, int numero, 
		int quartos, int banheiros, int andar, float taxa_condominio, int elevador, int sacada);
	~Apartamento() {}

	int getAndar() const;
	void setAndar(int);

	float getTaxaCondominio() const;
	void setTaxaCondominio(float);

	bool getElevador() const;
	void setElevador(bool);

	bool getSacada() const;
	void getSacada(bool);

	void setAllApartamento(int id, float valor, string proprietario, string rua, string bairro, string cidade, int numero, 
		int quartos, int banheiros, int andar, float taxa_condominio, bool elevador, bool sacada);

	friend ostream& operator<<(ostream& os, const Apartamento& c);

};

#endif