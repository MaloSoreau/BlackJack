#include <iostream>
#include "carte.h"


using namespace std;

Carte::Carte() : m_valeur(0), m_couleur(0) , m_nom(0), m_pasDejaPiochee(1)
{

}
Carte::Carte(int valeurCarte) : m_valeur(valeurCarte), m_couleur(0) , m_nom(0) , m_pasDejaPiochee(1)
{

}
bool Carte::estEgal(Carte const& b) const
{
    return (m_valeur==b.m_valeur);
}
bool Carte::estPlusPetitQue(Carte const& b) const
{
    return (m_valeur < b.m_valeur);
}
bool Carte::estPlusGrandQue(Carte const& b) const
{
    return (m_valeur > b.m_valeur);
}
void Carte::operator+=(const Carte& a)
{
    m_valeur+=a.m_valeur;
}
void Carte::setCouleur(int couleur)
{
    m_couleur=couleur;
}
void Carte::setValeur(int valeur)
{
    m_valeur=valeur;
}
void Carte::setNom(int nom)
{
    m_nom=nom;
}
void Carte::setPasDejaPiochee(int pasDejaPiochee)
{
    m_pasDejaPiochee=pasDejaPiochee;
}
int Carte::getValeur()
{
    return m_valeur;
}
int Carte::getPasDejaPiochee()
{
    return m_pasDejaPiochee;
}
void Carte::permutationCarte(Carte& b)//echanger deux carte
{
    Carte copie=*this;//en creer une carte copie pour enregistrer la premier carte
    m_valeur=b.m_valeur;//en affecte la valeur de 2 carte � la 1
    m_couleur=b.m_couleur;
    m_nom=b.m_nom;// en affecte la couleur de 2 carte � la 1
    b=copie;//en recopie la 2 carte dans la premier
}
void Carte::afficherNomCouleur(ostream &flux) const
{
    switch (m_couleur)
    {
    case 0: //PIQUE
        switch (m_nom)
        {
        case 11:
            flux << "Valet de Pique" << endl;
            break;
        case 12:
            flux << "Dame de Pique" << endl;
            break;
        case 13:
            flux << "Roi de Pique" << endl;
            break;
        default:
            flux << m_nom << " de Pique" << endl;
            break;
        }
        break;
    case 1: //TREFLE
        switch (m_nom)
        {
        case 11:
            flux << "Valet de Trefle" << endl;
            break;
        case 12:
            flux << "Dame de Trefle" << endl;
            break;
        case 13:
            flux << "Roi de Trefle" << endl;
            break;
        default:
            flux << m_nom << " de Trefle" << endl;
            break;
        }
        break;
    case 2: //COEUR
        switch (m_nom)
        {
        case 11:
            flux << "Valet de Coeur" << endl;
            break;
        case 12:
            flux << "Dame de Coeur" << endl;
            break;
        case 13:
            flux << "Roi de Coeur" << endl;
            break;
        default:
            flux << m_nom << " de Coeur" << endl;
            break;
        }
        break;
    case 3: //CARREAU
        switch (m_nom)
        {
        case 11:
            flux << "Valet de Carreau" << endl;
            break;
        case 12:
            flux << "Dame de Carreau" << endl;
            break;
        case 13:
            flux << "Roi de Carreau" << endl;
            break;
        default:
            flux << m_nom << " de Carreau" << endl;
            break;
        }
        break;
    }
}
void Carte::afficherValeur() const
{
    cout << m_valeur;
}

//OPERATEUR//
//COMPARAISON//

bool operator==(Carte const& a, Carte const& b)
{
    return a.estEgal(b);
}
bool operator!=(Carte const& a, Carte const& b)
{
    return !(a==b);
}
bool operator<(Carte const &a, Carte const& b)
{
    return a.estPlusPetitQue(b);
}
bool operator>(Carte const &a, Carte const& b)
{
    return a.estPlusGrandQue(b);
}
bool operator>=(Carte const &a, Carte const& b)
{
    return ((a>b)||(a==b));
}
bool operator<=(Carte const &a, Carte const& b)
{
    return ((a<b)||(a==b));
}

//ARITHMETIQUES//

Carte operator+(Carte const& a, Carte const& b)
{
    Carte copie(a);
    copie +=b;
    return copie;
}

//AUTRES//
std::ostream& operator<<( std::ostream &flux, Carte const& carte )
{
    carte.afficherNomCouleur(flux);
    return flux;
}
