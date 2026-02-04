#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    int i;
    int j;
    unsigned long m[17];
} uni_state_t;

extern  unsigned int m2;
extern unsigned int i;
extern unsigned int seed;
extern unsigned int k0;
extern unsigned int k1;
extern unsigned int _usr_j0;
extern unsigned int _usr_j1;
extern uni_state_t *state;

// Variable name mappings to avoid conflicts with system symbols
#define j0 _usr_j0
#define j1 _usr_j1

void loop(){
for (i = 0; i < 17; ++i) {
    seed = j0 * k0;
    j1 = (seed / m2 + j0 * k1 + j1 * k0) % (m2 / 2);
    j0 = seed % m2;
    state->m[i] = j0 + m2 * j1;
}

}
