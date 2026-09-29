#pragma once
#include <string>
using namespace std;

const int nb_max_sommet = 300;
const int nb_max_succ = 10;
const int mon_infini = 9999999;

typedef struct t_graphe {
	int n;
	int ns[nb_max_sommet];
	int s[nb_max_sommet][nb_max_succ];
	int l[nb_max_sommet][nb_max_succ];
	int ordre[nb_max_sommet];
} t_graphe;

typedef struct t_chemin {
	int count;
	int n;
	int liste[nb_max_sommet];
} t_chemin;

void lire_fichier(string nom_structure, string nom_longueurs, t_graphe& un_graphe);
void afficher_chemin(const t_chemin& c);
void calculer_dijstra(const t_graphe& un_graphe, int depart, int sommet_final, t_chemin& un_chemin);
void calculer_bellman(const t_graphe& un_graphe, int depart, int sommet_final, t_chemin& un_chemin);