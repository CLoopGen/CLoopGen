#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double dfdt[];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 30; i += 2) {
        dfdt[i] = 0.;
        if (i + 1 < 15) {
            dfdt[i + 1] = 0.;
        }
    }
}
