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
    length = 16777216; // 64 MB of data (16,777,216 elements * sizeof(wchar_t) = 134,217,728 bytes)
    target = (Py_UNICODE *)calloc(length, sizeof(Py_UNICODE));
    if (!target) {
        exit(1);
    }
}

__attribute__((constructor))
static void constructor_init() {
    init_vars();
}