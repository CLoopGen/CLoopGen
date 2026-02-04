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
    for (ssize_t j = 0; j < (ssize_t)channels; j++) {
        for (i = 0; i < (ssize_t)channels; i++) {
            if (j == 0) {
                destination[(ssize_t)channels * destination_offset + i] = source[source_offset * (ssize_t)channels + i];
            }
        }
    }
}
