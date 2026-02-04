#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    int i;
    unsigned long x[250];
} r250_state_t;

extern r250_state_t *state;
extern int i;
extern unsigned long msb;
extern unsigned long mask;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 8; i++) {
        for (int j = 0; j < 4; j++) {
            int idx = i * 4 + j;
            if (idx < 32) {
                int k = 7 * idx + 3;
                state->x[k] &= mask;
                state->x[k] |= msb;
                mask >>= 1;
                msb >>= 1;
            }
        }
    }
}
