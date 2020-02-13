#include <cstddef>
#include <string>

class HuffmanNode {
  public:
    // Character
    std::string character;

    // Character's frequency
    unsigned int freq;

    // Left and right children
    HuffmanNode *left, *right;

    // Constructor
    HuffmanNode(std::string character, unsigned int freq);

    // Functions
    void updateLeft(HuffmanNode *left);
    void updateRight(HuffmanNode *right);
};
