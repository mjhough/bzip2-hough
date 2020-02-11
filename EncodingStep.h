#ifndef ENCODINGSTEP_H
#define ENCODINGSTEP_H

#include <cstddef>
#include <string>

class EncodingStep {
	public:
		std::string getOutput();

  protected:
    std::string input;
    std::string output;
};

#endif
