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
    length = 16777216;  // 16M elements * sizeof(wchar_t) = 32MB (assuming 4-byte wchar_t on Linux)
    value = L'A';
    
    target = (Py_UNICODE*)calloc(length, sizeof(Py_UNICODE));
    if (!target) {
        exit(1);
    }
}