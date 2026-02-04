#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    int i;
    unsigned long x[250];
} r250_state_t;

unsigned long s = 123456789UL;
r250_state_t *state = NULL;
int i;

void init_vars() {
    state = (r250_state_t*)malloc(sizeof(r250_state_t));
    if (!state) {
        exit(1);
    }
    state->i = 0;
}