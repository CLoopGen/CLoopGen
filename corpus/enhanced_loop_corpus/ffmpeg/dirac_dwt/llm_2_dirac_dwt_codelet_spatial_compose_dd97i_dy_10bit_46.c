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
    // Variant 1: Strided memory access with step size 2, wrapping around using modulo
    // This changes the access pattern from sequential to strided (every other element)
    for (i = 0; i < 6; i += 2) {
        b[i] = cs->b[i];
        if (i + 1 < 6) {
            b[i + 1] = cs->b[i + 1];
        }
    }
}
