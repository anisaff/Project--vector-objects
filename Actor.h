//
// Created by Anisa on 11/25/2019.
//

#ifndef ANISAFILFIL_FINALPROGRAM_ACTOR_H
#define ANISAFILFIL_FINALPROGRAM_ACTOR_H

#include <iostream>
#include <string>
using namespace std;

class Actor{	//.H file
private:
        int year;
        string award;
        int winner;
        string name;
        string film;
public:
        Actor();	//Default constructor
        Actor(int, string, int, string, string);
        string getFirstName();

        //Getters and Setters
        int getYear(){return year;}
        void setYear(int y){year = y;}

        string getAward(){return award;}
        void setAward(string a){award = a;}

        int getWinner(){return winner;}
        void setWinner(int w){winner = w;}

        string getName(){return name;}
        void setName(string n){name = n;}

        string getFilm(){return film;}
        void setFilm(string f){film = f;}
};



#endif //ANISAFILFIL_FINALPROGRAM_ACTOR_H
