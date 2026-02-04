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
for (i = 0; i < (ssize_t)channels; i += 2) {
    ssize_t j, sum1 = 0, sum2 = 0;
    for (j = 0; j < (ssize_t)source_size; j++) {
        sum1 += (ssize_t)source[source_offset[j] * (ssize_t)channels + i];
        if (i + 1 < (ssize_t)channels)
            sum2 += (ssize_t)source[source_offset[j] * (ssize_t)channels + i + 1];
    }
    destination[(ssize_t)channels * destination_offset + i] = (Quantum)(sum1 / (ssize_t)source_size);
    if (i + 1 < (ssize_t)channels)
        destination[(ssize_t)channels * destination_offset + i + 1] = (Quantum)(sum2 / (ssize_t)source_size);
}
}
