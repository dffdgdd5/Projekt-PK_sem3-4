#pragma once
#define PI = 3,141592653589793238
#include "glowne.h"

enum class Typ
{
	skokowy = 0, sinus = 1, prostokatny = 2
};

class Generator
{
private:
    Typ wyborTypu;
    float wartoscStala;
    int czasAktywacji;
    int okres;
    float amplituda;
    float p;

public:
    Generator();
    Generator(Typ, float, int , int, float);
    float Generuj(int);
};