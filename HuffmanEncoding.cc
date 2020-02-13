#include "HuffmanEncoding.h"

HuffmanEncoding::HuffmanEncoding(std::string in) {
  input = in;
  output = "";
}

void HuffmanEncoding::buildTrie(void) {
  computeFrequencies();
}

void HuffmanEncoding::computeFrequencies(void) {
  unsigned int i = 0;
  while (i < input.length()) {
    std::string val;
    if (input[i+1] == ' ' || i+1 >= input.length()) {
      // One digit number
      val.push_back(input[i]);
      i += 2;
    } else if (input[i+2] == ' ' || i+2 >= input.length()) {
      // Two digit number
      val.push_back(input[i]);
      val.push_back(input[i+1]);
      i += 3;
    } else if (input[i+1] == '\\') {
      // One digit number with RLE repeats
      val.push_back(input[i]);

      std::string reps_str;
      unsigned int j = 0;
      // Check for number of digits after marker
      while (input[i+j+2] != ' ' && i+j+2 < input.length()) {
        reps_str.push_back(input[i+j+2]);
        j++;
      }
      int reps = std::stoi(reps_str);

      // Add repetitions to frequency
      // extra one will be handled later
      frequencies[val] += reps;

      i += j+3;
    } else if (input[i+2] == '\\') {
      // Two digit number with RLE repeats
      val.push_back(input[i]);
      val.push_back(input[i+1]);

      val.push_back(input[i]);

      std::string reps_str;
      unsigned int j = 0;
      // Check for number of digits after marker
      while (input[i+j+3] != ' ' && i+j+3 < input.length()) {
        reps_str.push_back(input[i+j+3]);
        j++;
      }
      int reps = std::stoi(reps_str);

      // Add repetitions to frequency
      // extra one will be handled later
      frequencies[val] += reps;

      i += j+3;
    }

    // Change frequency map
    if (frequencies.count(val) > 0) {
      // Key found in frequencies map
      frequencies[val]++;
    } else {
      // Key not found in frequencies map
      // Add it
      frequencies[val] = 1;
    }
  }
}
