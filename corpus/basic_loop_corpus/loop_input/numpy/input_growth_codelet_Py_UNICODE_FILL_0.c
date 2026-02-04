#include <stddef.h>
#include <stdlib.h>

typedef wchar_t Py_UNICODE;
typedef ssize_t Py_ssize_t;

Py_UNICODE *target;
Py_UNICODE value;
Py_ssize_t length;
Py_ssize_t i;

void init_vars() {
    length = 67108864; // 64 million elements, ~128MB for wchar_t (assuming 2 bytes)
    target = (Py_UNICODE *)calloc(length, sizeof(Py_UNICODE));
    value = L'A';
}

// Ensure the loop can run safely: i is initialized in loop(), target has valid memory via calloc