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
    length = 134217728; // 128 MB of data: 134217728 elements * sizeof(wchar_t) = 268,435,456 bytes
    value = L'A';
    target = (Py_UNICODE *)calloc(length, sizeof(Py_UNICODE));
    if (!target) exit(1);
}

void loop();