#include "PID.h"

PID::PID(float up, float ui, float ud)
    : Wzmocnienie(up), StalaCalkowania(ui), StalaRozniczkowania(ud),
    SumaCalkowania(0.0f), MinWyjscie(-100.0f), MaxWyjscie(100.0f)
{
    PoprzednieWartosci.resize(1, 0.0f);
}

void PID::UstawOgraniczenia(float minWyjscie, float maxWyjscie) {
    MinWyjscie = minWyjscie;
    MaxWyjscie = maxWyjscie;
}

float PID::ObliczProporcjonalne(float uchyb) {
    return Wzmocnienie * uchyb;
}

float PID::ObliczCalka(float uchyb) {
    if (StalaCalkowania)
    {
        SumaCalkowania += uchyb;
        return SumaCalkowania / StalaCalkowania;
    }
    else return 0;
}

float PID::ObliczRozniczka(float uchyb) {
    float wartoscRozniczkujaca = 0.0f;
    if (!PoprzednieWartosci.empty())
        wartoscRozniczkujaca = StalaRozniczkowania * (uchyb - PoprzednieWartosci.back());
    else wartoscRozniczkujaca = StalaRozniczkowania * uchyb;

    PoprzednieWartosci.push_back(uchyb);

    return wartoscRozniczkujaca;
}

float PID::ObliczSterowanie(float uchyb) {
    float proporcjonalne = ObliczProporcjonalne(uchyb);
    float calka = ObliczCalka(uchyb);
    float rozniczka = ObliczRozniczka(uchyb);

    float sterowanie = proporcjonalne + calka + rozniczka;
    return sterowanie;
}

float PID::Sumator(float wejscie, float wyjscie)
{
    return wejscie - wyjscie;
}

void PID::Reset() {
    SumaCalkowania = 0.0f;
    PoprzednieWartosci.clear();
    PoprzednieWartosci.push_back(0.0f);
}