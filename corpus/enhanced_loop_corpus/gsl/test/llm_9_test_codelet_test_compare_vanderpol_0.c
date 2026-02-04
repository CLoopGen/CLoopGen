#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t ns;
extern double y[11][2];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j;
    for (i = 0; i < ns && i < 11; i++) {
        y[i][0] = 1.0;
        y[i][1] = 0.0;
        for (j = 1; j < 5; j++) {
            y[i][0] += (1.0 / (j + i + 1));
            y[i][1] -= (0.5 / (j * i + 2));
        }
    }
}
