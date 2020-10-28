/*
  ---------------------------------------------------------------------------
  Fichier     : calendrier.cpp
  Nom du labo : Labo 03 - Calendrier
  Auteur(s)   : Richard Tenorio, Damiano Mondaini
  Date        : 27.10.2020
  But         : Le programme a pour but d'afficher le calendrier d'une année
                selon l'entrée de l'utilisateur. La mise en page du calendrier
                est soignée.

  Remarque(s) : - L'utilisateur ne peut entrer que des années entre 1900 et
                  2100
                - Les saisies de l'utilisateur sont vérifiés
                - Les premiers janvier sont considérés comme des lundis

  Compilateur : Mingw-w64 g++ 8.1.0
  ---------------------------------------------------------------------------
*/

#include <iostream>  // Gestion du flux
#include <iomanip>   // Gestion de l'afifchage
#include <cstdlib>   // EXIT_SUCCESS
#include <limits>    // numeric_limits<...> pour vider le buffer

using namespace std;
/*
   1.	Accueil du programme
      a.	Ce programme permet d’afficher le calendrier correspondant à une année
   2.	Saisie de l’année par l’utilisateur
      a.	Faire
      i.	Entrer une année [1900-2100] :
   ii.	Si année n’est pas valide
   1.	Afficher recommencer
   b.	Tant que
   i.	Année < 1900
   ii.	OU année est > 2100
   iii.	OU année n’est pas une date
   3.	Affichage du calendrier
      a.	Calculer si année bissextile
   b.	Pour chaque mois
      i.	Calculer nombre de jours
   ii.	Calculer quel est le premier jour
   iii.	Afficher le nom et l’année
      iv.	Afficher les jours de la semaine
   v.	Afficher la date du jour
   4.	Demander si l’utilisateur veut recommencer
      a.	Demander s’il veut recommencer
      b.	Tant que
   i.	L’utilisateur veut recommencer
   5.	Fin du programme
      a.	Appuyer sur enter pour quitter
*/

// Définitions de commande pour vider le buffer et afficher le message de fin
#define VIDER_BUFFER    cin.ignore(numeric_limits<streamsize>::max(), '\n')
#define MESSAGE_FIN     cout << "Presser ENTER pour quitter"; \
                        VIDER_BUFFER
#define REPARER_BUFFER  cin.clear()


int main () {
   // Accueil du programme
   cout << "Ce programme permet d’afficher le calendrier correspondant à une année" << endl;

   // Sasie de l'année par l'utilisateur
   const unsigned int anneeMax = 2100;
   const unsigned int anneeMin = 1900;

   unsigned int anneeSaisie = 0;

   do {
      cout << "Entrer une valeur [1900-2100] :";
      cin >> anneeSaisie;
      if (cin.fail() || anneeSaisie < anneeMin || anneeSaisie > anneeMax) {
         REPARER_BUFFER;
         VIDER_BUFFER;
         cout << "La valeur saisie n'est pas valide. Merci de recommencer." << endl;
      }
   } while (anneeSaisie < anneeMin || anneeSaisie > anneeMax);

   cout << "Annee saisie: " << anneeSaisie;

   return EXIT_SUCCESS;
}