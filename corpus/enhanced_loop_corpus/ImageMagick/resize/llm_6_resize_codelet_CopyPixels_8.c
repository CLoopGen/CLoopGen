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
    ssize_t base_dest = (ssize_t)channels * destination_offset;
    ssize_t base_src = source_offset * (ssize_t)channels;
    Quantum temp;
    for (i = 0; i < (ssize_t)channels; i++) {
        temp = source[base_src + i];
        destination[base_dest + i] = temp;
    }
}
