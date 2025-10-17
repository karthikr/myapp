#include "mylib.h"
#include <stddef.h>

int add(int a, int b) {
    return a + b;
}

DivStatus mydiv(int a, int b, int *result) {
    if (result == NULL) {
        return DIV_ERR_NULL_PTR;
    }
    if (b == 0) {
        return DIV_ERR_DIV_BY_ZERO;
    }

    *result = a / b;
    return DIV_SUCCESS;
}
