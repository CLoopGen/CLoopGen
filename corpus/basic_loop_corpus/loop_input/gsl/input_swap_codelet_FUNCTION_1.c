#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t size1;
size_t p;

void init_vars() {
    size1 = 67108864; // Approximately 64M iterations to target ~0.01 sec runtime on modern CPU
}