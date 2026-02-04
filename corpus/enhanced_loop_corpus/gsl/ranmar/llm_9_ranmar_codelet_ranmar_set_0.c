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
for (a = 0; a < 97; a += 3) {
    unsigned long sum1 = 0, sum2 = 0, sum3 = 0;
    unsigned long t1 = two24, t2 = two24 >> 1, t3 = two24 >> 2;
    for (b = 0; b < 8; b++) {
        unsigned long m1 = (((i * j) % 179) * k) % 179;
        i = j; j = k; k = m1;
        l = (53 * l + 1) % 169;
        if ((l * m1) % 64 >= 32) sum1 += t1;
        t1 >>= 3;

        unsigned long m2 = (((i * j) % 179) * k) % 179;
        i = j; j = k; k = m2;
        l = (53 * l + 1) % 169;
        if ((l * m2) % 64 >= 32) sum2 += t2;
        t2 >>= 3;

        unsigned long m3 = (((i * j) % 179) * k) % 179;
        i = j; j = k; k = m3;
        l = (53 * l + 1) % 169;
        if ((l * m3) % 64 >= 32) sum3 += t3;
        t3 >>= 3;
    }
    state->u[a] = sum1;
    if (a + 1 < 97) state->u[a+1] = sum2;
    if (a + 2 < 97) state->u[a+2] = sum3;
}
}
