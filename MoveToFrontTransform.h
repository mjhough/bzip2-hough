#include "EncodingStep.h"

class MoveToFrontTransform : public EncodingStep {
  public:
		// Constructor
		MoveToFrontTransform(std::string in);

		// Functions
		void encode();

  private:
    // Variables
    std::string dictionary;
};
