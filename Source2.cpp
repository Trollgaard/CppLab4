#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <iostream>
using namespace std;

class Anställd
{
public:
	Anställd(string förnamn, string efternamn, string avdelning, int ålder, int lön):_förnamn(förnamn), _efternamn(efternamn), _avdelning(avdelning), _ålder(ålder), _lön(lön){}
	//Överlagrar sort-funktionens operator.
	bool operator < (const Anställd& an) const
    {
        return (_lön > an._lön);
    }
	friend ostream & operator<<(ostream & o, Anställd a);

private:
	string _förnamn, _efternamn, _avdelning;
	int _ålder, _lön;
};

//Formaterar utskriften genom att överlagra ostreams << operator.
ostream & operator<<(ostream & o, Anställd a)
{
	return o << a._förnamn << " " << a._efternamn << ", " << a._ålder << ".\tAvd: " << a._avdelning << "\tLön: "<< a._lön<< endl;
}

void main()
{
	vector<Anställd> personal;

	//För att skriva ut vektorn med Anställda.
	ostream_iterator<Anställd> out_it (cout,"");

	personal.push_back(Anställd("Tim", "Hertzberg", "JTH", 19, 16000));
	personal.push_back(Anställd("Linus", "Berglund", "JTH", 21, 18000));
	personal.push_back(Anställd("Jan", "Assgård", "JTH", 19, 10000));
	personal.push_back(Anställd("Mikael", "Bergman", "JTH", 24, 250000));

	copy(personal.begin(), personal.end(), out_it);

	sort(personal.begin(), personal.end());
	cout << endl << "Sorterad:" << endl;
	copy(personal.begin(), personal.end(), out_it);

	cin.get();
}