#include "Usuario.h"

namespace Entities{

    Usuario::Usuario(){
        
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

    Usuario::~Usuario(){
        delete this;
    }

    //Classe Crianca 

    Crianca::Crianca(){
        
    }

    Crianca::Crianca(int id,string nome,int idade,float saldo,Adulto * responsavel) : Usuario::Usuario(id,nome,idade,saldo){
        responsavel_ = responsavel;
    }

    bool Crianca::operator==(const Crianca& x) const{
        if((this->id_ == x.id_) && (this->nome_ == x.nome_)){
            return true;
        }
        return false;
    }

    void Crianca::toString(){
        cout<< "ID : " << this->getId() <<endl;
        cout<< "Nome : " << this->getNome() <<endl;
        cout<< "Idade : " << this->getIdade() <<endl;
        cout<< "Saldo : " << this->getIdade() <<endl;
        cout<< "Responsavel : " << responsavel_->getNome() <<endl;
    }

    Crianca::~Crianca(){
        delete this;
    }

    //Classe Adulto

     Adulto::Adulto() : Usuario(){
        dependentes_ = new Crianca[capacidade_];
        numEventos_ = 0;
                        
    }
    Adulto::Adulto(int id,string nome,int idade,float saldo) : Usuario(id,nome,idade,saldo){
        capacidade_ = 1;
        numDependentes_ =0;
        dependentes_ = new Crianca[capacidade_];
        numEventos_ = 0;
        
    }

    Adulto::Adulto(int id,string nome,int idade,float saldo, Crianca dependentes[], int numDependentes) : Usuario(id,nome,idade,saldo){
        dependentes_ = dependentes;
        numDependentes_ =numDependentes;
        numEventos_ = 0;
    }

    void Adulto::addDependente(Crianca *c) {
        if (!pertence(c)) {
            if (numDependentes_ == capacidade_) {
            redimensionar(2 * capacidade_);
            }
        dependentes_[numDependentes_] = *c;
        numDependentes_++;
        }
    }

    bool Adulto::pertence(Crianca *c) const {
    for (int i = 0; i < numDependentes_; i++) {
        if (dependentes_[i] == *c){
            return true;
        }
    }
    return false;
    }

    void Adulto::remover(Crianca *c) {
        // Faz o laço de traz para frente para ser eficiente quando *c = elemento().
        for (int i = numDependentes_ - 1; i >=0; i--) {
            if (dependentes_[i] == *c){
                // Sobrescreve *c pelo último elemento do vetor.
                dependentes_[i] = dependentes_[numDependentes_ - 1];  
                numDependentes_--;
            }
        }
    }

    void Adulto::redimensionar(int n){
    Crianca* aux = new Crianca[n];
    for(int i = 0; i < numDependentes_; i++) {
        aux[i] = dependentes_[i];
    }
    delete [] dependentes_;
    dependentes_ = aux;
    capacidade_ = n;
    }

    void Adulto::toString(){
        cout<< "ID : " << this->getId() <<endl;
        cout<< "Nome : " << this->getNome() <<endl;
        cout<< "Idade : " << this->getIdade() <<endl;
        cout<< "Saldo : " << this->getSaldo() <<endl;
    }

    void Adulto::addEvento(){
        numEventos_++;
    }
    
    Adulto::~Adulto(){
        delete [] dependentes_;
        delete this;
    }

    //Class idoso

    Idoso::Idoso(){

    }

    Idoso::Idoso(int id,string nome,int idade,float saldo) {
        id_=id;
        nome_=nome;
        idade_ = idade;
        saldo_ = saldo;
    }

    Idoso::~Idoso(){

    }

}