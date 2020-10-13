#ifndef POMME_H
#define POMME_H

#include <iostream>
#include <vector>

class Pomme
{
    private:
        int m_posx;
        int m_posy;
        bool m_eat;

    public:
        Pomme();
        Pomme(int x, int y);
        ~Pomme();

        int getX() {return m_posx;} const
        int getY() {return m_posy;} const
        void setX(int x) {m_posx = x;}
        void setY(int y) {m_posy = y;}
};

#endif // POMME_H
