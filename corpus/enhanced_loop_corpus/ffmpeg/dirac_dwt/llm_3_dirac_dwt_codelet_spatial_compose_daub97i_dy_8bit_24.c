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
extern uint8_t *b[6];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array to simulate non-sequential access
    int indices[4] = {3, 1, 2, 0}; // Access in reverse-like order
    for (i = 0; i < 4; i++) {
        int idx = indices[i];
        b[idx] = cs->b[idx];
    }
}
