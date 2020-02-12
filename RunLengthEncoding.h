#include "EncodingStep.h"

class RunLengthEncoding : public EncodingStep {
  public:
    // Constructor
    RunLengthEncoding(std::string in);

    // Functions
    void encode();
};
