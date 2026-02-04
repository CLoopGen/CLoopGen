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
    length = 16777216; // 16 million elements ~ 64 MB for wchar_t (4 bytes each on many systems)
    target = (Py_UNICODE *)calloc(length, sizeof(Py_UNICODE));
    if (!target) {
        exit(1);
    }
    i = 0;
}