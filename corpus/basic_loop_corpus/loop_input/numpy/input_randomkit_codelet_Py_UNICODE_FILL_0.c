#include <stddef.h>
#include <stdlib.h>

typedef wchar_t Py_UNICODE;
typedef ssize_t Py_ssize_t;

Py_UNICODE *target;
Py_UNICODE value;
Py_ssize_t length;
Py_ssize_t i;

void init_vars() {
    length = 131072; // ~256KB assuming wchar_t is 2 bytes: 131072 * 2 = 262144 bytes
    value = L'A';
    target = (Py_UNICODE *)calloc(length, sizeof(Py_UNICODE));
    if (!target) {
        exit(1);
    }
}