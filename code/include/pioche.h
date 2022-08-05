#ifndef PIOCHE_H_INCLUDED
#define PIOCHE_H_INCLUDED
#include "carte.h"
#include <vector>

using namespace std;

class Pioche
{

public :

    Pioche();
    void melanger();
    Carte tirerCarte();
    double chanceGagnant(Carte score);

private :
    Carte m_pioche [312];
    int m_numeroCarte;
    int m_nbePaquet; //Nombre de paquet de 52 cartes dans 1 pioche
    int m_nbeCarteTotalPioche;  //Nombre de cartes total dans la pioche
};



#endif // PIOCHE_H_INCLUDED
