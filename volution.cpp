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
            compute::copy(accuracy,
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
            compute::vector<int> device_vertices(1);

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
                accuracy = argv[i + 1];
                // copy from host to device
                compute::copy(accuracy,
                    accuracy,
                    device_accuracy.begin());
                
            }
        if (std::string(argv[i]) == "-p") 
            {
                //initialise maximum polygons variable according to commandline argument -p
                polygons = argv[i + 1];
                // copy from host to device
                compute::copy(accuracy,
                    accuracy,
                    device_accuracy.begin());
               
            }
        if (std::string(argv[i]) == "-v") 
            {
                //initialise maximum verices per polygon variable according to commandline argument -v
                vertices = argv[i + 1];
                // copy from host to device
                compute::copy(accuracy,
                    accuracy,
                    device_accuracy.begin());
            }   
    }

    //create leaderDNA variable
        // generate random dna vector on the host
        std::vector<int> leaderDNA(1000000);
        std::generate(leaderDNA.begin(), leaderDNA.end(), rand);

        // create vector on the device
        compute::vector<int> device_leaderDNA(1000000, ctx);

        // copy data to the device
        compute::copy(
            leaderDNA.begin(),
            leaderDNA.end(),
            device_leaderDNA.begin(),
            queue
        );
    
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
                compute::vector<int> originalimage(ctx, n);
                // copy data to the device
                compute::copy(
                    host_vector.begin(),
                    host_vector.end(),
                    device_vector.begin(),
                    queue
                );
            }

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
        "int computefitnesspercent(int x) { }"
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
     
                        //mutate color
                            //randomly change mutated_shape colour
                                //change red
                                    //up
                                    //down
                                //change green
                                    //up
                                    //down
                                //change blue
                                    //up
                                    //down
                                //change alpha
                                    //up
                                    //down
                        //mutate shape
                            //randomly move one vertex in mutated_shape
                                //randomly pick vertex
                                    //move up
                                    //move down
                                    //move left
                                    //move right
                        //mutate stacking
                            //randomly move one shape up or down stack 
                                //randomly select shape
                                    //move shape up stack
                                    //move shape down stack
                        //100% mutation (create new random dna)
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

    //compute what % match mutated dna image is to original image
    boost::compute::function<int (int)> computefitnesspercent =
    boost::compute::make_function_from_source<int (int)>(
        "computefitnesspercent",
        "int computefitnesspercent(int x) {
        //get x, y size of images to be compared

        //for each x,y value
            //give % match between leaderDNAimage(x,y) and mutatedDNAimage(x,y)

        //calculate average % value and store to mutatedDNAfitness

         }"
    );
    
    //check if mutated dna image is fitter, if so overwrite leaderDNA
    if (mutatedDNAfitness > leaderDNAfitness)
        {
            //overwrite leaderDNA
            leaderDNA = mutatedDNA;

            //save dna to disk as filename.dna
            pFile = fopen ("%filename.dna","w");
            fprintf (pFile, DNA);
            fclose (pFile);
        }
    
    //perform final render, output svg and raster image
        //render final DNA to a raster image in opengl texture
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
                }
            }"
        );
    
        //copy raster image from gpu to main memory

        //save raster image to disk as filename.render.png
        pFile = fopen ("%filename.render.png","w");
                    fprintf (pFile, leaderDNAimage);
                    fclose (pFile);

        //render mutated DNA to a vector image 
        boost::compute::function<int (int)> renderDNA =
        boost::compute::make_function_from_source<int (int)>(
            "renderDNAvector",
            "int renderDNAvector(DNA)  
            { 
            //initialise svg string
            //for each shape in dna
                {
                    //add shape to svg
                }
            }"
            //close svg string
        );
    
        //copy vector image from gpu to main memory

        //save vector image to disk as filename.render.svg
        pFile = fopen ("%filename.render.svg","w");
                    fprintf (pFile, leaderDNAvector);
                    fclose (pFile);
}