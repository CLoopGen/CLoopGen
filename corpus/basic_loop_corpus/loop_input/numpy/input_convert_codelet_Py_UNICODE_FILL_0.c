#include <stddef.h>
#include <stdlib.h>
#include <wchar.h>

typedef wchar_t Py_UNICODE;
typedef ssize_t Py_ssize_t;

Py_UNICODE *target;
Py_UNICODE value;
Py_ssize_t length;
Py_ssize_t i;

void init_vars() {
    length = 16777216;  // 16M elements * sizeof(wchar_t) = ~32MB, target ~0.01s on modern CPU
    value = L'A';
    target = (Py_UNICODE*)aligned_alloc(_Alignof(Py_UNICODE), length * sizeof(Py_UNICODE));
    if (!target) exit(1);
}