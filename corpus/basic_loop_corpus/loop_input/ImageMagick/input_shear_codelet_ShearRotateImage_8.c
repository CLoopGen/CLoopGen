#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double MagickDoubleType;
typedef MagickDoubleType MagickRealType;

MagickRealType angle = 100000.0;
size_t rotations;

void init_vars() {
    // Ensure the loop runs enough iterations to last ~0.01 seconds
    // Each iteration subtracts 90 from angle until it's <= 45
    // To get sufficient iterations, initialize angle to a large value
    angle = 100000.0; // This will result in about (100000 - 45) / 90 ≈ 1111 iterations
    rotations = 0;
}