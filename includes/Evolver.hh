#ifndef EVOLVER_HH_
# define EVOLVER_HH_

#include <string>
#include <vector>

#include <boost/compute/command_queue.hpp>
#include <boost/compute/kernel.hpp>
#include <boost/compute/program.hpp>
#include <boost/compute/source.hpp>
#include <boost/compute/system.hpp>
#include <boost/compute/container/vector.hpp>
#include <boost/compute/interop/opengl.hpp>

namespace compute = boost::compute;

//Nearly everything is done in this class
class Evolver
{
public:
  Evolver();
  ~Evolver();

public://public functions
  bool		initialize(int ac, char **av);
  void		run();
  void		pause();
  void		checkDNA();
  bool		saveImage();
  bool		saveVector();
  
  
private://private functions
  void		getAttributes(int ac, char **av);
  bool		loadFile();
  bool		fitness();
  
private://private attributes
  std::string			_filename;
  compute::vector<int>		_deviceAccuracy;
  compute::vector<int>		_devicePolygons;
  compute::vector<int>		_deviceVertices;
  
private://compute vars
  compute::device 		_gpu;
  compute::context		_ctx;
  compute::command_queue	_queue;
  
private://DNA vars
 std::vector<int>		_leaderDNA;
 compute::vector<int>		_device_leaderDNA;
};

#endif // EVOLVER_HH_