#include <algorithm>
#include <deque>

#include "EncodingStep.h"
#include "BWTElement.h"

class BurrowsWheelerTransform : protected EncodingStep {
  public:
    // Constructor
    BurrowsWheelerTransform(std::string in);

    // Functions
    std::string getOutput();
    void updateInput(std::string in);
    void preprocessInput();
    void perform();

    // Static functions
    static bool compareElements(BWTElement e1, BWTElement e2);

    // Variables
    std::deque<BWTElement*> lookupTable;
};