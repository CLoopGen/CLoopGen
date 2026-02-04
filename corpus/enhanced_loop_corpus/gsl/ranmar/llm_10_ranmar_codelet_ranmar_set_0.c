#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    unsigned int i;
    unsigned int j;
    long carry;
    unsigned long u[97];
} ranmar_state_t;

extern  unsigned long two24;
extern ranmar_state_t *state;
extern int i;
extern int j;
extern int k;
extern int l;
extern int a;
extern int b;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (a = 0; a < 97; a++) {
    unsigned long sum = 0;
    unsigned long t = two24;
    for (b = 0; b < 12; b++) {
        unsigned long m = (((i * j + k) % 179) * (k + 1)) % 179;
        i = (j + 1) % 179;
        j = (k + 2) % 179;
        k = m;
        l = (53 * l + 1) % 169;
        t >>= 2;
        if (((l * m) % 64) >= 32)
            sum += t;
        if (((l * (m ^ 17)) % 64) >= 32 && t > 1)
            sum += t >> 1;
    }
    state->u[a] = sum;
}
}
