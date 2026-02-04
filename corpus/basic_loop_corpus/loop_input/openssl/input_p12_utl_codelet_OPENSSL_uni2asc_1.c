#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

unsigned char *uni;
int unilen;
int i;
char *asctmp;

void init_vars() {
    size_t data_size = 512 * 1024; // 512 KB of input data

    unilen = data_size;
    uni = (unsigned char *)aligned_alloc(32, unilen);
    asctmp = (char *)aligned_alloc(32, unilen >> 1);

    if (!uni || !asctmp) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (int j = 0; j < unilen; j++) {
        uni[j] = (unsigned char)(j & 0xFF);
    }

    memset(asctmp, 0, unilen >> 1);
}