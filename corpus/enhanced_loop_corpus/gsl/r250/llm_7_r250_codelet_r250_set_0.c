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
    unsigned long prev = s;
    unsigned long next;
    for (i = 0; i < 250; i += 2) {
        next = ((69069 * prev) & 4294967295UL);
        state->x[i] = prev;
        if (i + 1 < 250) {
            state->x[i + 1] = next;
        }
        prev = ((69069 * next) & 4294967295UL);
    }
    s = prev; // Update global s once at end
}
