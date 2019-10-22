#include "Usuario.h"

namespace Entities{

    Usuario::Usuario(){
        id_ = NULL;
        nome_ = "";
        idade_ = NULL;
        saldo_ = NULL;
    }

    Usuario::Usuario(int id,string nome,int idade, float saldo){
        id_ = id;
        nome_ = nome;
        idade_ = idade;
        saldo_ = saldo;
    }

    int Usuario::getId(){
        return id_;
    }

    string Usuario::getNome(){
        return nome_;
    } 

    int Usuario::getIdade(){
        return idade_;
    }

    float Usuario::getSaldo(){
        return saldo_;
    }

    void Usuario::setSaldo(float saldo){
        saldo_= saldo;
    }

    //Classe Crianca 

    Crianca::Crianca(int id,string nome,int idade,float saldo,Adulto * responsavel) : Usuario::Usuario(id,nome,idade,saldo){
        responsavel_ = responsavel;
    }

    void Crianca::toString(){
        cout<< "ID : " << this->getId() <<endl;
        cout<< "Nome : " << this->getNome() <<endl;
        cout<< "Idade : " << this->getIdade() <<endl;
        cout<< "Saldo : " << this->getIdade() <<endl;
        cout<< "Responsavel : " << responsavel_->getNome() <<endl;
    }

    //Classe Adulto

     Adulto::Adulto(){
        id_ = 0;
        nome_ = "";
        idade_ = 0;
        saldo_ =0.0;
                        
    }
    Adulto::Adulto(int id,string nome,int idade,float saldo){
        id_ = id;
        nome_ = nome;
        idade_ = idade;
        saldo_ =saldo;
        *dependentes_ = new array();
        numDependentes_ =0;
    }

    Adulto::Adulto(int id,string nome,int idade,float saldo, Crianca dependentes[], int numDependentes){
        id_ = id;
        nome_ = nome;
        idade_ = idade;
        saldo_ =saldo;
        dependentes_ = dependentes;
        numDependentes_ =numDependentes;
    }

}