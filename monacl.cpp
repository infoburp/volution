#include <iostream>
#include <stdexcept>
#include <vexcl/vexcl.hpp>

int main() {
    vex::Context ctx( vex::Filter::Type(CL_DEVICE_TYPE_GPU) && vex::Filter::DoublePrecision );

    if (!ctx) throw std::runtime_error("No devices available.");

    // Print out list of selected devices:
    std::cout << ctx << std::endl;
}

//initialise variables
const size_t n = 1024 * 1024;
vex::Context ctx( vex::Filter::Any );
vex::vector<double> leaderDNA(ctx, n);
vex::vector<double> mutatedDNA(ctx, n);
vex::vector<double> leaderDNArender(ctx, n);
vex::vector<double> mutatedDNArender(ctx, n);
vex::vector<double> originalimage(ctx, n);



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

//if more fit, overwrite leader dna

if (renderDNA(mutatedDNA) > leaderDNAscore) 
{
	leaderDNA = mutatedDNA;
}


