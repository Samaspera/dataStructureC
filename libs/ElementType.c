#include "ElementType.h"

/**
 * init a element by data
 * @param d data
 * @return new element
 */
ElemType newElement(int d) {
    ElemType e;
    e.id = DEFAULT;
    e.data = d;
    return e;
}

/**
 * init a element by all params
 * @param i id
 * @param d data
 * @return new element
 */
ElemType newElement2(int i, int d) {
    ElemType e;
    e.id = i;
    e.data = d;
    return e;
}

/**
 * return a error element
 * @return error element
 */
ElemType error() {
    ElemType e;
    e.id = ERROR;
    e.data = ERROR;
    return e;
}

/**
 * judge if two element is equal
 * @return equal or not
 */
bool eq(ElemType a, ElemType b) {
    return a.id == b.id && a.data == b.data;
}