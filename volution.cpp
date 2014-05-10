#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <vexcl/vexcl.hpp>

#include <boost/compute.hpp>

#include <algorithm>
#include <QtGui>
#include <QtOpenGL>
#include <boost/compute/command_queue.hpp>
#include <boost/compute/kernel.hpp>
#include <boost/compute/program.hpp>
#include <boost/compute/source.hpp>
#include <boost/compute/system.hpp>
#include <boost/compute/interop/opengl.hpp>

using namespace std;
namespace compute = boost::compute;

int main (int argc, char* argv[])
{
	//set some default values for when no commandline arguments are given
	int accuracy = 90;
	int polygons = 50;
	int vertices = 6;
    //read input commandline arguments
    for (int i = 1; i < argc; ++i) 
    {
        if (std::string(argv[i]) == "-a") 
            {
                //initialise desired accuracy variable according to commandline argument -a
                accuracy = ;
                
            }
        if (std::string(argv[i]) == "-p") 
            {
                //initialise maximum polygons variable according to commandline argument -p
                polygons = ;
               
            }
        if (std::string(argv[i]) == "-v") 
            {
                //initialise maximum verices per polygon variable according to commandline argument -v
                vertices = ;
               
            }
    }
     // get the default compute device
    compute::device gpu = compute::system::default_device();

    // create a compute context and command queue
    compute::context ctx(gpu);
    compute::command_queue queue(ctx, gpu);

    //initialise variables in gpu
    const size_t n = 1024 * 1024;
    std::vector<double> leaderDNA(ctx, n);
    std::vector<double> mutatedDNA(ctx, n);
    std::vector<double> leaderDNArender(ctx, n);
    std::vector<double> mutatedDNArender(ctx, n);
    std::vector<double> originalimage(ctx, n);

    //load image into gpu memory
    // copy data to the device
    compute::copy(
        host_vector.begin(),
        host_vector.end(),
        device_vector.begin(),
        queue
    );
    
    //initialise variables
	class DNA 
	{
		public:
		string genome;
        int polygons;
        int vertices;
        polygon[polygons];

	}
    class polygon;
    {
        public:
        int x[vertices];
        int y[vertices];
        int R;
        int G;
        int B;
        int alpha;
    }

    //initialise DNA with a random seed
    leaderDNA = seedDNA();
    //run render loop until desired accuracy is reached
    while (leaderaccuracy<accuracy) 
        {
            //mutate from the leaderDNA
            mutatedDNA = mutateDNA(leaderDNA)
            //compute fitness of mutation vs leaderDNA
            //check if it is fitter, if so overwrite leaderDNA
            if (computefitness(leaderDNA,mutatedDNA) == 1)
            {
                //overwrite leaderDNA
                leaderDNA = mutatedDNA;
            }
            //compute accuracy percent
            computefitnesspercent(leaderDNA, originalimage)
        }
    //perform final render, output svg and raster image
    saverender(leaderDNA);
}
int computefitnesspercent (DNA, originalimage)
{
    //compute what % match DNA is to original image
}
int computefitness (DNA0, DNA1)
{
	//compute the fitness of input DNA, i.e. how close is it to original image?
  boost::compute::function<int (int)> computefitness =
    boost::compute::make_function_from_source<int (int)>(
        "computefitness",
        "int computefitness(int x) { //read leader dna

    //compare input dna to leader dna to find changed polygons
    compareDNA(leaderDNA,DNA);
    //create bounding box containing changed polygons

    //render leader dna within bounding box
    leaderrender = renderDNA(leaderDNA,boundx,boundy);
    //render input dna within bounding box
    inputrender = renderDNA(DNA,boundx,boundy);
    //compare leader and input dna rendered bounding boxes
    compareimage(leaderrender,inputrender);
    //returns 1 if dna1 is fitter than dna0, else returns 0 }"
    );
    
}
int seedDNA()
{
    //create a random seed dna
       //create random leader dna
    // generate random dna vector on the host
    std::vector<float> host_vector(1000000);
    std::generate(host_vector.begin(), host_vector.end(), rand);

    // create vector on the device
    compute::vector<float> device_vector(1000000, ctx);

    // copy data to the device
    compute::copy(
        host_vector.begin(),
        host_vector.end(),
        device_vector.begin(),
        queue
    );


}
int compareDNA(DNA0,DNA1)
{
    //compare DNA0 to DNA1 to find changed polygons
    boost::compute::function<int (int)> compareDNA =
    boost::compute::make_function_from_source<int (int)>(
        "compareDNA",
        "int compareDNA(int x) { return x + 4; }"
    );
}
int compareimage(image0,image1)
{
    //compare two raster images, return 1 if image1 fitter than image0, else return 0
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

int renderDNA (DNA, boundx0, boundy0, boundx1, boundy1)
{
	//render input DNA to a raster image
 boost::compute::function<int (int)> renderDNA =
    boost::compute::make_function_from_source<int (int)>(
        "renderDNA",
        "int renderDNA(int x) { //for each shape in dna
    {
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, gl_texture_);

    glBegin(GL_QUADS);
    glTexCoord2f(0, 0); glVertex2f(0, 0);
    glTexCoord2f(0, 1); glVertex2f(0, h);
    glTexCoord2f(1, 1); glVertex2f(w, h);
    glTexCoord2f(1, 0); glVertex2f(w, 0);
    glEnd();
    } }"
    );
}

int renderSVG (DNA, boundx0, boundy0, boundx1, boundy1)
{
    //render input DNA to a vector image
 boost::compute::function<int (int)> renderSVG =
    boost::compute::make_function_from_source<int (int)>(
        "renderSVG",
        "int renderSVG(int x) { //for each shape in dna
    {
    
    } }"
    );
}

}

int mutateDNA (DNA)
{
     //mutate dna
    boost::compute::function<int (int)> mutateDNA =
    boost::compute::make_function_from_source<int (int)>(
        "mutateDNA",
        "int mutateDNA(int DNA) { //mutate input DNA randomly
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
 }"
    );
	
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

	}
}

int saverender(DNA)
{
    //render DNA and save resulting image to disk as .svg file and raster image (.png)

    //render image from DNA
    renderDNA(DNA);
    //save resultant image to disk as svg and png files
}

int importimage(image)
{
    //import specified image into the gpu memory
    // Load input image from file and load it into
    // an OpenCL image object
    int width, height;
    imageObjects[0] = LoadImage(context, argv[1], width, height);
    if (imageObjects[0] == 0)
    {
        std::cerr << "Error loading: " << std::string(argv[1]) << std::endl;
        Cleanup(context, commandQueue, program, kernel, imageObjects, sampler);
        return 1;
    }
     //load image into gpu memory
    // copy data to the device
    compute::copy(
        host_vector.begin(),
        host_vector.end(),
        device_vector.begin(),
        queue
    );
}

int drawshape()
{
	//user draws shape from ui

    //start drawing shape vertex by vertex
    //until max number of vertices reached or user closes polygon by clicking on initial vertex

    //check if drawn shape gives a better fitness

    //if it does update the leaderDNA
}

int dragvertex()
{
	//user drags vertex from ui

    //user stops dragging vertex

    //check if dragged vertex improves fitness

    //if it does update the leaderDNA
}
