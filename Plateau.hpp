#ifndef PLATEAU_HPP
#define PLATEAU_HPP

#include "Case.hpp"
#include <cstring>
#include <iomanip>
#include <iostream>

using namespace std;

class Plateau
{
private:
    // std::array<Case,20*20> m_plateau;
    /**
     * * Tableau de tableau de cases
     * TODO: faire une méthode deplacerPion() avec move d'une case à une autre
     */
    int m_taille;
    int m_lig;
    int m_col;
    Case ***tabCase;

public:
    /* Constructeur de plateau */
    Plateau(int nbx, int nby);
    /**
     * * Affichage du Plateau paramétrer sur 10*10
     * TODO: A rectifier pour 2eme affichage (Pinaillage)
     */
    void affiche();
    Case *** getTabCase() const;
    int getNbCol() const;
    int getTaille() const;
};

#endif // PLATEAU_HPP