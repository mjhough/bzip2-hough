#include <map>
#include <string>

#include "EncodingStep.h"

class HuffmanEncoding : public EncodingStep {
  public:
    // Constructor
    HuffmanEncoding(std::string in);

    // Functions
    void buildTrie();
    void computeFrequencies();

    // Variables
    std::map<std::string, int> frequencies;
};
