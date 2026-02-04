#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern float band_score[21];
extern float max_score;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2, wrapping around using modulo)
    max_score = band_score[0]; // Initialize to first element to ensure valid comparison
    for (i = 0; i < 21; i++) {
        int index = (i * 2) % 21; // Strided access: every second element, wrap with modulo
        if (band_score[index] > max_score)
            max_score = band_score[index];
    }
}
