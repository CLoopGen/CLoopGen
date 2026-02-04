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
    length = 16777216; // 16 million elements, ~32 MB for wchar_t (assuming 2 or 4 bytes)
    target = (Py_UNICODE*)calloc(length, sizeof(Py_UNICODE));
    if (!target) {
        exit(1);
    }
    value = L'A';
    i = 0;
}