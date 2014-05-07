#include <iostream>
using namespace std;

int main ()
{
	//initialise variables
	class DNA 
	{
		public:
		string genome;
	}
}

int computefitness (DNA, originalimage)
{
	//compute the fitness of input DNA, i.e. how close is it to original image?
	renderDNA(DNA);

	char *img1data, *img2data, fname[15];
	int s, n = 0, y = 0;

	sprintf(fname, "photo%d.bmp", p - 1);
	cout << "\n" << fname;
	ifstream img1(fname, ios::in|ios::binary|ios::ate);
	sprintf(fname, "photo%d.bmp", p);
	cout << "\n" << fname;
	ifstream img2(fname, ios::in|ios::binary|ios::ate);

	if (img1.is_open() && img2.is_open())
    {
		s = (int)img1.tellg();
		img1data = new char [s];
		img1.seekg (0, ios::beg);
		img1.read (img1data, s);
		img1.close();

		img2data = new char [s];
		img2.seekg (0, ios::beg);
		img2.read (img2data, s);
		img2.close();
	}
	
	for(int i=0; i<s; i++)
        if (img1data[i]==img2data[i]) y++;

	return (y);
}

int renderDNA (DNA)
{
	//render input DNA to an image
}

int mutateDNA (DNA,mutationtype)
{
	//mutate input DNA randomly according to mutation type
}