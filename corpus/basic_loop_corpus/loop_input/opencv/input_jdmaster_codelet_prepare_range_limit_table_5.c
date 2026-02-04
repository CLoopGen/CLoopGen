#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef short J12SAMPLE;

J12SAMPLE *table12;
int i;

void init_vars() {
    size_t total_size = 1 << 20; // 1MB
    table12 = (J12SAMPLE*)calloc(total_size, sizeof(J12SAMPLE));
    if (!table12) {
        exit(1);
    }
}