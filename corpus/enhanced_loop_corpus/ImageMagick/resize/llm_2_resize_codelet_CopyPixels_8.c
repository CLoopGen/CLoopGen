#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float MagickFloatType;

typedef MagickFloatType Quantum;

extern  Quantum *source;
extern  ssize_t source_offset;
extern Quantum *destination;
extern  ssize_t destination_offset;
extern  size_t channels;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by reordering computation to access source and destination sequentially
    ssize_t dest_base = (ssize_t)channels * destination_offset;
    ssize_t src_base = source_offset * (ssize_t)channels;
    for (i = 0; i < (ssize_t)channels; i++) {
        destination[dest_base + i] = source[src_base + i];
    }
}
