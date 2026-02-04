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
    length = 67108864 / sizeof(Py_UNICODE);  // ~256MB / sizeof(wchar_t), assuming 4-byte wchar_t -> 16M elements
    if (sizeof(Py_UNICODE) == 2) {
        length = 134217728;  // 256MB / 2 = 134M elements
    }

    target = (Py_UNICODE*)aligned_alloc(32, length * sizeof(Py_UNICODE));
    if (!target) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    value = L'A';

    for (Py_ssize_t j = 0; j < length; j++) {
        target[j] = 0;
    }
}