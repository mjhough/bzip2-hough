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

  std::cout << std::endl << "Burrows-Wheeler transform output:" << std::endl;
  BurrowsWheelerTransform bwt(in);
  bwt.perform();
  std::cout << bwt.getOutput() << std::endl << std::endl;

  std::cout << "Move-to-front transform output:" << std::endl;
  MoveToFrontTransform mtf(bwt.getOutput());
  mtf.encode();
  std::cout << mtf.getOutput() << std::endl << std::endl;

  std::cout << "Run-length encoding output:" << std::endl;
  RunLengthEncoding rle(mtf.getOutput());
  rle.encode();
  std::cout << rle.getOutput() << std::endl << std::endl;

  std::cout << "Huffman encoding output:" << std::endl;
  HuffmanEncoding he(rle.getOutput());
  he.buildTrie();
  std::cout << he.getOutput() << std::endl;

  return 0;
}
