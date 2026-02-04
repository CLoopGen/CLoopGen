#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern float band_score[21];
extern float max_score;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access
    max_score = band_score[20]; // Initialize with last element
    for (i = 20; i >= 0; i--) {
        if (band_score[i] > max_score)
            max_score = band_score[i];
    }
}
