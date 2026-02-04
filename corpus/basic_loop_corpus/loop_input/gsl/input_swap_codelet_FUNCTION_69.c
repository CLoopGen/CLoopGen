#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t size1 = 67108864; // 64M elements, approximates 0.01 sec on modern CPUs
size_t p;

void init_vars() {
    // No additional initialization needed for scalar externs already defined
}