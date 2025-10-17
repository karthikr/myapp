#ifndef MYLIB_H
#define MYLIB_H

#ifdef __cplusplus
extern "C" {
#endif

// Add
int add(int a, int b);

// Divide
typedef enum {
    DIV_SUCCESS = 0,
    DIV_ERR_NULL_PTR,
    DIV_ERR_DIV_BY_ZERO
} DivStatus;
DivStatus mydiv(int a, int b, int *result);

#ifdef __cplusplus
}
#endif

#endif
