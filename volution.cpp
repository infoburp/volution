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
    // get the default compute device
    compute::device gpu = compute::system::default_device();

    // create a compute context and command queue
    compute::context ctx(gpu);
    compute::command_queue queue(ctx, gpu);

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

    //initialise variables in gpu
    
    //create leaderDNA variable
        // create data array on host
        int host_data[] = { 1, 3, 5, 7, 9 };

        // create vector on device
        compute::vector<int> device_vector(5);

        // copy from host to device
        compute::copy(host_data,
            host_data + 5,
            device_vector.begin());
    
    //create mutatedDNA variable 
        // create data array on host
        int host_data[] = { 1, 3, 5, 7, 9 };

        // create vector on device
        compute::vector<int> device_vector(5);

        // copy from host to device
        compute::copy(host_data,
            host_data + 5,
            device_vector.begin());
    
    //create leaderDNArender variable 
        // create data array on host
        int host_data[] = { 1, 3, 5, 7, 9 };

        // create vector on device
        compute::vector<int> device_vector(5);

        // copy from host to device
        compute::copy(host_data,
            host_data + 5,
            device_vector.begin());

    //create mutatedDNArender variable
        // create data array on host
        int host_data[] = { 1, 3, 5, 7, 9 };

        // create vector on device
        compute::vector<int> device_vector(5);

        // copy from host to device
        compute::copy(host_data,
            host_data + 5,
            device_vector.begin());

    //create original image variable + load image into gpu memory
    if (std::string(argv[i]) == "") 
            {
                //load file according to commandline argument into gpu vector

                //get x(max), y(max). (image dimensions)

                //make image vector on device
                compute::vector<float> originalimage(ctx, n);
                // copy data to the device
                compute::copy(
                    host_vector.begin(),
                    host_vector.end(),
                    device_vector.begin(),
                    queue
                );
            }

    //initialise DNA with a random seed
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

    //run render loop until desired accuracy is reached
    while (leaderaccuracy<accuracy) 
        {

            //render leader DNA to a raster image in opengl texture
            boost::compute::function<int (int)> renderDNA =
            boost::compute::make_function_from_source<int (int)>(
                "renderDNA",
                "int renderDNA(int x)  
                    { //for each shape in dna
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

            //calculate leader fitness
            leaderfitness = computefitness(mutatedDNA,originalimage)
            while ()
                {
                //mutate from the leaderDNA
                boost::compute::function<int (int)> mutateDNA =
                boost::compute::make_function_from_source<int (int)>(
                    "mutateDNA",
                    "int mutateDNA(int DNA) 
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
                        }"
                );

    //render mutated DNA to a raster image in opengl texture
    boost::compute::function<int (int)> renderDNA =
    boost::compute::make_function_from_source<int (int)>(
        "renderDNA",
        "int renderDNA(int x)  
        { 
        //for each shape in dna
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

    //compute fitness of mutated dna image vs leader dna image
    //compute what % match DNAimage is to original image
    boost::compute::function<int (int)> computefitnesspercent =
    boost::compute::make_function_from_source<int (int)>(
        "computefitnesspercent",
        "int computefitnesspercent(int x) { //read leader dna

    //compare input dna to leader dna to find changed polygons
    compareDNA(leaderDNA,DNA);
    //create bounding box containing changed polygons

    //render leader dna within bounding box
    leaderrender = renderDNA(leaderDNA,boundx,boundy);
    //render input dna within bounding box
    inputrender = renderDNA(DNA,boundx,boundy);
    //compare leader and input dna rendered bounding boxes
    compareimage(leaderrender,inputrender);
    //returns % match }"
    );
                //check if it is fitter, if so overwrite leaderDNA
                while (fitness(mutatedDNA,originalimage) < leaderfitness))
                {
                    //overwrite leaderDNA
                    leaderDNA = mutatedDNA;

                    //save dna to disk
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
    //perform final render, output svg and raster image
        //render DNA and save resulting image to disk as .svg file and raster image (.png)

    //render image from DNA
    renderDNA(DNA);
    //save resultant image to disk as svg and png files

    //render input DNA to an svg file
 boost::compute::function<int (int)> renderSVG =
    boost::compute::make_function_from_source<int (int)>(
        "renderSVG",
        "int renderSVG(int x) { 

        //for each shape in dna
    {
        //add shape to svg file
    } }"
    );
}