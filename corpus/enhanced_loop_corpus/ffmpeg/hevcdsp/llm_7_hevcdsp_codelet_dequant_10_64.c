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
    int16_t *base = coeffs;
    for (y = 0; y < size; y++) {
        for (x = 0; x < size; x++) {
            int index = y * size + x;
            int16_t temp = *(int16_t*)((char*)base + index * sizeof(int16_t));
            temp = (int16_t)((uint16_t)temp << (-shift & 0xF)); // Mask shift to valid range
            *(int16_t*)((char*)base + index * sizeof(int16_t)) = temp;
        }
    }
    coeffs = base + size * size; // Update global pointer after loop
}
