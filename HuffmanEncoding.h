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
    struct compareNodes {
      bool operator()(HuffmanNode *left, HuffmanNode *right) {
        return (left->freq > right->freq);
      }
    };
    std::priority_queue<HuffmanNode*, std::vector<HuffmanNode*>, compareNodes> minHeap;

  private:
    // Functions
    void computeFrequencies();
    void generateCode(HuffmanNode *root, std::string str, std::string character);
};
