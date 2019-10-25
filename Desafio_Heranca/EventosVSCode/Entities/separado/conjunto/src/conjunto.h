#ifndef CONJUNTO_H
#define CONJUNTO_H

#include <string>

using std::string;

class Conjunto {
 public:
  // Cria um conjunto vazio.
  Conjunto();

  // Cria um conjunto unitário contendo s;
  Conjunto(string s);

  // Cria um conjunto com os mesmos elementos de x;
  Conjunto(const Conjunto& x);

  // Testa se o conjunto é vazio.
  bool vazio() const;

  // Retorna a cardinalidade do conjunto.
  int cardinalidade() const;

  // Testa se s pertence ao conjunto.
  bool pertence(string s) const;

  // Retorna um elemento qualquer do conjunto.
  // RECONDIÇÃO: o cojunto tem pelo menos um elemento.
  string elemento() const;

  // Insere s no conjunto, se lá ele não está.
  void inserir(string s);

  // Remove s do conjunto, se lá ele está.
  void remover(string s);

  // Retorna a união de *this e x.
  Conjunto uniao(const Conjunto& x);

  // Retorna a interseção de *this e x.
  Conjunto intersecao(const Conjunto& x);

  // Retorna a diferença entre *this e x.
  Conjunto operator-(const Conjunto& x);

  // Testa se *this tem exatamente os mesmos elementos de x.
  bool operator==(const Conjunto& x) const;

  // Faz com que *this tenha os mesmos elementos de x.
  void operator=(const Conjunto& x);

  // Desaloca toda a memória alocada para o conjunto.
  ~Conjunto();
  
 private:
  string* elementos_;  // Vetor de elementos do conjunto.
  int capacidade_;  // Tamanho do vetor elementos_.
  int cardinalidade_;  // Número de elementos no conjunto.

  // Altera o tamanho do vetor para n elementos.
  // PRECONDIÇÃO: n >= cardinalidade_.
  void redimensionar(int n);
};

#endif  // CONJUNTO_H
