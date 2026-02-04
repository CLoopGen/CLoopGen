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
    // Variant 2: Consecutive reverse-order access to source array
    // Instead of b[2], b[3], b[4], b[5], we now read from higher to lower consecutively
    for (i = 0; i < 4; i++) {
        int reverse_offset = 5 - i;  // Maps i=0->5, i=1->4, i=2->3, i=3->2
        cs->b[i] = b[reverse_offset];
    }
}
