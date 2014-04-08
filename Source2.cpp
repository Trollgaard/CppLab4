#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <iostream>
using namespace std;

class Anst�lld
{
public:
	Anst�lld(string f�rnamn, string efternamn, string avdelning, int �lder, int l�n):_f�rnamn(f�rnamn), _efternamn(efternamn), _avdelning(avdelning), _�lder(�lder), _l�n(l�n){}
	bool operator < (const Anst�lld& str) const
    {
        return (_l�n > str._l�n);
    }
	friend ostream & operator<<(ostream & o, Anst�lld a);

private:
	string _f�rnamn, _efternamn, _avdelning;
	int _�lder, _l�n;
};

ostream & operator<<(ostream & o, Anst�lld a)
{
	return o << a._f�rnamn << " " << a._efternamn << ", " << a._�lder << ".\tAvd: " << a._avdelning << "\tL�n: "<< a._l�n<< endl;
}

void main()
{
	vector<Anst�lld> personal;
	ostream_iterator<Anst�lld> out_it (cout,"");

	personal.push_back(Anst�lld("Tim", "Hertzberg", "JTH", 19, 16000));
	personal.push_back(Anst�lld("Linus", "Berglund", "JTH", 21, 18000));
	personal.push_back(Anst�lld("Jan", "Assg�rd", "JTH", 19, 10000));
	personal.push_back(Anst�lld("Mikael", "Bergman", "JTH", 24, 250000));

	copy(personal.begin(), personal.end(), out_it);

	sort(personal.begin(), personal.end());
	cout << endl;
	copy(personal.begin(), personal.end(), out_it);

	cin.get();
}