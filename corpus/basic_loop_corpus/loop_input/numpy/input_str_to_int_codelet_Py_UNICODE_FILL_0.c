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
    length = 67108864 / sizeof(Py_UNICODE);  // ~64MB of data to target ~0.01s on typical modern CPU
    target = (Py_UNICODE *)aligned_alloc(_Alignof(Py_UNICODE), length * sizeof(Py_UNICODE));
    if (!target) {
        exit(1);
    }
    memset(target, 0, length * sizeof(Py_UNICODE));
}