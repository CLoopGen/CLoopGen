#include <stdlib.h>
#include <stdint.h>

int *table;
int in;
int out;

void init_vars() {
    const size_t data_size = 128 * 1024 * 1024; // 128 MB
    table = (int*)aligned_alloc(64, data_size);
    for (size_t i = 0; i < data_size / sizeof(int); i++) {
        table[i] = 0;
    }
    in = 0;
    out = 0;
}