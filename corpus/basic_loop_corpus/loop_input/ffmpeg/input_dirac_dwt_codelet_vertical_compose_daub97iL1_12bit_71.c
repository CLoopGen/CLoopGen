#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

int width;
int i;
int32_t *b0;
int32_t *b1;
int32_t *b2;

void init_vars() {
    const size_t data_size = 64 * (1 << 20); // 64 MB of total data
    const size_t num_elements = data_size / (3 * sizeof(int32_t));
    
    width = (int)num_elements;

    b0 = aligned_alloc(32, width * sizeof(int32_t));
    b1 = aligned_alloc(32, width * sizeof(int32_t));
    b2 = aligned_alloc(32, width * sizeof(int32_t));

    if (!b0 || !b1 || !b2) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    srand((unsigned int)time(NULL));
    for (int j = 0; j < width; j++) {
        b0[j] = rand();
        b1[j] = rand();
        b2[j] = rand();
    }
}