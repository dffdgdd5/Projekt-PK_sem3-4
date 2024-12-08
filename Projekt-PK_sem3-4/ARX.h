#pragma once
#include "glowne.h"

class ARX
{
	vector<float> wektorA;
	vector<float> wektorB;
	int opoznienie;
	float m_u;

	deque<float> historiaY;
	deque<float> historiaU;
	deque<float> opoznienieTransportowe;
public:
	ARX(vector<float>, vector<float>, int, float);
	ARX(vector<float>, vector<float>, int);
	void setWektory(vector<float>, vector<float>);
	void setOpoznienie(int);
	float Oblicz(float);
	void inicjalizujBufory();

};
