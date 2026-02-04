#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    unsigned long x;
    unsigned long n;
    unsigned long shuffle[32];
} ran1_state_t;

long m = 2147483647; // 2^31 - 1
long a = 16807;
long q = 127773;
long r = 2836;
unsigned long s = 123456789;
ran1_state_t *state;
int i;

void init_vars() {
    state = (ran1_state_t*)malloc(sizeof(ran1_state_t));
    if (!state) {
        exit(1);
    }
    state->x = 0;
    state->n = 0;
    for (int j = 0; j < 32; j++) {
        state->shuffle[j] = 0;
    }
    s = 123456789;
}