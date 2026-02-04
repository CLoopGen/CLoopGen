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
    length = 67108864 / sizeof(Py_UNICODE);  // ~64MB of data to target ~0.01s runtime on modern CPU
    value = L'A';

    target = (Py_UNICODE *)calloc(length, sizeof(Py_UNICODE));
    if (!target) {
        exit(1);
    }

    i = 0;
}