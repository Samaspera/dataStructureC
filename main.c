#include <stdio.h>
#include <malloc.h>
#include "libs/SequenceList.h"
#include "libs/LinkedList.h"

void testSequenceList();

void testLinkedList();

int main() {
    testLinkedList();
    return 0;
}

void testSequenceList() {
    int i, a[101];
    for (i = 0; i < 101; i++) {
        a[i] = i + 1;
    }
    SequenceList *list = createSequenceList(a, 101);
    if (list->length < 101) {
        printf("failed");
        return;
    }
    ElemType e[list->length];
    traverseSequenceList(*list, e);
    for (i = 0; i < list->length; i++) {
        printf("%d ", e[i].data);
    }
}

void testLinkedList() {
    int i, a[101];
    for (i = 0; i < 101; i++) {
        a[i] = i + 1;
    }
    LinkedList list = createReverseLinkedList(a, 101);
    int length = list->data.data;
    int rank = 1;
    ElemType e[length];;
    traverseLinkedList(list, e);
    for (i = 0; i < length; i++) {
        printf("%d ", e[i].data);
    }
    printf("\n");
    ElemType front = newElement2(123, 1234);
//    if(!behindInsertInLinkedList(list, front, rank)) {
//        printf("error");
//        return;
//    }
    printf("\n");
    if(!frontInsertInLinkedList(list, front, rank)) {
        printf("error");
        return;
    }
    ElemType e1[length + 1];
    traverseLinkedList(list, e1);
    for (i = 0; i <= length; i++) {
        printf("%d ", e1[i].data);
    }
}
