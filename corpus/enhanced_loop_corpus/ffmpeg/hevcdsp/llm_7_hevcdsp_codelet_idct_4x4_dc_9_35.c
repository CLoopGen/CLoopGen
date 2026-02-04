#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *coeffs;
extern int i;
extern int j;
extern int coeff;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced trip count with increased outer complexity using stride and conditional computation
    for (j = 0; j < 2; j++) {
        for (i = 0; i < 8; i++) {
            int idx = i + (j * 8);
            if (i < 4) {
                coeffs[idx] = coeff + (i * j);
            } else {
                coeffs[idx - 4] = coeff - (i % 3);
            }
        }
    }
}
