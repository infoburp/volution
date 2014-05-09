#include <iostream>
#include <CL/cl.hpp>
#include <string>
#include <vector>

using namespace std;

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


    //read specified input image file into the gpu memory

    importimage(argv[]);
    
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
    //initialise opencl device
    //get all platforms (drivers)
    std::vector<cl::Platform> all_platforms;
    cl::Platform::get(&all_platforms);
    if(all_platforms.size()==0){
        std::cout<<" No platforms found. Check OpenCL installation!\n";
        exit(1);
    }
    cl::Platform default_platform=all_platforms[0];
    std::cout << "Using platform: "<<default_platform.getInfo<CL_PLATFORM_NAME>()<<"\n";
 
    //get default device of the default platform
    std::vector<cl::Device> all_devices;
    default_platform.getDevices(CL_DEVICE_TYPE_ALL, &all_devices);
    if(all_devices.size()==0){
        std::cout<<" No devices found. Check OpenCL installation!\n";
        exit(1);
    }
    cl::Device default_device=all_devices[0];
    std::cout<< "Using device: "<<default_device.getInfo<CL_DEVICE_NAME>()<<"\n";
 
 
    cl::Context context({default_device});
 
    cl::Program::Sources sources;

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

    //read leader dna

    //compare input dna to leader dna to find changed polygons
    compareDNA(leaderDNA,DNA);
    //create bounding box containing changed polygons

    //render leader dna within bounding box
    leaderrender = renderDNA(leaderDNA,boundx,boundy);
    //render input dna within bounding box
    inputrender = renderDNA(DNA,boundx,boundy);
    //compare leader and input dna rendered bounding boxes
    compareimage(leaderrender,inputrender);
    //returns 1 if dna1 is fitter than dna0, else returns 0
}
int seedDNA()
{
    //create a random seed dna
}
int compareDNA(DNA0,DNA1)
{
    //compare DNA0 to DNA1 to find changed polygons
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
	//render input DNA to a raster image and svg

    //render to raster image

    //read DNA from gpu memory

    //initialise a new opengl image and render the dna within bounding box into it
    cairo_set_source_rgb(cr, 1, 1, 1);
    cairo_rectangle(cr, 0, 0, WIDTH, HEIGHT);
    cairo_fill(cr);
    for(int i = 0; i < NUM_SHAPES; i++)
        draw_shape(dna, cr, i);
    //render to svg
}

void draw_shape(shape_t * dna, cairo_t * cr, int i)
{
	//render an individual shape within a DNA strand using opengl
    cairo_set_line_width(cr, 0);
    shape_t * shape = &dna[i];
    cairo_set_source_rgba(cr, shape->r, shape->g, shape->b, shape->a);
    cairo_move_to(cr, shape->points[0].x, shape->points[0].y);
    for(int j = 1; j < NUM_POINTS; j++)
        cairo_line_to(cr, shape->points[j].x, shape->points[j].y);
    cairo_fill(cr);
}

}

int mutateDNA (DNA)
{
	//mutate input DNA randomly
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