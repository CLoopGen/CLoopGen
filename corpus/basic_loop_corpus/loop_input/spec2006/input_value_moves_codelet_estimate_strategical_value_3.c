#include <stdio.h>
#include <inttypes.h>

int aa;
float dragon_value[400];

void init_vars() {
    // Initialize variables to ensure loop runs safely
    // The loop runs from (19+2) = 21 to (19+1)*(19+1) = 400, exclusive upper bound
    // So valid indices are from 21 to 399 inclusive -> size 400 is sufficient

    for (int i = 0; i < 400; i++) {
        dragon_value[i] = 0.0f;
    }
}