#ifndef DATASTRUCTUREINC_SEQUENCELIST_H
#define DATASTRUCTUREINC_SEQUENCELIST_H

#endif //DATASTRUCTUREINC_SEQUENCELIST_H

#include <stdbool.h>
#include "ElementType.h"

#define INIT_SIZE 100

//dynamic sequence list
typedef struct {
    ElemType *data;
    int length, maxSize;
} SequenceList;

//note that rank = index + 1

//init a sequence list
SequenceList *initSequenceList();

//create a sequence list quickly
SequenceList *createSequenceList(const int a[], int length);

//increase capacity of a sequence list
SequenceList *increaseSequenceList(SequenceList *sqList, int capacity);

//insert a element by rank
bool insertElementInSequenceList(SequenceList *sqlist, ElemType e, int i);

//get element by given rank
ElemType getElemInSequenceList(SequenceList list, int i);

//delete an element by given rank
ElemType deleteElementInSequenceList(SequenceList *list, int i);

//destroy a list
void destroySequenceList(SequenceList *list);

//traverse the list
void traverseSequenceList(SequenceList list, ElemType *res);