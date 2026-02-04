#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

typedef float LPC_TYPE;

LPC_TYPE *autoc;
int max_order;
int i;
LPC_TYPE gen0[32];
LPC_TYPE gen1[32];

void init_vars() {
    const int data_size = 1 << 20; // ~4MB of data (1M floats), adjust for ~0.01s runtime
    autoc = (LPC_TYPE*)aligned_alloc(32, data_size * sizeof(LPC_TYPE));
    if (!autoc) exit(1);

    max_order = 32;

    for (int j = 0; j < data_size; j++) {
        autoc[j] = (LPC_TYPE)(rand() % 1000) / 10.0f;
    }
}