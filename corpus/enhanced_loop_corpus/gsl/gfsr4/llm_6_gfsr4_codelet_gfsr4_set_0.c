#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    int nd;
    unsigned long ra[16384];
} gfsr4_state_t;

extern unsigned long s;
extern gfsr4_state_t *state;
extern int i;
extern int j;
extern unsigned long msb;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned long temp[16384];
    for (i = 0; i <= 16383; i++) {
        unsigned long t = 0;
        unsigned long bit = msb;
        for (j = 0; j < 32; j++) {
            s = ((69069 * s) & 4294967295UL);
            if (s & msb)
                t |= bit;
            bit >>= 1;
        }
        temp[i] = t;
    }
    for (i = 0; i <= 16383; i++) {
        state->ra[i] = temp[i];
    }
}
