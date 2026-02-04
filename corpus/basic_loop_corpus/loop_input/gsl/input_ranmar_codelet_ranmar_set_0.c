#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

unsigned long two24 = 1UL << 24;

typedef struct {
    unsigned int i;
    unsigned int j;
    long carry;
    unsigned long u[97];
} ranmar_state_t;

ranmar_state_t *state;
int i;
int j;
int k;
int l;
int a;
int b;

void init_vars() {
    state = (ranmar_state_t*)malloc(sizeof(ranmar_state_t));
    if (!state) {
        exit(1);
    }
    i = 12;
    j = 34;
    k = 56;
    l = 78;
}

// Ensure the data size is sufficient to make the loop take ~0.01s
// The inner loop runs 97 * 24 = 2328 iterations, which is fixed.
// To meet timing, we rely on the complexity of operations rather than data size.
// No additional data beyond the fixed u[97] is needed.