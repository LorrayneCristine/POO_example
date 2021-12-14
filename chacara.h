/* Membros do grupo: Guilherme Augusto Anicio Drummond do Nascimento
 *					 Iago de Castro Andrade
 *					 Lorrayne Cristine Ferreira
 *					 Lucas Silva Barbosa
 *
 * Disciplina: BCC221 - Programacao orientada a objetos
 * Turma: 11
 */

#ifndef CHACARA_H
#define CHACARA_H

using namespace std;

class Chacara : public Imovel {

	bool salao_festa, salao_jogos, campo_futebol, churrasqueira, piscina;

public:

	Chacara() {};
	Chacara(int id, float valor, string proprietario, string rua, string bairro, string cidade, int numero, int quartos,
		int banheiros, int salao_festa, int salao_jogos, int campo_futebol, int churrasqueira, int piscina);
	~Chacara() {}

	bool getSalaoFesta() const;
	void setSalaoFesta(bool);

	bool getSalaoJogos() const;
	void setSalaoJogos(bool);

	bool getCampoFutebol() const;
	void setCampoFutebol(bool);

	bool getChurrasqueira() const;
	void setChurrasqueira(bool);

	bool getPiscina() const;
	void setPiscina(bool);

	void setAllChacara(int id, float valor, string proprietario, string rua, string bairro, string cidade, int numero, int quartos,
		int banheiros, bool salao_festa, bool salao_jogos, bool campo_futebol, bool churrasqueira, bool piscina);

	friend ostream& operator<<(ostream& os, const Chacara& c);

};

#endif