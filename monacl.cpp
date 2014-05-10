#include <vector>
#include <boost/compute.hpp>
#include <iostream>
#include <algorithm>
#include <QtGui>
#include <QtOpenGL>
#include <boost/compute/command_queue.hpp>
#include <boost/compute/kernel.hpp>
#include <boost/compute/program.hpp>
#include <boost/compute/source.hpp>
#include <boost/compute/system.hpp>
#include <boost/compute/interop/opengl.hpp>
namespace compute = boost::compute;

int main()
{
    // get the default compute device
    compute::device gpu = compute::system::default_device();

    // create a compute context and command queue
    compute::context ctx(gpu);
    compute::command_queue queue(ctx, gpu);

    //create random leader dna
    // generate random dna vector on the host
    std::vector<float> host_vector(1000000);
    std::generate(host_vector.begin(), host_vector.end(), rand);

    // create vector on the device
    compute::vector<float> device_vector(1000000, ctx);

    //initialise variables
    const size_t n = 1024 * 1024;
    vex::Context ctx( vex::Filter::Any );
    vex::vector<double> leaderDNA(ctx, n);
    vex::vector<double> mutatedDNA(ctx, n);
    vex::vector<double> leaderDNArender(ctx, n);
    vex::vector<double> mutatedDNArender(ctx, n);
    vex::vector<double> originalimage(ctx, n);


    //load image into gpu memory
    // copy data to the device
    compute::copy(
        host_vector.begin(),
        host_vector.end(),
        device_vector.begin(),
        queue
    );

    

    //render dna
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

    //render leader dna
    boost::compute::function<int (int)> renderDNA =
    boost::compute::make_function_from_source<int (int)>(
        "renderDNA",
        "int renderDNA(int x) { return x + 4; }"
    );

    boost::compute::transform(vector.begin(), vector.end(), vector.begin(), renderDNA);

    //mutate leader dna
     boost::compute::function<int (int)> mutateDNA =
    boost::compute::make_function_from_source<int (int)>(
        "mutateDNA",
        "int mutateDNA(int x) { return x + 4; }"
    );

    //render mutated dna
     boost::compute::function<int (int)> renderDNA =
    boost::compute::make_function_from_source<int (int)>(
        "renderDNA",
        "int renderDNA(int x) { return x + 4; }"
    );

    //compare mutated dna to leader dna
     boost::compute::function<int (int)> compareDNA =
    boost::compute::make_function_from_source<int (int)>(
        "compareDNA",
        "int compareDNA(int x) { return x + 4; }"
    );

    //if more fit, overwrite leader dna

    if (renderDNA(mutatedDNA) > leaderDNAscore) 
    {
    leaderDNA = mutatedDNA;
     // copy data back to the host
    compute::copy(
        device_vector.begin(),
        device_vector.end(),
        host_vector.begin(),
        queue
    );
    }
   

    return 0;

}