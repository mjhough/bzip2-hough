#include "HuffmanEncoding.h"

HuffmanEncoding::HuffmanEncoding(std::string in) {
  input = in;
  output = "";
}

HuffmanEncoding::~HuffmanEncoding(void) {
  while (!minHeap.empty()) {
    delete minHeap.top();
    minHeap.pop();
  }
}

void HuffmanEncoding::buildTrie(void) {
  computeFrequencies();

  for (auto const &pair : frequencies) {
    minHeap.push(new HuffmanNode(pair.first, pair.second));
  }

  while (minHeap.size() != 1) {
    // Get two smallest frequency
    // nodes and join them to create
    // a new trie with a dummy node
    HuffmanNode *left = minHeap.top();
    minHeap.pop();
    HuffmanNode *right = minHeap.top();
    minHeap.pop();

    // New frequency is sum of below.
    // Give empty string as character value
    HuffmanNode *sub_root = new HuffmanNode("", left->freq + right->freq);
    sub_root->left = left;
    sub_root->right = right;
    minHeap.push(sub_root);
  }

  unsigned int i = 0;
  while (i < input.length()) {
    std::string val;
    unsigned int num_times = 1;
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

      // Add to num_times for later loop
      num_times += std::stoi(reps_str);

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

      // Add to num_times for later loop
      num_times += std::stoi(reps_str);

      i += j+3;
    }

    // Generate the code and add to the output
    while (num_times > 0) {
      generateCode(minHeap.top(), "", val);
      num_times--;

      // Add a space between codes for readability
      // Except for last one
      if (i < input.length())
        output.append(" ");
    }
  }
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

// Generate code for given character and append it to the output
void HuffmanEncoding::generateCode(HuffmanNode *root, std::string str, std::string character) {
  // Check if exists
  if (root == NULL)
    return;

  // If the node we want, add to output
  if (root->character == character) {
    output.append(str);
  }

  // Follow left and right paths with 0 for left and 1 for right
  generateCode(root->left, str + "0", character);
  generateCode(root->right, str + "1", character);
}
