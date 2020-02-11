#include <iostream>
#include <string>

#include "BurrowsWheelerTransform.h"
#include "MoveToFrontTransform.h"

int main(int argc, char *argv[]) {
  std::string in;
  std::cout << "Enter string to perform BWT on: ";
  std::getline(std::cin, in);
  BurrowsWheelerTransform bwt(in);
  bwt.perform();
  std::cout << bwt.getOutput() << std::endl;

  MoveToFrontTransform mtf(bwt.getOutput());
  mtf.encode();
  std::cout << mtf.getOutput() << std::endl;

  return 0;
}
