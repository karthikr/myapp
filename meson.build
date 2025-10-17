project(
    'myapp',
    'c',
    default_options: {
        'debug': true,
        'optimization': 'g',
        'warning_level': '3',
        'werror': true,
        'c_std': 'c17',
        'b_ndebug': 'if-release',
        'tests': not meson.is_subproject(),
    },
    version: '0.14.0',
    meson_version: '>=1.4.0',
)

executable('myapp', files('src/main.c', 'src/mylib.c'))

test_exe = executable(
    'test_mylib',
    files('src/mylib.c', 'tests/test_mylib.c'),
    dependencies: [dependency('glib-2.0')],
)

test('mylib unit test', test_exe)
