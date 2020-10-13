#include "Jeu.h"

void Color(int couleurDuTexte, int couleurDeFond) // fonction d'affichage des couleurs, SOURCE : https://pedago-ece.campusonline.me/course/view.php?id=593
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}

void gotoligcol( int lig, int col ) // fonction pour placer le curseur SOURCE : https://pedago-ece.campusonline.me/course/view.php?id=593
{
// ressources
    COORD mycoord;

    mycoord.X = col;
    mycoord.Y = lig;
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), mycoord );
}

void Terrain::afficher() const
{
    int largeur(m_lTaille), hauteur(m_hTaille);
    char cv(179), ch(196);
    char chg(218), chd(191), cbg(192), cbd(217);
    //gotoligcol(0, 70);
    //std::cout << "l : " << m_lTaille << " - h : " << m_hTaille;

    for(int i(0); i<=hauteur; i++)
    {
        for(int j(0); j<=largeur; j++)
        {
            gotoligcol(i, j);
            if((i == 0 || i == hauteur) && (j>0 && j<largeur))
                std::cout << ch;
            else if((i>0 && i<hauteur) && (j == 0 || j == largeur))
                std::cout << cv;
            else if(i == 0 && j == 0)
                std::cout << chg;
            else if(i == 0 && j == largeur)
                std::cout << chd;
            else if(i == hauteur && j == 0)
                std::cout << cbg;
            else if(i == hauteur && j ==largeur)
                std::cout << cbd;
        }
        //std::cout << std::endl;
    }
}

void Terrain::afficherS(Snake serpent) const
{
    char c(233);

    std::vector<Carre> sPos = serpent.Getpos();

    Color(14,0);
    gotoligcol(sPos[0].getY(), sPos[0].getX());
    std::cout << c;
    Color(10,0);
    for(int i(1); i<serpent.Getsize()-1; i++)
    {
        gotoligcol(sPos[i].getY(), sPos[i].getX());
        std::cout << c;
    }
    Color(15,0);
        gotoligcol(sPos[serpent.Getsize()-1].getY(), sPos[serpent.Getsize()-1].getX());
        std::cout << " ";
}

void Terrain::afficherP()
{
    char c(232);
    gotoligcol(m_apple.getY(), m_apple.getX());
    Color(12, 0);
    std::cout << c;
    Color(15, 0);
}

void Terrain::genererPomme()
{
    int rdx = (rand()%(m_lTaille-1))+1;
    int rdy = (rand()%(m_hTaille-1))+1;

    m_apple = Pomme(rdx, rdy);
}

bool Terrain::manger(Snake serpent)
{
    std::vector<Carre> sPos = serpent.Getpos();

    if(sPos[0].getX() == m_apple.getX() && sPos[0].getY() == m_apple.getY())
        return true;
    else
        return false;
}

bool Terrain::out(Snake serpent)
{
    std::vector<Carre> sPos = serpent.Getpos();

    if(sPos[0].getX() >= m_lTaille || sPos[0].getY() >= m_hTaille || sPos[0].getX() <= 0 || sPos[0].getY() <= 0)
        return true;
    else
        return false;
}



