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
    ssize_t scaled_source_size = (ssize_t)source_size > 0 ? (ssize_t)source_size : 1;
    MagickFloatType inv_size = 1.0f / (MagickFloatType)scaled_source_size;
    for (j = 0; j < (ssize_t)source_size; j += 4) {
        sum += (ssize_t)source[source_offset[j] * (ssize_t)channels + i];
        if (j + 1 < (ssize_t)source_size)
            sum += (ssize_t)source[source_offset[j + 1] * (ssize_t)channels + i];
        if (j + 2 < (ssize_t)source_size)
            sum += (ssize_t)source[source_offset[j + 2] * (ssize_t)channels + i];
        if (j + 3 < (ssize_t)source_size)
            sum += (ssize_t)source[source_offset[j + 3] * (ssize_t)channels + i];
    }
    destination[(ssize_t)channels * destination_offset + i] = (Quantum)((MagickFloatType)sum * inv_size);
}
}
