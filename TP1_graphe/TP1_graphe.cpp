// TP1_graphe.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "Header.h"

int main()
{
    t_graphe mon_graphe;

    //sommet_1
    mon_graphe.ns[1] = 2;
    mon_graphe.s[1][1] = 2;
    mon_graphe.s[1][2] = 3;
    mon_graphe.l[1][1] = 10;
    mon_graphe.l[1][2] = 12;

    t_chemin mon_chemin;

    calculer_dijstra(mon_graphe, 1, 5, mon_chemin);

    std::cout << "cout du chemin : " << mon_chemin.count << endl;
    for (int i = 1; i <= mon_chemin.n;i++)
    {
        std::cout << mon_chemin.liste[i] << " ";
    }


    std::cout << "Hello World!\n";
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
