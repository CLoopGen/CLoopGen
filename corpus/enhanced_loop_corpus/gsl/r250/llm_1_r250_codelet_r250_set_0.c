#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    int i;
    unsigned long x[250];
} r250_state_t;

extern unsigned long s;
extern r250_state_t *state;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 50; i++) {
    int base = i * 5;
    for (int k = 0; k < 5; k++) {
        int idx = base + k;
        if (idx < 250) {
            s = ((69069 * s) & 4294967295UL);
            state->x[idx] = s;
        }
    }
}
}
