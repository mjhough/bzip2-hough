#include "MoveToFrontTransform.h"

// Constructor
MoveToFrontTransform::MoveToFrontTransform(std::string in) {
	input = in;
  output = "";
	dictionary.insert(0, 1, '\000');
}

void MoveToFrontTransform::encode(void) {
	for (unsigned int i=0; i < input.length(); i++) {
		std::size_t found = dictionary.find(input[i]);
		if (found == std::string::npos)
			throw "Invalid input: not in dictionary.";

		// Delete character from existing spot in dictionary
		dictionary.erase(found,1);

		// Put character at front of dictionary
		dictionary.insert(0, 1, input[i]);

    // Add accessed value to output as per algorithm
    output.append(std::to_string(found));
    output.append(" ");
	}
}
