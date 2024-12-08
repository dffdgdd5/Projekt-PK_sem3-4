#pragma once
#include "glowne.h"

class PID 
{
private:
    float wzmocnienie;
    float stalaCalkowania;
    float stalaRozniczkowania;
    float sumaCalkowania;
    float minWyjscie;
    float maxWyjscie;
    std::vector<float> poprzednieWartosci;

public:
    PID(float, float = 0, float = 0);
    void UstawOgraniczenia(float, float);

    float ObliczProporcjonalne(float);
    float ObliczCalka(float);
    float ObliczRozniczka(float);

    float ObliczSterowanie(float);

    float Sumator(float, float);

    void Reset();
};
