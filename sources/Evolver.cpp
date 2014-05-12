#include <cstdio>
#include <exception>
#include <system_error>

#include <boost/program_options.hpp>
#include <boost/exception/all.hpp>


#include "Evolver.hh"

namespace po = boost::program_options;

Evolver::Evolver()
{
  _deviceAccuracy.push_back(90);
  _devicePolygons.push_back(60);
  _deviceVertices.push_back(6);
  
  if (compute::system::device_count() == 0)
    throw new std::runtime_error("No opencl device found");
  _gpu = compute::system::default_device();
  _ctx = compute::context(_gpu);
  _queue = compute::command_queue(_ctx, _gpu);
  
  #ifdef DEBUG
  std::cout << "number of opencl device(s) : " << compute::system::device_count() << std::endl;
  std::cout << "selected opencl devide : " << _gpu.name() << std::endl;
  #endif
  
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
    _deviceAccuracy.push_back(vm["accuracy"].as<int>());
  if (vm.count("polygons"))
    _devicePolygons.push_back(vm["polygons"].as<int>());
  if (vm.count("vertices"))
    _deviceVertices.push_back(vm["vertices"].as<int>());
  
  #ifdef DEBUG
  std::cout << "input file\t" << _filename << std::endl;
  std::cout << "accuracy\t" << _deviceAccuracy.front() << std::endl;
  std::cout << "Polygons\t" << _devicePolygons.front() << std::endl;
  std::cout << "Vertices\t" << _deviceVertices.front() << std::endl;
  #endif
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
  
  
  
  return true;
}


void Evolver::run()
{
  
}

void Evolver::pause()
{
  
}

// SAVES

bool	Evolver::saveImage()
{
  FILE	*pFile;
  
  pFile = fopen ("%filename.render.png","w");
  if (pFile == NULL)
  {
    std::cerr << "Error while opening the png file." << std::endl;
    return false;
  }
  /*if (fprintf (pFile, leaderDNAimage < 0)
   *  {
   *     std::cerr << "Error while writing the png file." << std::endl;
   *     return false;
   *   }	
   */
  fclose (pFile);
  return true;
}

bool	Evolver::saveVector()
{
  FILE	*pFile;
  
  pFile = fopen ("%filename.render.svg","w");
  if (pFile == NULL)
  {
    std::cerr << "Error while opening the svg file." << std::endl;
    return false;
  }
  /* if (fprintf (pFile, leaderDNAvector) < 0)
   *	{
   *     std::cerr << "Error while writing the svg file." << std::endl;
   *     return false;
   *	}
   */
  fclose (pFile);
  return true;
}