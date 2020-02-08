#include <string>

class BWTElement {
  public:
    char key;
    BWTElement *prev;
    BWTElement *next;

    BWTElement(char key);
    BWTElement(char key, BWTElement *prev);
    void updatePrev(BWTElement *el);
    void updateNext(BWTElement *el);
    static bool compareElements(BWTElement *e1, BWTElement *e2);
};
