#include "Header.h"

void lire_fichier(string  nom, t_graphe& un_graphe) {

}
int mon_mini;
int pos_mini;
int nn;


void calculer_dijstra(t_graphe un_graphe, int depart, int sommet_final, t_chemin& un_chemin) {
	int m[nb_max_sommet] = { mon_infini };
	int t[nb_max_sommet];
	int pere[nb_max_sommet];
	

	std::memset(&t, 0, sizeof(int) * un_graphe.n);


	for (int i = 1; i <= un_graphe.n;i++)
		m[i] = mon_infini;
	m[0] = 0;

	m[depart] = 0;


	for (int i = 1;i <= un_graphe.n;i++)
	{
		//recherche du prochain sommet
		mon_mini = mon_infini;
		pos_mini = -1;
		nn = un_graphe.n;
		for (int j = 1; j <= nn; j++) {
			if (t[j] == 0)
				if (m[j] < mon_mini)
				{
					mon_mini = m[j];
					pos_mini = j;
				}
		}

		// on memorise que le sommet est maintenant traite
		t[pos_mini] = 1;

		//propager vers tous les successeurs
		int nb = un_graphe.ns[pos_mini];
		for (int j = 1; j <= nb; j++) {

		}



	}
}

void calculer_bellman(t_graphe un_graphe, int depart, int sommet_final, t_chemin& un_chemin) {

}