#include <iostream>
#include <string>

#include "BurrowsWheelerTransform.h"
#include "MoveToFrontTransform.h"
#include "RunLengthEncoding.h"
#include "HuffmanEncoding.h"

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

  RunLengthEncoding rle(mtf.getOutput());
  rle.encode();
  std::cout << rle.getOutput() << std::endl;

  HuffmanEncoding he(rle.getOutput());
  he.buildTrie();
  std::cout << rle.getOutput() << std::endl;

  return 0;
}
