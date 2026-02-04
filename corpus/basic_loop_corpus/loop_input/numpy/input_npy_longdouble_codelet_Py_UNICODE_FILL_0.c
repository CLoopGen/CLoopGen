#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <string.h>

typedef wchar_t Py_UNICODE;
typedef ssize_t Py_ssize_t;

Py_UNICODE *target;
Py_UNICODE value;
Py_ssize_t length;
Py_ssize_t i;

void init_vars() {
    length = 67108864; // 64 million elements, roughly 128MB for wchar_t (2 bytes), targets ~0.01s on modern CPUs
    value = L'A';

    target = (Py_UNICODE*)calloc(length, sizeof(Py_UNICODE));
    if (!target) {
        exit(1);
    }

    i = 0;
}