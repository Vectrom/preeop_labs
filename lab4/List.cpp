#include "List.h"
#include <iostream>

void prepare(List *list_pointer) {
    list_pointer->head = list_pointer->tail = nullptr;
}

void add(List *list_pointer, const char *buffer) {
    Node *newNode = new_node(buffer);
    
    if(empty(list_pointer))
        list_pointer->head = list_pointer->tail = newNode;
    else {
        list_pointer->tail->next = newNode;
        list_pointer->tail = newNode;
    }
}

bool empty(const List *list_pointer) {
    if(list_pointer->head == nullptr)
        return true;
    return false;
}

void dump(const List *list_pointer) {
    if(empty(list_pointer))
        return;

    Node *p = list_pointer->head;

    while(p != nullptr)     {
        std::cout << p->data << " ";
        p = p->next;
    }
}

void clear(List *list_pointer) {
    if(empty(list_pointer))
        return;

    Node *p = list_pointer->head;
    Node *nextNode;

    while(p != nullptr) {
        nextNode = p->next;
        free(p->data);
        free(p);
        p = nextNode;
    }
        
    list_pointer->head = list_pointer->tail = nullptr;
}

Node *new_node(const char *buffer) {
    int size = strlen(buffer) + 1;

    Node *newNode = (Node *) malloc (sizeof(Node));
    newNode->data = (char *) malloc(sizeof(char) * size);
    newNode->next = nullptr;
    
    strcpy(newNode->data, buffer);
    return newNode;
}