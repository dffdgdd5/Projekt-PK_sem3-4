#include "ARX.h"
#include "Generator.h"
#include "PID.h"
#include "Sprzezenie_zwrotne.h"
#include "Symulacja.h"
#include "Zarzadzanie_plikami.h"

#include "glowne.h"

#ifdef RELEASE

int main()
{
	//generator
	float amplituda = 3;
	int okres = 5;
	Typ wyborTypu = Typ::skokowy;
	float wartoscStala = 1;
	float p = 0.8001;
	int czasAktywacji = 0;

	//arx
	vector<float> A = { -0.4 };
	vector<float> B = { 0.6 };
	int u = 15;
	int opoznienie = 5;

	//pid
	float up = 0.5;
	float ui = 10.0;
	float ud = 0.2;

	ARX arx(A,B, opoznienie);
	PID regulator(up, ui, ud);
	Generator generator(wyborTypu,amplituda,okres,czasAktywacji,wartoscStala, p);

	Symulacja symulator(regulator, arx, generator, 10000);

	symulator.uruchom();
}

#endif
