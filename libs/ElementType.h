#include <stdbool.h>

#ifndef DATASTRUCTUREINC_ELEMENTTYPE_H
#define DATASTRUCTUREINC_ELEMENTTYPE_H

#define DEFAULT 1
#define ERROR -1

typedef struct ElemType {
    //custom data type
    int id;
    int data;
} ElemType;

//init a element
ElemType newElement(int d);

//init a element by all params
ElemType newElement2(int i, int d);

//error element
ElemType error();

//judge if two element is equal
bool eq(ElemType a, ElemType b);

#endif //DATASTRUCTUREINC_ELEMENTTYPE_H