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
    // Variant 1: Strided memory access with step of 2, unrolling the loop to access i and i+2
    int idx;
    for (idx = 0; idx < 4; idx += 2) {
        if (idx < 4)      b[idx] = cs->b[idx];
        if (idx + 1 < 4)  b[idx + 1] = cs->b[idx + 1];
    }
}
