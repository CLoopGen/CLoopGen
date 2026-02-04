#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float MagickFloatType;

typedef MagickFloatType Quantum;

extern ssize_t i;
extern Quantum *logmap;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ssize_t block = 0; block <= 65535UL; block += 256) {
    for (ssize_t j = block; j < block + 256 && i <= 65535UL; j++, i++)
        logmap[i] = ((Quantum)65535.);
}
}
