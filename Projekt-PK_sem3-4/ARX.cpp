#include "ARX.h";

#ifdef DEBUG_ARX
ARX::ARX(vector<float> wektorA, vector<float> wektorB, int opoznienie, float i_u)
:m_u(i_u)
{
	setOpoznienie(opoznienie);
	setWektory(wektorA, wektorB);
	inicjalizujBufory();
}
#endif

#ifdef RELEASE
ARX::ARX(vector<float> wektorA, vector<float> wektorB, int opoznienie)
{
	setOpoznienie(opoznienie);
	setWektory(wektorA, wektorB);
	inicjalizujBufory();
}
#endif

void ARX::setOpoznienie(int i_opoznienie)
{
	if (i_opoznienie < 0) opoznienie = 0;
	else opoznienie = i_opoznienie;
}

void ARX::setWektory(vector<float> A, vector<float> B)
{
	wektorA.clear();
	wektorB.clear();
	wektorA = A;
	wektorB = B;
}

void ARX::inicjalizujBufory()
{
	historiaY.clear();
	historiaU.clear();
	opoznienieTransportowe.clear();

	historiaU.resize(wektorB.size());
	historiaY.resize(wektorA.size());
}

float ARX::Oblicz(float u)
{
	float mean = 0, stdev = 0.1;

	random_device gen_los;
	mt19937 gen_plos;
	gen_plos.seed(gen_los());

	normal_distribution<float> rozkladGausa(mean, stdev);
	float zaklocenia = rozkladGausa(gen_plos);

	float wyjscie = 0.0f;
	
	opoznienieTransportowe.push_back(u);

	if (opoznienieTransportowe.size() > opoznienie)
	{
		float opoznione_u = opoznienieTransportowe.front();
		opoznienieTransportowe.pop_front();

		historiaU.push_front(opoznione_u);
		if (historiaU.size() > wektorB.size())
			historiaU.pop_back();
	}
	

	for (int i = 0; i < wektorA.size(); i++)
		wyjscie -= wektorA[i] * historiaY[i];
	for (int j = 0; j < wektorB.size(); j++)
		wyjscie += wektorB[j] * historiaU[j];

	historiaY.push_front(wyjscie);
	if (historiaY.size() > wektorA.size())
		historiaY.pop_back();

	return wyjscie + zaklocenia;
}