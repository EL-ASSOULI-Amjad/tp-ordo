// TP1_graphe.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
#include <iostream>
#include "Header.h"

void afficher_chemin(const t_chemin& c) {
	if (c.n == 0) {
		std::cout << "Pas de chemin" << endl;
		return;
	}
	std::cout << "cout du chemin : " << c.count << endl;
	for (int i = 1; i <= c.n; i++)
		std::cout << c.liste[i] << " ";
	std::cout << endl;
}

int main()
{
	t_graphe mon_graphe = {};
	mon_graphe.n = 5;

	mon_graphe.ns[1] = 2;
	mon_graphe.s[1][1] = 2;  mon_graphe.l[1][1] = 10;
	mon_graphe.s[1][2] = 3;  mon_graphe.l[1][2] = 12;

	mon_graphe.ns[2] = 1;
	mon_graphe.s[2][1] = 4;  mon_graphe.l[2][1] = 5;

	mon_graphe.ns[3] = 2;
	mon_graphe.s[3][1] = 4;  mon_graphe.l[3][1] = 2;
	mon_graphe.s[3][2] = 5;  mon_graphe.l[3][2] = 20;

	mon_graphe.ns[4] = 1;
	mon_graphe.s[4][1] = 5;  mon_graphe.l[4][1] = 3;

	mon_graphe.ns[5] = 0;

	t_chemin mon_chemin;

	std::cout << "--- Dijkstra ---" << endl;
	calculer_dijstra(mon_graphe, 1, 5, mon_chemin);
	afficher_chemin(mon_chemin);

	std::cout << "--- Bellman ---" << endl;
	calculer_bellman(mon_graphe, 1, 5, mon_chemin);
	afficher_chemin(mon_chemin);

	return 0;
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
