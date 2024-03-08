#include "ElementType.h"

#ifndef DATASTRUCTUREINC_LINKEDLIST_H
#define DATASTRUCTUREINC_LINKEDLIST_H

#define HEAD 12345

typedef struct LinkNode {
    ElemType data;
    struct LinkNode *next;
} LinkNode, *LinkedList;

//init a linked list
LinkedList initLinkedList();

//insert an element from head
bool headInsert(LinkedList list, ElemType e);

//insert an element from tail
bool tailInsert(LinkedList list, ElemType e);

//insert an element into any position of a linked list(behind)
bool behindInsertInLinkedList(LinkedList list, ElemType e, int rank);

//insert an element into any position of a linked list(front)
bool frontInsertInLinkedList(LinkedList list, ElemType e, int rank);

//create a linked list in normal order
LinkedList createNormalLinkedList(const int a[], int size);

//create a linked list in reverse order
LinkedList createReverseLinkedList(const int a[], int size);

//get element by rank in a linked list
LinkNode *getElementInLinkedList(LinkedList list, int i);

//delete a element by rank in given linked list and return it
ElemType deleteElementInLinkedList(LinkedList list, int i);

//destroy a linked list
void destroyLinkedList(LinkedList);

//traverse a linked list
void traverseLinkedList(LinkedList list, ElemType *res);

#endif //DATASTRUCTUREINC_LINKEDLIST_H