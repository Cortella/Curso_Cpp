#include <iostream>
#include <stdlib.h>
#include "Usuario.h"
#include "Eventos.h"

using namespace std;
using namespace Entities;

int main(){
    cout<< "---------------TEST ENTITIES";
    Adulto * paulo = new Adulto(15,"Paulo",30,305);
    paulo->toString();
    Crianca *c = new Crianca(1,"Roberta",15,300,paulo);
    Crianca *j = new Crianca(1,"Pedro",15,300,paulo);
    c->toString();
    Idoso * jose = new Idoso(2,"Jose",65,1050);
    jose->toString();

    cout<< "end test Usuario.h" <<endl;

    cout<< (*c == *j);
    int capacidades[2] = {2,1};
    int preco[2] = {500,300};
    int vet[2] = {100,250};
    TeatroFantoche *fantoche = new TeatroFantoche(0,"Fantoche",paulo,capacidades,preco,vet);
    fantoche->toString();
    system("pause");
    return 0;

}