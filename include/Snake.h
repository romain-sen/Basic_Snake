#ifndef SNAKE_H
#define SNAKE_H
#include <iostream>
#include <vector>

enum direction {DROITE, GAUCHE, HAUT, BAS};

class Carre
{
private :
    int m_x;
    int m_y;
public :
    Carre(int x = 0, int y = 0) : m_x(x), m_y(y) {}
    ~Carre() {}

    int getX() {return m_x;} const
    int getY() {return m_y;} const
    void setX(int nx) {m_x = nx;}
    void setY(int ny) {m_y = ny;}
    void pX() {m_x ++;}
    void mX() {m_x --;}
    void pY() {m_y ++;}
    void mY() {m_y --;}

    void afficher() {std::cout << m_x << " , " << m_y << std::endl;}
    bool egal(Carre const& c1) const;
};

bool operator==(Carre const& c1, Carre const& c2);



class Snake
{
    private:
        int m_size;
        std::vector<Carre> m_pos;
        direction m_way;

    public:
        Snake();
        ~Snake() {}

        int Getsize() { return m_size; }
        void Setsize(int val) { m_size = val; }
        std::vector<Carre> Getpos() { return m_pos; }
        void setPos(std::vector<Carre> newPos) {m_pos = newPos;}
        void add();
        void dep(); //0 si pas de nouveau bloc, 1 si nouveau
        direction getWay() {return m_way;}
        void setWay(direction newWay) {m_way = newWay;}
        bool touch() const;
};

#endif // SNAKE_H
