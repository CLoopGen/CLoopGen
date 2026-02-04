#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

unsigned int max;
unsigned short count[16];

void init_vars() {
    for (int i = 0; i < 16; i++) {
        count[i] = 0;
    }
    // Set one non-zero value near the end to control loop termination
    count[15] = 1;
}