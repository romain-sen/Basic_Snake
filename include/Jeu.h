#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED


#include <iostream>
#include <vector>
#include <windows.h>
#include <conio.h>
#include <ctime>

#include "Pomme.h"
#include "Snake.h"


void Color(int couleurDuTexte, int couleurDeFond); //SOURCE : https://pedago-ece.campusonline.me/course/view.php?id=593
void gotoligcol( int lig, int col );

class Terrain
{
private :
    int m_lTaille;
    int m_hTaille;
    Pomme m_apple;

public :
    Terrain(int h, int l) : m_lTaille(l), m_hTaille(h), m_apple(Pomme(5,5)){}
    void afficher() const;

    void afficherS(Snake serpent) const;
    void afficherP();
    void genererPomme();
    bool manger(Snake serpent);
    bool out(Snake serpent);

};
#endif // JEU_H_INCLUDED
