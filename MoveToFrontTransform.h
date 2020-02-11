#include "EncodingStep.h"
#include <map>

class MoveToFrontTransform : public EncodingStep {
  public:
		// Constructor
		MoveToFrontTransform(std::string in);

		// Functions
		void encode();
		
		// Variables
    std::map<char, int> charLookup;
    std::map<int, char> intLookup;
};
