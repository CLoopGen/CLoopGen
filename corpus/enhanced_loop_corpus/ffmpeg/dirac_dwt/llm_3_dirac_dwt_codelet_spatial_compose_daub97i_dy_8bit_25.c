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
    // Variant 2: Consecutive forward access using pointer arithmetic to simulate different access pattern
    uint8_t **src = &b[2];
    uint8_t **dst = cs->b;
    for (i = 0; i < 4; i++) {
        dst[i] = src[i];
    }
}
