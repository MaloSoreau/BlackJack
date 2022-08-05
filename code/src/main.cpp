#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "carte.h"
#include "pioche.h"
#include "simulation.h"

using namespace std;

int main()
{
    //DECLARATION VARIABLE//
    double partiGagne(0);
    double partiTotal(0);
    int nbeDeSimulation(10000); //Nombre de fois qu'on veut lancer la simulation

//On cr�e un paquet de carte classique pour les besoins du programme
    Carte a;
    Carte carte[52];
    for (int i=0; i<53; i++)
    {
        carte[i]= Carte(i);
    }

    //Construction de la simulation//
    Simulation newGame;

    string reponse;
    
    cout << "///////////////////////////////////////////////////////////////////" <<endl;
    cout << "////////////////////////////BLACKJACK//////////////////////////////" <<endl;
    cout << "///////////////////////////////////////////////////////////////////" <<endl;
    cout << "///Voulez vous jouer ou lancer une simulation ? Jouer/Simulation///" <<endl;
    cin >> reponse;
    while (reponse == "42")
    {
	cout <<"Bravo vous avez la reponse, mais quelle etait la question ?"<<endl;//EasterEgg
	cin >> reponse;	
    }
    while (reponse!="Jouer" && reponse!="Simulation")
    {
        cout << "'Ce que tu dis n'a aucun sens !' Jack Sparrow" << endl;    
        cin >> reponse;
    }
    if (reponse == "Simulation")
    {
	cout << "Combien d'iteration par simulation voulez vous faire ?"<< endl;
	cin >> nbeDeSimulation;
    }
		

//////////////////////////////////////////////////////////////////
////////////////////////////JEU CLASSIQUE/////////////////////////
//////////////////////////////////////////////////////////////////

    if(reponse == "Jouer")
    {
	newGame.nouvelleSimulation(); //On lance une nouvelle parti (sans reset de la pioche)
        string rejouer;
        do
        {
            cout << "///////////////////////////////////////////////////////////////////" <<endl;
            cout << "///////////////////////NOUVELLE PARTIE/////////////////////////////" << endl;
            cout << endl;
            partiTotal++; // On incremente le nombre total de parti
            newGame.nouvelleSimulation();
            newGame.tourCroupier();//Le croupier pioche la carte est automatiquement ajoute a son score.
            cout << "Le croupier pioche une carte :" << newGame.getCarteTiree() << endl;
            cout << "Le score du croupier est de : ";
            newGame.getScoreCroupier().afficherValeur(); // On affiche la valeur
            cout << endl;
            cout << endl;

            cout << "///////////////////////////////////////////////////////////////////" <<endl;
            cout << "//////////////////A vous de jouer maintenant///////////////////////" << endl;

            do
            {
                cout << "///////////////////////////////////////////////////////////////////" <<endl;
                cout << endl;
                newGame.tourJoueur();//Le joueur pioche la carte est automatiquement ajoute a son score.
                cout << "Vous avez pioche : " << newGame.getCarteTiree() << endl;
                cout << "Votre score total est de ";
                newGame.getScoreJoueur().afficherValeur();

                if ((newGame.getScoreJoueur()!=newGame.getScoreJoueurAs()) && (newGame.getScoreJoueurAs() <= carte[21]))//Si un as a ete pioche les deux scores sont different et on les affiches.
                {
                    cout << "/";
                    newGame.getScoreJoueurAs().afficherValeur();
                }

                cout << endl;
                cout << endl;
                cout << "///////////////////////////////////////////////////////////////////" <<endl;

                if (newGame.getScoreJoueurAs() == carte[21] && newGame.getNbeCarteJoueJoueur() == 2)
                {
                    cout << "Black Jack ! Vous etes chanceux" << endl;
                    newGame.setBlackJackJoueur(true); //Si le joueur atteint 21 en tirant 2 cartes : BlackJack
                    reponse = "Non";
                }
                if (newGame.getScoreJoueur() > carte[21])
                {
                    reponse = "Non"; //Si le joueur depasse 21 Perdu
                }
                if (newGame.getScoreJoueur() < carte[21])
                {
		    cout << "Voulez vous repiocher ? Oui/Non ?" << endl;
                    cin >> reponse;
                    while(reponse!="Oui" && reponse!="Non")
                    {
	   		cout << "'Ce que tu dis n'a aucun sens !' Jack Sparrow" << endl;    
	    		cin >> reponse;
    		    }
                }
            }while((newGame.getScoreJoueur()  < carte[21] || newGame.getScoreJoueurAs()  < carte[21]) && reponse=="Oui");
	    if (newGame.getScoreJoueur()  < carte[21] || newGame.getScoreJoueurAs()  < carte[21])
	    {
            cout << "///////////////////////////////////////////////////////////////////" <<endl;
            cout << "/////////////////////////TOUR DU CROUPIER//////////////////////////" << endl;
	    }
            while (newGame.getScoreCroupier()  < carte[17] && (newGame.getScoreJoueur() <= carte[21] || newGame.getScoreJoueurAs() <= carte[21]))
            {
                cout << "///////////////////////////////////////////////////////////////////" <<endl;
                cout << endl;

                newGame.tourCroupier();
                cout << "Le croupier pioche une carte :" << newGame.getCarteTiree() << endl;
                cout << "Le score du croupier est de : ";
                newGame.getScoreCroupier().afficherValeur();
                cout << endl;
                cout << endl;
                cout << "///////////////////////////////////////////////////////////////////" <<endl;
            }
            if ((newGame.getScoreCroupier() == carte[21]) && newGame.getNbeCarteJoueCroupier() == 2)
            {
                newGame.setBlackJackCroupier(true);
                cout << endl;
                cout << "BlackJack pour le croupier !" <<endl;
            }

            switch (newGame.resultat())
            {
            case 0:
                cout << "Desole, vous avez perdu ! " << endl;
                break;
            case 1:
                cout << "Egalite! " << endl;
                partiTotal--;
                break;
            case 2:
                cout << "Bravo, vous avez gagne ! " << endl;
                partiGagne++;
                break;
            }
            cout << endl;
            cout << "///////////////////////////////////////////////////////////////////" <<endl;
            
            do
	    {
		cout << "Voulez vous rejouer ? Oui/Non" <<endl;
           	cin >> rejouer;
	    }while(rejouer!="Oui" && rejouer!="Non");

        }while (rejouer == "Oui");
    }

//////////////////////////////////////////////////////////////////
////////////////////////////SIMULATION////////////////////////////
//////////////////////////////////////////////////////////////////

    if(reponse == "Simulation")
    {
        do
        {
            cout << "Voulez vous lancer une simulation a la maniere du croupier, en comptant les cartes restante dans le paquet, ou en jouant selon les cartes sur la table a l'aide d'un tableau de strategie ? Croupier/Comptage/Tableau" << endl;
	        cin >> reponse;
        }while (reponse!="Croupier" && reponse!="Comptage" && reponse!="Tableau");


//////////////////////////////////////////////////////////////////
//////////////////////METHODE CROUPIER////////////////////////////
//////////////////////////////////////////////////////////////////


        if(reponse== "Croupier")
        {
            for(int i=0; i<22; i++)
            {
                partiTotal=0;
                partiGagne=0;

                while (partiTotal < nbeDeSimulation)
                {
                    newGame.nouvelleSimulation();
                    partiTotal++;
                                //NOUVELLE PARTIE//
                                //TOUR CROUPIER 1
                    newGame.tourCroupier(); //Le croupier pioche la carte est automatiquement ajoute a son score.
                                //TOUR JOUEUR
                    do
                    {
                        newGame.tourJoueur(); //LeJoueurPioche la carte est automatiquement ajoute a son score.
                    }while (!((newGame.getScoreJoueurAs() >= carte[i] && newGame.getScoreJoueurAs() <= carte[21]) || (newGame.getScoreJoueur() >= carte[i] && newGame.getScoreJoueur() <= carte[21]) || newGame.getScoreJoueur() > carte[21]));//Tant le score du croupier n'est pas compris entre i et 21 ou que le score avec As n'est pas compris entre i et 21 ou que le score n'est pas plus grand que 21, le joueur joue

                                //TOUR DU CROUPIER
                    do
                    {
                        newGame.tourCroupier();
                    }while (!((newGame.getScoreCroupierAs() > carte[16] && newGame.getScoreCroupierAs() <= carte[21]) || (newGame.getScoreCroupier() > carte[16] && newGame.getScoreCroupier() <= carte[21]) || newGame.getScoreCroupier() > carte[21]));//Tant le score du croupier n'est pas compris entre 16 et 21 ou que le score avec As n'est pas compris entre 16 et 21 ou que le score n'est pas plus grand que 21, le croupier rejoue
                    //RESULTAT//
                    switch (newGame.resultat())
                    {
                    case 0:
                        break;
                    case 1:
                        partiTotal--;
                        break;
                    case 2:
                        partiGagne++;
                        break;
                    }
                }
                double pourcentageGagne = (partiGagne/partiTotal)*100;
                cout << "La limite est de " << carte[i].getValeur() << " et " << setprecision(4) << pourcentageGagne << "% de parti gagne avec la methode du Croupier" << endl;
            }
        }

//////////////////////////////////////////////////////////////////
//////////////////////COMPTAGE DES CARTES/////////////////////////
//////////////////////////////////////////////////////////////////


        if(reponse== "Comptage")
        {
            double limitePourcentage (0);
            for(double i=0; i<1; i+=0.05)
            {
                limitePourcentage=i*100;
                partiTotal=0;
                partiGagne=0;

                while (partiTotal < nbeDeSimulation)
                {
                    newGame.nouvelleSimulation();
                    partiTotal++;
                                //NOUVELLE PARTIE//
                                //TOUR CROUPIER 1
                    newGame.tourCroupier();
                                //TOUR JOUEUR TEST NON ETUDIE
                    do
                    {
                        newGame.tourJoueurTest();
                    }while (newGame.getScoreJoueurAsTest() < carte[17]);
                                //TOUR JOUEUR ETUDIE
                    double z;
                    double y;
                    do
                    {
                        newGame.tourJoueur();
                        z=newGame.getPioche().chanceGagnant(newGame.getScoreJoueur());
                        y=newGame.getPioche().chanceGagnant(newGame.getScoreJoueurAs());
                    }while ((z > i) && (y > i));

                                //TOUR DU CROUPIER
                    do
                    {
                        newGame.tourCroupier();
                    }while(!((newGame.getScoreCroupierAs() > carte[16] && newGame.getScoreCroupierAs() <= carte[21]) || (newGame.getScoreCroupier() > carte[16] && newGame.getScoreCroupier() <= carte[21]) || newGame.getScoreCroupier() > carte[21])); //Tant le score du croupier n'est pas compris entre 16 et 21 ou que le score avec As n'est pas compris entre 16 et 21 ou que le score n'est pas plus grand que 21, le croupier rejoue
                    //RESULTAT//
                    switch (newGame.resultat())
                    {
                    case 0:
                        break;
                    case 1:
                        partiTotal--;
                        break;
                    case 2:
                        partiGagne++;
                        break;
                    }
                }
                double pourcentageGagne = (partiGagne/partiTotal)*100;
                cout << "La limite est de " << limitePourcentage << " % et " << pourcentageGagne << "% de partis gagnees grace au comptage des cartes." << endl;
            }
        }
//////////////////////////////////////////////////////////////////
//////////////////////METHODE TABLEAU/////////////////////////////
//////////////////////////////////////////////////////////////////
/* POUR CETTE PARTIE ON UTILISE UN TABLEAU DE STRATEGIE DE BLACKJACK DISPONIBLE ICI http://blackjackdoc.fr/generateur-de-tableaux-de-strategie.html */
        if(reponse== "Tableau")
        {
            partiTotal=0;
            partiGagne=0;

            while (partiTotal < nbeDeSimulation)
            {
                newGame.nouvelleSimulation();
                partiTotal++;
                            //NOUVELLE PARTIE//
                            //TOUR CROUPIER 1
                newGame.tourCroupier();
                            //TOUR JOUEUR
                while (newGame.getScoreJoueur() < carte[12] )
                {
                    newGame.tourJoueur();
                }
                if (newGame.getScoreJoueur()==newGame.getScoreJoueurAs()) //Si on a pas tir� d'AS on continue avec cette strategie.
                {
                    while (newGame.getScoreJoueur() < carte[13] && newGame.getScoreCroupierAs() < 4)
                    {
                    newGame.tourJoueur();
                    }
                    while (newGame.getScoreJoueur() < carte[17] && newGame.getScoreCroupierAs() > 6)
                    {
                        newGame.tourJoueur();
                    }
                }
                else
                {
                    while (newGame.getScoreJoueurAs() < carte[18])
                    {
                        newGame.tourJoueur();
                    }
                    while (newGame.getScoreJoueurAs() < carte[18])
                    {
                        newGame.tourJoueur();
                    }
                    if (newGame.getScoreJoueurAs() > carte[21])
                    {
                        while (newGame.getScoreJoueur() < carte[13] && newGame.getScoreCroupierAs() < 4)
                        {
                            newGame.tourJoueur();
                        }
                        while (newGame.getScoreJoueur() < carte[17] && newGame.getScoreCroupierAs() > 6)
                        {
                            newGame.tourJoueur();
                        }
                    }
                }
                            //TOUR DU CROUPIER
                do
                {
                    newGame.tourCroupier();
                }while (!((newGame.getScoreCroupierAs() > carte[16] && newGame.getScoreCroupierAs() <= carte[21]) || (newGame.getScoreCroupier() > carte[16] && newGame.getScoreCroupier() <= carte[21]) || newGame.getScoreCroupier() > carte[21])); //Tant le score du croupier n'est pas compris entre 16 et 21 ou que le score avec As n'est pas compris entre 16 et 21 ou que le score n'est pas plus grand que 21, le croupier rejoue
                //RESULTAT//
                switch (newGame.resultat())
                {
                case 0:
                    break;
                case 1:
                    partiTotal--;
                    break;
                case 2:
                    partiGagne++;
                    break;
                }
            }
            double pourcentageGagne = (partiGagne/partiTotal)*100;
            cout << setprecision(4) << pourcentageGagne << "% de parti gagne avec la methode du tableau" << endl;
        }
    }
return 0;
}

