#include "Jeu.h"

int main()
{
    srand(time(NULL));

    bool ech(false);
    char touche;
    int score(0);

    Snake serp;
    Terrain field(35, 60);

    field.afficher();

    do
    {
        Sleep(50);

        if(_kbhit())
        {
            touche =_getch();
            switch(touche)
            {
            case '5':
            {
                if(serp.getWay() != HAUT)
                    serp.setWay(direction::BAS);
                break;
            }
            case '8':
            {
                if(serp.getWay() != BAS)
                    serp.setWay(direction::HAUT);
                break;
            }
            case '4':
            {
                if(serp.getWay() != DROITE)
                    serp.setWay(direction::GAUCHE);
                break;
            }
            case '6':
            {
                if(serp.getWay() != GAUCHE)
                    serp.setWay(direction::DROITE);
                break;
            }
            case 27:
            {
                ech = true;
                break;
            }
            }
        }

        serp.dep();
        field.afficherS(serp);
        field.afficherP();

        if(field.manger(serp))
        {
            score++;
            gotoligcol(2,65);
            Color(11,0);
            std::cout << "Score : " << score;
            Color(15,0);
            serp.add();
            field.genererPomme();
        }
    }while(!field.out(serp) && !serp.touch() && !ech);

    return 0;
}
