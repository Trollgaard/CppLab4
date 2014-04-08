#include <iostream>
#include <string>
#include <time.h>
using namespace std;

template <class X> class Stacken
{
public:
	Stacken()
	{
		arrP = new X[100];
		senast = 0;
	}

	void push(X x)
	{
		if (senast > 99)
			throw 1;
		arrP[senast] = x;
		senast++;
	}

	X pop()
	{
		if (senast < 1)
			throw 2;
		X temp = arrP[senast-1];
		senast--;
		return temp;
	}
private:
	X * arrP;
	int senast;
};

void main()
{
	srand(time(NULL));
	string text;
	try
	{
		Stacken<int> minStack;
		for (int i = 0; i < 101; i++)
		{
			//text = rand()%100; //string
			//minStack.push(text); //string
			minStack.push(rand()%100); //int
		}
		
		for (int i = 0; i < 100; i++)
		{
			cout << i+1 << ": " << minStack.pop() << endl;
		}
	}
	catch (int e)
	{
		if (e == 1)
			cout << endl << "Stacken är full. Tryck på enter för att avsluta" << endl;
		else if (e == 2)
			cout << endl << "Stacken är tom. Tryck på enter för att avsluta" << endl;
		else
			cout << endl << "Ett fel uppstod. Tryck på enter för att avsluta" << endl;
	}

	cin.get();
}