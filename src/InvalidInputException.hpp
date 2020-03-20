#define BACKWARD_HAS_BFD 1
#define BACKWARD_HAS_DW 1
#include "util/backward.hpp"
#include <exception>
using namespace backward;
using namespace std;

class InvalidInputException : public exception{

    public:

    const char * what() const throw();

};
