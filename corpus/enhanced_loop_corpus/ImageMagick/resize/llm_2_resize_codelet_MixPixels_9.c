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
    Quantum *src_base = &source[i];
    for (j = 0; j < (ssize_t)source_size; j++) {
        ssize_t offset = source_offset[j] * (ssize_t)channels;
        sum += (ssize_t)src_base[offset];
    }
    destination[(ssize_t)channels * destination_offset + i] = (Quantum)(sum / (ssize_t)source_size);
}
}
