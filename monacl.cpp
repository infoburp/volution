#include <vector>
#include <algorithm>
#include <boost/compute.hpp>

namespace compute = boost::compute;

int main()
{
    // get the default compute device
    compute::device gpu = compute::system::default_device();

    // create a compute context and command queue
    compute::context ctx(gpu);
    compute::command_queue queue(ctx, gpu);

    // generate random numbers on the host
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

//create random leader dna

//render dna
VEX_FUNCTION(double, renderDNA, (double, x)(double, y),
    return x * x + y * y;
    );

//render leader dna
leaderDNArender = renderDNA(squared_radius(X, Y));

//mutate leader dna
VEX_FUNCTION(double, renderDNA, (double, x)(double, y),
    return x * x + y * y;
    );

//render mutated dna
mutatedDNArender = renderDNA(squared_radius(X, Y));

//compare mutated dna to leader dna
VEX_FUNCTION(double, renderDNA, (double, x)(double, y),
    return x * x + y * y;
    //return % match
    );


 

    // sort data on the device
    compute::sort(
        device_vector.begin(),
        device_vector.end(),
        queue
    );

//if more fit, overwrite leader dna

if (renderDNA(mutatedDNA) > leaderDNAscore) 
{
    leaderDNA = mutatedDNA;
}
    // copy data back to the host
    compute::copy(
        device_vector.begin(),
        device_vector.end(),
        host_vector.begin(),
        queue
    );

    return 0;
}