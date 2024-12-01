#pragma once
#include "glowne.h"

class Zarzadzanie_plikami;
class Zarzadzanie_plikami
{
	string SciezkaKonfiguracja;
	string SciezkaSymulacja;
public:
	void ZapiszKonfiguracje();
	void ZapiszSymulacje();
	void OdczytajKonfiguracje();
	void OdczytajSymulacje();
};