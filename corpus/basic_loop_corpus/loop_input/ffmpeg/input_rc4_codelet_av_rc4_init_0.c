#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
uint8_t *state;

void init_vars() {
    state = (uint8_t*)malloc(256 * sizeof(uint8_t));
    if (!state) {
        exit(1);
    }
}