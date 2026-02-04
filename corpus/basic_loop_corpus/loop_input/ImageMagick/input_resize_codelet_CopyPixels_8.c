#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float MagickFloatType;
typedef MagickFloatType Quantum;

Quantum *source;
ssize_t source_offset;
Quantum *destination;
ssize_t destination_offset;
size_t channels;
ssize_t i;

void init_vars() {
    channels = 1024 * 1024 / sizeof(Quantum); // ~1MB of data
    size_t total_size = channels;

    source = (Quantum*)aligned_alloc(32, total_size * sizeof(Quantum));
    destination = (Quantum*)aligned_alloc(32, total_size * sizeof(Quantum));

    if (!source || !destination) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < total_size; ++idx) {
        source[idx] = (Quantum)(idx % 1000) + 0.5f;
        destination[idx] = 0.0f;
    }

    source_offset = 0;
    destination_offset = 0;
}