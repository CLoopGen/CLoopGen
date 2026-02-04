#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct DWTCompose {
    uint8_t *b[8];
    int y;
} DWTCompose;

DWTCompose *cs;
int i;
uint8_t *b[6];

void init_vars() {
    // Allocate cs structure
    cs = (DWTCompose *)malloc(sizeof(DWTCompose));
    if (!cs) exit(1);

    // Allocate each pointer in cs->b to point to 32MB of data (total ~256MB for all)
    const size_t block_size = 32 << 20; // 32 MB
    for (int j = 0; j < 8; j++) {
        cs->b[j] = (uint8_t *)malloc(block_size);
        if (!cs->b[j]) exit(1);
    }

    // Initialize b[0..5] to point to 32MB blocks, but we only use b[2..5] in loop
    for (int j = 0; j < 6; j++) {
        b[j] = (uint8_t *)malloc(block_size);
        if (!b[j]) exit(1);
        // Touch memory to ensure allocation and prevent lazy allocation issues
        for (size_t k = 0; k < block_size; k += 4096) {
            b[j][k] = (uint8_t)(j + k);
        }
    }

    // Initialize cs fields
    cs->y = 0;
}