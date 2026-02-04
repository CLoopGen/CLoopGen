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
    unsigned long acc = s;
    for (i = 0; i <= 16383; i++) {
        unsigned long t = 0;
        unsigned long bit = msb;
        for (j = 0; j < 32; j++) {
            acc = ((69069 * acc) & 4294967295UL);
            if (acc & msb)
                t |= bit;
            bit >>= 1;
        }
        state->ra[i] = t;
    }
    s = acc;
}
