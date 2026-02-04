#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

__attribute__((aligned(32))) float window[3712];

int i;

void init_vars() {
    for (int idx = 0; idx < 3712; idx++) {
        window[idx] = 0.0F;
    }
    i = 0;
}