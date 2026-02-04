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
    length = 16777216; // 16 million elements, ~32MB for wchar_t (2 or 4 bytes depending on platform)
    target = (Py_UNICODE*)malloc(length * sizeof(Py_UNICODE));
    if (!target) {
        exit(1);
    }
    value = L'A';
}
// Note: 'i' is used as a loop counter and does not need initialization in init_vars since it's set in the loop.