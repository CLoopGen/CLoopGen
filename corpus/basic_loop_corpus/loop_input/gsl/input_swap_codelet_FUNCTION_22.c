#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t size1 = 134217728; // 128MB of data to target ~0.01 sec runtime
size_t p;

void init_vars() {
    // No additional initialization needed for scalar externs already defined
}