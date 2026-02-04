#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <wchar.h>

typedef wchar_t Py_UNICODE;
typedef ssize_t Py_ssize_t;

Py_UNICODE *target;
Py_UNICODE value;
Py_ssize_t length;
Py_ssize_t i;

void init_vars() {
    length = 67108864 / sizeof(Py_UNICODE);  // ~64MB of data to target typical 0.01 sec runtime
    target = (Py_UNICODE *)calloc(length, sizeof(Py_UNICODE));
    if (!target) exit(1);
    value = L'A';
    i = 0;
}