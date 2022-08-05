#include <iostream>
#include "simulation.h"
#include "carte.h"
#include "pioche.h"
//CREATION SIMULATION//
Simulation::Simulation()
{
    for (int i=0; i<53; i++)
    {
        m_carte[i]= Carte(i);
    }
    m_scoreJoueur = m_carte[0];
    m_scoreJoueurAs = m_carte[0];
    m_scoreCroupier = m_carte[0];
    m_scoreCroupierAs = m_carte[0];
    m_carteTiree = m_carte[0];
    m_nbeCarteJoueJoueur = 0;
    m_nbeCarteJoueCroupier = 0;
    m_blackJackJoueur = false;
    m_blackJackCroupier = false;
    m_piocheDeCarte.melanger();
}
void Simulation::nouvelleSimulation()
{
    m_scoreJoueur = m_carte[0];
    m_scoreJoueurAs = m_carte[0];
    m_scoreCroupier = m_carte[0];
    m_scoreCroupierAs = m_carte[0];
    m_nbeCarteJoueJoueur = 0;
    m_nbeCarteJoueCroupier = 0;
    m_blackJackJoueur = false;
    m_blackJackCroupier = false;
}

//METHODE JOUEUR//
void Simulation::tourJoueur()
{
    m_carteTiree=m_piocheDeCarte.tirerCarte();
    m_nbeCarteJoueJoueur++;
    m_scoreJoueur += m_carteTiree;
    m_scoreJoueurAs += m_carteTiree;
    if (m_carteTiree == m_carte[1])
    {
        m_scoreJoueurAs+=10;
    }
}
Carte Simulation::getScoreJoueur()
{
    return m_scoreJoueur;
}
Carte Simulation::getScoreJoueurAs()
{
    return m_scoreJoueurAs;
}
int Simulation::getNbeCarteJoueJoueur()
{
    return m_nbeCarteJoueJoueur;
}
void Simulation::setBlackJackJoueur(bool blackJackJ)
{
    m_blackJackJoueur = blackJackJ;
}



//METHODE CROUPIER//
void Simulation::tourCroupier()
{
    m_carteTiree=m_piocheDeCarte.tirerCarte();
    m_nbeCarteJoueCroupier++;
    m_scoreCroupier += m_carteTiree;
    m_scoreCroupierAs += m_carteTiree;
    if (m_carteTiree == m_carte[1])
    {
        m_scoreCroupierAs+=10;
    }
}
Carte Simulation::getScoreCroupier()
{
    return m_scoreCroupier;
}
Carte Simulation::getScoreCroupierAs()
{
    return m_scoreCroupierAs;
}
int Simulation::getNbeCarteJoueCroupier()
{
    return m_nbeCarteJoueCroupier;
}
void Simulation::setBlackJackCroupier(bool blackJackC)
{
    m_blackJackCroupier = blackJackC;
}



//METHODE JOUEUR TEST//
void Simulation::tourJoueurTest()
{
    m_carteTiree=m_piocheDeCarte.tirerCarte();
    m_scoreJoueurTest += m_carteTiree;
    m_scoreJoueurAsTest += m_carteTiree;
    if (m_carteTiree == m_carte[1])
    {
        m_scoreJoueurAsTest+=10;
    }
}
Carte Simulation::getScoreJoueurTest()
{
    return m_scoreJoueurTest;
}
Carte Simulation::getScoreJoueurAsTest()
{
    return m_scoreJoueurAsTest;
}

//AUTRE METHODE

Pioche Simulation::getPioche()
{
    return m_piocheDeCarte;
}
Carte Simulation::getCarteTiree()
{
    return m_carteTiree;
}

int Simulation::resultat() //Donne les resultat
{
    int rep = 0;//0 = Perdu 1 = Egalite 2= Gagne

    //On choisi le score valable le plus haut entre scoreAs et score sans As//
    if (m_scoreCroupierAs <= m_carte[21])
    {
        m_scoreCroupier = m_scoreCroupierAs;
    }
    if (m_scoreJoueurAs <= m_carte[21])
    {
        m_scoreJoueur = m_scoreJoueurAs;
    }

    //On regarde s'il y a eu des BlackJack//
    if (m_scoreCroupier == m_carte[21] && m_nbeCarteJoueCroupier == 2)
    {
        m_blackJackCroupier = true;
    }
    if (m_scoreJoueur == m_carte[21] && m_nbeCarteJoueJoueur == 2)
    {
        m_blackJackJoueur = true;
    }

    //On faite les resultat maintenant//
    if (m_blackJackJoueur == true && m_blackJackCroupier==false )
    {
        rep=2;//BlackJack du joueur donc gagne
    }
    else if (m_blackJackJoueur == false && m_blackJackCroupier == true)
    {
        rep=0;//BlackJack du croupier donc perdu
    }
    else if (m_blackJackCroupier == true && m_blackJackCroupier == true)
    {
        rep=1; //BlackJack des deux joueur donc egalite
    }
    else if (m_scoreJoueur > m_carte[21])
    {
        rep=0;
    }
    else if (m_scoreJoueur == m_scoreCroupier)
    {
        rep=1;
    }
    else if (m_scoreJoueur > m_scoreCroupier || m_scoreCroupier > m_carte[21])
    {
        rep=2; //Si le score du jouer est plus grand ou que le croupier a depasse 21 il gagne.
    }
    else
    {
        rep=0;
    }
return rep;
}



























