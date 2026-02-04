#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

size_t data_size;
size_t n;

void init_vars() {
    data_size = 100000000; // Approximately 100 million iterations for ~0.01 sec on modern CPU
}