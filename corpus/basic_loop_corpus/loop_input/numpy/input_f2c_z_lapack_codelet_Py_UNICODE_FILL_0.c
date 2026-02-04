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
    length = 32 * 1024 * 1024 / sizeof(Py_UNICODE);
    if (length == 0) length = 1;
    target = (Py_UNICODE*)calloc(length, sizeof(Py_UNICODE));
    value = L'A';
}

__attribute__((constructor))
static void constructor() {
    init_vars();
}