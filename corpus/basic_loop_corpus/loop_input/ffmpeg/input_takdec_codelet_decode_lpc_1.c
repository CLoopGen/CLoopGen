#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int32_t *coeffs;
int length;
int i;
unsigned int a1;
unsigned int a2;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024;
    coeffs = aligned_alloc(32, data_size);
    if (!coeffs) {
        exit(1);
    }
    length = data_size / sizeof(int32_t);
    for (int j = 0; j < length; j++) {
        coeffs[j] = (int32_t)(rand() & 0xFFFF);
    }
    a1 = (unsigned int)(rand() & 0xFFFF);
    a2 = (unsigned int)(rand() & 0xFFFF);
    i = 0;
}