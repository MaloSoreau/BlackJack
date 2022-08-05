#include <iostream>
#include "carte.h"
#include "pioche.h"
#include <stdlib.h>
#include <time.h> //sinon on dit adieu au cote aleatoire de rand

Pioche::Pioche()
{
    m_numeroCarte=0;
    m_nbePaquet = 6;
    m_nbeCarteTotalPioche = m_nbePaquet*52;
    int z=0;
    int valeur;
    for (int i=0; i < m_nbePaquet; i++)
    {
        for (int couleur=0; couleur<4; couleur++)//0 a 3 (carreau, trefle, coeur, pique)
        {
            for (int nom=1; nom<14; nom++)// 1 a 10 + valet,reine, roi
            {
                valeur=nom;
                if (valeur>10)
                {
                    valeur=10;
                }

                m_pioche[z].setValeur(valeur);
                m_pioche[z].setCouleur(couleur);
                m_pioche[z].setNom(nom);
                z++;
            }
        }

    }
}
void Pioche::melanger()
{

    int nbeCartes=312; //Nombre de cartes non pioche dans le paquet
    int position;
    srand(time(NULL));

    for(int i=0;i<m_nbeCarteTotalPioche;i++)
    {
        position = rand()%(nbeCartes); //en prendre une position d'une carte aux hasard
        m_pioche[position].setPasDejaPiochee(1);
        m_pioche[position].permutationCarte(m_pioche[nbeCartes-1]); //en remplace la carte par le dernier carte
        nbeCartes--; // en decrement la fin du paquet pour ne pas melanger la carte choisie encore une foix
    }
}
Carte Pioche::tirerCarte()
{
    if (m_numeroCarte > m_nbeCarteTotalPioche)
    {
        this->melanger();//Si on utilise les m_nbeCarteTotalPioche cartes de la pioche on remelange puis on reset le m_numeroCarte � 0 et c'est reparti pour un tour.
        m_numeroCarte=0;
    }
    
    Carte cartePiochee(m_pioche[m_numeroCarte]);
    m_pioche[m_numeroCarte].setPasDejaPiochee(0);
    m_numeroCarte++;
    
    return cartePiochee;//On retourne la carte pioch�e
}

double Pioche::chanceGagnant(Carte score)
{
    double nbeDeCarteGagnante(0);
    double nbeDeCarteTotal(0);
    Carte b;
    for (int i=0; i<m_nbeCarteTotalPioche; i++)
    {
        if (m_pioche[i].getPasDejaPiochee()==1)
        {
            nbeDeCarteTotal++;
            b=(m_pioche[i] + score);
            if (b<=21)
            {
                nbeDeCarteGagnante++;//On prend toute les cartes qui n'ont pas ete encore tiree, et on regarde si le score depasserai 21, si la reponse est non on augmente le nbe de carteGagnante de 1
            }

        }
    }
    double chanceDeGagner = nbeDeCarteGagnante /nbeDeCarteTotal;
    return chanceDeGagner;// On retourne le % de chance de ne pas depasser 21 si on pioche une carte
}
