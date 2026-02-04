#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float vals[8];
int mask;
int i;

void init_vars() {
    // Initialize vals array with sample data
    for (int j = 0; j < 8; j++) {
        vals[j] = (j >= 4) ? ((j - 4) * 0.5f - 1.0f) : 0.0f; // vals[4..7] will be -1.0, -0.5, 0.0, 0.5
    }
    // Ensure that some conditions are true: vals[4+i] > 0.F for i in [0,3]
    // So set vals[7] to positive to trigger one condition
    vals[7] = 2.0f;

    // Initialize mask to 0
    mask = 0;

    // Initialize loop index i to 0 (though loop will reset it)
    i = 0;
}