#include "Header.h"
#include <fstream>
#include <iostream>

void lire_fichier(string nom_structure, string nom_longueurs, t_graphe& un_graphe) {
	un_graphe.n = 0;

	ifstream fichier(nom_structure);
	if (!fichier) {
		cout << "Impossible d'ouvrir " << nom_structure << endl;
		return;
	}

	int nb_sommet;
	fichier >> nb_sommet;
	un_graphe.n = nb_sommet;

	for (int i = 1; i <= nb_sommet; i++)
	{
		int nb_succ = -1;
		fichier >> nb_succ;
		un_graphe.ns[i] = nb_succ;

		for (int j = 1; j <= nb_succ; j++)
		{
			int numero = -1;
			fichier >> numero;
			un_graphe.s[i][j] = numero;
			un_graphe.l[i][j] = mon_infini;
		}
	}

	ifstream fichier_l(nom_longueurs);
	if (!fichier_l) {
		cout << "Impossible d'ouvrir " << nom_longueurs << endl;
		un_graphe.n = 0;
		return;
	}

	int origine, destination;
	double longueur, duree;
	while (fichier_l >> origine >> destination >> longueur >> duree)
	{
		bool trouve = false;
		for (int j = 1; j <= un_graphe.ns[origine]; j++)
		{
			if (un_graphe.s[origine][j] == destination)
			{
				un_graphe.l[origine][j] = longueur;
				trouve = true;
			}
		}
		if (!trouve)
			cout << "Arc " << origine << " -> " << destination << " absent de la structure" << endl;
	}
}


static void construire_chemin(int pere[], int m[], int sommet_final, t_chemin& un_chemin) {
	un_chemin.n = 0;
	un_chemin.count = m[sommet_final];

	if (m[sommet_final] >= mon_infini)
		return;

	int tmp[nb_max_sommet];
	int k = 0;
	int x = sommet_final;
	while (x != -1 && k < nb_max_sommet - 1) {
		k++;
		tmp[k] = x;
		x = pere[x];
	}

	for (int i = 1; i <= k; i++)
		un_chemin.liste[i] = tmp[k - i + 1];
	un_chemin.n = k;
}


void calculer_dijstra(const t_graphe& un_graphe, int depart, int sommet_final, t_chemin& un_chemin) {


	int m[nb_max_sommet];
	int t[nb_max_sommet];
	int pere[nb_max_sommet];

	for (int i = 0; i < nb_max_sommet; i++) {
		m[i] = mon_infini;
		t[i] = 0;
		pere[i] = -1;
	}
	m[depart] = 0;

	for (int k = 1; k <= un_graphe.n; k++)
	{
		int mon_mini = mon_infini;
		int pos_mini = -1;
		for (int j = 1; j <= un_graphe.n; j++) {
			if (t[j] == 0 && m[j] < mon_mini) {
				mon_mini = m[j];
				pos_mini = j;
			}
		}

		if (pos_mini == -1)
			break;

		t[pos_mini] = 1;

		int nb = un_graphe.ns[pos_mini];
		for (int j = 1; j <= nb; j++) {
			int succ = un_graphe.s[pos_mini][j];
			if (succ < 1 || succ > un_graphe.n)
				continue;
			int nouveau = m[pos_mini] + un_graphe.l[pos_mini][j];
			if (t[succ] == 0 && nouveau < m[succ]) {
				m[succ] = nouveau;
				pere[succ] = pos_mini;
			}
		}
	}

	construire_chemin(pere, m, sommet_final, un_chemin);
}


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