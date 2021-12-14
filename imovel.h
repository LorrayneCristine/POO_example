/* Membros do grupo: Guilherme Augusto Anicio Drummond do Nascimento
 *					 Iago de Castro Andrade
 *					 Lorrayne Cristine Ferreira
 *					 Lucas Silva Barbosa
 *
 * Disciplina: BCC221 - Programacao orientada a objetos
 * Turma: 11
 */

#ifndef IMOVEL_H
#define IMOVEL_H

using namespace std;

class Imovel {

	int id, numero, quartos, banheiros;
	float valor;
	string proprietario, rua, bairro, cidade;

  public:

	Imovel() {}
	Imovel(int id, float valor, string proprietario, string rua, string bairro, string cidade, int numero, 
		   int quartos, int banheiros);
	virtual ~Imovel() {}

	int getId() const;
	void setId(int);

	float getValor() const;
	void setValor(float);

	string getProprietario() const;
	void setProprietario(string);

	string getRua() const;
	void setRua(string);

	string getBairro() const;
	void setBairro(string);

	string getCidade() const;
	void setCidade(string);

	int getNumero() const;
	void setNumero(int);

	int getQuartos() const;
	void setQuartos(int);

	int getBanheiros() const;
	void setBanheiros(int);

	void setAll(int id, float valor, string proprietario, string rua, string bairro, string cidade, int numero, 
		int quartos, int banheiros);

	friend ostream& operator<<(ostream& os, const Imovel& c);

};

#endif