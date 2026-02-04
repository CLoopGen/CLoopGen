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
extern uint8_t *b[8];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step of 2, unrolled by factor 2
    // Access pattern: b[2], b[4], b[6] (even indices only), limiting effective range to 3 iterations
    for (i = 0; i < 6; i += 2)
        cs->b[i] = b[i + 2];
}
