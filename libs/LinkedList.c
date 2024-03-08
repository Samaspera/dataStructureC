#include "LinkedList.h"
#include <stdlib.h>


/** v0.1 tested
 * init a linked list
 * @return pointer of a linked list head pointer
 */
LinkedList initLinkedList() {
    LinkNode *head = (LinkNode *) malloc(sizeof(LinkNode));
    ElemType h = newElement2(HEAD, 0);  //data field of a head node is the length of this linked list
    head->data = h;
    head->next = NULL;
    return head;
}

/** v0.1 tested
 * insert an element from head
 * @param list the list to be inserted
 * @param e the element to insert
 */
bool headInsert(LinkedList list, ElemType e) {
    LinkNode *node = (LinkNode *) malloc(sizeof(LinkNode));
    if (!node) return false;
    node->data = e;
    node->next = list->next;
    list->next = node;
    list->data.data++;
    return true;
}

/** v0.1 tested
 * insert an element from tail
 * @param list the list to be inserted
 * @param e e the element to insert
 */
bool tailInsert(LinkedList list, ElemType e) {
    LinkNode *node = (LinkNode *) malloc(sizeof(LinkNode));
    if (!node) return false;
    node->data = e;
    LinkNode *rear = list;  //rear pointer of a linked list
    while (rear->next) {
        rear = rear->next;
    }
    rear->next = node;
    node->next = NULL;
    list->data.data++;
    return true;
}

/** v0.1 tested
 * insert an element into any position of a linked list(behind)
 * @param list the linked list to be inserted
 * @param e the element to insert
 * @param rank position
 * @return
 */
bool behindInsertInLinkedList(LinkedList list, ElemType e, int rank) {
    if(!list || rank < 1 || rank > list->data.data) return false;
    LinkNode *element = getElementInLinkedList(list, rank);
    LinkNode *node = (LinkNode *) malloc(sizeof(LinkNode));
    node->data = e;
    node->next = element->next;
    element->next = node;
    return true;
}

/** v0.1 tested
 * insert an element into any position of a linked list (front)
 * @param list the linked list to be inserted
 * @param e the element to insert
 * @param rank position
 * @return
 */
bool frontInsertInLinkedList(LinkedList list, ElemType e, int rank) {
    if(!list || rank < 1 || rank > list->data.data) return false;
    LinkNode *previous = getElementInLinkedList(list, rank);
    ElemType p = previous->data;
    if(!behindInsertInLinkedList(list, e, rank)) return false;
    previous->next->data = p;
    previous->data = e;
    return true;
}

/**
 * create a linked list in normal order using tail insert
 * @param a the data to create a linked list
 * @param size the length of the data array
 * @return the result linked list
 */
LinkedList createNormalLinkedList(const int a[], int size) {
    LinkedList head = initLinkedList();
    LinkNode *rear = head;
    int i;
    for (i = 0; i < size; i++) {
        LinkNode *node = (LinkNode *) malloc(sizeof(LinkNode));
        node->next = NULL;
        node->data.id = i;
        node->data.data = a[i];
        rear->next = node;
        rear = node;
    }
    head->data.data = size;
    return head;
}

/** v0.1 tested
 * create a linked list in reverse order using head insert
 * @param a the data to create a linked list
 * @param size the length of the data array
 * @return a linked list in reverse order
 */
LinkedList createReverseLinkedList(const int a[], int size) {
    LinkedList list = (LinkNode *) malloc(sizeof(LinkNode));
    list->data = newElement2(HEAD, 0);
    list->next = NULL;
    int i;
    for (i = 0; i < size && headInsert(list, newElement2(i, a[i])); i++);
    return list;
}

/** v0.1 tested
 * get element by rank in a linked list
 * @param list the linked list to be checked
 * @param i rank of the element
 * @return the node
 */
LinkNode *getElementInLinkedList(LinkedList list, int i){
    if(!list) return NULL;
    LinkNode *temp = list->next;
    while(temp && (i - 1)) {
        temp = temp->next;
        i--;
    }
    if(!temp) return NULL;  //if out of range return null
    return temp;
}

/**
 * delete a element by rank in given linked list and return it
 * @param list the list to be operated
 * @param i the rank of element to be deleted
 * @return the element to be deleted
 */
ElemType deleteElementInLinkedList(LinkedList list, int i) {
    LinkNode *temp = list->next;

}

//destroy a linked list
void destroyLinkedList(LinkedList) {
    
}

/**
 * traverse a linked list
 * @param list the list to be traversed
 * @param res the result of the traversal
 */
void traverseLinkedList(LinkedList list, ElemType res[]) {
    if (!res || !list) return;
    LinkNode *temp = list->next;
    int i = 0;
    while (temp) {
        res[i++] = temp->data;
        temp = temp->next;
    }
}