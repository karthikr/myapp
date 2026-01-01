#include "mylib.h"
#include <stddef.h>
#include <stdlib.h>

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

    // clobber
    // Use: meson setup build -Db_sanitize=address --reconfigure
    // Then: meson test -C build --print
    *(result - 1) = a; // underflow

    // leak
    // Use: meson setup build -Db_sanitize=leak --reconfigure
    // Then: meson test -C build --print
    // Or
    // Use: meson setup build --reconfigure
    // Then: meson test -C build --print --wrap 'valgrind --leak-check=full'
    //   Or: ninja -C build clang-tidy
    //   Or: ninja -C build scan-build
    int *test = calloc(1, sizeof(int));
    *test = *result;

    return DIV_SUCCESS;
}
