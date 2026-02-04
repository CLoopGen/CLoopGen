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
    length = 16777216; // 16M elements, approximately 32MB for wchar_t (assuming 2 bytes), target ~0.01s runtime
    value = L'A';
    target = (Py_UNICODE*)calloc(length, sizeof(Py_UNICODE));
    if (!target) {
        exit(1);
    }
}