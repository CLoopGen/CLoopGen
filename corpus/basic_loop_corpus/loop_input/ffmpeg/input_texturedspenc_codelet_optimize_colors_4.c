#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float covf[6] = {0.0f};
int cov[6] = {255, 204, 153, 102, 51, 0};
int x = 0;

void init_vars() {
    // No additional initialization needed beyond static initializers
    // Array sizes are fixed at 6, as used in the loop
    // Values in cov are initialized to valid integers in [0,255] range
    // covf will hold the divided results: cov[i] / 255.0f
}