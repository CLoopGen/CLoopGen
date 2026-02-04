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
        ssize_t j;
        Quantum temp_sum = 0.0f;
        ssize_t base_index = i;
        for (j = 0; j < (ssize_t)source_size; j++) {
            ssize_t source_idx = source_offset[j] * (ssize_t)channels + base_index;
            temp_sum += source[source_idx];
        }
        ssize_t dest_index = (ssize_t)channels * destination_offset + i;
        destination[dest_index] = (Quantum)(temp_sum / (ssize_t)source_size);
    }
}
