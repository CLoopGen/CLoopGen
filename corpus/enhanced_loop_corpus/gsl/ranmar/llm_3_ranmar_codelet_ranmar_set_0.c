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
for (a = 0; a < 97; a += 2) {
    unsigned long sum1 = 0, sum2 = 0;
    unsigned long t1 = two24, t2 = two24;
    int temp_i1 = i, temp_j1 = j, temp_k1 = k, temp_l1 = l;
    int temp_i2 = i, temp_j2 = j, temp_k2 = k, temp_l2 = l;

    for (b = 0; b < 24; b++) {
        unsigned long m1 = (((temp_i1 * temp_j1) % 179) * temp_k1) % 179;
        temp_i1 = temp_j1;
        temp_j1 = temp_k1;
        temp_k1 = m1;
        temp_l1 = (53 * temp_l1 + 1) % 169;
        t1 >>= 1;
        if ((temp_l1 * m1) % 64 >= 32)
            sum1 += t1;

        unsigned long m2 = (((temp_i2 * temp_j2) % 179) * temp_k2) % 179;
        temp_i2 = temp_j2;
        temp_j2 = temp_k2;
        temp_k2 = m2;
        temp_l2 = (53 * temp_l2 + 1) % 169;
        t2 >>= 1;
        if ((temp_l2 * m2) % 64 >= 32)
            sum2 += t2;
    }

    state->u[a] = sum1;
    if (a + 1 < 97) {
        state->u[a + 1] = sum2;
    }
}
}
