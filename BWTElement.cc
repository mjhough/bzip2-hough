#include "BWTElement.h"

BWTElement::BWTElement(char key) {
  this->key = key;
}

void BWTElement::updatePrev(BWTElement *el) {
  prev = el;  
}

void BWTElement::updateNext(BWTElement *el) {
  next = el;  
}

// Compare elements.
// Rules:
// - The termination char is always smallest.
// - If a char is alphabetically smaller than another, it should occur first.
// - If two chars are the same, we split the tie recursively according to their next
// chars.
bool BWTElement::compareElements(BWTElement *e1, BWTElement *e2) {
  if (e1->key == '\0')
    return true;
  else if (e1->key == e2->key) {
    if (e1->next == NULL)
      return true;
    else if (e2->next == NULL)
      return false;

    return compareElements(e1->next, e2->next);
  }

  return (e1->key < e2->key);
}
