#ifndef MINESWEEPER_CASILLA_H
#define MINESWEEPER_CASILLA_H

class Casilla {
private:
    // Atributos
    bool revelada;
    bool marcada;
    bool mina;
    int minasAlrededor;
    int x;
    int y;

public:
    // Constructores
    Casilla();
    ~Casilla();

    // Getters
    bool getRevelada();
    bool getMarcada();
    bool getMina();
    int getMinasAlrededor();
    int getX();
    int getY();

    // Setters
    void setRevelada(bool _revelada);
    void setMarcada(bool _marcada);
    void setMina(bool _mina);
    void setMinasAlrededor(int _minasAlrededor);
    void setX(int _x);
    void setY(int _y);
};

#endif //MINESWEEPER_CASILLA_H
