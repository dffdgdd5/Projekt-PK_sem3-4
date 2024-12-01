#pragma once
#include "glowne.h"

enum class Typ
{
	skokowy = 0, sinus = 1, kwadratowy = 2
};

class Generator
{
private:
    Typ WyborTypu;
    int CzasAktywacji;
    float Okres;
    float Amplituda;
    float Czêstotliwoœæ;

public:
    Generator(Typ typ, float amplituda = 1.0f, float okres = 1.0f, int czasAktywacji = 0, float czestotliwosc = 1.0f);
    float Generuj(int czas);
};