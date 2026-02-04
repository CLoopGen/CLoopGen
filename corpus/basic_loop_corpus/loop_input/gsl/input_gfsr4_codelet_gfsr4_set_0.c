#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    int nd;
    unsigned long ra[16384];
} gfsr4_state_t;

unsigned long s = 123456789UL;
gfsr4_state_t *state;
int i;
int j;
unsigned long msb = 2147483648UL; // 2^31

void init_vars() {
    state = (gfsr4_state_t*)malloc(sizeof(gfsr4_state_t));
    if (!state) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    state->nd = 0;
}