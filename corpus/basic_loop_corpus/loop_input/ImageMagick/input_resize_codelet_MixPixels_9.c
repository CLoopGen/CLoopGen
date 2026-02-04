#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

typedef float MagickFloatType;

typedef MagickFloatType Quantum;

Quantum *source;
ssize_t *source_offset;
size_t source_size;
Quantum *destination;
ssize_t destination_offset;
size_t channels;
ssize_t i;

static size_t total_data_size = 64 * 1024 * 1024; // Aim for ~64MB of source data

void init_vars() {
    channels = 4;
    source_size = total_data_size / (channels * sizeof(Quantum));
    
    if (source_size == 0) source_size = 1;
    
    source = (Quantum *)aligned_alloc(32, source_size * channels * sizeof(Quantum));
    source_offset = (ssize_t *)aligned_alloc(32, source_size * sizeof(ssize_t));
    destination = (Quantum *)aligned_alloc(32, channels * sizeof(Quantum));
    
    destination_offset = 0;
    
    for (size_t j = 0; j < source_size; j++) {
        source_offset[j] = j;
        for (size_t c = 0; c < channels; c++) {
            source[j * channels + c] = (Quantum)(rand() % 1000) / 10.0f;
        }
    }
    
    for (size_t c = 0; c < channels; c++) {
        destination[c] = 0.0f;
    }
}