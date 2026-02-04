#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double *arguments;
extern size_t i;
extern double inverse[8];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 12UL; i += 2) {
        inverse[i % 8] = arguments[i % 8] * 2.0 + 1.5;
        inverse[(i + 1) % 8] = (arguments[(i + 1) % 8] * 2.0 + 1.5) / 3.0;
    }
}
