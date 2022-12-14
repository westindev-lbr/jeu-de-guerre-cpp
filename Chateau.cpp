#include "Chateau.hpp"
#include <iostream>
#include "functions.hpp"
#include "Paysan.hpp"
#include <vector>

/* Méthodes */
Chateau::Chateau(Joueur *j, int x, int y) : Pion(j, x, y)
{
    m_pow = 0;
    m_pdv = 20;
    m_pdm = 0;
    m_prod = 2;
    m_cout = 15;
    m_ref = "C" + j->getCouleur();
    m_joueur = j;
    m_coutrect = {10, 10, 20};
}

int Chateau::getCout() const
{
    return m_cout;
}

/* Un chateau peut recruter si le joueur à assez d'or (minimum requis 10 d'or) */
bool Chateau::peutRecruter(int price)
{
    if(m_joueur->getOr() >= price) 
    {
        return true;
    }
    return false;
}


string Chateau::affichetype()
{
    return "Chateau";
}

void Chateau::afficheActions()
{
    cout << endl;
    cout << "SELECT: [ " << this->affichetype()
         << " (" << enumToChar(this->getX())
         << ", " << this->getY() << ") ]" << endl;
    cout << endl
         << "# Menu action :" << endl;
    cout << "   1 - Recruter un pion" << endl;
    cout << "   2 - Ne fait rien" << endl;
    cout << "   3 - Retour" << endl;
}

void Chateau::afficheRecruter()
{
    cout << endl
         << "# Menu Recrutement :" << endl;
    cout << "   1 - Recruter un Seigneur *" << m_coutrect[0] << " D'OR |" << endl;
    cout << "   2 - Recruter un Guerrier *" << m_coutrect[1] << " D'OR |" << endl;
    cout << "   3 - Recruter un Paysan *" << m_coutrect[2] << " D'OR |" << endl;
    cout << "   4 - Retour" << endl;
}

void Chateau::afficheEmplPossible(vector<Case *> &vecCases)
{
    cout << endl;
    cout << "Emplacements possibles: " << vecCases.size() << " positions: " << endl;
    for (int i = 0; i < (int)vecCases.size(); i++)
    {
        cout << "   "
             << (i + 1)
             << " - Case: "
             << "(" << enumToChar(vecCases[i]->getX()) << "," << vecCases[i]->getY() << ")" << endl;
    }
    cout << "   "
         << ((int)vecCases.size() + 1)
         << " - Retour au menu précédent" << endl;
}
