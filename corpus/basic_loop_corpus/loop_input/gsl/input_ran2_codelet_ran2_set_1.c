#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

typedef struct {
    unsigned long x;
    unsigned long y;
    unsigned long n;
    unsigned long shuffle[32];
} ran2_state_t;

long m1 = 2147483563L;
long a1 = 40014L;
long q1 = 53668L;
long r1 = 12211L;
unsigned long s = 123456789UL;
ran2_state_t *state;
int i;

void init_vars() {
    state = (ran2_state_t*)malloc(sizeof(ran2_state_t));
    if (!state) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    state->x = 0;
    state->y = 0;
    state->n = 0;
    memset(state->shuffle, 0, sizeof(state->shuffle));
}