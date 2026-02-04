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
for (i = 0; i < 250; i++) {
    s = ((69069 * s) & 4294967295UL);
    state->x[i] = s;
}

}
