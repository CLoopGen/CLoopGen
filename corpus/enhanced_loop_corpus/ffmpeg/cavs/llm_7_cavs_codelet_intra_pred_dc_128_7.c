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
    // Remove loop-carried dependencies by precomputing values into local array
    for (int i = 0; i < 8; i++) {
        local_a[i] = a + (i * 17); // Independent computation, no WAW or RAW across iterations
    }
    for (y = 0; y < 8; y++) {
        *((uint64_t *)(d + y * stride)) = local_a[y];
    }
}
