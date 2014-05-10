#ifndef EVOLVER_HH_
# define EVOLVER_HH_

#include <string>

//Nearly everything is done in this class
class Evolver
{
public:
  Evolver();
  ~Evolver();

public://public fucntions
  bool		initialize(int ac, char **av);
  void		run();
  void		pause();
  
  
private://private functions
  void		getAttributes(int ac, char **av);
  bool		loadFile();
  
private://private attributes
  std::string	_filename;
  int		_accuracy;
  int		_polygons;
  int		_vertices;
};

#endif // EVOLVER_HH_