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
    for (b = 0; b < 24; b++) {
        unsigned long m = (((i * j) % 179) * k) % 179;
        i = j;
        j = k;
        k = m;
        l = (53 * l + 1) % 169;
        unsigned long t = two24 >> b;
        if ((l * m) % 64 >= 32)
            sum += t;
    }
    state->u[a] = sum;
}
}
