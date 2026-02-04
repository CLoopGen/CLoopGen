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
    length = 67108864; // 64M elements * sizeof(wchar_t) = 128MB, target ~0.01s on modern CPU
    target = (Py_UNICODE *)aligned_alloc(_Alignof(Py_UNICODE), length * sizeof(Py_UNICODE));
    if (!target) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    memset(target, 0, length * sizeof(Py_UNICODE));
}