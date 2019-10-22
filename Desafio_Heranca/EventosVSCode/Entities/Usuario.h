#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <iostream>

using std::string;
using namespace std;

namespace Entities{
    //----------------------------- Classe-base usuario -----------------------------------
    class Usuario{

        protected:
        int id_;
        string nome_;
        int idade_;
        float saldo_;

        public:

        //Construtor Padrao
        Usuario();
        
        //Cria novo usuario
        //Pre-Condicao: Nao pode ser instanciado como Usuario
        Usuario(int id,string nome,int idade,float saldo);

        //Retorna ID do usuario
        int getId();

        //Retorna nome do usuario
        string getNome();

        //Retorna idade do usuario
        int getIdade();

        //Retorna saldo do usuario
        float getSaldo();

        //Modifica saldo do usuario
        void setSaldo(float valor);

        //Imprime dados do Usuario
        //Funcao virtual pura -> define Usuario como classe abstrata
        virtual void toString() = 0;
    };

    //----------------------------- Classe Adulto -----------------------------------
    class Adulto : public Usuario{

        private:
        Crianca *dependentes_;
        int numDependentes_;

        public:

        //Cria novo usuario adulto
        Adulto();

        //Cria novo usuario com atributos
        Adulto(int id,string nome,int idade,float saldo);

        //Cria adulto co dependentes
        Adulto(int id,string nome,int idade,float saldo, Crianca dependentes[], int numDependentes);

        //Torna Adulto uma classe instanciavel
        void toString() override;

        //Adiciona dependente
        void addDependente(Crianca *dependente);

        
    };

    //----------------------------- Classe Crianca -----------------------------------
    class Crianca: public Usuario{

    private:
    Adulto *responsavel_;
    
    public:
    
    //Cria novo usuario Crianca
    Crianca(int id,string nome,int idade,float saldo,Adulto *responsavel);

    //Sobrescreve funcao toString e permite que Crianca seja uma classe instanciavel
    //Imprime na tela dados da crianca
    void toString() override;

    };


    //----------------------------- Classe Idoso -----------------------------------
    class Idoso : public Adulto{
    public:

    //Cria um novo Idoso
    Idoso();

    //Cria um novo idoso pre definiddo
    Idoso(int id,string nome,int idade,float saldo);

    //escreve dados na tela
    void toString();
    };
}


#endif //USUARIO_H