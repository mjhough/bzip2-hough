#include "RunLengthEncoding.h"
#include <iostream>

RunLengthEncoding::RunLengthEncoding(std::string in) {
  input = in;
  output = "";
}

void RunLengthEncoding::encode(void) {
  int last_num = -1; // placeholder. -1 cannot be in input
  int run_length = 0;
  unsigned int i = 0;
  int num_count = 0;
  while (i < input.length()) {
    std::string num_str;
    int num;
    bool final_num = false;

    if (i+1 >= input.length())
      final_num = true;
    else if (input[i+1] != ' ' && i+2 >= input.length())
      final_num = true;

    if (input[i+1] == ' ' || i+1 >= input.length()) {
      // One digit number
      num_str.push_back(input[i]);
      num = std::stoi(num_str);
      i += 2;
    } else if (input[i+2] == ' ' || i+2 >= input.length()) {
      // Two digit number
      num_str.push_back(input[i]);
      num_str.push_back(input[i+1]);
      num = std::stoi(num_str);
      i += 3;
    } else {
      throw "Malformed input to RLE.";
      return;
    }

    // We have found another number. Increase count.
    num_count++;

    // If there has been a number switch, handle it
    if (num != last_num && num_count > 1) {
      // First handle last run length
      int j = 0;
      if (run_length >= 4) {
        int rep = run_length - 4;
        while (j < 4) {
          output.append(std::to_string(last_num));
          if (j+1 < 4)
            output += " ";
          j++;
        }
        output.append("\\" + std::to_string(rep) + " ");
      } else {
        while (j < run_length) {
          output.append(std::to_string(last_num) + " ");
          j++;
        }
      }

      // Reset run length
      run_length = 0;
    }

    // Increase the run length. This always happens.
    run_length++;

    // If we are at the final number, we aren't going to loop
    // again and we know we are at the max run length. So deal with it.
    if (final_num) {
      int j = 0;
      if (run_length >= 4) {
        int rep = run_length - 4;
        while (j < 4) {
          output.append(std::to_string(num));
          j++;
        }
        output.append("\\" + std::to_string(rep));
      } else {
        while (j < run_length) {
          output.append(std::to_string(num));
          j++;
        }
      }
    }

    // Finally set new last_num
    last_num = num;
  }
}
