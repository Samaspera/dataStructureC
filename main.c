#include <stdio.h>
#include "./libs/SequenceList.h"

void testSequenceList();

int main() {
    testSequenceList();
    return 0;
}

void testSequenceList() {
    int i, a[101];
    for (i = 0; i < 101; i++) {
        a[i] = i + 1;
    }
    SequenceList *list = createList(a, 101);
    if(list->length < 101) {
        printf("failed");
        return;
    }
    ElemType e[list->length];
    traverse(*list, e);
    for (i = 0; i < list->length; i++) {
        printf("%d ", e[i].data);
    }
}
