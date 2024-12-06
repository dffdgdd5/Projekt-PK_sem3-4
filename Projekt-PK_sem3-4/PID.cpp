#include "PID.h"

PID::PID(float up, float ui, float ud)
    : wzmocnienie(up), stalaCalkowania(ui), stalaRozniczkowania(ud),
    sumaCalkowania(0.0f), minWyjscie(-100.0f), maxWyjscie(100.0f)
{
     poprzednieWartosci.push_back(0.0f);
}

void PID::UstawOgraniczenia(float minWyjscie, float maxWyjscie) {
    this->minWyjscie = minWyjscie;
    this->maxWyjscie = maxWyjscie;
}

float PID::ObliczProporcjonalne(float uchyb) {
    return wzmocnienie * uchyb;
}

float PID::ObliczCalka(float uchyb) {
    if (stalaCalkowania)
    {
        sumaCalkowania += uchyb;
        return sumaCalkowania / stalaCalkowania;
    }
    else return 0;
}

float PID::ObliczRozniczka(float uchyb) {
    float wartoscRozniczkujaca = 0.0f;
    if (! poprzednieWartosci.empty())
        wartoscRozniczkujaca = stalaRozniczkowania * (uchyb -  poprzednieWartosci.back());
    else wartoscRozniczkujaca = stalaRozniczkowania * uchyb;

     poprzednieWartosci.push_back(uchyb);

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
    sumaCalkowania = 0.0f;
     poprzednieWartosci.clear();
     poprzednieWartosci.push_back(0.0f);
}