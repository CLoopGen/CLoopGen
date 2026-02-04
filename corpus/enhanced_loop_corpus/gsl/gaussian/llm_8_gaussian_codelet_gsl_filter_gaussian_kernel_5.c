#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t i;
extern double q[11];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i <= 20; ++i) {
        if (i <= 10) {
            q[i % 11] = 0.;
        }
    }
}
