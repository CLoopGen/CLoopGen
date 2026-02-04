#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct DWTCompose {
    uint8_t *b[8];
    int y;
} DWTCompose;

uint8_t *b[10];  // Need b[0] to b[9] to safely access b[i+2] for i from 0 to 5
DWTCompose *cs;
int i;

void init_vars() {
    const size_t data_size = 16 << 20;  // 16 MB per buffer

    // Allocate and initialize cs
    cs = (DWTCompose*)calloc(1, sizeof(DWTCompose));
    if (!cs) exit(1);

    // Allocate 10 buffers for b[0..9], each of size data_size
    for (int j = 0; j < 10; j++) {
        b[j] = (uint8_t*)calloc(data_size, sizeof(uint8_t));
        if (!b[j]) exit(1);
    }

    // Initialize cs->b pointers to NULL to avoid garbage values
    for (int j = 0; j < 8; j++) {
        cs->b[j] = NULL;
    }

    // 'i' will be initialized in the loop itself (from 0 to 5), so no need to set here
}