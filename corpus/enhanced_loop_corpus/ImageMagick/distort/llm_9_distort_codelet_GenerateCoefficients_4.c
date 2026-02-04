#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double *arguments;
extern size_t i;
extern double inverse[8];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j;
    for (i = 0; i < 3UL; i++) {
        for (j = 0; j < 3UL; j++) {
            if (i * 3 + j < 8) {
                inverse[i * 3 + j] = (arguments[i * 3 + j] + arguments[(i * 3 + j) ^ 1]) * 0.5;
            }
        }
    }
}
