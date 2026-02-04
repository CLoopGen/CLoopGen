#include <stdlib.h>
#include <stdint.h>

int *coefs;
int i;

void init_vars() {
    coefs = (int*)aligned_alloc(32, 64 * 1024 * 1024);
    if (!coefs) exit(1);
    for (size_t j = 0; j < (64 * 1024 * 1024) / sizeof(int); j++) {
        coefs[j] = rand();
    }
}