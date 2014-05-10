#include <boost/program_options.hpp>
#include <boost/exception/all.hpp>

#include <exception>
#include <vexcl/vexcl.hpp>

#include "Evolver.hh"

namespace po = boost::program_options;

Evolver::Evolver()
{
  _accuracy = 90;
  _polygons = 50;
  _vertices = 6;
}

Evolver::~Evolver()
{}

void Evolver::getAttributes(int ac, char **av)
{
  po::options_description	desc("Volution usage");
  po::variables_map		vm;
  
  //setting name and description of each options
  desc.add_options()
  ("help", "Produce this message")
  ("file", po::value<std::string>(), "Input file")
  ("accuracy", po::value<int>(), "Accuracy at which the program stop (default 90)")
  ("polygons", po::value<int>(), "Number of polygons (default 6)")
  ("vertices", po::value<int>(), "Number of verticles (default 50)");
  
  po::store(po::parse_command_line(ac, av, desc), vm);
  po::notify(vm);    
  
  if (vm.count("help"))
  {
    std::cout << desc << "\n";
    return ;
  }
  
  //Check if commands have been provided and bind the value to variables
  if (vm.count("file"))
    _filename = vm["file"].as<std::string>();
  if (vm.count("accuracy"))
    _accuracy = vm["accuracy"].as<int>();
  if (vm.count("polygons"))
    _polygons = vm["polygons"].as<int>();
  if (vm.count("vertices"))
    _vertices = vm["vertices"].as<int>();
  
  std::cout << "input file\t" << _filename << std::endl;
  std::cout << "accuracy\t" << _accuracy << std::endl;
  std::cout << "Polygons\t" << _polygons << std::endl;
  std::cout << "Vertices\t" << _vertices << std::endl;
}

bool Evolver::loadFile()
{
  return true;
}


bool Evolver::initialize(int ac, char** av)
{
  try
  {
    getAttributes(ac, av);
  }
  catch  (boost::exception const &e)
  {
    std::cerr <<  boost::diagnostic_information(e) << std::endl;
  }
  
  if (!loadFile())
    return false;
  return true;
}


void Evolver::run()
{

}

void Evolver::pause()
{

}
