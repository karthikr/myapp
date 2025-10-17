#include "../src/mylib.h"
#include <glib.h>

static void test_add(void) {
  g_assert_cmpint(add(2, 3), ==, 5);
  g_assert_cmpint(add(-1, 1), ==, 0);
}

int main(int argc, char **argv) {
  g_test_init(&argc, &argv, NULL);
  g_test_add_func("/mylib/add", test_add);
  return g_test_run();
}
