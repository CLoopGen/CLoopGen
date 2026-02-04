#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *d;
extern ptrdiff_t stride;
extern int y;
extern uint64_t a;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t local_a[8];
    // Remove loop-carried dependency by precomputing values independently
    for (y = 0; y < 8; y++)
        local_a[y] = a + y; // Independent computation, no WAW or RAW across iterations

    for (y = 0; y < 8; y++)
        *((uint64_t *)(d + y * stride)) = local_a[y];
}
