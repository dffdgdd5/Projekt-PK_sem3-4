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
	float amplituda = 2;
	int okres = 2;
	Typ wyborTypu = Typ::prostokatny;
	float wartoscStala = 1;
	int p = 1;

	//arx
	vector<float> A = { -0.4 };
	vector<float> B = { 0.6 };
	int u = 15;
	int opoznienie = 0;

	//pid
	float up = 0.5;
	float ui = 10.0;
	float ud = 0.2;

	ARX arx(A,B, opoznienie, u);
	PID regulator(up, ui, ud);
	Generator generator(wyborTypu,amplituda,okres,opoznienie,wartoscStala);

	Symulacja symulator(regulator, arx, generator, 50);

	symulator.uruchom();
}

#endif
