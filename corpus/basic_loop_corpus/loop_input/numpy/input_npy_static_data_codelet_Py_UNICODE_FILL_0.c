#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <wchar.h>
#include <time.h>

typedef wchar_t Py_UNICODE;
typedef ssize_t Py_ssize_t;

Py_UNICODE *target;
Py_UNICODE value;
Py_ssize_t length;
Py_ssize_t i;

void init_vars() {
    const size_t target_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec on typical CPU
    target = (Py_UNICODE*)calloc(target_size, sizeof(Py_UNICODE));
    if (!target) {
        exit(1);
    }
    length = target_size;
    value = L'A';
    i = 0;
}