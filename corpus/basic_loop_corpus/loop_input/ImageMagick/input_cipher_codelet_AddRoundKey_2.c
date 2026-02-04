#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

unsigned int *ciphertext;
unsigned int *key;
unsigned int *plaintext;
ssize_t i;

static size_t data_size = 64 * 1024 * 1024; // ~256 MB of total data (64M uints)

void init_vars() {
    ciphertext = (unsigned int*)aligned_alloc(32, data_size * sizeof(unsigned int));
    key = (unsigned int*)aligned_alloc(32, data_size * sizeof(unsigned int));
    plaintext = (unsigned int*)aligned_alloc(32, data_size * sizeof(unsigned int));

    for (size_t j = 0; j < data_size; j++) {
        ciphertext[j] = (unsigned int)rand();
        key[j] = (unsigned int)rand();
        plaintext[j] = 0;
    }
}