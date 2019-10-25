#include <iostream>
#include <stdio.h>
#include <list>
#include <fstream>
#include <string.h>

using namespace std;

int main(){
    string x = "usuarios.txt";
    ifstream streamEntrada(x);
	if (streamEntrada.is_open()) {
		while (!streamEntrada.eof()) {
            string atual;
            getline(streamEntrada,atual);
            cout<< atual << endl;
		}
	}
	else {
		cout << "Erro ao abrir arquivo!" << endl;
	}
    system("pause");
    return 0;
}