#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

unsigned long zuf_randmax = 2147483647UL;

long i = 12;
long j = 13;
long k = 14;
long l = 15;
long m;
double x;
double y;
long ii;
long jj;

typedef struct {
    int n;
    unsigned long u[607];
} zuf_state_t;

zuf_state_t *state;

void init_vars() {
    state = (zuf_state_t*)malloc(sizeof(zuf_state_t));
    if (!state) {
        exit(1);
    }
    state->n = 607;
}