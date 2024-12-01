#include "glowne.h"

class PID {
private:
    float Wzmocnienie;
    float StalaCalkowania;
    float StalaRozniczkowania;
    float SumaCalkowania;
    float MinWyjscie;
    float MaxWyjscie;
    std::vector<float> PoprzednieWartosci;

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
