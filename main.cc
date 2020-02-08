#include <iostream>
#include <string>

#include "BurrowsWheelerTransform.h"

int main(int argc, char *argv[]) {
  std::string in;
  std::cout << "Enter string to perform BWT on: ";
  std::getline(std::cin, in);
  BurrowsWheelerTransform bwt(in);
  bwt.perform();
  std::cout << bwt.getOutput() << std::endl;

  return 0;
}
