#pragma once
#include "glowne.h"

class ARX
{
	vector<float> WektorA;
	vector<float> WektorB;
	int Opoznienie;
	float Wyjscie; // ??
public:
	ARX(vector<float>, vector<float>, int);
	void setWektory(vector<float>, vector<float>);
	void setOpoznienie(int);
	float Oblicz(float);
};
