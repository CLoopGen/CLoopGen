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
    // Allocate a large enough data size to make the loop take ~0.01 seconds
    // Since the loop is very small (4 iterations, simple pointer assignments),
    // we need to ensure underlying data is sizable to have measurable effect in context.
    // However, the loop itself does not iterate over data in b[i], so performance
    // impact is minimal. We initialize substantial buffers to allow surrounding
    // code or future changes to have meaningful workload.

    const size_t buffer_size = 64 * 1024 * 1024; // 64 MB per buffer to induce memory pressure

    // Allocate cs structure
    cs = malloc(sizeof(DWTCompose));
    if (!cs) exit(1);

    // Allocate and initialize each of cs->b[0..7], only b[0..3] are used in loop
    for (int j = 0; j < 8; j++) {
        cs->b[j] = malloc(buffer_size);
        if (!cs->b[j]) exit(1);
        // Touch memory to ensure it's committed
        for (size_t k = 0; k < buffer_size; k += 4096) {
            cs->b[j][k] = (uint8_t)(j + k);
        }
    }

    // Initialize b array (only b[0..3] will be assigned in loop)
    for (int j = 0; j < 6; j++) {
        b[j] = NULL; // Will be overwritten in loop for j=0..3
    }

    // Initialize i to avoid undefined behavior
    i = 0;
}