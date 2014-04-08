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
	bool operator < (const Anställd& str) const
    {
        return (_lön > str._lön);
    }
	friend ostream & operator<<(ostream & o, Anställd a);

private:
	string _förnamn, _efternamn, _avdelning;
	int _ålder, _lön;
};

ostream & operator<<(ostream & o, Anställd a)
{
	return o << a._förnamn << " " << a._efternamn << ", " << a._ålder << ".\tAvd: " << a._avdelning << "\tLön: "<< a._lön<< endl;
}

void main()
{
	vector<Anställd> personal;
	ostream_iterator<Anställd> out_it (cout,"");

	personal.push_back(Anställd("Tim", "Hertzberg", "JTH", 19, 16000));
	personal.push_back(Anställd("Linus", "Berglund", "JTH", 21, 18000));
	personal.push_back(Anställd("Jan", "Assgård", "JTH", 19, 10000));
	personal.push_back(Anställd("Mikael", "Bergman", "JTH", 24, 250000));

	copy(personal.begin(), personal.end(), out_it);

	sort(personal.begin(), personal.end());
	cout << endl;
	copy(personal.begin(), personal.end(), out_it);

	cin.get();
}