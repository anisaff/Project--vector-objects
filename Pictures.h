//
// Created by Anisa on 11/25/2019.
//

#ifndef ANISAFILFIL_FINALPROGRAM_PICTURES_H
#define ANISAFILFIL_FINALPROGRAM_PICTURES_H

#include <iostream>
#include <string>
using namespace std;

class Pictures {  //.H file

private:
    string movieName;
    int year;
    int numNominations;
    float rating;
    string genre1, genre2;
    int duration;
    string releaseMonth;
    int metacritic;
    string synopsis;

public:
    Pictures();     //Default Constructor
    Pictures(string, int, int, float, int, string, string, string, int, string);

    //Getters and Setters
    string getmovieName(){return movieName;}
    void setmovieName(string m){movieName = m;}

    int getyear(){return year;}
    void setyear(int y){year = y;}

    int getnumNominations(){return numNominations;}
    void setnumNominations(int n){numNominations = n;}

    float getrating(){return rating;}
    void setrating(float r){rating = r;}

    string getGenre1(){return genre1;}
    void  setGenre1(string g) {genre1 = g;}

    string getGenre2(){return genre2;}
    void  setGenre2(string g) {genre2 = g;}

    int getDuration() { return duration;}
    void setDuration (int d) { duration = d;}

    string getreleaseMonth() { return releaseMonth;}
    void  setreleaseMonth(string m ){ m = releaseMonth;}

    int getmetacritic() { return metacritic;}
    void setmetacritic(int m) {metacritic = m;}

    string getsynopsis() { return synopsis;}
    void setsynopsis (string s) {synopsis = s;}
};



#endif //ANISAFILFIL_FINALPROGRAM_PICTURES_H
