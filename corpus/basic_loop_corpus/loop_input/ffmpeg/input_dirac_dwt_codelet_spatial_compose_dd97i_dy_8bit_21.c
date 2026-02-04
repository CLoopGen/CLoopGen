#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct DWTCompose {
    uint8_t *b[8];
    int y;
} DWTCompose;

uint8_t *b[10];  // Need b[0..9] to safely access b[i+2] for i in [0,5]
DWTCompose *cs;
int i;

void init_vars() {
    // Allocate 64MB of data to ensure loop takes noticeable time (~0.01s)
    const size_t data_size = 64 << 20;  // 64 * 1024 * 1024 = 67,108,864 bytes
    uint8_t *data_pool = (uint8_t *)calloc(data_size, sizeof(uint8_t));
    if (!data_pool) exit(1);

    // Initialize each b[i+2] for i from 0 to 5 (i.e., b[2] to b[7])
    for (int j = 2; j <= 7; j++) {
        b[j] = &data_pool[(j - 2) * (data_size / 6)];
    }

    // Initialize cs and its pointer array
    cs = (DWTCompose *)malloc(sizeof(DWTCompose));
    if (!cs) exit(1);

    // Initialize cs->b pointers to NULL initially (will be overwritten in loop)
    for (int j = 0; j < 8; j++) {
        cs->b[j] = NULL;
    }
    cs->y = 0;
}