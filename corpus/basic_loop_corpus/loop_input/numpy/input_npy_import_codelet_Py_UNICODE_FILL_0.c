#include <stdio.h>
#include <inttypes.h>
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
    length = 67108864; // 64 million elements, ~128MB for wchar_t (2 bytes on most systems, 4 on some)
    value = L'A'; 

    target = (Py_UNICODE*)calloc(length, sizeof(Py_UNICODE));
    if (!target) {
        exit(1);
    }
}

void loop();