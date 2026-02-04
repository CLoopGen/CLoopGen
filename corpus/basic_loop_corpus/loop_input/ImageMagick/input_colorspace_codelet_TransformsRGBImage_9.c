#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float MagickFloatType;
typedef MagickFloatType Quantum;

ssize_t i;
Quantum *logmap;

void init_vars() {
    i = 0;
    size_t data_size = 64 * 1024 * 1024; // ~256 MB of data to target 0.01 sec runtime
    logmap = (Quantum *)calloc(data_size, sizeof(Quantum));
}

// Do not include main or additional comments