#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct DWTCompose {
    uint8_t *b[8];
    int y;
} DWTCompose;

extern DWTCompose *cs;
extern int i;
extern uint8_t *b[10];

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect memory access using an index map (simulates irregular access pattern)
    int indices[8] = {0, 2, 4, 6, 1, 3, 5, 7}; // Even indices first, then odd
    for (i = 0; i < 8; i++) {
        int idx = indices[i];
        b[idx] = cs->b[idx];
    }
}
