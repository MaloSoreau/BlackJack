#ifndef SIMULATION_H_INCLUDED
#define SIMULATION_H_INCLUDED
#include "carte.h"
#include "pioche.h"

using namespace std;

class Simulation
{
public :
    //CREATION SIMULATION//
    Simulation();
    void nouvelleSimulation();


    //METHODE JOUEUR//

    void tourJoueur();
    Carte getScoreJoueur();
    Carte getScoreJoueurAs();
    int getNbeCarteJoueJoueur();
    void setBlackJackJoueur(bool blackJackJ);

    //METHODE CROUPIER//

    void tourCroupier();
    Carte getScoreCroupier();
    Carte getScoreCroupierAs();
    int getNbeCarteJoueCroupier();
    void setBlackJackCroupier(bool blackJackC);

    //METHODE JOUEUR TEST//

    void tourJoueurTest();
    Carte getScoreJoueurTest();
    Carte getScoreJoueurAsTest();

    //AUTRE METHODE//
    Pioche getPioche();
    void melangerCarte();
    Carte getCarteTiree();
    int resultat();


private :
    Carte m_scoreJoueur;
    Carte m_scoreJoueurAs;
    int m_nbeCarteJoueJoueur;
    bool m_blackJackJoueur;

    Carte m_scoreJoueurTest;
    Carte m_scoreJoueurAsTest;

    Carte m_scoreCroupier;
    Carte m_scoreCroupierAs;
    int m_nbeCarteJoueCroupier;
    bool m_blackJackCroupier;


    Carte m_carteTiree;
    Pioche m_piocheDeCarte;
    Carte m_carte[52];
};


#endif // SIMULATION_H_INCLUDED
