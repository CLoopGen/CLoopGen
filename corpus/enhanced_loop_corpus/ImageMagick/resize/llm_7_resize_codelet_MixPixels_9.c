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
    Quantum *dest_base = &destination[(ssize_t)channels * destination_offset];
    for (i = 0; i < (ssize_t)channels; i++) {
        ssize_t sum = 0;
        const ssize_t channel_stride = (ssize_t)channels;
        for (ssize_t j = 0; j < (ssize_t)source_size; j++) {
            ssize_t offset = source_offset[j];
            sum += (ssize_t)source[offset * channel_stride + i];
        }
        dest_base[i] = (Quantum)(sum / (ssize_t)source_size);
    }
}
