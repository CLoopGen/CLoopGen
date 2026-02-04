#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double normalized_degrees;
unsigned int rotations;

void init_vars() {
    normalized_degrees = 1000000.0 * 45.1; // Ensures many iterations: ~1000000*45.1 / 90 ≈ 500000 iterations
    rotations = 0;
}