#pragma once
/*
class Symulacja;

class Symulacja
{
	int KrokCzasowy;
public:
	void StartSymulacji();
	void ResetSymulacji();
};
*/
#include "glowne.h"

#include "PID.h"
#include "ARX.h"
#include "Generator.h"

class Symulacja {
private:
    PID regulator;      // Kompozycja: obiekt PID
    ARX obiekt;         // Kompozycja: obiekt ARX
    Generator generator; // Kompozycja: obiekt Generator
    int liczbaKrokow;

    // Wektory do przechowywania wyników symulacji
    std::vector<float> czasy;
    std::vector<float> wyjscia;
    std::vector<float> zadane;
    std::vector<float> sterowania;

public:
    // Konstruktor przyjmuje obiekty PID, ARX i Generator przez const&, 
    // nastêpnie kopiuje je do w³asnych pól.
    Symulacja(PID pid, ARX arx, Generator gen, int liczbaKrokow_);

    void uruchom();  // Metoda uruchamiaj¹ca pêtlê symulacji

    // Metody do pobrania wyników po symulacji
    const std::vector<float>& pobierzCzasy() const { return czasy; }
    const std::vector<float>& pobierzWyjscia() const { return wyjscia; }
    const std::vector<float>& pobierzZadane() const { return zadane; }
    const std::vector<float>& pobierzSterowania() const { return sterowania; }

    // Metody do zapisu i odczytu konfiguracji do/z pliku tekstowego
    void ZapiszKonfiguracje(const std::string& nazwaPliku) const;
    void WczytajKonfiguracje(const std::string& nazwaPliku);
};