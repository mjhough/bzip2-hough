#include "HuffmanNode.h"

HuffmanNode::HuffmanNode(std::string character, unsigned int freq) {
  this->character = character;
  this->freq = freq;

  // Initialize with no left and right nodes
  left = right = NULL;
}

void HuffmanNode::updateLeft(HuffmanNode *left) {
  this->left = left;
}

void HuffmanNode::updateRight(HuffmanNode *right) {
  this->right = right;
}
