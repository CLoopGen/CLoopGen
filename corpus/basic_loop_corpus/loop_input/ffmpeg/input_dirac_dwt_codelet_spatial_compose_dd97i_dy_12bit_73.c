#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct DWTCompose {
    uint8_t *b[8];
    int y;
} DWTCompose;

uint8_t *b[10];  // Need b[2] to b[7], so size 10 to be safe
DWTCompose *cs;
int i;

void init_vars() {
    const size_t data_size = 64 << 20; // 64 MB per buffer to ensure ~0.01s runtime

    // Allocate and initialize cs
    cs = (DWTCompose*)calloc(1, sizeof(DWTCompose));
    if (!cs) exit(1);

    // Allocate 10 pointers in b, but only use b[2] to b[7]
    for (int idx = 0; idx < 10; idx++) {
        b[idx] = (uint8_t*)malloc(data_size * sizeof(uint8_t));
        if (!b[idx]) exit(1);
    }

    // Ensure cs->b[0..5] are accessible (only 6 iterations)
    for (int idx = 0; idx < 6; idx++) {
        cs->b[idx] = NULL;  // Will be assigned in loop
    }
}

// Provide the loop function as extern elsewhere
void loop();