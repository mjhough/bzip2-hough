#include "BurrowsWheelerTransform.h"

// Constructor
BurrowsWheelerTransform::BurrowsWheelerTransform(std::string in) {
  input = in;
  output = "";
  preprocessInput();
}

// Destructor
BurrowsWheelerTransform::~BurrowsWheelerTransform(void) {
  while (!lookupTable.empty()) {
    delete lookupTable.front();
    lookupTable.pop_front();
  }
}

// Update the input string
void BurrowsWheelerTransform::updateInput(std::string in) {
  this->input = in;
  preprocessInput();
}

void BurrowsWheelerTransform::preprocessInput(void) {
  for (int i = input.length(); i >= 0; i--) {
    BWTElement *el = new BWTElement(input[i]);
    if (lookupTable.size() > 0) {
      lookupTable.front()->updatePrev(el);
      el->updateNext(lookupTable.front());
    }
    lookupTable.push_front(el);
  }
  // Set the prev value of the first element in the lookup table
  // to the final element in the string
  lookupTable.front()->updatePrev(lookupTable.back());

  // Now should have a lookup table where the keys are
  // ordered by the ordering of the input string.
}

void BurrowsWheelerTransform::perform(void) {
  // 1. Sort according to the compareElements function in BWTElement
  std::sort(lookupTable.begin(), lookupTable.end(), BWTElement::compareElements);

  // 2. Create the output string from the previous values
  std::deque<BWTElement*>::iterator it = lookupTable.begin();
  while (it != lookupTable.end()) {
    output.push_back((*it)->prev->key);
    *it++;
  }
}
