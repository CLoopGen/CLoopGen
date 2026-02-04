#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <wchar.h>

typedef wchar_t Py_UNICODE;
typedef ssize_t Py_ssize_t;

Py_UNICODE *target;
Py_UNICODE value;
Py_ssize_t length;
Py_ssize_t i;

void init_vars() {
    length = 67108864 / sizeof(Py_UNICODE);  // ~256MB / sizeof(wchar_t) elements
    value = L'A';
    target = (Py_UNICODE *)calloc(length, sizeof(Py_UNICODE));
    if (!target) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
}