#include <iostream>
#include <stdio.h>
#include <list>
#include <fstream>
#include <string>
#include <stdio.h>
#include "Usuario.h"
#include "Eventos.h"
#include <string.h>
#include <cstring>

using namespace std;
using namespace Entities;

void idade(list<Usuario> &usuarios){
    int menor = 0;
    int maior = 0;
    int contador=0;
    double soma = 0.0;
    list<Usuario>::iterator it = usuarios.begin();
    for(it; it != usuarios.end();it++){
        contador++;
        soma += it->getIdade();
        if(it->getIdade() > maior){
            maior = it->getIdade();
        }
        if(it->getIdade() < menor){
            menor = it->getIdade();
        }
    }
    cout << "Idade dos usuários:" <<endl;
    cout << "Minima: " << menor <<endl;
    cout << "Maior: " << maior << endl;
    cout << "Media: " << soma/contador << endl;
    cout << "\n";
    
}

//Imprime dependnetes e numero de dependentes
void dependentes(list<Adulto> &adulto){
    int min=0;
    int max=0;
    double soma =0.0;
    int contador =0;
    list<Adulto>::iterator it = adulto.begin();
    for(it; it != adulto.end();it++){
        
        if(it->getIdade() > max){
            max = it->getIdade();
        }
        if(it->getIdade() < min){
            min = it->getIdade();
        }
    }

}

//imprime quais e 

//Le arquivos e incializa listas
void le_entrada(string arquivo1,string arquivo2,list<Usuario> &usu,list<Evento> &ev){
    int numCriancas=0;
    int numAdultos=0;
    int numIdosos=0;
    ifstream streamEntrada(x);
	if (streamEntrada.is_open()) {
        
		while (!streamEntrada.eof()) {
            
            string atual = "";
            char posicao[20];
            getline(streamEntrada,atual);
            
            
        }
    }else {
		cout << "Erro ao abrir arquivo!" << endl;
	}
    streamEntrada.close();
}
int main(){
    
    
    system("pause");
    return 0;
}