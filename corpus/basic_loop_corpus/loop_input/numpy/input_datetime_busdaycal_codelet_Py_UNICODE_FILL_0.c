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
    length = 131072; // 131072 * sizeof(wchar_t) = 262144 bytes (~0.25 MB), suitable for ~0.01 sec runtime
    value = L'A';
    target = (Py_UNICODE *)calloc(length, sizeof(Py_UNICODE));
    i = 0;
}