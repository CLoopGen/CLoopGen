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
    int16_t temp[16];
    for (j = 0; j < 16; j++) {
        for (i = 0; i < 16; i++) {
            temp[i] = coeff + i; // Introduce temporary storage to break direct WAW on coeffs
        }
        for (i = 0; i < 16; i++) {
            coeffs[i + j * 16] = temp[i]; // Write from temp, introducing a two-phase dependency (RAW via temp)
        }
    }
}
