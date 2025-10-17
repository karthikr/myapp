#ifndef MYLIB_H
#define MYLIB_H

int add(int a, int b);

typedef enum {
    DIV_SUCCESS = 0,
    DIV_ERR_NULL_PTR,
    DIV_ERR_DIV_BY_ZERO
} DivStatus;

DivStatus mydiv(int a, int b, int *result);

#endif
