project(
    'myapp',
    ['c', 'cpp'],
    default_options: {
        'debug': true,
        'optimization': 'g',
        'warning_level': '3',
        'werror': true,
        'c_std': 'c17',
        'cpp_std': 'c++17',
        'b_ndebug': 'if-release',
        'tests': not meson.is_subproject(),
    },
    version: '0.14.0',
    meson_version: '>=1.4.0',
)

# headers
mylib_inc = include_directories('src')

# library
mylib_a = static_library(
    'mylib',
    files('src/mylib.c'),
    include_directories: mylib_inc,
)

# main
main_exe = executable(
    'myapp',
    files('src/main.c'),
    link_with: mylib_a,
    include_directories: mylib_inc,
)

# tests using glib
glib_dep = dependency('glib-2.0')
test_exe = executable(
    'test_mylib',
    files('tests/test_mylib.c'),
    dependencies: [glib_dep],
    link_with: mylib_a,
    include_directories: mylib_inc,
)

test('mylib unit test', test_exe)

# tests using gtest (required) / gmock (optional)
gtest_dep = dependency('gtest', required: true)
gtest_main_dep = dependency('gtest_main', required: true)
gmock_dep = dependency('gmock', required: false)

test_g_exe = executable(
    'test_mylib_g',
    files('tests/test_mylib_g.cpp'),
    dependencies: [gtest_dep, gtest_main_dep],
    link_with: mylib_a,
    include_directories: mylib_inc,
    cpp_args: ['-Wno-cpp'],
)

test('mylib gtest unit test', test_g_exe)
