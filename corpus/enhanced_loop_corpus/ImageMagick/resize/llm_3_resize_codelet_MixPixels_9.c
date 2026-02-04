#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float MagickFloatType;

typedef MagickFloatType Quantum;

extern  Quantum *source;
extern  ssize_t *source_offset;
extern  size_t source_size;
extern Quantum *destination;
extern  ssize_t destination_offset;
extern  size_t channels;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < (ssize_t)channels; i++) {
    ssize_t j, sum = 0;
    for (j = 0; j < (ssize_t)source_size; j++) {
        ssize_t linear_index = i + (ssize_t)channels * source_offset[j];
        sum += (ssize_t)source[linear_index];
    }
    ssize_t dest_idx = (ssize_t)channels * destination_offset + i;
    destination[dest_idx] = (Quantum)(sum / (ssize_t)source_size);
}
}
