#include <stdlib.h>
#include <stddef.h>
#include <wchar.h>

typedef wchar_t Py_UNICODE;
typedef ssize_t Py_ssize_t;

Py_UNICODE *target;
Py_UNICODE value;
Py_ssize_t length;
Py_ssize_t i;

void init_vars() {
    length = 16777216; // 16 million elements, ~32MB for wchar_t (assuming 2 bytes)
    value = L'A';
    target = (Py_UNICODE *)calloc(length, sizeof(Py_UNICODE));
    i = 0;
}