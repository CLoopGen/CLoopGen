#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <wchar.h>
#include <string.h>
#include <time.h>

typedef wchar_t Py_UNICODE;
typedef ssize_t Py_ssize_t;

Py_UNICODE *target;
Py_UNICODE value;
Py_ssize_t length;
Py_ssize_t i;

void init_vars() {
    value = L'A';
    length = 67108864; // 64 million elements ≈ 128 MB for wchar_t (2 bytes on most systems, but use 4-byte safety)
    target = (Py_UNICODE *)calloc(length, sizeof(Py_UNICODE));
    if (!target) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    i = 0;
}