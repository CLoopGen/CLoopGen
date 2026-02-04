#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float ac[5];

void init_vars() {
    for (int i = 0; i < 5; i++) {
        ac[i] = 1.0f;
    }
}