//Programà kûrë Vilius Macijauskas P63R
/* 
Programa atkartoja duomenø failà á rezultatø failà,
suranda kiek mokiniø neturi neigiamø paþymiø ir
suranda, kuris mokinys turi daugiausia 10-kø.
*/

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const string CDFV = "Dalykai.txt";
const string CRFV = "Rezultatai.txt";
const int Cmax =50;

// Funkcijos
void Ivedimas (string fv, int M[][Cmax], int & n, int & m);
void Spausdinimas (string fv, int M[][Cmax], int m, int n);
int Daugiausia_10 (int M[][Cmax], int m, int n);
int Neturi_neig (int M[][Cmax], int m, int n);
//----------


int main()
{
	setlocale(LC_ALL, "Lithuanian");

	// mok_sk, dal_sk
	int n, m;
	int B[Cmax][Cmax];

	Ivedimas (CDFV, B, n, m);

	// á failà:
	Spausdinimas (CRFV, B, m, n);

	// á konsolæ:
	cout << "Daugiausia 10-kø turi mokinys - Nr. " << Daugiausia_10 (B, m, n) << endl;
	cout << "Mokiniai, neturintys neigiamø paþymiø: " <<  Neturi_neig(B, m, n) << endl << endl;
	//----------

	return 0;
}

void Ivedimas (string fv, int M[][Cmax], int & n, int & m)
{
	ifstream fd(fv);

	fd >> m >> n;

	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			fd >> M[i][j];
		}
	}
}

void Spausdinimas (string fv, int M[][Cmax], int m, int n)
{
	ofstream fr(fv);

	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			fr << M[i][j] << " ";
		}
		fr << endl;
	}
	fr.close();
}

int Daugiausia_10 (int M[][Cmax], int m, int n)
{
	int daug_10_nr = 0, didz_des_sk = 0, des_sk;

	for(int i = 0; i < m; i++)
	{
		des_sk = 0;
		for(int j = 0; j < n; j++)
		{
			if(M[i][j] == 10)
			{
				des_sk++;
			}
		}
		if(didz_des_sk < des_sk)
		{
			daug_10_nr = i + 1;
		}
	}

	return daug_10_nr;
}

int Neturi_neig (int M[][Cmax], int m, int n)
{
	int be_neig = 0, neig_sk;

	for(int i = 0; i < m; i++)
	{
		neig_sk = 0;
		for(int j = 0; j < n; j++)
		{
			if(M[i][j] < 4)
				neig_sk++;
		}
		if(neig_sk == 0)
			be_neig++;
	}
	return be_neig;
}