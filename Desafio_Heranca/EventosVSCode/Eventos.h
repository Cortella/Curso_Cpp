#ifndef EVENTOS_H
#define EVENTOS_H

#include <iostream>
#include<string>
#include "Usuario.h"
#include <vector>

using namespace std;

    namespace Entities{

        //----------------------------- Classe-base Evento -----------------------------------

        class Evento{
            public:

            //Construtor Padrao de eventos
            Evento();

            //Cria novo evento
            Evento(int id,string nome,Adulto *responsavel,int capacidades[],int precos[]);

            //retorna id do evento
            int getId();
            
            // retorna nome do evento
            string getNome();

            //retorna nome do Adulto responsavel
            string getNomeResponsavel();
            
            //retorna ponteiro para vetor com capacidades
            int * getCapacidades();

            //retorna ponteiro para vetor de precos
            int * getPrecos();
            //Escreve na tela os dados do evento
            virtual void toString() = 0;

            //Destrutor padrao
            ~Evento();

            protected:
            int id_;
            string nome_;
            Adulto *responsavel_;
            int *capacidades_;
            int *precos_;

        };

        //----------------------------- Classe-base EventoInfantil -----------------------------------

        class EventoInfantil : public Evento{

            public:

            //Construtor padrao de evento infantil
            EventoInfantil();

            //Cria evento infantil
            EventoInfantil(int id,string nome,Adulto *responsavel,int capacidades[], int precos[]);

            //Destrutor padrao
            ~EventoInfantil();
        };

        //----------------------------- Classe TeatroFantoche -----------------------------------

        class TeatroFantoche : public EventoInfantil{
            
            public:
            //Construtor Padrao
            TeatroFantoche();

            //Cria novo Teatro de fantoches
            TeatroFantoche(int id,string nome,Adulto *responsavel,int capacidades[], int precos[],int horarios[]);

            //Retorna ponteiro para vetor de hoarios
            int* getHorarios();

            //@override
            //Sobrescreve funcao toString e torna funcao TeatroFantoche instanciavel
            void toString() override;

            //Destrutor Padrao
            ~TeatroFantoche();
            private:
            int *horarios_;
        };

        //----------------------------- Classe-Cinema -----------------------------------

        class Cinema : public Evento{

            public:
            //Construtor Padrao
            Cinema();

            //Cria novo evento de cinema
            Cinema(int id,string nome,Adulto *responsavel,int capacidades[], int precos[],int horarios[], int duracao);

            //Retorna ponteira para vetor de horarios
            int* getHorarios();

            //retorna duracao
            int getDuracao(); 
            //@override
            //Sobresceve metodo toString e tona Cinema uma classe instanciavel
            void toString() override;

            //Destrutor 
            ~Cinema();

            private:

            int *horarios_;
            int duracao_;
        };

        //----------------------------- Classe base - EventoAdulto -----------------------------------
        
        class EventoAdulto : public Evento{
            
            public:
            //Construtor Padrao
            EventoAdulto();

            //Cria novo evento Adulto
            EventoAdulto(int id,string nome,Adulto *responsavel,int capacidades[], int precos[],int quota_idoso);

            //return quota_idoso

            int getQuotaIdoso();
            //Destrutor
            ~EventoAdulto();

            private:
            int quota_idoso_;
        };

        //----------------------------- Classe Boate -----------------------------------

        class Boate : public EventoAdulto{
            
            public:
            //Construtor padrao
            Boate();

            //Cria novo evento adulto boate
            Boate(int id,string nome,Adulto *responsavel,int capacidades[], int precos[],int horaInicio, int horaFim);
            
            //retorna hora de inicio
            int getInicio();

            //retorna hora do fim
            int getFim();
            
            //Sobresceve metodo toString e torna Boate uma classe instanciavel
            void toString() override;

            //Destrutor
            ~Boate();

            private:
            int horaInicio_;
            int horaFim_;
        };

        //--------------------------------- Classe Show ------------------------------------------------

        class Show : public EventoAdulto{
            
            public:
            //Construtor padrao
            Show();

            //Cria novo evento adulto boate
            Show(int id,string nome,Adulto *responsavel,int capacidades[], int precos[],int abertura, string artistas[]);
            
            //Sobresceve metodo toString e torna Show uma classe instanciavel
            void toString() override;
            
            //Retorna ponteiro para vetor de artistas
            string* getArtistas();
            
            //Destrutor
            ~Show();

            private:
            int abertura_;
            string *artistas_;
        };
    }

#endif //EVENTOS_H