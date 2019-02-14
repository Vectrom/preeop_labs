#include "Node.h"
#include <iostream>

	Node::Node(const int data) : _data(data), _nextNode(nullptr) {}

	int Node::data() const{
		return _data;
	}

	Node * Node::getNextNode() const {
		return _nextNode;
	}

	void Node::setNextNode(Node *node) {
		_nextNode = node;
	}
