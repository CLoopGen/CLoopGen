#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int offset[8];
int i;

void init_vars() {
    // Initialize offset array to safe values
    for (int j = 0; j < 8; j++) {
        offset[j] = j; // arbitrary initial values
    }
    i = 0; // reset loop index
}