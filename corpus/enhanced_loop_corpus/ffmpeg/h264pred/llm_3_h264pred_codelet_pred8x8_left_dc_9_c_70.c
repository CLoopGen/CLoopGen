#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int i;
extern int dc0;
extern int dc2;
extern uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with reversed loop order and direct offset indexing to create a different access pattern
    for (i = 3; i >= 0; i--) {
        dc0 += src[-1 + i * stride];
        dc2 += src[-1 + (i + 4) * stride];
    }
}
