#include "HuffmanNode.h"

HuffmanNode::HuffmanNode(char character, unsigned int freq) {
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

bool HuffmanNode::compareNodes(HuffmanNode *left, HuffmanNode *right) {
  return (left->freq > right->freq);
}
