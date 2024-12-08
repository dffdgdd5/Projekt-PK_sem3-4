#include "ARX.h"
#include "Generator.h"
#include "PID.h"
#include "Sprzezenie_zwrotne.h"
#include "Symulacja.h"
#include "Zarzadzanie_plikami.h"


Symulacja::Symulacja(PID pid, ARX arx, Generator gen, int liczbaKrokow_)
    : regulator(pid), obiekt(arx), generator(gen), liczbaKrokow(liczbaKrokow_)
{}

void Symulacja::uruchom() {
    float y = 0.0f;
    float w = 0.0f;
    float u = 0.0f;
    float e = 0.0f;

    regulator.Reset();

    for (int i = 0; i < liczbaKrokow; i++) {
        w = generator.Generuj(i);
        e = regulator.Sumator(w, y);
        u = regulator.ObliczSterowanie(e);
        y = obiekt.Oblicz(u);

        cout << "Wejscie: " << w <<"\tPID: " << e << "\t\tWyjscie:\t" << y << endl;
    }
}
