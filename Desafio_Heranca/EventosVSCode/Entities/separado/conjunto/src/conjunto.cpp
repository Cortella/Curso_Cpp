#include "conjunto.h"

using std::string;

Conjunto::Conjunto() {
  cardinalidade_ = 0;
  capacidade_ = 1;
  elementos_ = new string[capacidade_];
}

Conjunto::Conjunto(string s) : Conjunto() {
  inserir(s);
}

Conjunto::Conjunto(const Conjunto& x) : Conjunto() {
  redimensionar(x.capacidade_);
  for (int i = 0; i < x.cardinalidade_; i++) {
    this->inserir(x.elementos_[i]);
  }
}

bool Conjunto::vazio() const {
  return (cardinalidade_ == 0);
}

int Conjunto::cardinalidade() const {
  return cardinalidade_;
}

bool Conjunto::pertence(string s) const {
  for (int i = 0; i < cardinalidade_; i++) {
    if (elementos_[i] == s){
      return true;
    }
  }
  return false;
}

string Conjunto::elemento() const {
  return elementos_[cardinalidade_ - 1];
}

void Conjunto::inserir(string s) {
  if (!pertence(s)) {
    if (cardinalidade_ == capacidade_) {
      redimensionar(2 * capacidade_);
    }
    elementos_[cardinalidade_] = s;
    cardinalidade_++;
  }
}

void Conjunto::remover(string s) {
  // Faz o laço de traz para frente para ser eficiente quando s = elemento().
  for (int i = cardinalidade_ - 1; i >=0; i--) {
    if (elementos_[i] == s){
      // Sobrescreve s pelo último elemento do vetor.
      elementos_[i] = elementos_[cardinalidade_ - 1];  
      cardinalidade_--;
    }
  }
}

Conjunto Conjunto::uniao(const Conjunto& x) {
  // c começa com todos os elementos de *this.
  Conjunto c(*this);  
  // Insere todos os elementos de x que não estão em c.
  for (int i = 0; i < x.cardinalidade_; i++) {
    if (!c.pertence(x.elementos_[i])) {
      c.inserir(x.elementos_[i]);
    }
  }
  return c;
}

Conjunto Conjunto::intersecao(const Conjunto& x) {
  Conjunto c;  
  // Insere em c todos os elementos de x que estão em *this.
  for (int i = 0; i < x.cardinalidade_; i++) {
    if (this->pertence(x.elementos_[i])) {
      c.inserir(x.elementos_[i]);
    }
  }
  return c;
}

Conjunto Conjunto::operator-(const Conjunto& x) {
  // c começa com todos os elementos de *this.
  Conjunto c(*this);  
  // Remove de c todos os elementos que também estão em x.
  for (int i = 0; i < x.cardinalidade_; i++) {
    if (c.pertence(x.elementos_[i])) {
      c.remover(x.elementos_[i]);
    }
  }
  return c;
}

bool Conjunto::operator==(const Conjunto& x) const {
  if (this->cardinalidade_ != x.cardinalidade_) {
    return false;
  } else {
    for (int i = 0; i < this->cardinalidade_; i++) {
      if (!x.pertence(this->elementos_[i]))
        return false;
    }
    return true;
  }
}

void Conjunto::operator=(const Conjunto& x) {
  this->cardinalidade_ = 0;  // Remove todos os elementos de *this.
  redimensionar(x.capacidade_);
  for (int i = 0; i < x.cardinalidade_; i++) {
    this->inserir(x.elementos_[i]);
  }
}

Conjunto::~Conjunto(){
  delete [] elementos_;
}

void Conjunto::redimensionar(int n){
  string* aux = new string[n];
  for (int i = 0; i < cardinalidade_; i++) {
    aux[i] = elementos_[i];
  }
  delete [] elementos_;
  elementos_ = aux;
  capacidade_ = n;
}