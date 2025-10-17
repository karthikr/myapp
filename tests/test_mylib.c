#include "mylib.h"
#include <glib.h>

static void test_add(void) {
    g_assert_cmpint(add(2, 3), ==, 5);
    g_assert_cmpint(add(-1, 1), ==, 0);
}

static void test_div_success(void) {
    int res = 0;
    DivStatus status = mydiv(10, 2, &res);
    g_assert_cmpint(status, ==, DIV_SUCCESS);
    g_assert_cmpint(res, ==, 5);
}

static void test_div_by_zero(void) {
    int res = 0;
    DivStatus status = mydiv(10, 0, &res);
    g_assert_cmpint(status, ==, DIV_ERR_DIV_BY_ZERO);
}

static void test_null_result_ptr(void) {
    DivStatus status = mydiv(10, 2, NULL);
    g_assert_cmpint(status, ==, DIV_ERR_NULL_PTR);
}

int main(int argc, char **argv) {
    g_test_init(&argc, &argv, NULL);
    g_test_add_func("/mylib/add", test_add);
    g_test_add_func("/mylib/div", test_div_success);
    g_test_add_func("/mylib/div_by_zero", test_div_by_zero);
    g_test_add_func("/mylib/div_null_ptr", test_null_result_ptr);
    return g_test_run();
}
