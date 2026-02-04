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
    length = 134217728 / sizeof(Py_UNICODE);  // ~128MB of data, assuming sizeof(wchar_t) is typically 4 on many systems
    value = L'A';

    target = (Py_UNICODE *)calloc(length, sizeof(Py_UNICODE));
    if (!target) {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(1);
    }
}

__attribute__((constructor))
static void constructor_init() {
    init_vars();
}