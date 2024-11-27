#ifndef __ENTETE_H_
#define __ENTETE_H_

#include <cstdio>
#include <cstdlib> 
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <ctime>  
#include <cmath>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

//Ne pas modifier TProblem
enum TProblemType { MIN, MAX };					//** Definition du sens de l'optimisation du probleme

struct TProblem									//**Définition du problème:
{
	std::string Nom;							//**Nom du fichier de données
	int N;										//**Taille du probleme: Nombre d'elements
	int M;										//**Nombre d'elements a selectionner
	std::vector<std::vector <int> > Distance;	//**Distance entre chaque paire d'element. NB: Tableau de 0 à N-1.  Indice 0 utilisé.
	TProblemType Type = MAX;					//**Type du probleme (e.g.Maximisation ou minimisation)
};

//Ne pas modifier TSolution
struct TSolution						//**Definition d'une solution: 
{
	std::vector <bool> Selec;			//**Ensemble de genes: indique si l'element i est sélectionne (true) ou non (false). NB: Tableau de 0 à N-1.
	long FctObj = -INT_MAX;				//**Valeur de la fonction obj: Sommation des distances entre les objects sélectionnes
	bool Valide=false;					//**Etat de validité de la solution (nombre elements selectionnes)
	int NbEvaltoGet;					//**Nombre d'evalutions de solutions necessaires pour trouver cette solution... pour évaluer convergence
};

//Ne pas modifier TAlgo
struct TAlgo
{
	int		TaillePop;					//**Taille de la population (nombre d'individus). NB: valeur minimale = 2
	int		TaillePopEnfant;			//**Taille de la populationEnfant (nombre d'enfants = TaillePop * ProbCr)
	double	ProbCr;						//**Probabilite de croisement [0%,100%]
	double	ProbMut;					//**Probabilite de mutation [0%,100%] 
	int		Gen;						//**Compteur du nombre de generations (iterations)

	int		CptEval=0;					//**COMPTEUR DU NOMBRE DE SOLUTIONS EVALUEES. SERT POUR CRITERE D'ARRET.
	int		NB_EVAL_MAX;				//**CRITERE D'ARRET: MAXIMUM "NB_EVAL_MAX" EVALUATIONS.
	long	FctObjSolDepart;			//**Valeur de la fonction objectif de la meilleure solution lors de la 1ere generation (iteration)
};
#endif