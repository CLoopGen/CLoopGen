#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float MagickFloatType;

typedef MagickFloatType Quantum;

extern ssize_t i;
extern double reference_black;
extern Quantum *logmap;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (reference_black >= 0) {
        ssize_t limit = (ssize_t)(reference_black * 65535UL / 1024.);
        for (i = 0; i <= limit; i += 8) {
            for (ssize_t j = 0; j < 8 && (i + j) <= limit; j++) {
                logmap[i + j] = (Quantum)0;
            }
        }
    }
}
