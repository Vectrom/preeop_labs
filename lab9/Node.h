#pragma once

class Node {

public:
	Node(const int data);

	int data() const;

	Node * getNextNode() const;

	void setNextNode(Node *node);

private:
	int _data;
	Node *_nextNode;

};