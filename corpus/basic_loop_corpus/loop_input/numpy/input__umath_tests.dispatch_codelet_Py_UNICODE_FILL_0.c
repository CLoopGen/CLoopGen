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
    value = L'A';
    length = 67108864; // ~256MB / sizeof(wchar_t) assuming 4-byte wchar_t
    target = (Py_UNICODE*)calloc(length, sizeof(Py_UNICODE));
    if (!target) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
}

__attribute__((constructor))
static void constructor_init() {
    init_vars();
}