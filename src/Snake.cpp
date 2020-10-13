#include "Snake.h"
#include "Jeu.h"

Snake::Snake()
{
    for(int i(0); i<5; i++)
    {
        m_pos.push_back(Carre(10-i, 10));
    }

    m_way = DROITE;
    m_size = 5;
}

void Snake::add()
{
    std::vector<Carre> newPos = m_pos;
    Carre newCarre( m_pos[m_size-1].getX(), m_pos[m_size-1].getY()); //le nouveau carre va copier l'ancien dernier
    newPos.push_back(newCarre);
    m_size ++;
    this->setPos(newPos);
}

void Snake::dep() //0 si pas de nouveau bloc, 1 si nouveau bloc
{
    std::vector<Carre> pos = m_pos;

    switch (m_way)
    {
    case DROITE :
    {
        m_pos[0].pX();

        for(int i(1); i<m_size; i++)
        {
            m_pos[i].setX(pos[i-1].getX());
            m_pos[i].setY(pos[i-1].getY());
        }
    }
    break;
    case GAUCHE :
    {
        m_pos[0].mX();
        for(int i(1); i<m_size; i++)
        {
            m_pos[i].setX(pos[i-1].getX());
            m_pos[i].setY(pos[i-1].getY());
        }
    }
    break;
    case HAUT :
    {
        m_pos[0].mY();
        for(int i(1); i<m_size; i++)
        {
            m_pos[i].setX(pos[i-1].getX());
            m_pos[i].setY(pos[i-1].getY());
        }
    }
    break;
    case BAS :
    {
        m_pos[0].pY();
        for(int i(1); i<m_size; i++)
        {
            m_pos[i].setX(pos[i-1].getX());
            m_pos[i].setY(pos[i-1].getY());
        }
    }
    break;
    }
}

bool operator==(Carre const& c1, Carre const& c2)
{
    return c1.egal(c2);
}

bool Carre::egal(Carre const& c1) const
{
    if(c1.m_x == m_x && c1.m_y == m_y)
        return true;
    else
        return false;
}

bool Snake::touch() const
{
    bool egal = false;

    for(int i(1); i<m_size-1; i++)
    {
        if(m_pos[0] == m_pos[i])
            egal = true;
    }

    return egal;
}
