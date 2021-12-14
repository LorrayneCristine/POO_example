/* Membros do grupo: Guilherme Augusto Anicio Drummond do Nascimento
 *					 Iago de Castro Andrade
 *					 Lorrayne Cristine Ferreira
 *					 Lucas Silva Barbosa
 *
 * Disciplina: BCC221 - Programacao orientada a objetos
 * Turma: 11
 */

#ifndef CASA_H
#define CASA_H

using namespace std;

class Casa : public Imovel {

	int andares;
	bool sala_jantar;

public:

	Casa() {};
	Casa(int id, float valor, string proprietario, string rua, string bairro, string cidade, int numero, 
		int quartos, int banheiros, int andares, int sala_jantar);
	~Casa() {}

	int getAndares() const;
	void setAndares(int);

	bool getSalaJantar() const;
	void setSalaJantar(bool);

	void setAllCasa(int id, float valor, string proprietario, string rua, string bairro, string cidade, int numero, 
		int quartos, int banheiros, int andares, bool sala_jantar);

	friend ostream& operator<<(ostream& os, const Casa& c);

};

#endif