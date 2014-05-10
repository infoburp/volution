#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
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
        //create accuracy variable
        int accuracy = 90;

        // create vector on device
        compute::vector<int> device_accuracy(1);

        // copy from host to device
        compute::copy(host_data,
            accuracy,
            device_accuracy.begin());
        
        //create polygons variable
        int polygons = 50;

        // create vector on device
        compute::vector<int> device_polygons(1);

        // copy from host to device
        compute::copy(host_data,
            host_data + 5,
            device_vector.begin());
        
        //create vertices variable
        int vertices = 6;

        // create vector on device
        compute::vector<int> device_vector(5);

        // copy from host to device
        compute::copy(host_data,
            host_data + 5,
            device_vector.begin());

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


            //compute fitness of leader dna image
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
                        double roulette = RANDDOUBLE(3);
     
                        // mutate color
                            //randomly change mutated_shape colour
                        // mutate shape
                            //randomly move one vertex in mutated_shape
                        // mutate stacking
                            //randomly move one shape up or down stack in mutated_shape
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
                    pFile = fopen ("volution.dna","w");
                    fprintf (pFile, DNA);
                    fclose (pFile);
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
                }
            }"
        );
}