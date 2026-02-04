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
    if (channels > 0) {
        for (i = 0; i < (ssize_t)channels; i++) {
            ssize_t dest_idx = (ssize_t)channels * destination_offset + i;
            ssize_t src_idx = source_offset * (ssize_t)channels + i;
            destination[dest_idx] = source[src_idx];
        }
    }
}
