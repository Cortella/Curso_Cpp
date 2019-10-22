#include "Eventos.h"

namespace Entities{

    //--------------------------Implementacao classe-base Evento -------------------------------------

    Evento::Evento(){
        this->id_ = NULL;
        this->nome_ = "";
        this->precos_ = NULL;
        responsavel_ = new Adulto(); 
    }

    Evento::Evento(int id,string nome,Adulto *responsavel,int capacidades[],int precos[]){
        this->id_ = id;
        this->nome_ = nome;
        responsavel_ = responsavel;
        capacidades_ = capacidades;
        precos_ = precos;
    }

    //--------------------------Implementacao classe-base EventoInfantil -------------------------------------

    EventoInfantil::EventoInfantil(){

    }

   EventoInfantil::EventoInfantil(int id,string nome,Adulto *responsavel,int capacidades[],int precos[]){
        this->id_ = id;
        this->nome_ = nome;
        responsavel_ = responsavel;
        capacidades_ = capacidades;
        precos_ = precos;
    }

    //--------------------------Implementacao classe TeatroFantoche -------------------------------------

    TeatroFantoche::TeatroFantoche(){
 
    }

     TeatroFantoche::TeatroFantoche(int id,string nome,Adulto *responsavel,int capacidades[],int precos[],int horarios[]){

        this->id_ = id;
        this->nome_ = nome;
        responsavel_ = responsavel;
        capacidades_ = capacidades;
        precos_ = precos;
        horarios_ = horarios;
    }

    //@override
    void TeatroFantoche::toString(){
        cout << "ID : " << this->id_ << endl;
        cout << "NOME : " << this->nome_ << endl;
        cout << "-------- DADOS DO RESPONSAVEL ------------" << endl;
        responsavel_->toString();
        cout<< "CAPACIDADES: " <<endl; 
    }

      //--------------------------Implementacao classe Cinema -------------------------------------

    Cinema::Cinema(){

    }

    Cinema::Cinema(int id,string nome,Adulto*responsavel,int capacidades[], int precos[],int horarios[], int duracao){
        this->id_ = id;
        this->nome_ = nome;
        responsavel_ = responsavel;
        capacidades_ = capacidades;
        precos_ = precos;
        horarios_ = horarios;
        duracao_ = duracao;
    }

    void Cinema::toString(){
        cout << "ID : " << this->id_ << endl;
        cout << "NOME : " << this->nome_ << endl;
        cout << "-------- DADOS DO RESPONSAVEL ------------" << endl;
        responsavel_->toString();
        cout<< "CAPACIDADES: " <<endl; 
    }

//--------------------------Implementacao classe-base EventoAdulto -------------------------------------

    EventoAdulto::EventoAdulto(){

    }

    EventoAdulto::EventoAdulto(int id,string nome,Adulto*responsavel,int capacidades[], int precos[],int quota){
        id_ = id;
        this->nome_ = nome;
        responsavel_ = responsavel;
        capacidades_ = capacidades;
        precos_ = precos;
        quota_idoso_ = quota;
    }

//----------------------------- Implementacao da classe Boate ----------------------------------

    Boate::Boate(){

    }

    Boate::Boate(int id,string nome,Adulto *responsavel,int capacidades[], int precos[],int horaInicio, int horaFim){
        id_ = id;
        this->nome_ = nome;
        responsavel_ = responsavel;
        capacidades_ = capacidades;
        precos_ = precos;
        horaInicio_ = horaInicio;
        horaFim_ = horaFim;
    }

    void Boate::toString(){
        cout << "ID : " << this->id_ << endl;
        cout << "NOME : " << this->nome_ << endl;
        cout << "-------- DADOS DO RESPONSAVEL ------------" << endl;
        responsavel_->toString();
        cout<< "CAPACIDADES: " <<endl; 
    }

//----------------------------- Implementacao da classe Show ----------------------------------
    Show::Show(){

    }

    Show::Show(int id,string nome,Adulto *responsavel,int capacidades[], int precos[],int abertura, string artistas[]){
        id_ = id;
        this->nome_ = nome;
        responsavel_ = responsavel;
        capacidades_ = capacidades;
        precos_ = precos;
        abertura_ = abertura;
        artistas_ = artistas;
    }

    void Show::toString(){
        cout << "ID : " << this->id_ << endl;
        cout << "NOME : " << this->nome_ << endl;
        cout << "-------- DADOS DO RESPONSAVEL ------------" << endl;
        responsavel_->toString();
        cout<< "CAPACIDADES: " <<endl; 
    }

}