#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *coeffs;
extern int shift;
extern int x;
extern int y;
extern int size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int16_t *local_coeffs = coeffs;
    for (y = 0; y < size; y++) {
        for (x = 0; x < size; x++) {
            int16_t temp = *local_coeffs;
            temp = (int16_t)((uint16_t)temp << -shift);
            *local_coeffs = temp;
            local_coeffs++;
        }
    }
}
