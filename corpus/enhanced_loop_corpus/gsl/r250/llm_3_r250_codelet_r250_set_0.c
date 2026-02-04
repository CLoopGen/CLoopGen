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
    int indices[250];
    for (int j = 0; j < 250; j++) {
        indices[j] = (j * 7) % 250; // Strided access pattern with modulo to stay in bounds
    }
    for (i = 0; i < 250; i++) {
        s = ((69069 * s) & 4294967295UL);
        state->x[indices[i]] = s;
    }
}
