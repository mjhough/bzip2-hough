#include "MoveToFrontTransform.h"

// Constructor
MoveToFrontTransform::MoveToFrontTransform(std::string in) {
	input = in;
  output = "";

  // Insert the special termination character used in
  // BWT
	dictionary.insert(0, 1, '\000');  
}

void MoveToFrontTransform::encode(void) {
	for (unsigned int i=0; i < input.length(); i++) {
		std::size_t found = dictionary.find(input[i]);
		if (found == std::string::npos) {
			throw "Invalid input: not in dictionary.";
      return;
    }

		// Delete character from existing spot in dictionary
		dictionary.erase(found,1);

		// Put character at front of dictionary
		dictionary.insert(0, 1, input[i]);

    // Add accessed value to output as per algorithm
    output.append(std::to_string(found));
    if (i+1 < input.length()) {
      // Don't append space at very end
      output.append(" ");
    }
	}
}
