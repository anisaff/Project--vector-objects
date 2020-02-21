//
// Created by Anisa on 11/25/2019.
//

// .cpp file for pictures

#include "Pictures.h"

Pictures::Pictures( ) {}

Pictures::Pictures(string m, int y, int n, float r, int d, string g1, string g2, string month, int mc, string s)
{
    movieName = m;
    year = y;
    numNominations = n;
    rating = r;
    duration = d;
    genre1= g1;
    genre2= g2;
    releaseMonth = month;
    metacritic  = mc;
    synopsis = s;

}
