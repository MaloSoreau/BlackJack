#ifndef CARTE_H_INCLUDED
#define CARTE_H_INCLUDED

using namespace std;

class Carte
{
public :

    Carte();
    Carte(int valeurCarte);
    bool estEgal(Carte const& b) const;
    bool estPlusPetitQue(Carte const& b) const;
    bool estPlusGrandQue(Carte const& b) const;
    void operator+=(const Carte& b);
    void setCouleur(int couleur) ;
    void setValeur(int valeur) ;
    void setNom(int nom) ;
    void setPasDejaPiochee(int pasDejaPiochee) ;
    int getValeur();
    int getPasDejaPiochee() ;

    void permutationCarte(Carte& b);

    void afficherNomCouleur(std::ostream &flux) const;
    void afficherValeur() const;

private :

    int m_valeur ;
    int m_couleur ; //0 = Piques, 1 = Trefles, 2 = Coeur, 3 = Carreau
    int m_nom ;
    int m_pasDejaPiochee ;
};
//OPERATEUR//
//COMPARAISON//
bool operator==(Carte const& a, Carte const& b);
bool operator!=(Carte const& a, Carte const& b);
bool operator<(Carte const &a, Carte const& b);
bool operator>(Carte const &a, Carte const& b);
bool operator>=(Carte const &a, Carte const& b);
bool operator<=(Carte const &a, Carte const& b);

//ARITHMETIQUES//
Carte operator+(Carte const& a, Carte const& b);

//AUTRES//
std::ostream& operator<<( std::ostream &flux, Carte const& carte );

#endif // CARTE_H_INCLUDED
