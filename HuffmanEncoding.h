#include <map>
#include <queue> 
#include <vector>
#include <string>

#include "EncodingStep.h"
#include "HuffmanNode.h"

class HuffmanEncoding : public EncodingStep {
  public:
    // Constructor
    HuffmanEncoding(std::string in);

    // Functions
    void buildTrie();

    // Variables
    std::map<std::string, int> frequencies;

  private:
    // Functions
    void computeFrequencies();
    void generateOutput(HuffmanNode *root);
};
