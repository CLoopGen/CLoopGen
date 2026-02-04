#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

size_t j;
size_t stl_size;
unsigned long hist[1000];
size_t _usr_index;

#define index _usr_index

void init_vars() {
    index = 0;
    stl_size = 0;
    for (size_t i = 0; i < 1000; ++i) {
        hist[i] = (unsigned long)(i * 31);
    }
}