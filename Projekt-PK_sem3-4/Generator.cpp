#include "Generator.h"

constexpr float PI = 3.141592653589793238;

Generator::Generator()
{
    amplituda = 1;
    okres = 1;
    czasAktywacji = 0;
    wyborTypu = Typ::skokowy;
    wartoscStala = 1;
    p = 1;
};

Generator::Generator(Typ typ, float amplituda, int okres, int czasAktywacji, float wartoscStala)
    :wyborTypu(typ), wartoscStala(wartoscStala), czasAktywacji(czasAktywacji)
{
    this->amplituda = (amplituda < 0) ? 1 : amplituda;
    this->okres = (okres < 0) ? 1 : okres;
}

float Generator::Generuj(int czas)
{
    if (wyborTypu == Typ::skokowy) 
        return (czas <= czasAktywacji) ? wartoscStala : 0;
    else if (wyborTypu == Typ::sinus)
    {
        float x = ((czas % okres)/okres)*2*PI;
        return amplituda * sin(x);
    }
    else if (wyborTypu == Typ::prostokatny)
    {
        int i_mod = czas % okres;
        int prog = (p * okres);
        if (i_mod < prog)
            return amplituda;
        else
            return 0.0;
    }
}