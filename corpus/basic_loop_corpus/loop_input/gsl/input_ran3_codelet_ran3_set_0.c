#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    unsigned int x;
    unsigned int y;
    unsigned long buffer[56];
} ran3_state_t;

ran3_state_t *state;
int i;
long j;
long k;

void init_vars() {
    state = (ran3_state_t*)malloc(sizeof(ran3_state_t));
    if (!state) {
        exit(1);
    }
    state->x = 12345;
    state->y = 67890;
    for (int idx = 0; idx < 56; idx++) {
        state->buffer[idx] = 100000000UL * ((idx + 1) % 10);
    }
    i = 0;
    j = 987654321L;
    k = 123456789L;
}