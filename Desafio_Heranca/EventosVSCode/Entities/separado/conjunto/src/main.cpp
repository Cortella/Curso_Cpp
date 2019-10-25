#include <iostream>
#include <string>

#include "conjunto.h"

using std::cout;
using std::endl;
using std::string;
using std::to_string;

void Imprimir(Conjunto x) {
  cout << "{";
  while(x.cardinalidade() > 1){
    string e = x.elemento();
    cout << e << ", ";
    x.remover(e);
  }
  cout << x.elemento() << "}" << endl;
}

int main() {
  // x = {8, 6, 4, 2, 0, -1}.
  Conjunto x("-1");
  for (int i = 0; i < 10; i += 2) {
    x.inserir(to_string(i));
  }
  cout << "x = ";
  Imprimir(x); 
  // x2 = {0, 2, 4, 6, 8, -1}, i.e. x2 == x.
  Conjunto x2("-1");
  for (int i = 8; i >=0; i -= 2) {
    x2.inserir(to_string(i));
  }
  cout << "x2 = ";
  Imprimir(x2); 
  // y = {9, 7, 5, 3, 1, -1}.
  Conjunto y("-1");
  for (int i = 1; i < 10; i += 2) {
    y.inserir(to_string(i));
  }
  cout << "y = ";
  Imprimir(y); 
  // Testa se x == x2.
  if (x == x2) {
    cout << "x == x2" << endl;
  } else {
    cout << "x != x2" << endl;
  }
  // Testa se x != y.
  if (x == y) {
    cout << "x == y" << endl;
  } else {
    cout << "x != y" << endl;
  }
  // u = x união y = {-1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9}.
  Conjunto u = x.uniao(y);
  cout << "x <união> y = ";
  Imprimir(u); 
  // i = x Interseção y = {-1}.
  Conjunto i = x.intersecao(y);
  cout << "x <interseção> y = ";
  Imprimir(i); 
    // d = x - y = {8, 6, 4, 2, 0}.
  Conjunto d = x - y;
  cout << "x - y = ";
  Imprimir(d); 
}