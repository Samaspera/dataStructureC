#include <stdlib.h>
#include "SequenceList.h"

/** tested v0.1
 * init a sequence list
 * @return pointer of the sequence list
 */
SequenceList *initList() {
    SequenceList *sqList = (SequenceList *) malloc(sizeof(SequenceList));
    sqList->maxSize = INIT_SIZE;
    sqList->data = (ElemType *) malloc(sizeof(ElemType) * INIT_SIZE);
    sqList->length = 0;
    return sqList;
}

/** tested v0.1
 * create a sequence list quickly
 * @param a array
 * @param length the length of array
 * @return pointer of a sequence list
 */
SequenceList *createList(const int a[], int length) {
    SequenceList *list = initList();
    int i;
    for (i = 1; i <= length; i++) {
        ElemType e;
        e.id = i;
        e.data = a[i - 1];
        if (!insertElement(list, e, i)) {  //if insert failed, return the list incompletely
            return list;
        }
    }
    return list;
}

/**
 * increase capacity of a sequence list
 * @param sqList origin sequence list
 * @param capacity new added capacity
 * @return pointer of new sequence list
 */
SequenceList *increaseList(SequenceList *sqList, int capacity) {
    SequenceList *newList = (SequenceList *) malloc(sizeof(SequenceList));
    newList->length = sqList->length;
    newList->maxSize = sqList->maxSize + capacity;
    newList->data = (ElemType *) malloc(sizeof(ElemType) * newList->maxSize);
    int i;
    for (i = 0; i < sqList->length; i++) {
        newList[i] = sqList[i];
    }
    free(sqList);
    return newList;
}

/** tested v0.1
 * insert a element by rank
 * @param sqlist the sequence list to be inserted
 * @param e the element to insert
 * @param i rank
 * @return inserted sequence list
 */
bool insertElement(SequenceList *sqlist, ElemType e, int i) {
    if (i > sqlist->length + 1) return false;  //overflowed
    if (sqlist->length >= sqlist->maxSize) return false;
    int j;
    for (j = sqlist->length; j >= i; j--) {
        sqlist->data[j] = sqlist->data[j - 1];
    }
    sqlist->data[i - 1] = e;
    sqlist->length++;
    return true;
}

/**
 * return a element by given rank
 * @param list original sequence list
 * @param i element rank
 * @return element
 */
ElemType getElem(SequenceList list, int i) {
    if (i >= list.length || i <= 0) return error();  //if out of index, return error
    return list.data[i - 1];
}

/**
 * delete an element by given rank
 * @param list original list
 * @param i element rank
 * @return deleted element
 */
ElemType deleteElement(SequenceList *list, int i) {
    if (i >= list->length || i <= 0) return error();
    ElemType e;
    e = list->data[i - 1];
    int j;
    for (j = i; j < list->length; j++) {
        list->data[j - 1] = list->data[j];
    }
    list->length--;
    return e;
}

/**
 * destroy a list
 * @param list the sequence list to be destroyed
 */
void destroyList(SequenceList *list) {
    free(list->data);
    free(list);
}

/** tested v0.1
 * traverse the list
 * @param list
 * @param res the result of traverse
 */
void traverse(SequenceList list, ElemType *res) {
    int i;
    for (i = 0; i < list.length; i++) {
        res[i] = list.data[i];
    }
}