// Copyright 2018 Universidade Federal de Minas Gerais (UFMG)
//
// Lista de exercícios sobre Tipos Abstratos de Dados.
// Aplicação: Números Complexos - Coordenadas Euclidianas.
//

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "conjunto.h"
#include "doctest.h"

#include <iostream>

TEST_SUITE("Conjunto") {
  Conjunto c("Hello");
  Conjunto d("World");
  Conjunto e("elem");
  Conjunto f;

  TEST_CASE("Atribuicao") {
    REQUIRE(c.pertence("Hello"));
    REQUIRE(d.pertence("World"));
    REQUIRE(e.pertence("elem"));

    Conjunto g;
    g = c;
    CHECK(g.pertence("Hello") == true);
    g = d;
    g = e;
    g = d;
    CHECK(g.pertence("World") == true);
    CHECK(g.pertence("Hello") == false);

    Conjunto h("teste");
    REQUIRE(h.pertence("teste"));
    h = g;
    g = e;
    CHECK(h.pertence("World"));
    CHECK(g.pertence("elem"));




  }

  TEST_CASE("Uniao") {

    Conjunto g = c.uniao(d).uniao(e).uniao(f);

    CHECK(g.pertence("elem") == true);
    CHECK(g.pertence("World") == true);
    CHECK(g.pertence("Hello") == true);
    CHECK(g.pertence("!") == false);
    CHECK(g.pertence("noop") == false);
    CHECK(g.pertence("") == false);
  }

  TEST_CASE("Intersecao") {
    Conjunto g = c.uniao(d);
    Conjunto h = d.uniao(e);
    Conjunto i = c.uniao(d).uniao(f);

    CHECK(c.intersecao(c) == c);
    CHECK(d.intersecao(d) == d);
    CHECK(e.intersecao(e) == e);

    CHECK(c.intersecao(d) == Conjunto());
    CHECK(g.intersecao(i) == g);
    CHECK(g.intersecao(h) == d);
    CHECK(h.intersecao(i) == i.intersecao(h));
  }

  TEST_CASE("Menor") {
    CHECK(c.menor() == "Hello");
    CHECK(d.menor() == "World");
    CHECK(e.menor() == "elem");
  }

  TEST_CASE("Diferenca") {
    Conjunto g = c.uniao(d);
    Conjunto h = d.uniao(e);
    Conjunto i = c.uniao(d).uniao(e);


    REQUIRE(g.pertence("Hello"));
    REQUIRE(g.pertence("World")); 
    REQUIRE(h.pertence("elem"));
    REQUIRE(h.pertence("World"));
    REQUIRE(i.pertence("Hello"));
    REQUIRE(i.pertence("World"));
    REQUIRE(i.pertence("elem"));

    CHECK(c.diferenca(c) == Conjunto());
    CHECK(d.diferenca(d) == Conjunto());
    CHECK(e.diferenca(e) == Conjunto());

    CHECK(g.diferenca(d) == c);
    CHECK(g.diferenca(c) == d);
    CHECK(h.diferenca(g) == e);
    CHECK(i.diferenca(g) == e);
    CHECK(f.diferenca(g) == Conjunto());
  }
  
  TEST_CASE("Pertence") {
    CHECK(c.pertence("Hello") == true);
    CHECK(d.pertence("World") == true);
    CHECK(e.pertence("elem") == true);

    CHECK(c.pertence("World") == false);
    CHECK(e.pertence("") == false);
  }

  TEST_CASE("Igual ==") {
    CHECK(c == c);
    CHECK(d == d);
    CHECK(e == e);
    CHECK(f == f);
    CHECK(!(c == d));
    CHECK(!(c == f));
    CHECK(!(d == e));
  }
}