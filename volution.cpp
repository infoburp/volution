#include <iostream>
#include <stdio.h>
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

int renderDNA (shape_t * DNA, cairo_t * cr)
{
	//render input DNA to an image
    cairo_set_source_rgb(cr, 1, 1, 1);
    cairo_rectangle(cr, 0, 0, WIDTH, HEIGHT);
    cairo_fill(cr);
    for(int i = 0; i < NUM_SHAPES; i++)
        draw_shape(dna, cr, i);
}

void draw_shape(shape_t * dna, cairo_t * cr, int i)
{
	//draw an individual shape within a DNA strand
    cairo_set_line_width(cr, 0);
    shape_t * shape = &dna[i];
    cairo_set_source_rgba(cr, shape->r, shape->g, shape->b, shape->a);
    cairo_move_to(cr, shape->points[0].x, shape->points[0].y);
    for(int j = 1; j < NUM_POINTS; j++)
        cairo_line_to(cr, shape->points[j].x, shape->points[j].y);
    cairo_fill(cr);
}

}

int mutateDNA (DNA,mutationtype)
{
	//mutate input DNA randomly according to mutation type
	    mutated_shape = RANDINT(NUM_SHAPES);
    double roulette = RANDDOUBLE(2.8);
    double drastic = RANDDOUBLE(2);
     
    // mutate color
    if(roulette<1)
    {
        if(dna_test[mutated_shape].a < 0.01 // completely transparent shapes are stupid
                || roulette<0.25)
        {
            if(drastic < 1)
            {
                dna_test[mutated_shape].a += RANDDOUBLE(0.1);
                dna_test[mutated_shape].a = CLAMP(dna_test[mutated_shape].a, 0.0, 1.0);
            }
            else
                dna_test[mutated_shape].a = RANDDOUBLE(1.0);
        }
        else if(roulette<0.50)
        {
            if(drastic < 1)
            {
                dna_test[mutated_shape].r += RANDDOUBLE(0.1);
                dna_test[mutated_shape].r = CLAMP(dna_test[mutated_shape].r, 0.0, 1.0);
            }
            else
                dna_test[mutated_shape].r = RANDDOUBLE(1.0);
        }
        else if(roulette<0.75)
        {
            if(drastic < 1)
            {
                dna_test[mutated_shape].g += RANDDOUBLE(0.1);
                dna_test[mutated_shape].g = CLAMP(dna_test[mutated_shape].g, 0.0, 1.0);
            }
            else
                dna_test[mutated_shape].g = RANDDOUBLE(1.0);
        }
        else
        {
            if(drastic < 1)
            {
                dna_test[mutated_shape].b += RANDDOUBLE(0.1);
                dna_test[mutated_shape].b = CLAMP(dna_test[mutated_shape].b, 0.0, 1.0);
            }
            else
                dna_test[mutated_shape].b = RANDDOUBLE(1.0);
        }
    }
    
    // mutate shape
    else if(roulette < 2.0)
    {
        int point_i = RANDINT(NUM_POINTS);
        if(roulette<1.5)
        {
            if(drastic < 1)
            {
                dna_test[mutated_shape].points[point_i].x += (int)RANDDOUBLE(WIDTH/10.0);
                dna_test[mutated_shape].points[point_i].x = CLAMP(dna_test[mutated_shape].points[point_i].x, 0, WIDTH-1);
            }
            else
                dna_test[mutated_shape].points[point_i].x = RANDDOUBLE(WIDTH);
        }
        else
        {
            if(drastic < 1)
            {
                dna_test[mutated_shape].points[point_i].y += (int)RANDDOUBLE(HEIGHT/10.0);
                dna_test[mutated_shape].points[point_i].y = CLAMP(dna_test[mutated_shape].points[point_i].y, 0, HEIGHT-1);
            }
            else
                dna_test[mutated_shape].points[point_i].y = RANDDOUBLE(HEIGHT);
        }
    }

    // mutate stacking
    else
    {
        int destination = RANDINT(NUM_SHAPES);
        shape_t s = dna_test[mutated_shape];
        dna_test[mutated_shape] = dna_test[destination];
        dna_test[destination] = s;
        return destination;
    }
    return -1;

}
}

int saveDNA(DNA)
{
	int result;

	while(1)
	{
		// start by writing a temp file.

		pFile = fopen ("volution.dna.temp","w");
		fprintf (pFile, DNA);
		fclose (pFile);

		// Then rename the real backup to a secondary backup.
    
		result = rename("volution.dna","volution_2.dna");
    
		// Then rename the temp file to the primary backup

		result = rename("volution.dna.temp","volution.dna");
    
		// Then delete the temp file
    
		result = remove("volution.dna.temp");

		//sleep for 30 seconds.
		
		sleep(30000);
	}
}

int saveSVG(DNA)
{
    //render DNA and save resulting image to disk as .svg file

    //render image from DNA
    renderDNA(DNA);
    //save resultant image to disk as svg
}
