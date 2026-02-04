#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float MagickFloatType;
typedef MagickFloatType Quantum;

ssize_t i;
double reference_black;
Quantum *logmap;

void init_vars() {
    reference_black = 4.0; // Ensures loop runs for ~256 iterations: (4 * 65535 / 1024) ≈ 256
    size_t array_size = 1024 * 1024 * sizeof(Quantum); // ~4MB of data
    logmap = (Quantum *)calloc(array_size / sizeof(Quantum), sizeof(Quantum));
    if (!logmap) {
        exit(1);
    }
}