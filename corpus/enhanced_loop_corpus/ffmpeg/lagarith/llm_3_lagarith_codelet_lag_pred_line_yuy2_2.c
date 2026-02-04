#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *buf;
extern int L;
extern  int HEAD;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access (traverse from HEAD-1 down to 0)
    for (i = HEAD - 1; i >= 0; i--) {
        L += buf[i];
        buf[i] = L;
    }
}
