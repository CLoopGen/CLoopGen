#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

struct huffcodetab {
    unsigned int xlen;
    unsigned int linmax;
    unsigned long *table;
    unsigned char *hlen;
};

struct huffcodetab ht[34];
int *ix;
int linbits1;
int linbits2;
int sum;
int sum1;
int sum2;
int i;

void init_vars() {
    const size_t data_size = 1 << 20; // ~1MB of data

    // Initialize linbits
    linbits1 = 5;
    linbits2 = 7;
    sum = 0;
    sum1 = 0;
    sum2 = 0;
    i = 0;

    // Allocate and initialize ix array with sufficient size
    ix = (int*)calloc(data_size, sizeof(int));
    for (size_t j = 0; j < data_size - 4; j += 4) {
        ix[j] = (j % 32) + 1;     // ensure *ix values from 1 to 32
        ix[j + 3] = ((j + 3) % 32) + 1; // ensure *(ix+3) values
    }

    // Initialize each used huffman table entry
    for (int t = 0; t < 34; t++) {
        ht[t].xlen = 256;
        ht[t].linmax = 100;
        ht[t].table = (unsigned long*)calloc(256, sizeof(unsigned long));
        ht[t].hlen = (unsigned char*)calloc(256, sizeof(unsigned char));
        // Default initialization: small values in hlen
        for (int k = 0; k < 256; k++) {
            ht[t].hlen[k] = k % 16;
        }
    }

    // Specifically ensure ht[16] and ht[24] are safe for indexing up to at least 255
    // Already covered in loop above
}