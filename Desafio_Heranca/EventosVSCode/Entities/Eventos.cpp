#include "Eventos.h"

namespace Entities{

    //--------------------------Implementacao classe-base Evento -------------------------------------

    Evento::Evento(){

    }

    Evento::Evento(int id,string nome,Adulto *responsavel,int capacidades[],int precos[]){
        this->id_ = id;
        this->nome_ = nome;
        responsavel_ = responsavel;
        capacidades_ = capacidades;
        precos_ = precos;
    }

    int Evento::getId(){
        return id_;
    }

    string Evento::getNome(){
        return nome_;
    }

    string Evento::getNomeResponsavel(){
        return responsavel_->getNome();
    }

    int* Evento::getCapacidades(){
        return capacidades_;
    }

    int* Evento::getPrecos(){
        return precos_;
    }

    Evento::~Evento(){
        delete [] capacidades_;
        delete [] precos_;
        delete this;
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

    EventoInfantil::~EventoInfantil(){
        delete [] capacidades_;
        delete [] precos_;
        delete this;
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

    int* TeatroFantoche::getHorarios(){
        return horarios_;
    }

    //@override
    void TeatroFantoche::toString(){
        cout << "ID : " << this->id_ << endl;
        cout << "NOME : " << this->nome_ << endl;
        cout << "Nome responsavel: " <<responsavel_->getNome() << "ID" <<responsavel_->getId() <<endl;
        for(int i=0;i<(sizeof(capacidades_))/4;i++){
            cout<< " Capacidade: " << capacidades_[i]  << "|Valor : "<< precos_[i]<< endl;
        }
        cout<< "Horarios: " <<endl;

        for(int i=0;i<(sizeof(horarios_))/4;i++){
            cout<< " Horarios: " << horarios_[i]  << endl;
        }
    }

        TeatroFantoche::~TeatroFantoche(){
        delete [] capacidades_;
        delete [] precos_;
        delete [] horarios_;
        delete this;
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

    int* Cinema::getHorarios(){
        return horarios_;
    }

    int Cinema::getDuracao(){
        return duracao_;
    }

    void Cinema::toString(){
        cout << "ID : " << this->id_ << endl;
        cout << "NOME : " << this->nome_ << endl;
        cout << "Nome responsavel: " <<responsavel_->getNome() << "ID" <<responsavel_->getId() <<endl;
        for(int i=0;i<(sizeof(capacidades_))/4;i++){
            cout<< " Capacidade: " << capacidades_[i]  << "|Valor : "<< precos_[i]<< endl;
        }
        cout<< "Horarios: " <<endl;

        for(int i=0;i<(sizeof(horarios_))/4;i++){
            cout<< " Horarios: " << horarios_[i]  << endl;
        }
        cout<< "Duracao: " << duracao_<<endl;
    }

    Cinema::~Cinema(){
        delete [] capacidades_;
        delete [] precos_;
        delete [] horarios_;
        delete this;
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

    int EventoAdulto::getQuotaIdoso(){
        return quota_idoso_;
    }

    EventoAdulto::~EventoAdulto(){
        delete [] capacidades_;
        delete [] precos_;
        delete this;
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
    
    int Boate::getInicio(){
        return horaInicio_;
    }

    int Boate::getFim(){
        return horaFim_;
    }

    void Boate::toString(){
        cout << "ID : " << this->id_ << endl;
        cout << "NOME : " << this->nome_ << endl;
        cout << "Nome responsavel: " <<responsavel_->getNome() << "ID" <<responsavel_->getId() <<endl;
        for(int i=0;i<(sizeof(capacidades_))/4;i++){
            cout<< " Capacidade: " << capacidades_[i]  << "|Valor : "<< precos_[i]<< endl;
        }
        cout<< "Qouta Idoso: " << getQuotaIdoso() <<endl;
        cout<< "Começa : " << getInicio() << " | Termina: " << getFim() <<endl; 
    }

    ~Boate::Boate(){
        delete [] capacidades_;
        delete [] precos_;
        delete this;
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

    Show::string* getArtistas(){
        return artistas_;
    }

    void Show::toString(){
        {
        cout << "ID : " << this->id_ << endl;
        cout << "NOME : " << this->nome_ << endl;
        cout << "Nome responsavel: " <<responsavel_->getNome() << "ID" <<responsavel_->getId() <<endl;
        for(int i=0;i<(sizeof(capacidades_))/4;i++){
            cout<< " Capacidade: " << capacidades_[i]  << "|Valor : "<< precos_[i]<< endl;
        }
        for(int i=0;i<(sizeof(artistas_))/artistas_[i].size();i++){
            cout<< " Artista: " << artistas_[i]  << "|Valor : "<< precos_[i]<< endl;
        }
        cout<< "Qouta Idoso: " << getQuotaIdoso() <<endl;
    }

    Show::~Show(){
        delete [] capacidades_;
        delete [] precos_;
        delete [] artistas_;
        delete this;
    }

}