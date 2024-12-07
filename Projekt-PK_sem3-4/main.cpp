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

	vector<int> T;
	T.push_back(1);
	cout << T.size() << endl;
	T.push_back(2);
	cout << T.size() << endl;
	T.push_back(3);
	cout << T.size() << endl;
	T.push_back(4);
	cout << T.size() << endl;
	T.push_back(5);
	cout << T.size() << endl;

	T.resize(T.size() + 1 );
	move_backward(T.begin(), T.end() -1 , T.begin());
	for (int i = 0; i < T.size(); i++)
		cout << T[i] << " "; 
	T[0] = 0;

}

#endif
