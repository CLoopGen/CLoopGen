#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int32_t *p1;
int32_t *p2;
int length;
int i;

static int32_t *allocated_p1;
static int32_t *allocated_p2;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; 
    length = data_size / sizeof(int32_t);

    allocated_p1 = aligned_alloc(32, data_size);
    allocated_p2 = aligned_alloc(32, data_size);

    if (!allocated_p1 || !allocated_p2) {
        exit(1);
    }

    p1 = allocated_p1;
    p2 = allocated_p2;

    for (int j = 0; j < length; j++) {
        p1[j] = (int32_t)(j & 0xFFFFF);
        p2[j] = (int32_t)((j + 0x80000) & 0xFFFFF);
    }
}