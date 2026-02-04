#include <stdlib.h>
#include <stddef.h>

typedef wchar_t Py_UNICODE;
typedef ssize_t Py_ssize_t;

Py_UNICODE *target;
Py_UNICODE value;
Py_ssize_t length;
Py_ssize_t i;

void init_vars() {
    length = 67108864; // 64M elements * sizeof(wchar_t) = 128MB (assuming 2-byte wchar_t)
    target = (Py_UNICODE *)calloc(length, sizeof(Py_UNICODE));
    if (!target) exit(1);
    value = L'A';
    i = 0;
}